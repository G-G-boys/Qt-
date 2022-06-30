#ifndef ASSESS_H
#define ASSESS_H

#include <QWidget>

namespace Ui {
class assess;
}

class assess : public QWidget
{
    Q_OBJECT

public:
    explicit assess(QWidget *parent = 0);
    ~assess();

private slots:
    void on_pushButton_clicked();

private:
    Ui::assess *ui;
};

#endif // ASSESS_H
