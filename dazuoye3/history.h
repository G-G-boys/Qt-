#ifndef HISTORY_H
#define HISTORY_H

#include <QWidget>
#include "assess.h"

namespace Ui {
class history;
}

class history : public QWidget
{
    Q_OBJECT

public:
    explicit history(QWidget *parent = 0);
    ~history();
    assess *new_ass;

private slots:
    void on_historyButton_1_clicked();

    void on_historyButton_2_clicked();

    void on_historyButton_3_clicked();

    void on_historyButton_4_clicked();

private:
    Ui::history *ui;
};

#endif // HISTORY_H
