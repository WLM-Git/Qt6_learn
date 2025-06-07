#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->labHover->installEventFilter(this);             //安装事件过滤器
    ui->labDBClick->installEventFilter(this);           //安装事件过滤器
}

Widget::~Widget()
{
    delete ui;
}

bool Widget::eventFilter(QObject *watched, QEvent *event)
{
    //如果监视的是labHover的事件
    if(watched == ui->labHover)
    {
        if(event->type() == QEvent::Enter)
        {
            ui->labHover->setStyleSheet("background-color: rgb(170, 255, 255);");
        }
        else if (event->type() == QEvent::Leave)
        {
            ui->labHover->setStyleSheet("");
            ui->labHover->setText("爱我，别走，点我");
        }
        else if (event->type() == QEvent::MouseButtonPress)
        {
            ui->labHover->setText("你点我了");
        }
        else if (event->type() == QEvent::MouseButtonRelease)
        {
            ui->labHover->setText("你放手了");
        }
    }
    //如果监视的是labDBClick的事件
    if (watched == ui->labDBClick)
    {
        if(event->type() == QEvent::Enter)
        {
            ui->labDBClick->setStyleSheet("background-color: rgb(85, 255, 127);");
        }
        else if (event->type() == QEvent::Leave)
        {
            ui->labDBClick->setStyleSheet("");
            ui->labDBClick->setText("我能点两下");
        }
        else if (event->type() == QEvent::MouseButtonDblClick)
        {
            ui->labDBClick->setText("啊，被双击了");
        }
    }
    return QWidget::eventFilter(watched,event);
}
