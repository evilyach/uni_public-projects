#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "manual.h"
#include "ui_manual.h"
#include "list.h"
#include <QMessageBox>
#include <QFileDialog>
#include <string>
#include <regex>
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    list = new CircularSinglyLinkedList();
    ui->setupUi(this);

    printList();
    updateForm();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateForm()
{
    ui->addAfterPosSpinBox->setMaximum(list->getSize());
}

void MainWindow::printList()
{
    ui->listList->clear();
    ui->listList->addItem("Всего элементов: " + QString::number(list->getSize()));

    Node *temp = list->begin();
    for (int i = 0; i < list->getSize(); ++i) {
        ui->listList->addItem("#" + QString::number(i) +
                              ": " + QString::number(temp->value));
        temp = temp->next;
    }
}

void MainWindow::on_exitAction_triggered()
{
    close();
}

void MainWindow::on_checkIfCircularAction_triggered()
{
    if (list->isCircular())
        QMessageBox::information(this, "Проверка на цикличность",
                                 "Список является циклическим",
                                 QMessageBox::Ok);
    else
        QMessageBox::information(this, "Проверка на цикличность",
                                 "Список не является циклическим",
                                 QMessageBox::Ok);
}

void MainWindow::on_clearAction_triggered()
{
    list->clear();

    printList();
    updateForm();
}

void MainWindow::on_addAtEndAction_triggered()
{
    ui->panel->setCurrentIndex(0);
}

void MainWindow::on_addAfterAction_triggered()
{
    ui->panel->setCurrentIndex(1);
}

void MainWindow::on_deleteAction_triggered()
{
    ui->panel->setCurrentIndex(2);
}


void MainWindow::on_addAtEndButton_clicked()
{
    if (list->addAtEnd(ui->addAtEndSpinBox->value())) {
        QMessageBox::warning(this, "Ошибка ввода",
                             "Не удалось добавить элемент: недопустимое значение",
                             QMessageBox::Ok);
    }

    printList();
    updateForm();
}

void MainWindow::on_addAfterButton_clicked()
{
    int error_code = list->addAfter(ui->addAfterPosSpinBox->value(),
                                    ui->addAfterXSpinBox->value());

    switch (error_code) {
    case EXIT_VALERROR:
        QMessageBox::warning(this, "Ошибка ввода",
                             "Не удалось добавить элемент: недопустимое значение",
                             QMessageBox::Ok);
        break;
    case EXIT_POSERROR:
        break;
    case EXIT_FAILURE:
        QMessageBox::warning(this, "Ошибка ввода",
                             "Не удалось добавить элемент: неизвестная ошибка",
                             QMessageBox::Ok);
        break;
    }

    printList();
    updateForm();
}

void MainWindow::on_deleteKeyButton_clicked()
{
    int errcode = list->remove(ui->deleteSpinBox->value());

    switch (errcode) {
    case EXIT_DELEMPTY:
        QMessageBox::warning(this, "Ошибка удаления",
                             "Не удалось удалить элемент: список пустой",
                             QMessageBox::Ok);
        break;
    case EXIT_DELNFOUND:
        QMessageBox::warning(this, "Ошибка удаления",
                             "Не удалось найти элемент",
                             QMessageBox::Ok);
        break;
    case EXIT_FAILURE:
        QMessageBox::warning(this, "Ошибка",
                             "Не удалось удалить элемент: неизвестная ошибка",
                             QMessageBox::Ok);
        break;
    }

    printList();
    updateForm();
}

void MainWindow::on_infoAction_triggered()
{
    QMessageBox::information(this, "О программе",
        "Выполнил курсовую работу\n"
        "по теме «Реализация списковых и древовидных структур данных»\n"
        "студент группы 641 Чесалин Илья Евгеньевич.\n"
        "Научный руководитель: ассистент кафедры ИБ Кураксин В.А.");
}

void MainWindow::on_manualAction_triggered()
{
    Manual *manual = new Manual();
    manual->exec();
}
