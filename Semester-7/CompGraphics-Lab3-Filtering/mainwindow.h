#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "filter.h"

#include <QPixmap>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ExitAction_triggered();
    void on_OpenAction_triggered();
    void on_SaveAsAction_triggered();
    void on_ApplyFilterAction_triggered();
    void on_ApplyButton_clicked();
    void on_ModeBox_currentIndexChanged(int index);
    void on_InfoAction_triggered();

    void on_AboutAction_triggered();

private:
    void apply();
    Filter::filter_kernel_t getMode();
    void setKernelMode(Filter::filter_kernel_t mode);

    Ui::MainWindow *ui;

    QImage *image;

    Filter::filter_kernel_t kernel_mode;
    QString filepath;
    QStringList locations;
    bool first_time;
};
#endif // MAINWINDOW_H
