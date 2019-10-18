#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "list.h"
#include "manual.h"
#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void printList();
    void updateForm();

private slots:
    void on_exitAction_triggered();
    void on_checkIfCircularAction_triggered();
    void on_addAtEndButton_clicked();
    void on_addAfterButton_clicked();
    void on_deleteKeyButton_clicked();
    void on_addAtEndAction_triggered();
    void on_addAfterAction_triggered();
    void on_deleteAction_triggered();
    void on_clearAction_triggered();
    void on_infoAction_triggered();
    void on_manualAction_triggered();

private:
    Ui::MainWindow *ui;
    CircularSinglyLinkedList *list;
};

#endif // MAINWINDOW_H
