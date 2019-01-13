#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStandardItemModel>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QDate>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    printWarehouses(NONE);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::printWarehouses(enum Filters filter)
{
    model = new QStandardItemModel();

    // Установка заголовка
    QStringList header;
    header.append("Наименование");
    header.append("В наличии");
    header.append("Необходимо");
    header.append("Покупатель");
    header.append("Дата");
    header.append("Цена");
    model->setHorizontalHeaderLabels(header);

    for (int i = 0; i < warehouse_list.warehouses.length(); ++i) {
        switch (filter) {
        case NONE:
            addToModel(i);
            break;
        case TOADD:
            if (warehouse_list.warehouses[i].items_needed > warehouse_list.warehouses[i].items_stock)
                addToModel(i);
            break;
        case BUYERS:
            if (ui->buyerEdit->text() == warehouse_list.warehouses[i].buyer)
                addToModel(i);
            break;
        case UNGOTTEN:
        {
            QDate today = QDate::fromString(ui->dateEdit->text(), "dd/MM/yyyy");
            QDate date  = QDate::fromString(warehouse_list.warehouses[i].date, "dd/MM/yyyy");

            if (date < today)
                addToModel(i);
            break;
        }
        case EXPENSIVE:
            int max = 0;
            int max_index = 0;
            for (int j = 0; j < warehouse_list.warehouses.length(); ++j) {
                if (warehouse_list.warehouses[j].price > max) {
                    max = warehouse_list.warehouses[j].price;
                    max_index = j;
                }
            }
            addToModel(max_index);
            break;
        }
    }

    ui->table->setModel(model);
    ui->table->resizeColumnsToContents();
}

void MainWindow::addToModel(int i)
{
    item = new QStandardItem(warehouse_list.warehouses[i].name);
    model->setItem(i, 0, item);

    item = new QStandardItem(QString::number(warehouse_list.warehouses[i].items_stock));
    model->setItem(i, 1, item);

    item = new QStandardItem(QString::number(warehouse_list.warehouses[i].items_needed));
    model->setItem(i, 2, item);

    item = new QStandardItem(warehouse_list.warehouses[i].buyer);
    model->setItem(i, 3, item);

    item = new QStandardItem(warehouse_list.warehouses[i].date);
    model->setItem(i, 4, item);

    item = new QStandardItem(QString::number(warehouse_list.warehouses[i].price));
    model->setItem(i, 5, item);
}

void MainWindow::on_addButton_clicked()
{
    Warehouse warehouse = Warehouse(
        ui->nameEdit->text(),
        ui->stockBox->value(),
        ui->neededBox->value(),
        ui->buyerEdit->text(),
        ui->dateEdit->text(),
        ui->priceBox->value()
    );

    warehouse_list.warehouses.append(warehouse);

    ui->nameEdit->setText("");
    ui->stockBox->setValue(0);
    ui->neededBox->setValue(0);
    ui->buyerEdit->setText("");
    ui->dateEdit->setText("");
    ui->priceBox->setValue(0);

    printWarehouses(NONE);
}

void MainWindow::on_noneFilterButton_clicked()
{
    printWarehouses(NONE);
}

void MainWindow::on_toaddFilterButton_clicked()
{
    printWarehouses(TOADD);
}

void MainWindow::on_buyersFilterButton_clicked()
{
    printWarehouses(BUYERS);
}

void MainWindow::on_ungottenFilterButton_clicked()
{
    printWarehouses(UNGOTTEN);
}

void MainWindow::on_expensiveFilterButton_clicked()
{
    printWarehouses(EXPENSIVE);
}

void MainWindow::on_openAction_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, "Открыть файл");
    QFile f(filename);

    if (!f.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(
            this, "Предупреждение!",
            "Не удалось открыть файл " + filename);
        return;
    }

    warehouse_list.warehouses.clear();

    QTextStream in(&f);
    in.setCodec("UTF-8");
    QString raw_data;

    do {
        Warehouse temp = Warehouse();

        temp.name = in.readLine();
        temp.items_stock = in.readLine().toInt();
        temp.items_needed = in.readLine().toInt();
        temp.buyer = in.readLine();
        temp.date = in.readLine();
        temp.price = in.readLine().toInt();

        warehouse_list.warehouses.append(temp);
    } while (!raw_data.isNull());
    f.close();

    printWarehouses(NONE);
}

void MainWindow::on_saveAction_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this, "Открыть файл");
    QFile f(filename);

    if (!f.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(
            this, "Предупреждение!",
            "Не удалось открыть файл " + filename);
        return;
    }

    QTextStream out(&f);
    out.setCodec("UTF-8");
    for (int i = 0; i < warehouse_list.warehouses.length(); ++i) {
        out << warehouse_list.warehouses[i].name << "\n";
        out << QString::number(warehouse_list.warehouses[i].items_stock) << "\n";
        out << QString::number(warehouse_list.warehouses[i].items_needed) << "\n";
        out << warehouse_list.warehouses[i].buyer << "\n";
        out << warehouse_list.warehouses[i].date << "\n";
        out << QString::number(warehouse_list.warehouses[i].price) << "\n";
    }

    f.close();
}

void MainWindow::on_exitAction_triggered()
{
    close();
}
