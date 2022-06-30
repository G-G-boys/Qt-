#include "adddishes.h"
#include "ui_adddishes.h"
#include <QButtonGroup>
#include<QDebug>
#include "mainwindow.h"
#include "main.cpp"
#pragma execution_character_set(“GBK”)
using namespace std;
adddishes::adddishes(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::adddishes)
{
    setAttribute(Qt::WA_QuitOnClose,false);
    ui->setupUi(this);
    QButtonGroup *Group_1 = new QButtonGroup(this);
    Group_1->addButton(ui->radioButton_1);
    Group_1->addButton(ui->radioButton_2);
    Group_1->addButton(ui->radioButton_3);
    Group_1->addButton(ui->radioButton_4);
    Group_1->addButton(ui->radioButton_5);
    Group_1->addButton(ui->radioButton_6);
    QButtonGroup *Group_2 = new QButtonGroup(this);
    Group_2->addButton(ui->radioButton_7);
    Group_2->addButton(ui->radioButton_8);
    Group_2->addButton(ui->radioButton_9);
    Group_2->addButton(ui->radioButton_10);
}

adddishes::~adddishes()
{
    delete ui;
}

void adddishes::on_pushButton_clicked()
{
    Food addfood;
    double jia = ui->doubleSpinBox->value();
    addfood.setprice(jia);
    string ming = ui->lineEdit_1->text().toStdString();
    string chuang = ui->lineEdit_2->text().toStdString();
    QString mmm = QString::fromStdString(ming);
    mmm = QString::fromStdString(chuang);
    addfood.setname(ming);
    addfood.setwindow(chuang);
    string addshitang;
    if(ui->radioButton_1->isChecked())
        addshitang = "家园";
    if(ui->radioButton_2->isChecked())
        addshitang = "燕南";
    if(ui->radioButton_3->isChecked())
        addshitang = "学一";
    if(ui->radioButton_4->isChecked())
        addshitang = "农园";
    if(ui->radioButton_5->isChecked())
        addshitang = "学五";
    if(ui->radioButton_6->isChecked())
        addshitang = "勺园";
    addfood.setcanteen(addshitang);
    string zhonglei;
    if(ui->radioButton_7->isChecked())
        zhonglei="Veg_Diet";
    if(ui->radioButton_8->isChecked())
        zhonglei="Meat_Diet";
    if(ui->radioButton_9->isChecked())
        zhonglei="VegnMeat_mix";
    if(ui->radioButton_10->isChecked())
        zhonglei="Set_Meal";
    addfood.settype(zhonglei);
    int kouwei1=ui->Slider_1->value();
    int kouwei2=ui->Slider_2->value();
    int kouwei3=ui->Slider_3->value();
    addfood.setsalt(kouwei1);
    addfood.setsweet(kouwei2);
    addfood.setspicy(kouwei3);
    int shanshi1=ui->ScrollBar_1->value();
    int shanshi2=ui->ScrollBar_2->value();
    int shanshi3=ui->ScrollBar_3->value();
    int shanshi4=ui->ScrollBar_4->value();
    addfood.setcalorie(shanshi1);
    addfood.setprotein(shanshi2);
    addfood.setgrease(shanshi3);
    addfood.setcellulose(shanshi4);
    add_reset_file(addfood);
    this->close();
}
