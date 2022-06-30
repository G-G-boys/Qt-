#ifndef ADDDISHES_H
#define ADDDISHES_H

#include <QWidget>

namespace Ui {
class adddishes;
}

class adddishes : public QWidget
{
    Q_OBJECT

public:
    explicit adddishes(QWidget *parent = 0);
    ~adddishes();

private slots:
    void on_pushButton_clicked();

private:
    Ui::adddishes *ui;
};

#endif // ADDDISHES_H
