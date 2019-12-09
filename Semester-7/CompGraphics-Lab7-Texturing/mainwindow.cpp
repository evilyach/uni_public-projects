#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_CloseAction_triggered()
{
    close();
}

void MainWindow::on_InfoAction_triggered()
{
    const char *caption = "О программе";
    const char *about_text =
        "Выполнил лабораторную работу №2\n"
        "по теме \"Программирование с использованием OpenGL. Часть 1.\n"
        "Трехмерные построения в OpenGL\".\n"
        "студент группы 641 Чесалин И.Е.\n"
        "Проверил доцент кафедры САПР Телков И.А.\n"
        "\n"
        "Иконки: icons8.com";

    QMessageBox::about(this, tr(caption), tr(about_text));
}

void MainWindow::on_AboutAction_triggered()
{
    const char *caption = "О программе";
        const char *about_text =
            "Данная программа позволяет строить фигуру, указанную для варианта 9\n"
            "с использованием библиотеки OpenGL.";

        QMessageBox::information(this, tr(caption), tr(about_text));
}
