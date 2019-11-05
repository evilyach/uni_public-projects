#include "mainwindow.h"
#include "rasformat.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QFile>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QFile *file = new QFile("./CHEM02.RAS");
    if (!file->open(QIODevice::ReadOnly)) {
        qDebug() << "Could not open file!";
        return;
    }

    RASFormat *ras = new RASFormat();
    QPixmap *pixmap = ras->load(file);

    if (!pixmap) {
        qDebug() << "Could not load ras picture";
    }

    ui->ImageLabel->setPixmap(*pixmap);

    file->close();
}

MainWindow::~MainWindow()
{
    delete ui;
}
