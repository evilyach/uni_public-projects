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

    this->setKernelMode(Filter::FK_3x3_K1);

    this->first_time = true;
}

MainWindow::~MainWindow()
{
    delete image;
    delete ui;
}

void MainWindow::setKernelMode(Filter::filter_kernel_t mode)
{
    this->kernel_mode = mode;

    QString basename("Низкочастотная фильтрация - Размытие с центральным элементом");
    QString *modename;

    switch (mode) {
        case (Filter::FK_3x3_K1): modename = new QString(" (3x3; тип 1)"); break;
        case (Filter::FK_3x3_K2): modename = new QString(" (3x3; тип 2)"); break;
        case (Filter::FK_3x3_K3): modename = new QString(" (3x3; тип 3)"); break;
        case (Filter::FK_5x5_K1): modename = new QString(" (5x5)"); break;
        case (Filter::FK_7x7_K1): modename = new QString(" (7x7)"); break;
        case (Filter::FK_9x9_K1): modename = new QString(" (9x9)"); break;
    }

    MainWindow::setWindowTitle(basename + modename);
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
    ui->ApplyButton->setEnabled(true);
    ui->SaveAsAction->setEnabled(true);
}

void MainWindow::on_SaveAsAction_triggered()
{
    QString location = locations.last();

    const char *filter = "All (*)";
    const char *caption = "Сохранить изображение";

    QString filename = QFileDialog::getSaveFileName(
        this, tr(caption), location, tr(filter));

    if (!image->save(filename, nullptr, -1)) {
        QMessageBox::critical(this, tr("Ошибка!"),
            tr("Не удалось сохранить файл!"));
    }
}

Filter::filter_kernel_t MainWindow::getMode()
{
    switch (ui->ModeBox->currentIndex()) {
        case 0: return Filter::FK_3x3_K1;
        case 1: return Filter::FK_3x3_K2;
        case 2: return Filter::FK_3x3_K3;
        case 3: return Filter::FK_5x5_K1;
        case 4: return Filter::FK_7x7_K1;
        case 5: return Filter::FK_9x9_K1;
    }

    Q_ASSERT_X(1, __func__, "You did not add new kernel right!");
}

void MainWindow::apply()
{
    Filter *filter = new Filter();
    filter->lffBlurApply(image, getMode());

    *image = image->scaled(ui->ImageLabel->size(), Qt::KeepAspectRatio);
    ui->ImageLabel->setPixmap(QPixmap::fromImage(*image));
}

void MainWindow::on_ApplyFilterAction_triggered()
{
    apply();
}

void MainWindow::on_ApplyButton_clicked()
{
    apply();
}

void MainWindow::on_ModeBox_currentIndexChanged(int index)
{
    if (index > 2) {
        ui->InfoLabel->setText("Применение фильтра может занять долгое время!");
    } else {
        ui->InfoLabel->setText("");
    }
}

void MainWindow::on_InfoAction_triggered()
{
    const char *caption = "О программе";
    const char *about_text =
        "Выполнил лабораторную работу №1\n"
        "по теме \"Фильтрация растровых изображений.\n"
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
        "Данная программа позволяет применять фильтр размытия для любых изображений,\n"
        "включая монохромные и цветные изображения любого адекватного размера и формата."
        "\n"
        "Чтобы применить фильтр, загрузите изображение через меню либо через панель управления.\n"
        "На экране появится изображение. Далее Вашему вниманию предлагается выбор из возможных\n"
        "режимов работы, каждый из которых представляет ядро фильтра.\n"
        "Выбрать фильтр можно в правой части интерфейса, в выпадающем меню. "
        "Чем больше ядро фильтра по размеру, тем более агрессивное размытие изображения происходит.\n"
        "Применять фильтр необходимо до достижения необходимого результата.\n"
        "После этого Вы можете сохранить отфильтрованное изображение.";

    QMessageBox::information(this, tr(caption), tr(about_text));
}
