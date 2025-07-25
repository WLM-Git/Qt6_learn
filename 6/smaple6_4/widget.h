#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;

    // QWidget interface
protected:
    virtual void resizeEvent(QResizeEvent *event) override;                     //窗口大小改变时触发的事件处理函数
    virtual void dragEnterEvent(QDragEnterEvent *event) override;               //拖动文件进入窗口时触发的事件处理函数
    virtual void dropEvent(QDropEvent *event) override;                         //拖动文件在窗口放置时触发的事件处理函数
};
#endif // WIDGET_H
