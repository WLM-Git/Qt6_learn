#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::resizeEvent(QResizeEvent *event)
{
    QSize sz = ui->plainTextEdit->size();

    ui->plainTextEdit->move(5,5);
    ui->label->move(5,sz.height()+10);
    ui->plainTextEdit->resize(this->width()-10,sz.height());
    ui->label->resize(this->width()-10,this->height()-sz.height()-20);

    event->accept();
}

void Widget::dragEnterEvent(QDragEnterEvent *event)
{

}

void Widget::dropEvent(QDropEvent *event)
{

}
