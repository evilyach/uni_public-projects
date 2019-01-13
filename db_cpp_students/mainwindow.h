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
 * \brief The Student class
 */
class Student
{
public:
    //! Контрукторы
    Student(): id(0), math_mark(0), cs_mark(0), physics_mark(0) {}
    Student(QString nSurname, QString nName, QString nPatronymic,
            QString nGroupId, int nMathMark, int nCsMark, int nPhysicsMark):
        surname(nSurname), name(nName), patronymic(nPatronymic),
        group_id(nGroupId), math_mark(nMathMark), cs_mark(nCsMark),
        physics_mark(nPhysicsMark) {}

    // Поля таблицы
    int id;                 // Порядковый номер в группе
    QString surname;        // Фамилия
    QString name;           // Имя
    QString patronymic;     // Отчество
    QString group_id;       // Номер группы
    int math_mark;          // Оценка по математике
    int cs_mark;            // Оценка по информатике
    int physics_mark;       // Оценка по физике
};


/*!
 * \brief The StudentList class
 */
class StudentList
{
public:
    QVector<Student> students;
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

    enum Filters { NONE, GROUP, DEBT, GOOD, DECREASE };

    void printStudents(enum Filters filter);
    void addToModel(int i);
    void sortByAverage();

private slots:
    void on_addButton_clicked();
    void on_noneFilterButton_clicked();
    void on_groupFilterButton_clicked();
    void on_debtFilterButton_clicked();
    void on_goodFilterButton_clicked();
    void on_decreaseFilterButton_clicked();
    void on_closeAction_triggered();
    void on_saveAction_triggered();
    void on_openAction_triggered();

private:
    Ui::MainWindow *ui;
    StudentList student_list;
    QStandardItemModel *model;
    QStandardItem *item;
    int ids;
};

#endif // MAINWINDOW_H
