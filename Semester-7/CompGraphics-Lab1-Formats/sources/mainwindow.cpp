#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "helpwindow.h"

#include <QMessageBox>
#include <QFileDialog>
#include <QStandardPaths>
#include <QPainter>
#include <QProcess>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->saveAction->setDisabled(true);

    ui->imageLabel->setBackgroundRole(QPalette::Base);
    ui->imageLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

    help = new HelpWindow();

    first_time = true;
}

MainWindow::~MainWindow()
{
    delete help;
    delete ui;
}


void MainWindow::on_helpAction_triggered()
{
    help->show();
}

void MainWindow::on_aboutAction_triggered()
{
    const char *caption = "О программе";
    const char *about_text =
        "Выполнил лабораторную работу №1\n"
        "по теме \"Графика в Delphi. Часть 1.\n"
        "Использование стандартных графических компонентов\"\n"
        "студент группы 641 Чесалин И.Е.\n"
        "Проверил доцент кафедры САПР Телков И.А.\n"
        "\n"
        "Иконки: icons8.com";

    QMessageBox::about(this, tr(caption), tr(about_text));
}

void MainWindow::on_exitAction_triggered()
{
    this->close();
}

void MainWindow::on_openAction_triggered()
{
    const char *filter = "Images (*.bmp)";
    const char *caption = "Загрузить изображение";

    QString location;
    if (first_time) {
        locations = QStandardPaths::standardLocations(QStandardPaths::PicturesLocation);
        location = locations.isEmpty() ? QDir::currentPath() : locations.last();
    }

    first_time = false;

    filepath = QFileDialog::getOpenFileName(
        this, tr(caption), location, tr(filter)
    );

    if (filepath.isEmpty())
        return;

    image = QImage(filepath);

    if (image.isNull()) {
        QMessageBox::critical(this, "Ошибка!",
            tr("Не удалось открыть файл!"));
        return;
    }

    QPainter painter(&pic);
    painter.drawImage(0, 0, image);
    painter.end();

    ui->imageLabel->setPicture(pic);
    ui->imageLabel->adjustSize();

    scroll_area.setBackgroundRole(QPalette::Dark);
    scroll_area.setWidget(ui->imageLabel);
    scroll_area.setVisible(true);
    setCentralWidget(&scroll_area);

    this->setGeometry(this->x(), this->y(),
        image.width() >= 800 ? 800 : image.width(),
        image.height() >= 600 ? 600 : image.height());

    ui->saveAction->setDisabled(false);
}

void MainWindow::on_saveAction_triggered()
{
    QString location = locations.last();

    const char *filter = "All (*)";
    const char *caption = "Сохранить изображение";

    QString filename = QFileDialog::getSaveFileName(
        this, tr(caption), location, tr(filter));

    if (!image.save(filename, nullptr, -1)) {
        const QStringList args = {"-i", filepath, filename};
        if (QProcess::execute("./ffmpeg.exe", args) < 0) {
            QMessageBox::information(this,
                tr("Ошибка!"),
                tr("Не удалось сохранить"
                   "Для сохранения GIF необходим программный пакет FFMPEG"));
            return;
        }

        QMessageBox::critical(this, tr("Ошибка!"),
            tr("Не удалось сохранить файл!"));
    }
}
