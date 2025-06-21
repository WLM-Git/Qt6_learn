#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QAbstractItemView>
#include <QGroupBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT
private:
    QAbstractItemView *m_itemView = nullptr;            //当前设置属性的组件
    void refreshToUI(QGroupBox *curGroupBox);                                 //将组件的属性显示到界面上
    int getDropActionIndex(Qt::DropAction actionType);
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_radio_Source_clicked();

    void on_radioButton_clicked();

    void on_radio_Tree_clicked();

    void on_radio_Table_clicked();

    void on_chkBox_AcceptDrops_clicked(bool checked);

    void on_chkBox_DragEnabled_clicked(bool checked);

    void on_combo_Mode_currentIndexChanged(int index);

    void on_combo_DefaultActionIndex_currentIndexChanged(int index);

private:
    Ui::Widget *ui;
    Qt::DropAction getDropActionType(int index);

    // QObject interface
public:
    bool eventFilter(QObject *watched, QEvent *event);
};
#endif // WIDGET_H
