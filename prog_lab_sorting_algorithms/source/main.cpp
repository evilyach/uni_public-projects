#include "sort.h"
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Создание объекта окна
    MainWindow w;

    // Показ окна
    w.show();

    return a.exec();
}
