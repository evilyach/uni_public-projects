#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sort.h"
#include <QString>
#include <QInputDialog>
#include <QFileDialog>
#include <QMessageBox>
#include <QSettings>
#include <vector>
#include <cstring>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <regex>
#include <chrono>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    /**
     * Конструктор класса MainWindow
     */

    // Конструктор окна
    ui->setupUi(this);

    // По умолчанию все кнопки выключены
    disable_buttons();

    // Стандартный диапазон случайной генерации
    how_random = 1000;

    // По умолчанию размер массива равен нулю
    ui->textArrayLengthDisplay->setText(QString::number(v.size()));
}


MainWindow::~MainWindow()
{
    /**
     * Деструктор класса MainWindow
     */

    delete ui;
}


QString vector_to_string(std::vector<int> vec)
{
    /**
     * Выполняет вывод элементов вектора в строку
     *
     * Параметры:
     * vec - исходный вектор
     *
     * Возвращает: строку
     */

    QString string;

    for (auto &iterable:vec)
        string.append(QString::number(iterable) + " ");

    return string;
}


void MainWindow::disable_buttons()
{
    ui->pushButtonInsertionSort->setDisabled(true);
    ui->pushButtonSelectionSort->setDisabled(true);
    ui->pushButtonBubbleSort->setDisabled(true);
    ui->pushButtonShellSort->setDisabled(true);
    ui->pushButtonTetragonSort->setDisabled(true);
    ui->pushButtonQuickSort->setDisabled(true);
    ui->pushButtonMergeSort->setDisabled(true);
}


void MainWindow::enable_buttons()
{
    ui->pushButtonInsertionSort->setDisabled(false);
    ui->pushButtonSelectionSort->setDisabled(false);
    ui->pushButtonBubbleSort->setDisabled(false);
    ui->pushButtonShellSort->setDisabled(false);
    ui->pushButtonTetragonSort->setDisabled(false);
    ui->pushButtonQuickSort->setDisabled(false);
    ui->pushButtonMergeSort->setDisabled(false);
}


void MainWindow::on_actionAppend_triggered()
{
    /**
     * Обработчик события "Добавить элемент массива"
     */

    bool bOk;   // Кнопка OK

    // Запрос на ввод
    QString input = QInputDialog::getText(
        this,
        "Введите элемент массива",
        "Элемент массива:",
        QLineEdit::Normal,
        "",
        &bOk
    );

    // Если нажата кнопка "Cancel"
    if (!bOk)
        return;

    v.push_back(input.toInt());

    // Обновление полей на форме
    enable_buttons();
    ui->textArrayDisplay->setText(vector_to_string(v));
    ui->textArrayLengthDisplay->setText(QString::number(v.size()));
}


void MainWindow::on_actionGenerateRandomArray_triggered()
{
    /**
     * Обработчик события "Сгенерировать случайный массив"
     */

    bool bOk;   // Кнопка ОК

    // Запрос на ввод
    QString amount = QInputDialog::getText(
        this,
        "Генератор массива",
        "Введите количество случайных элементов массива:",
        QLineEdit::Normal,
        "",
        &bOk
    );

    // Если нажата кнопка "Cancel"
    if (!bOk)
        return;

    v.clear();

    for (int i = 0; i < amount.toInt(); ++i)
        v.push_back(rand() % how_random);

    // Обновление полей на форме
    enable_buttons();
    ui->textArrayDisplay->setText(vector_to_string(v));
    ui->textArrayLengthDisplay->setText(QString::number(v.size()));
}


void MainWindow::on_actionRemove_triggered()
{
    /**
     * Обработчик события "Удалить последний элемент массива"
     */

    if (v.size())
    {
        v.pop_back();

        // Обновление полей на форме
        ui->textArrayDisplay->setText(vector_to_string(v));
        ui->textArrayLengthDisplay->setText(QString::number(v.size()));
    }

    if (!v.size())
        disable_buttons();
}


void MainWindow::on_actionDelete_triggered()
{
    /**
     * Обработчик события "Удалить массив"
     */

    v.clear();

    // Обновление полей на форме
    disable_buttons();
    ui->textArrayDisplay->setText(vector_to_string(v));
    ui->textArrayLengthDisplay->setText(QString::number(v.size()));
}


void MainWindow::on_actionSaveAs_triggered()
{
    /**
     * Обработчик события "Сохранить как..."
     */

    QString filename = QFileDialog::getSaveFileName(
        this,
        "Сохранить файл"
    );

    QFile f(filename);

    if (!f.open( QIODevice::WriteOnly | QIODevice::Text ))
    {
        QMessageBox::warning(
            this,
            "Предупреждение!",
            "Не удалось открыть файл " + filename
        );
        return;
    }

    QDataStream out(&f);
    out << vector_to_string(v);
    f.close();
}


void MainWindow::on_actionOpen_triggered()
{
    /**
     * Обработчик события "Открыть"
     */

    QString filename = QFileDialog::getOpenFileName(
        this,
        "Открыть файл",
        "",
        "Все файлы (*);; Текстовые файлы (*.txt);; Исходные файлы (*.pas, *.c, *.cpp, *.h, *.py)"
    );

    QFile f(filename);

    if (!f.open( QIODevice::ReadOnly | QIODevice::Text ))
    {
        QMessageBox::warning(
            this,
            "Предупреждение!",
            "Не удалось открыть файл " + filename
        );
        return;
    }

    v.clear();

    QDataStream in(&f);
    QString qstring;
    in >> qstring;
    f.close();

    std::string string = qstring.toUtf8().constData();
    std::regex expression("\\d+ ");

    std::cout << "DEBUG";
    std::regex_iterator<std::string::iterator> rit( string.begin(), string.end(), expression );
    std::regex_iterator<std::string::iterator> rend;

    while (rit != rend)
    {
        v.push_back(std::stoi(rit->str()));
        ++rit;
    }

    // Обновление полей на форме
    enable_buttons();
    ui->textArrayDisplay->setText(vector_to_string(v));
    ui->textArrayLengthDisplay->setText(QString::number(v.size()));
}


void MainWindow::on_actionSave_triggered()
{
    /**
     * Обработчик события "Сохранить массив в память"
     */

    saved = v;
}


void MainWindow::on_actionUndo_triggered()
{
    /**
     * Обработчик события "Загрузить массив из памяти"
     */

    v = saved;

    // Обновление полей на форме
    if (v.size())
        enable_buttons();
    else
        disable_buttons();

    ui->textArrayDisplay->setText(vector_to_string(v));
    ui->textArrayLengthDisplay->setText(QString::number(v.size()));
}


void MainWindow::on_actionExit_triggered()
{
    /**
     * Обработчик события "Выйти"
     */

    close();
}


void MainWindow::on_actionSettings_triggered()
{
    /**
     * Обработчик события "Настройки"
     */

    bool bOk;   // Кнопка ОК

    // Запрос на ввод
    QString text = QInputDialog::getText(
        this,
        "Способ генерации",
        "Введите, в каком диапазоне необходимо генерировать числа:",
        QLineEdit::Normal,
        "",
        &bOk
    );

    // Если нажата кнопка "Cancel"
    if (!bOk)
        return;

    how_random = text.toInt();
}


void MainWindow::on_pushButtonInsertionSort_clicked()
{
    /**
     * Обработчик события "Сортировка простыми вставками"
     */

    auto start_time = std::chrono::high_resolution_clock::now();
    insersion_sort(v);
    auto finish_time = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> time_passed = finish_time - start_time;

    // Обновление полей на форме
    ui->textArrayDisplay->setText(vector_to_string(v));
    ui->textDisplayTimeInsertionSort->setText(QString::number(time_passed.count()) + " с");
}


void MainWindow::on_pushButtonSelectionSort_clicked()
{
    /**
     * Обработчик события "Сортировка простыми вставками"
     */

    auto start_time = std::chrono::high_resolution_clock::now();
    selection_sort(v);
    auto finish_time = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> time_passed = finish_time - start_time;

    // Обновление полей на форме
    ui->textArrayDisplay->setText(vector_to_string(v));
    ui->textDisplayTimeSelectionSort->setText(QString::number(time_passed.count()) + " с");
}


void MainWindow::on_pushButtonBubbleSort_clicked()
{
    /**
     * Обработчик события "Сортировка простым обменом"
     */

    auto start_time = std::chrono::high_resolution_clock::now();
    bubble_sort(v);
    auto finish_time = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> time_passed = finish_time - start_time;

    // Обновление полей на форме
    ui->textArrayDisplay->setText(vector_to_string(v));
    ui->textDisplayTimeBubbleSort->setText(QString::number(time_passed.count()) + " с");
}


void MainWindow::on_pushButtonShellSort_clicked()
{
    /**
     * Обработчик события "Сортировка простым обменом"
     */

    auto start_time = std::chrono::high_resolution_clock::now();
    shell_sort(v);
    auto finish_time = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> time_passed = finish_time - start_time;

    // Обновление полей на форме
    ui->textArrayDisplay->setText(vector_to_string(v));
    ui->textDisplayTimeShellSort->setText(QString::number(time_passed.count()) + " с");
}


void MainWindow::on_pushButtonTetragonSort_clicked()
{
    /**
     * Обработчик события "Сортировка двоичными вставками"
     */

    auto start_time = std::chrono::high_resolution_clock::now();
    tetragon_sort(v);
    auto finish_time = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> time_passed = finish_time - start_time;

    // Обновление полей на форме
    ui->textArrayDisplay->setText(vector_to_string(v));
    ui->textDisplayTimeTetragonSort->setText(QString::number(time_passed.count()) + " с");
}


void MainWindow::on_pushButtonQuickSort_clicked()
{
    /**
     * Обработчик события "Быстрая сортировка"
     */

    auto start_time = std::chrono::high_resolution_clock::now();
    quick_sort(v, 0, v.size());
    auto finish_time = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> time_passed = finish_time - start_time;

    // Обновление полей на форме
    ui->textArrayDisplay->setText(vector_to_string(v));
    ui->textDisplayTimeQuickSort->setText(QString::number(time_passed.count()) + " с");
}


void MainWindow::on_pushButtonMergeSort_clicked()
{
    /**
     * Обработчик события "Сортировка слиянием"
     */

    auto start_time = std::chrono::high_resolution_clock::now();
    merge_sort(v, 0, v.size());
    auto finish_time = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> time_passed = finish_time - start_time;

    // Обновление полей на форме
    ui->textArrayDisplay->setText(vector_to_string(v));
    ui->textDisplayTimeMergeSort->setText(QString::number(time_passed.count()) + " с");
}
