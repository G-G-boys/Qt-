#include "dish.h"
#include "ui_dish.h"

dish::dish(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dish)
{
    setAttribute(Qt::WA_QuitOnClose,false);
    ui->setupUi(this);
}

dish::~dish()
{
    delete ui;
}
