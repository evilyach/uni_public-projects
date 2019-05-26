#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStandardItemModel>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ids = 0;
    ui->setupUi(this);
    printStudents(NONE);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::printStudents(enum Filters filter)
{
    model = new QStandardItemModel();

    // Установка заголовка
    QStringList header;
    header.append("Номер");
    header.append("Фамилия");
    header.append("Имя");
    header.append("Отчество");
    header.append("Номер группы");
    header.append("Оценка матем.");
    header.append("Оценка инф.");
    header.append("Оценка физика");
    model->setHorizontalHeaderLabels(header);

    if (filter == DECREASE)
        sortByAverage();

    for (int i = 0; i < student_list.students.length(); ++i) {
        switch (filter) {
        case NONE:
        case DECREASE:
            addToModel(i);
            break;
        case GROUP:
            if (student_list.students[i].group_id == ui->groupFilterEdit->text())
                addToModel(i);
            break;
        case DEBT:
            if (student_list.students[i].math_mark <= 2 or
                student_list.students[i].cs_mark <= 2 or
                student_list.students[i].physics_mark <= 2)
                addToModel(i);
            break;
        case GOOD:
            if (student_list.students[i].math_mark >= 4 and
                student_list.students[i].cs_mark >= 4 and
                student_list.students[i].physics_mark >= 4)
                addToModel(i);
            break;
        }
    }

    ui->table->setModel(model);
    ui->table->resizeColumnsToContents();
}

void MainWindow::addToModel(int i)
{
    item = new QStandardItem(QString::number(student_list.students[i].id));
    model->setItem(i, 0, item);

    item = new QStandardItem(student_list.students[i].surname);
    model->setItem(i, 1, item);

    item = new QStandardItem(student_list.students[i].name);
    model->setItem(i, 2, item);

    item = new QStandardItem(student_list.students[i].patronymic);
    model->setItem(i, 3, item);

    item = new QStandardItem(student_list.students[i].group_id);
    model->setItem(i, 4, item);

    item = new QStandardItem(QString::number(student_list.students[i].math_mark));
    model->setItem(i, 5, item);

    item = new QStandardItem(QString::number(student_list.students[i].cs_mark));
    model->setItem(i, 6, item);

    item = new QStandardItem(QString::number(student_list.students[i].physics_mark));
    model->setItem(i, 7, item);
}

void MainWindow::sortByAverage()
{
    return;
}

void MainWindow::on_addButton_clicked()
{
    Student student = Student(
        ui->curnameEdit->text(),
        ui->nameEdit->text(),
        ui->patronymicEdit->text(),
        ui->groupIdEdit->text(),
        ui->mathMarkBox->value(),
        ui->csMarkBox->value(),
        ui->physicsMarkBox->value()
    );
    student.id = ++ids;

    student_list.students.append(student);

    ui->curnameEdit->setText("");
    ui->nameEdit->setText("");
    ui->patronymicEdit->setText("");
    ui->groupIdEdit->setText("");
    ui->mathMarkBox->setValue(0);
    ui->csMarkBox->setValue(0);
    ui->physicsMarkBox->setValue(0);

    printStudents(NONE);
}

void MainWindow::on_noneFilterButton_clicked()
{
    printStudents(NONE);
}

void MainWindow::on_groupFilterButton_clicked()
{
    printStudents(GROUP);
}

void MainWindow::on_debtFilterButton_clicked()
{
    printStudents(DEBT);
}

void MainWindow::on_goodFilterButton_clicked()
{
    printStudents(GOOD);
}

void MainWindow::on_decreaseFilterButton_clicked()
{
    printStudents(DECREASE);
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
    for (int i = 0; i < student_list.students.length(); ++i) {
        out << QString::number(student_list.students[i].id) << "\n";
        out << student_list.students[i].surname << "\n";
        out << student_list.students[i].name << "\n";
        out << student_list.students[i].patronymic << "\n";
        out << student_list.students[i].group_id << "\n";
        out << QString::number(student_list.students[i].math_mark) << "\n";
        out << QString::number(student_list.students[i].cs_mark) << "\n";
        out << QString::number(student_list.students[i].physics_mark) << "\n";
    }

    f.close();
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

    student_list.students.clear();
    ids = 0;

    QTextStream in(&f);
    in.setCodec("UTF-8");
    QString raw_data;

    do {
        Student temp = Student();

        temp.id = in.readLine().toInt();
        temp.surname = in.readLine();
        temp.name = in.readLine();
        temp.patronymic = in.readLine();
        temp.group_id = in.readLine();
        temp.math_mark = in.readLine().toInt();
        temp.cs_mark = in.readLine().toInt();
        temp.physics_mark = in.readLine().toInt();

        student_list.students.append(temp);
        ++ids;
    } while (!raw_data.isNull());
    f.close();

    printStudents(NONE);
}

void MainWindow::on_closeAction_triggered()
{
    close();
}
