#include "assess.h"
#include "ui_assess.h"

assess::assess(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::assess)
{
    setAttribute(Qt::WA_QuitOnClose,false);
    ui->setupUi(this);
}

assess::~assess()
{
    delete ui;
}


void assess::on_pushButton_clicked()
{
    this->close();
    int lovevalue=3;
    if(ui->radioButton_1->isChecked())
        lovevalue=1;
    if(ui->radioButton_2->isChecked())
        lovevalue=2;
    if(ui->radioButton_3->isChecked())
        lovevalue=3;
    if(ui->radioButton_4->isChecked())
        lovevalue=4;
    if(ui->radioButton_5->isChecked())
        lovevalue=5;
    int asskou1=ui->spinBox_1->value();
    int asskou2=ui->spinBox_2->value();
    int asskou3=ui->spinBox_3->value();
}
