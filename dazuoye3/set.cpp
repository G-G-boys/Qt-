#include "set.h"
#include "ui_set.h"
#include "mainwindow.h"
#include <QDebug>
using namespace std;
#pragma execution_character_set(“GBK”)
set::set(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::set)
{
    setAttribute(Qt::WA_QuitOnClose,false);
    ui->setupUi(this);
}

set::~set()
{
    delete ui;
}

void set::on_intrecbutton_clicked()
{
    this->close();
    Food aim;
    int kou1=ui->spinBox_1->value();
    int kou2=ui->spinBox_2->value();
    int kou3=ui->spinBox_3->value();
    aim.setsalt(kou1);
    aim.setsweet(kou2);
    aim.setspicy(kou3);
    int shan1=ui->ScrollBar_1->value();
    int shan2=ui->ScrollBar_2->value();
    int shan3=ui->ScrollBar_3->value();
    int shan4=ui->ScrollBar_4->value();
    aim.setcalorie(shan1);
    aim.setprotein(shan3);
    aim.setgrease(shan2);
    aim.setcellulose(shan4);
    int setshitang=0;
    if(ui->checkBox_1->isChecked())
        setshitang+=1;
    if(ui->checkBox_2->isChecked())
        setshitang+=2;
    if(ui->checkBox_3->isChecked())
        setshitang+=4;
    if(ui->checkBox_4->isChecked())
        setshitang+=8;
    if(ui->checkBox_5->isChecked())
        setshitang+=16;
    if(ui->checkBox_6->isChecked())
        setshitang+=32;

    Dish_Package selected, ans;
        string t="Set_Meal";
        string s="Veg_Diet";
        string h="Meat_Diet";
        string b="VegnMeat_mix";
        //add_reset_file(temp);
        //cout << "TEST: output pack:\n";
        read_all_file(selected, setshitang);
        //(int ww=0;)
        //output_DishPack(selected);
        CalculateWeight_forPack(selected,aim);//智能推荐
        //Calrandom_weight_forPack(selected);//随机推荐
        ans = Weighted_random(selected);
        //output_DishPack(ans);
    new_recc = new recommend;
    new_recc->show();
    string ss;
    QString str;
    ss=ans.pVeg_Diet[0]->getname();
    str = QString::fromStdString(ss.c_str());
    //qDebug()<<str;
    new_recc->ui->suButton_1->setText(str);
    ss=ans.pVeg_Diet[0]->getcanteen();ss+="\n";ss+="价格:";
    str = QString::fromStdString(ss.c_str());
    str+= QString::number(ans.pVeg_Diet[0]->getprice(), 'f', 2);
    ss="元";ss+="\n";
    ss+=ans.pVeg_Diet[0]->getwindow();
    str += QString::fromStdString(ss.c_str());
    new_recc->ui->sulabel_1->setText(str);

    ss=ans.pVeg_Diet[1]->getname();
    str = QString::fromStdString(ss.c_str());
    //qDebug()<<str;
    new_recc->ui->suButton_2->setText(str);
    ss=ans.pVeg_Diet[1]->getcanteen();ss+="\n";ss+="价格:";
    str = QString::fromStdString(ss.c_str());
    str+= QString::number(ans.pVeg_Diet[1]->getprice(), 'f', 2);
    ss="元";ss+="\n";
    ss+=ans.pVeg_Diet[1]->getwindow();
    str += QString::fromStdString(ss.c_str());
    new_recc->ui->sulabel_2->setText(str);

    ss=ans.pVeg_Diet[2]->getname();
    str = QString::fromStdString(ss.c_str());
    //qDebug()<<str;
    new_recc->ui->suButton_3->setText(str);
    ss=ans.pVeg_Diet[2]->getcanteen();ss+="\n";ss+="价格:";
    str = QString::fromStdString(ss.c_str());
    str+= QString::number(ans.pVeg_Diet[2]->getprice(), 'f', 2);
    ss="元";ss+="\n";
    ss+=ans.pVeg_Diet[2]->getwindow();
    str += QString::fromStdString(ss.c_str());
    new_recc->ui->sulabel_3->setText(str);

    ss=ans.pMeat_Diet[0]->getname();
    str = QString::fromStdString(ss.c_str());
    //qDebug()<<str;
    new_recc->ui->hunButton_1->setText(str);
    ss=ans.pMeat_Diet[0]->getcanteen();ss+="\n";ss+="价格:";
    str = QString::fromStdString(ss.c_str());
    str+= QString::number(ans.pMeat_Diet[0]->getprice(), 'f', 2);
    ss="元";ss+="\n";
    ss+=ans.pMeat_Diet[0]->getwindow();
    str += QString::fromStdString(ss.c_str());
    new_recc->ui->hunlabel_1->setText(str);

    ss=ans.pMeat_Diet[1]->getname();
    str = QString::fromStdString(ss.c_str());
    //qDebug()<<str;
    new_recc->ui->hunButton_2->setText(str);
    ss=ans.pMeat_Diet[1]->getcanteen();ss+="\n";ss+="价格:";
    str = QString::fromStdString(ss.c_str());
    str+= QString::number(ans.pMeat_Diet[1]->getprice(), 'f', 2);
    ss="元";ss+="\n";
    ss+=ans.pMeat_Diet[1]->getwindow();
    str += QString::fromStdString(ss.c_str());
    new_recc->ui->hunlabel_2->setText(str);

    ss=ans.pMeat_Diet[2]->getname();
    str = QString::fromStdString(ss.c_str());
    //qDebug()<<str;
    new_recc->ui->hunButton_3->setText(str);
    ss=ans.pMeat_Diet[2]->getcanteen();ss+="\n";ss+="价格:";
    str = QString::fromStdString(ss.c_str());
    str+= QString::number(ans.pMeat_Diet[2]->getprice(), 'f', 2);
    ss="元";ss+="\n";
    ss+=ans.pMeat_Diet[2]->getwindow();
    str += QString::fromStdString(ss.c_str());
    new_recc->ui->hunlabel_3->setText(str);

    ss=ans.pVegnMeat_mix[0]->getname();
    str = QString::fromStdString(ss.c_str());
    //qDebug()<<str;
    new_recc->ui->hunsuButton_1->setText(str);
    ss=ans.pVegnMeat_mix[0]->getcanteen();ss+="\n";ss+="价格:";
    str = QString::fromStdString(ss.c_str());
    str+= QString::number(ans.pVegnMeat_mix[0]->getprice(), 'f', 2);
    ss="元";ss+="\n";
    ss+=ans.pVegnMeat_mix[0]->getwindow();
    str += QString::fromStdString(ss.c_str());
    new_recc->ui->hunsulabel_1->setText(str);

    ss=ans.pVegnMeat_mix[1]->getname();
    str = QString::fromStdString(ss.c_str());
    //qDebug()<<str;
    new_recc->ui->hunsuButton_2->setText(str);
    ss=ans.pVegnMeat_mix[1]->getcanteen();ss+="\n";ss+="价格:";
    str = QString::fromStdString(ss.c_str());
    str+= QString::number(ans.pVegnMeat_mix[1]->getprice(), 'f', 2);
    ss="元";ss+="\n";
    ss+=ans.pVegnMeat_mix[1]->getwindow();
    str += QString::fromStdString(ss.c_str());
    new_recc->ui->hunsulabel_2->setText(str);

    ss=ans.pVegnMeat_mix[2]->getname();
    str = QString::fromStdString(ss.c_str());
    //qDebug()<<str;
    new_recc->ui->hunsuButton_3->setText(str);
    ss=ans.pVegnMeat_mix[2]->getcanteen();ss+="\n";ss+="价格:";
    str = QString::fromStdString(ss.c_str());
    str+= QString::number(ans.pVegnMeat_mix[2]->getprice(), 'f', 2);
    ss="元";ss+="\n";
    ss+=ans.pVegnMeat_mix[2]->getwindow();
    str += QString::fromStdString(ss.c_str());
    new_recc->ui->hunsulabel_3->setText(str);

    ss=ans.pSet_Meal[0]->getname();
    str = QString::fromStdString(ss.c_str());
    //qDebug()<<str;
    new_recc->ui->taoButton_1->setText(str);
    ss=ans.pSet_Meal[0]->getcanteen();ss+="\n";ss+="价格:";
    str = QString::fromStdString(ss.c_str());
    str+= QString::number(ans.pSet_Meal[0]->getprice(), 'f', 2);
    ss="元";ss+="\n";
    ss+=ans.pSet_Meal[0]->getwindow();
    str += QString::fromStdString(ss.c_str());
    new_recc->ui->taolabel_1->setText(str);

    ss=ans.pSet_Meal[1]->getname();
    str = QString::fromStdString(ss.c_str());
    //qDebug()<<str;
    new_recc->ui->taoButton_2->setText(str);
    ss=ans.pSet_Meal[1]->getcanteen();ss+="\n";ss+="价格:";
    str = QString::fromStdString(ss.c_str());
    str+= QString::number(ans.pSet_Meal[1]->getprice(), 'f', 2);
    ss="元";ss+="\n";
    ss+=ans.pSet_Meal[1]->getwindow();
    str += QString::fromStdString(ss.c_str());
    new_recc->ui->taolabel_2->setText(str);

    ss=ans.pSet_Meal[2]->getname();
    str = QString::fromStdString(ss.c_str());
    //qDebug()<<str;
    new_recc->ui->taoButton_3->setText(str);
    ss=ans.pSet_Meal[2]->getcanteen();ss+="\n";ss+="价格:";
    str = QString::fromStdString(ss.c_str());
    str+= QString::number(ans.pSet_Meal[2]->getprice(), 'f', 2);
    ss="元";ss+="\n";
    ss+=ans.pSet_Meal[2]->getwindow();
    str += QString::fromStdString(ss.c_str());
    new_recc->ui->taolabel_3->setText(str);
}
