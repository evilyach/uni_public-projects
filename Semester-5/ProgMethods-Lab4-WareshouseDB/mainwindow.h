#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QVector>
#include "QStandardItemModel"

namespace Ui {
class MainWindow;
}

/*!
 * \brief The Warehouse class
 */
class Warehouse
{
public:
    //! Контрукторы
    Warehouse(): items_stock(0), items_needed(0), price(0) {}
    Warehouse(QString nName, int nItemsStock, int nItemsNeeded,
            QString nBuyer, QString nDate, int nPrice):
        name(nName), items_stock(nItemsStock), items_needed(nItemsNeeded),
        buyer(nBuyer), date(nDate), price(nPrice) {}

    // Поля таблицы
    QString name;           // Наименование
    int items_stock;        // Товаров в наличии
    int items_needed;       // Товаров необходимо
    QString buyer;          // Наименование покупателя
    QString date;           // Дата получения
    int price;              // Цена
};


/*!
 * \brief The StudentList class
 */
class WarehouseList
{
public:
    QVector<Warehouse> warehouses;
};


/*!
 * \brief The MainWindow class
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    enum Filters { NONE, TOADD, BUYERS, UNGOTTEN, EXPENSIVE};

    void printWarehouses(enum Filters filter);
    void addToModel(int i);

private slots:
    void on_addButton_clicked();
    void on_noneFilterButton_clicked();
    void on_toaddFilterButton_clicked();
    void on_buyersFilterButton_clicked();
    void on_ungottenFilterButton_clicked();
    void on_expensiveFilterButton_clicked();
    void on_exitAction_triggered();
    void on_openAction_triggered();
    void on_saveAction_triggered();

private:
    Ui::MainWindow *ui;
    WarehouseList warehouse_list;
    QStandardItemModel *model;
    QStandardItem *item;
};

#endif // MAINWINDOW_H
