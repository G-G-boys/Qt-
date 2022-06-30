#ifndef DISH_H
#define DISH_H

#include <QWidget>

namespace Ui {
class dish;
}

class dish : public QWidget
{
    Q_OBJECT

public:
    explicit dish(QWidget *parent = 0);
    ~dish();

private:
    Ui::dish *ui;
};

#endif // DISH_H
