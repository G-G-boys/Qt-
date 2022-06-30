#ifndef SET_H
#define SET_H

#include <QWidget>
#include "recommend.h"
#include "ui_recommend.h"

namespace Ui {
class set;
}

class set : public QWidget
{
    Q_OBJECT

public:
    explicit set(QWidget *parent = 0);
    ~set();
    recommend *new_recc;

private slots:
    void on_intrecbutton_clicked();

private:
    Ui::set *ui;
};

#endif // SET_H
