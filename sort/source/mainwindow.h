#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSettings>

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    std::vector<int> v, saved;

private slots:
    void on_actionAppend_triggered();
    void on_actionGenerateRandomArray_triggered();
    void on_actionRemove_triggered();
    void on_actionDelete_triggered();
    void on_actionSave_triggered();
    void on_actionUndo_triggered();
    void on_actionExit_triggered();
    void on_actionOpen_triggered();
    void on_actionSaveAs_triggered();
    void on_actionSettings_triggered();
    void on_pushButtonInsertionSort_clicked();
    void on_pushButtonSelectionSort_clicked();
    void on_pushButtonBubbleSort_clicked();
    void on_pushButtonShellSort_clicked();
    void on_pushButtonTetragonSort_clicked();
    void on_pushButtonQuickSort_clicked();
    void on_pushButtonMergeSort_clicked();

private:
    QSettings *settings;
    int how_random;
    void disable_buttons();
    void enable_buttons();
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
