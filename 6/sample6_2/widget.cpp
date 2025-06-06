#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->lab, SIGNAL(doubleClicked()), this,SLOT(do_doubleClick()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::mouseDoubleClickEvent(QMouseEvent *event)
{
    //双击窗口时的响应
    ui->lab->setText("窗口被双击了");
    ui->lab->adjustSize();
}

void Widget::do_doubleClick()
{
    //双击标签时的响应
    ui->lab->setText("标签被双击了，信号的槽函数的响应");
    ui->lab->adjustSize();
}
