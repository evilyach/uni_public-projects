#include <QDir>
#include <QFileDialog>
#include <QMessageBox>
#include <QPixmap>
#include <QStandardPaths>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "filter.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setKernelMode(Filter::FK_3x3);

    this->first_time = true;
}

MainWindow::~MainWindow()
{
    delete image;
    delete ui;
}

void MainWindow::on_ExitAction_triggered()
{
    this->close();
}

void MainWindow::on_OpenAction_triggered()
{
    const char *filter = "";
    const char *caption = "Открыть изображение";

    QString location;
    if (this->first_time) {
        locations = QStandardPaths::standardLocations(QStandardPaths::PicturesLocation);
        location = locations.isEmpty() ? QDir::currentPath() : locations.last();
    }

    this->first_time = false;

    filepath = QFileDialog::getOpenFileName(this, caption, location, filter);
    if (filepath.isEmpty()) {
        const char *caption = "Ошибка";
        const char *message = "Не удалось найти файл!";

        QMessageBox::information(this, caption, message);

        return;
    }

    image = new QImage();
    image->load(filepath);
    if (image->isNull()) {
        const char *caption = "Ошибка";
        const char *message = "Не удалось открыть файл!";

        QMessageBox::information(this, caption, message);

        return;
    }

    *image = image->scaled(ui->ImageLabel->size(), Qt::KeepAspectRatio);
    ui->ImageLabel->setPixmap(QPixmap::fromImage(*image));

    ui->ApplyFilterAction->setEnabled(true);
}

void MainWindow::setKernelMode(Filter::filter_kernel_t mode)
{
    this->kernel_mode = mode;

    QString basename("Низкочастотная фильтрация - Размытие с центральным элементом");
    QString *modename;

    switch (mode) {
        case (Filter::FK_3x3): modename = new QString(" (3x3)"); break;
        case (Filter::FK_5x5): modename = new QString(" (5x5)"); break;
        case (Filter::FK_7x7): modename = new QString(" (7x7)"); break;
        case (Filter::FK_9x9): modename = new QString(" (9x9)"); break;
    }

    MainWindow::setWindowTitle(basename + modename);
}

void MainWindow::on_ApplyFilterAction_triggered()
{
    Filter filter;
    filter.lff_blur_apply(image, kernel_mode);

    *image = image->scaled(ui->ImageLabel->size(), Qt::KeepAspectRatio);
    ui->ImageLabel->setPixmap(QPixmap::fromImage(*image));
}
