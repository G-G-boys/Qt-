#include "history.h"
#include "ui_history.h"

history::history(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::history)
{
    setAttribute(Qt::WA_QuitOnClose,false);
    ui->setupUi(this);
}

history::~history()
{
    delete ui;
}

void history::on_historyButton_1_clicked()
{
    new_ass = new assess;
    new_ass->show();
    this->close();
}

void history::on_historyButton_2_clicked()
{
    new_ass = new assess;
    new_ass->show();
    this->close();
}

void history::on_historyButton_3_clicked()
{
    new_ass = new assess;
    new_ass->show();
    this->close();
}

void history::on_historyButton_4_clicked()
{
    new_ass = new assess;
    new_ass->show();
    this->close();
}
