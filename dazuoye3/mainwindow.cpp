#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <iostream>
using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addbutton_clicked()
{
    new_add = new adddishes;
    new_add->show();
}

void MainWindow::on_historybutton_clicked()
{
    new_his = new history;
    new_his->show();
}

void MainWindow::on_setbutton_clicked()
{
    new_set = new set;
    new_set->show();
}

void MainWindow::on_intrecbutton_clicked()
{
    /*new_set = new set;
    new_set->show();*/
    new_rec = new recommend;
    new_rec->show();
    int shitang=0;
    if(ui->checkBox_1->isChecked())
        shitang+=1;
    if(ui->checkBox_2->isChecked())
        shitang+=2;
    if(ui->checkBox_3->isChecked())
        shitang+=4;
    if(ui->checkBox_4->isChecked())
        shitang+=8;
    if(ui->checkBox_5->isChecked())
        shitang+=16;
    if(ui->checkBox_6->isChecked())
        shitang+=32;
    Dish_Package selected, ans;
        string t="Set_Meal";
        string s="Veg_Diet";
        string h="Meat_Diet";
        string b="VegnMeat_mix";
        //add_reset_file(temp);
        //cout << "TEST: output pack:\n";
        read_all_file(selected, shitang);
        //output_DishPack(selected);
        Food zhuaim = read_preference();
        CalculateWeight_forPack(selected,zhuaim);//智能推荐
        //Calrandom_weight_forPack(selected);//随机推荐
        ans = Weighted_random(selected);
        //output_DishPack(ans);
    string ss;
    QString str;
    ss=ans.pVeg_Diet[0]->getname();
    str = QString::fromStdString(ss.c_str());
    //qDebug()<<str;
    new_rec->ui->suButton_1->setText(str);
    ss=ans.pVeg_Diet[0]->getcanteen();ss+="\n";ss+="价格:";
    str = QString::fromStdString(ss.c_str());
    str+= QString::number(ans.pVeg_Diet[0]->getprice(), 'f', 2);
    ss="元";ss+="\n";
    ss+=ans.pVeg_Diet[0]->getwindow();
    str += QString::fromStdString(ss.c_str());
    new_rec->ui->sulabel_1->setText(str);

    ss=ans.pVeg_Diet[1]->getname();
    str = QString::fromStdString(ss.c_str());
    //qDebug()<<str;
    new_rec->ui->suButton_2->setText(str);
    ss=ans.pVeg_Diet[1]->getcanteen();ss+="\n";ss+="价格:";
    str = QString::fromStdString(ss.c_str());
    str+= QString::number(ans.pVeg_Diet[1]->getprice(), 'f', 2);
    ss="元";ss+="\n";
    ss+=ans.pVeg_Diet[1]->getwindow();
    str += QString::fromStdString(ss.c_str());
    new_rec->ui->sulabel_2->setText(str);

    ss=ans.pVeg_Diet[2]->getname();
    str = QString::fromStdString(ss.c_str());
    //qDebug()<<str;
    new_rec->ui->suButton_3->setText(str);
    ss=ans.pVeg_Diet[2]->getcanteen();ss+="\n";ss+="价格:";
    str = QString::fromStdString(ss.c_str());
    str+= QString::number(ans.pVeg_Diet[2]->getprice(), 'f', 2);
    ss="元";ss+="\n";
    ss+=ans.pVeg_Diet[2]->getwindow();
    str += QString::fromStdString(ss.c_str());
    new_rec->ui->sulabel_3->setText(str);

    ss=ans.pMeat_Diet[0]->getname();
    str = QString::fromStdString(ss.c_str());
    //qDebug()<<str;
    new_rec->ui->hunButton_1->setText(str);
    ss=ans.pMeat_Diet[0]->getcanteen();ss+="\n";ss+="价格:";
    str = QString::fromStdString(ss.c_str());
    str+= QString::number(ans.pMeat_Diet[0]->getprice(), 'f', 2);
    ss="元";ss+="\n";
    ss+=ans.pMeat_Diet[0]->getwindow();
    str += QString::fromStdString(ss.c_str());
    new_rec->ui->hunlabel_1->setText(str);

    ss=ans.pMeat_Diet[1]->getname();
    str = QString::fromStdString(ss.c_str());
    //qDebug()<<str;
    new_rec->ui->hunButton_2->setText(str);
    ss=ans.pMeat_Diet[1]->getcanteen();ss+="\n";ss+="价格:";
    str = QString::fromStdString(ss.c_str());
    str+= QString::number(ans.pMeat_Diet[1]->getprice(), 'f', 2);
    ss="元";ss+="\n";
    ss+=ans.pMeat_Diet[1]->getwindow();
    str += QString::fromStdString(ss.c_str());
    new_rec->ui->hunlabel_2->setText(str);

    ss=ans.pMeat_Diet[2]->getname();
    str = QString::fromStdString(ss.c_str());
    //qDebug()<<str;
    new_rec->ui->hunButton_3->setText(str);
    ss=ans.pMeat_Diet[2]->getcanteen();ss+="\n";ss+="价格:";
    str = QString::fromStdString(ss.c_str());
    str+= QString::number(ans.pMeat_Diet[2]->getprice(), 'f', 2);
    ss="元";ss+="\n";
    ss+=ans.pMeat_Diet[2]->getwindow();
    str += QString::fromStdString(ss.c_str());
    new_rec->ui->hunlabel_3->setText(str);

    ss=ans.pVegnMeat_mix[0]->getname();
    str = QString::fromStdString(ss.c_str());
    //qDebug()<<str;
    new_rec->ui->hunsuButton_1->setText(str);
    ss=ans.pVegnMeat_mix[0]->getcanteen();ss+="\n";ss+="价格:";
    str = QString::fromStdString(ss.c_str());
    str+= QString::number(ans.pVegnMeat_mix[0]->getprice(), 'f', 2);
    ss="元";ss+="\n";
    ss+=ans.pVegnMeat_mix[0]->getwindow();
    str += QString::fromStdString(ss.c_str());
    new_rec->ui->hunsulabel_1->setText(str);

    ss=ans.pVegnMeat_mix[1]->getname();
    str = QString::fromStdString(ss.c_str());
    //qDebug()<<str;
    new_rec->ui->hunsuButton_2->setText(str);
    ss=ans.pVegnMeat_mix[1]->getcanteen();ss+="\n";ss+="价格:";
    str = QString::fromStdString(ss.c_str());
    str+= QString::number(ans.pVegnMeat_mix[1]->getprice(), 'f', 2);
    ss="元";ss+="\n";
    ss+=ans.pVegnMeat_mix[1]->getwindow();
    str += QString::fromStdString(ss.c_str());
    new_rec->ui->hunsulabel_2->setText(str);

    ss=ans.pVegnMeat_mix[2]->getname();
    str = QString::fromStdString(ss.c_str());
    //qDebug()<<str;
    new_rec->ui->hunsuButton_3->setText(str);
    ss=ans.pVegnMeat_mix[2]->getcanteen();ss+="\n";ss+="价格:";
    str = QString::fromStdString(ss.c_str());
    str+= QString::number(ans.pVegnMeat_mix[2]->getprice(), 'f', 2);
    ss="元";ss+="\n";
    ss+=ans.pVegnMeat_mix[2]->getwindow();
    str += QString::fromStdString(ss.c_str());
    new_rec->ui->hunsulabel_3->setText(str);

    ss=ans.pSet_Meal[0]->getname();
    str = QString::fromStdString(ss.c_str());
    //qDebug()<<str;
    new_rec->ui->taoButton_1->setText(str);
    ss=ans.pSet_Meal[0]->getcanteen();ss+="\n";ss+="价格:";
    str = QString::fromStdString(ss.c_str());
    str+= QString::number(ans.pSet_Meal[0]->getprice(), 'f', 2);
    ss="元";ss+="\n";
    ss+=ans.pSet_Meal[0]->getwindow();
    str += QString::fromStdString(ss.c_str());
    new_rec->ui->taolabel_1->setText(str);

    ss=ans.pSet_Meal[1]->getname();
    str = QString::fromStdString(ss.c_str());
    //qDebug()<<str;
    new_rec->ui->taoButton_2->setText(str);
    ss=ans.pSet_Meal[1]->getcanteen();ss+="\n";ss+="价格:";
    str = QString::fromStdString(ss.c_str());
    str+= QString::number(ans.pSet_Meal[1]->getprice(), 'f', 2);
    ss="元";ss+="\n";
    ss+=ans.pSet_Meal[1]->getwindow();
    str += QString::fromStdString(ss.c_str());
    new_rec->ui->taolabel_2->setText(str);

    ss=ans.pSet_Meal[2]->getname();
    str = QString::fromStdString(ss.c_str());
    //qDebug()<<str;
    new_rec->ui->taoButton_3->setText(str);
    ss=ans.pSet_Meal[2]->getcanteen();ss+="\n";ss+="价格:";
    str = QString::fromStdString(ss.c_str());
    str+= QString::number(ans.pSet_Meal[2]->getprice(), 'f', 2);
    ss="元";ss+="\n";
    ss+=ans.pSet_Meal[2]->getwindow();
    str += QString::fromStdString(ss.c_str());
    new_rec->ui->taolabel_3->setText(str);
}

void MainWindow::on_ranrecbutton_clicked()
{
    new_rec = new recommend;
    new_rec->show();
    int thisshitang=0;
    if(ui->checkBox_1->isChecked())
        thisshitang+=1;
    if(ui->checkBox_2->isChecked())
        thisshitang+=2;
    if(ui->checkBox_3->isChecked())
        thisshitang+=4;
    if(ui->checkBox_4->isChecked())
        thisshitang+=8;
    if(ui->checkBox_5->isChecked())
        thisshitang+=16;
    if(ui->checkBox_6->isChecked())
        thisshitang+=32;
    Dish_Package selected, ans;
        string t="Set_Meal";
        string s="Veg_Diet";
        string h="Meat_Diet";
        string b="VegnMeat_mix";
        //add_reset_file(temp);
        //cout << "TEST: output pack:\n";
        read_all_file(selected,thisshitang );
        //output_DishPack(selected);
        //CalculateWeight_forPack(selected,zhuaim);
        Calrandom_weight_forPack(selected);//随机推荐
        ans = Weighted_random(selected);//智能推荐
        //output_DishPack(ans);
    string ss;
    QString str;
    ss=ans.pVeg_Diet[0]->getname();
    str = QString::fromStdString(ss.c_str());
    //qDebug()<<str;
    new_rec->ui->suButton_1->setText(str);
    ss=ans.pVeg_Diet[0]->getcanteen();ss+="\n";ss+="价格:";
    str = QString::fromStdString(ss.c_str());
    str+= QString::number(ans.pVeg_Diet[0]->getprice(), 'f', 2);
    ss="元";ss+="\n";
    ss+=ans.pVeg_Diet[0]->getwindow();
    str += QString::fromStdString(ss.c_str());
    new_rec->ui->sulabel_1->setText(str);

    ss=ans.pVeg_Diet[1]->getname();
    str = QString::fromStdString(ss.c_str());
    //qDebug()<<str;
    new_rec->ui->suButton_2->setText(str);
    ss=ans.pVeg_Diet[1]->getcanteen();ss+="\n";ss+="价格:";
    str = QString::fromStdString(ss.c_str());
    str+= QString::number(ans.pVeg_Diet[1]->getprice(), 'f', 2);
    ss="元";ss+="\n";
    ss+=ans.pVeg_Diet[1]->getwindow();
    str += QString::fromStdString(ss.c_str());
    new_rec->ui->sulabel_2->setText(str);

    ss=ans.pVeg_Diet[2]->getname();
    str = QString::fromStdString(ss.c_str());
    //qDebug()<<str;
    new_rec->ui->suButton_3->setText(str);
    ss=ans.pVeg_Diet[2]->getcanteen();ss+="\n";ss+="价格:";
    str = QString::fromStdString(ss.c_str());
    str+= QString::number(ans.pVeg_Diet[2]->getprice(), 'f', 2);
    ss="元";ss+="\n";
    ss+=ans.pVeg_Diet[2]->getwindow();
    str += QString::fromStdString(ss.c_str());
    new_rec->ui->sulabel_3->setText(str);

    ss=ans.pMeat_Diet[0]->getname();
    str = QString::fromStdString(ss.c_str());
    //qDebug()<<str;
    new_rec->ui->hunButton_1->setText(str);
    ss=ans.pMeat_Diet[0]->getcanteen();ss+="\n";ss+="价格:";
    str = QString::fromStdString(ss.c_str());
    str+= QString::number(ans.pMeat_Diet[0]->getprice(), 'f', 2);
    ss="元";ss+="\n";
    ss+=ans.pMeat_Diet[0]->getwindow();
    str += QString::fromStdString(ss.c_str());
    new_rec->ui->hunlabel_1->setText(str);

    ss=ans.pMeat_Diet[1]->getname();
    str = QString::fromStdString(ss.c_str());
    //qDebug()<<str;
    new_rec->ui->hunButton_2->setText(str);
    ss=ans.pMeat_Diet[1]->getcanteen();ss+="\n";ss+="价格:";
    str = QString::fromStdString(ss.c_str());
    str+= QString::number(ans.pMeat_Diet[1]->getprice(), 'f', 2);
    ss="元";ss+="\n";
    ss+=ans.pMeat_Diet[1]->getwindow();
    str += QString::fromStdString(ss.c_str());
    new_rec->ui->hunlabel_2->setText(str);

    ss=ans.pMeat_Diet[2]->getname();
    str = QString::fromStdString(ss.c_str());
    //qDebug()<<str;
    new_rec->ui->hunButton_3->setText(str);
    ss=ans.pMeat_Diet[2]->getcanteen();ss+="\n";ss+="价格:";
    str = QString::fromStdString(ss.c_str());
    str+= QString::number(ans.pMeat_Diet[2]->getprice(), 'f', 2);
    ss="元";ss+="\n";
    ss+=ans.pMeat_Diet[2]->getwindow();
    str += QString::fromStdString(ss.c_str());
    new_rec->ui->hunlabel_3->setText(str);

    ss=ans.pVegnMeat_mix[0]->getname();
    str = QString::fromStdString(ss.c_str());
    //qDebug()<<str;
    new_rec->ui->hunsuButton_1->setText(str);
    ss=ans.pVegnMeat_mix[0]->getcanteen();ss+="\n";ss+="价格:";
    str = QString::fromStdString(ss.c_str());
    str+= QString::number(ans.pVegnMeat_mix[0]->getprice(), 'f', 2);
    ss="元";ss+="\n";
    ss+=ans.pVegnMeat_mix[0]->getwindow();
    str += QString::fromStdString(ss.c_str());
    new_rec->ui->hunsulabel_1->setText(str);

    ss=ans.pVegnMeat_mix[1]->getname();
    str = QString::fromStdString(ss.c_str());
    //qDebug()<<str;
    new_rec->ui->hunsuButton_2->setText(str);
    ss=ans.pVegnMeat_mix[1]->getcanteen();ss+="\n";ss+="价格:";
    str = QString::fromStdString(ss.c_str());
    str+= QString::number(ans.pVegnMeat_mix[1]->getprice(), 'f', 2);
    ss="元";ss+="\n";
    ss+=ans.pVegnMeat_mix[1]->getwindow();
    str += QString::fromStdString(ss.c_str());
    new_rec->ui->hunsulabel_2->setText(str);

    ss=ans.pVegnMeat_mix[2]->getname();
    str = QString::fromStdString(ss.c_str());
    //qDebug()<<str;
    new_rec->ui->hunsuButton_3->setText(str);
    ss=ans.pVegnMeat_mix[2]->getcanteen();ss+="\n";ss+="价格:";
    str = QString::fromStdString(ss.c_str());
    str+= QString::number(ans.pVegnMeat_mix[2]->getprice(), 'f', 2);
    ss="元";ss+="\n";
    ss+=ans.pVegnMeat_mix[2]->getwindow();
    str += QString::fromStdString(ss.c_str());
    new_rec->ui->hunsulabel_3->setText(str);

    ss=ans.pSet_Meal[0]->getname();
    str = QString::fromStdString(ss.c_str());
    //qDebug()<<str;
    new_rec->ui->taoButton_1->setText(str);
    ss=ans.pSet_Meal[0]->getcanteen();ss+="\n";ss+="价格:";
    str = QString::fromStdString(ss.c_str());
    str+= QString::number(ans.pSet_Meal[0]->getprice(), 'f', 2);
    ss="元";ss+="\n";
    ss+=ans.pSet_Meal[0]->getwindow();
    str += QString::fromStdString(ss.c_str());
    new_rec->ui->taolabel_1->setText(str);

    ss=ans.pSet_Meal[1]->getname();
    str = QString::fromStdString(ss.c_str());
    //qDebug()<<str;
    new_rec->ui->taoButton_2->setText(str);
    ss=ans.pSet_Meal[1]->getcanteen();ss+="\n";ss+="价格:";
    str = QString::fromStdString(ss.c_str());
    str+= QString::number(ans.pSet_Meal[1]->getprice(), 'f', 2);
    ss="元";ss+="\n";
    ss+=ans.pSet_Meal[1]->getwindow();
    str += QString::fromStdString(ss.c_str());
    new_rec->ui->taolabel_2->setText(str);

    ss=ans.pSet_Meal[2]->getname();
    str = QString::fromStdString(ss.c_str());
    //qDebug()<<str;
    new_rec->ui->taoButton_3->setText(str);
    ss=ans.pSet_Meal[2]->getcanteen();ss+="\n";ss+="价格:";
    str = QString::fromStdString(ss.c_str());
    str+= QString::number(ans.pSet_Meal[2]->getprice(), 'f', 2);
    ss="元";ss+="\n";
    ss+=ans.pSet_Meal[2]->getwindow();
    str += QString::fromStdString(ss.c_str());
    new_rec->ui->taolabel_3->setText(str);
}


