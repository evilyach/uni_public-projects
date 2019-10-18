#ifndef MANUAL_H
#define MANUAL_H

#include <QDialog>

namespace Ui {
    class Manual;
}

class Manual : public QDialog
{
    Q_OBJECT

public:
    explicit Manual(QWidget *parent = nullptr);
    ~Manual();

private:
    Ui::Manual *manual;
};

#endif // MANUAL_H
