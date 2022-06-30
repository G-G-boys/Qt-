#include "recommend.h"
#include "ui_recommend.h"


recommend::recommend(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::recommend)
{
    setAttribute(Qt::WA_QuitOnClose,false);
    ui->setupUi(this);
}

recommend::~recommend()
{
    delete ui;
}
void recommend::push_choose()
{

}

void recommend::on_suButton_1_clicked()
{
    ui->suButton_1->setDisabled(true);
    ui->suButton_1->setStyleSheet("QPushButton{background-color:yellow;color: blue;border-radius: 10px;border: 2px groove gray;border-style: outset;}");
    push_choose();
}

void recommend::on_suButton_2_clicked()
{
    ui->suButton_2->setDisabled(true);
    ui->suButton_2->setStyleSheet("QPushButton{background-color:yellow;color: blue;border-radius: 10px;border: 2px groove gray;border-style: outset;}");
    push_choose();
}

void recommend::on_suButton_3_clicked()
{
    ui->suButton_3->setDisabled(true);
    ui->suButton_3->setStyleSheet("QPushButton{background-color:yellow;color: blue;border-radius: 10px;border: 2px groove gray;border-style: outset;}");
    push_choose();
}

void recommend::on_hunButton_1_clicked()
{
    ui->hunButton_1->setDisabled(true);
    ui->hunButton_1->setStyleSheet("QPushButton{background-color:yellow;color: blue;border-radius: 10px;border: 2px groove gray;border-style: outset;}");
    push_choose();
}

void recommend::on_hunButton_2_clicked()
{
    ui->hunButton_2->setDisabled(true);
    ui->hunButton_2->setStyleSheet("QPushButton{background-color:yellow;color: blue;border-radius: 10px;border: 2px groove gray;border-style: outset;}");
    push_choose();
}

void recommend::on_hunButton_3_clicked()
{
    ui->hunButton_3->setDisabled(true);
    ui->hunButton_3->setStyleSheet("QPushButton{background-color:yellow;color: blue;border-radius: 10px;border: 2px groove gray;border-style: outset;}");
    push_choose();
}

void recommend::on_hunsuButton_1_clicked()
{
    ui->hunsuButton_1->setDisabled(true);
    ui->hunsuButton_1->setStyleSheet("QPushButton{background-color:yellow;color: blue;border-radius: 10px;border: 2px groove gray;border-style: outset;}");
    push_choose();
}

void recommend::on_hunsuButton_2_clicked()
{
    ui->hunsuButton_2->setDisabled(true);
    ui->hunsuButton_2->setStyleSheet("QPushButton{background-color:yellow;color: blue;border-radius: 10px;border: 2px groove gray;border-style: outset;}");
    push_choose();
}

void recommend::on_hunsuButton_3_clicked()
{
    ui->hunsuButton_3->setDisabled(true);
    ui->hunsuButton_3->setStyleSheet("QPushButton{background-color:yellow;color: blue;border-radius: 10px;border: 2px groove gray;border-style: outset;}");
    push_choose();
}

void recommend::on_taoButton_1_clicked()
{
    ui->taoButton_1->setDisabled(true);
    ui->taoButton_1->setStyleSheet("QPushButton{background-color:yellow;color: blue;border-radius: 10px;border: 2px groove gray;border-style: outset;}");
    push_choose();
}

void recommend::on_taoButton_2_clicked()
{
    ui->taoButton_2->setDisabled(true);
    ui->taoButton_2->setStyleSheet("QPushButton{background-color:yellow;color: blue;border-radius: 10px;border: 2px groove gray;border-style: outset;}");
    push_choose();
}

void recommend::on_taoButton_3_clicked()
{
    ui->taoButton_3->setDisabled(true);
    ui->taoButton_3->setStyleSheet("QPushButton{background-color:yellow;color: blue;border-radius: 10px;border: 2px groove gray;border-style: outset;}");
    push_choose();
}

void recommend::on_pushButton_clicked()
{
    this->close();
}
