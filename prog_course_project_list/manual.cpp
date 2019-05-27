#include "manual.h"
#include "ui_manual.h"

Manual::Manual(QWidget *parent) :
    QDialog(parent),
    manual(new Ui::Manual)
{
    manual->setupUi(this);
}

Manual::~Manual()
{
    delete manual;
}
