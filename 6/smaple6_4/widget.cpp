#include "widget.h"
#include "ui_widget.h"
#include <QMimeData>
#include <QFileInfo>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->label->setScaledContents(true);                     //图片适应组件大小
    this->setAcceptDrops(true);                             //设置此窗口可以接受放置
    ui->label->setAcceptDrops(false);                       //不接受放置操作，由窗口去处理
    ui->plainTextEdit->setAcceptDrops(false);               //不接受放置操作，由窗口去处理
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
    //显示MIME信息
    ui->plainTextEdit->clear();
    ui->plainTextEdit->appendPlainText("dragEnterEvent 事件 mimeData()->formats()");
    for (int i = 0; i < event->mimeData()->formats().size(); i++)
    {
        ui->plainTextEdit->appendPlainText(event->mimeData()->formats().at(i));
    }

    ui->plainTextEdit->appendPlainText("\n dragEnterEvent 事件 mimeData()->urls()");
    for (int i = 0; i < event->mimeData()->urls().size(); i++)
    {
        QUrl url = event->mimeData()->urls().at(i);
        ui->plainTextEdit->appendPlainText(url.path());
    }

    if (event->mimeData()->hasUrls())
    {
        QString filename = event->mimeData()->urls().at(0).fileName();          //获取文件名
        QFileInfo fileInfo(filename);                                           //获取文件信息
        QString ext = fileInfo.suffix().toUpper();                              //获取文件后缀
        if (ext == "JPG")
            event->acceptProposedAction();                                      //接受拖动事件
        else
            event->ignore();                                                    //忽略事件
    }
    else
    {
        event->ignore();
    }
}

void Widget::dropEvent(QDropEvent *event)
{
    QString filename = event->mimeData()->urls().at(0).path();      //完整文件名
    qDebug() <<"完整文件名为: "<<filename;
    //在macos下使用完整文件名即可
    //filename = filename.right(filename.length() - 1);               //去掉最左边的"/"
    QPixmap pixmap(filename);
    ui->label->setPixmap(pixmap);
    event->accept();
}
