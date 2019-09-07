#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "helpwindow.h"
#include <QMainWindow>
#include <QScrollArea>
#include <QPicture>

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
    void on_helpAction_triggered();
    void on_aboutAction_triggered();
    void on_exitAction_triggered();
    void on_openAction_triggered();

    void on_saveAction_triggered();

private:
    Ui::MainWindow *ui;
    HelpWindow *help;
    QImage image;
    QPicture pic;
    QScrollArea scroll_area;
    QStringList locations;
    QString filepath;

    bool first_time;
};

#endif // MAINWINDOW_H
