#ifndef RECOMMEND_H
#define RECOMMEND_H

#include <QWidget>

namespace Ui {
class recommend;
}

class recommend : public QWidget
{
    Q_OBJECT

public:
    explicit recommend(QWidget *parent = 0);
    ~recommend();
    friend class MainWindow;
    friend class set;

private slots:
    void on_suButton_1_clicked();

    void on_suButton_2_clicked();

    void on_suButton_3_clicked();

    void on_hunsuButton_1_clicked();

    void on_hunsuButton_2_clicked();

    void on_hunsuButton_3_clicked();

    void on_hunButton_1_clicked();

    void on_hunButton_2_clicked();

    void on_hunButton_3_clicked();

    void on_taoButton_1_clicked();

    void on_taoButton_2_clicked();

    void on_taoButton_3_clicked();

    void on_pushButton_clicked();

private:
    Ui::recommend *ui;

    void push_choose();
};

#endif // RECOMMEND_H
