#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //将“定时器”和“定时器精度”分组框在垂直方向设置为固定尺寸
    ui->groupBox->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    ui->groupBox_3->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);

    m_timer = new QTimer(this);             //创建定时器
    m_counter = new QElapsedTimer();        //创建计时器
    m_timer->stop();                        //停止定时器
    m_timer->setTimerType(Qt::CoarseTimer); //设置定时器精度
    ui->radioCoarse->setChecked(true);
    connect(m_timer,SIGNAL(timeout()),this,SLOT(do_timer_timeout()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::do_timer_timeout()
{//与定时器的timeout()信号关联的槽函数
    //使系统"嘀"一声
    QApplication::beep();
    //获取当前系统时间
    QTime curTime = QTime::currentTime();
    //LCD显示“小时”
    ui->LCDHour->display(curTime.hour());
    //LCD显示“分钟”
    ui->LCDMin->display(curTime.minute());
    //LCD显示“秒”
    ui->LCDSec->display(curTime.second());

    if(m_timer->isSingleShot())
    {
        int tmMsec = m_counter->elapsed();
        QString str = QString("流逝的时间：%1毫秒").arg(tmMsec);
        ui->labElapsedTime->setText(str);
        ui->btnStart->setEnabled(true);
        ui->btnOneShot->setEnabled(true);
        ui->btnStop->setEnabled(false);
    }
}

void Widget::do_time_shot()
{//与动态创建的单次定时器的timeout()信号相关联的槽函数
    QApplication::beep();
    //流逝的时间
    int tmMsec = m_counter->elapsed();
    QString str = QString("流逝的时间：%1毫秒").arg(tmMsec);
    ui->labElapsedTime->setText(str);
    ui->btnOneShot->setEnabled(true);
}

void Widget::on_btnStart_clicked()
{//"开始"按钮
    //设置定时器的周期
    m_timer->setInterval(ui->spinBoxIntv->value());
    //设置定时器是否循环
    if(ui->radioContiue->isChecked())
    {
        m_timer->setSingleShot(false);
    }
    else
    {
        m_timer->setSingleShot(true);
    }
    //设置定时器精度
    if(ui->radioPrecise->isChecked())
    {
        m_timer->setTimerType(Qt::PreciseTimer);
    }
    else if(ui->radioCoarse->isChecked())
    {
        m_timer->setTimerType(Qt::CoarseTimer);
    }
    else
    {
        m_timer->setTimerType(Qt::VeryCoarseTimer);
    }

    //启动定时器
    m_timer->start();
    //启动计时器
    m_counter->start();
    ui->btnStart->setEnabled(false);
    ui->btnOneShot->setEnabled(false);
    ui->btnStop->setEnabled(true);
}


void Widget::on_btnStop_clicked()
{//“停止按钮”
    m_timer->stop();
    //从启动计时器开始到调用这个elspsed()函数经过的时间
    int tmMsec = m_counter->elapsed();
    int ms = tmMsec % 1000;
    int sec = tmMsec / 1000;
    QString str = QString("流逝的时间：%1秒，%2毫秒").arg(sec).arg(ms,3,10,QChar('0'));
    ui->labElapsedTime->setText(str);
    ui->btnStart->setEnabled(true);
    ui->btnOneShot->setEnabled(true);
    ui->btnStop->setEnabled(false);
}


void Widget::on_btnOneShot_clicked()
{//"动态创建单次定时器"按钮
    //定时周期
    int intv = ui->spinBoxIntv->value();
    QTimer::singleShot(intv, Qt::PreciseTimer, this, &Widget::do_time_shot);
    m_counter->start();
    ui->btnOneShot->setEnabled(false);
}

