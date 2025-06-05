#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QMessageBox>
#include <QCloseEvent>

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

void Widget::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    if(event->button() == Qt::LeftButton)
    {
        QPoint pt = event->pos();
        QPointF relaPt = event->position();
        QPointF winPt = event->scenePosition();
        QPointF globPt = event->globalPosition();
        QString str = QString::asprintf("pos()=(%d,%d)",pt.x(),pt.y());
        str = str + QString::asprintf("\nscenrPosition()=(%.0f,%.0f)",relaPt.x(),relaPt.y());
        str = str + QString::asprintf("\nposition()=(%.0f,%.0f)",winPt.x(),winPt.y());
        str = str + QString::asprintf("\nglobalPosition()=(%.0f,%.0f)",globPt.x(),globPt.y());
        ui->labMove->setText(str);
        ui->labMove->adjustSize();
        ui->labMove->move(event->pos());
    }
    QWidget::mousePressEvent(event);
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    Q_UNUSED(event);
    QPoint pt = ui->btnMove->pos();
    if((event->key()==Qt::Key_A)||(event->key()==Qt::Key_Left))
    {
        ui->btnMove->move(pt.x()-20,pt.y());
    }
    else if((event->key()==Qt::Key_D)||(event->key()==Qt::Key_Right))
    {
        ui->btnMove->move(pt.x()+20,pt.y());
    }
    else if((event->key()==Qt::Key_W)||(event->key()==Qt::Key_Up))
    {
        ui->btnMove->move(pt.x(),pt.y()-20);
    }
    else if((event->key()==Qt::Key_S)||(event->key()==Qt::Key_Down))
    {
        ui->btnMove->move(pt.x(),pt.y()+20);
    }
    //设置此事件在此已处理，避免父组件处理
    event->accept();
}

void Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.drawPixmap(0,0,width(),height(),
                       QPixmap(":/pics/images/background.jpg"));
}

void Widget::closeEvent(QCloseEvent *event)
{
    Q_UNUSED(event);
    QString dlgTitle = "消息框";
    QString strInfo = "确定要退出吗";
    QMessageBox::StandardButton result = QMessageBox::question(this, dlgTitle, strInfo,
                                                               QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel);
    if(result == QMessageBox::Yes)
    {
        event->accept();
    }
    else
    {
        event->ignore();
    }
}

void Widget::showEvent(QShowEvent *event)
{
    Q_UNUSED(event);
    qDebug("showEvent函数被触发");
}

void Widget::hideEvent(QHideEvent *event)
{
    Q_UNUSED(event);
    qDebug("hideEvent函数被触发");
}
