#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include<QElapsedTimer>
#include <QTime>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

private:
    QTimer *m_timer;                    //定时器
    QElapsedTimer *m_counter;          //计时器
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void do_timer_timeout();            //自定义槽函数，与定时器timeout()信号关联
    void do_time_shot();                //与单次定时器关联的槽函数

    void on_btnStart_clicked();

    void on_btnStop_clicked();

    void on_btnOneShot_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
