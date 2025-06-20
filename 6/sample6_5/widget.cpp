#include "widget.h"
#include "ui_widget.h"

void Widget::refreshToUI(QGroupBox *curGroupBox)
{
    //组件属性显示到界面上
    ui->chkBox_AcceptDrops->setChecked(m_itemView->acceptDrops());      //acceptDrops复选框
    ui->chkBox_DragEnabled->setChecked(m_itemView->dragEnabled());      //dragEnabled复选框
    ui->combo_Mode->setCurrentIndex((int)m_itemView->dragDropMode());   //dragDropMode下拉复选框
    int index = getDropActionIndex(m_itemView->defaultDropAction());
    ui->combo_DefaultActionIndex->setCurrentIndex(index);

    QFont font = ui->groupBox_1->font();
    font.setBold(false);
    ui->groupBox_1->setFont(font);
    ui->groupBox->setFont(font);
    ui->groupBox_2->setFont(font);
    ui->groupBox_3->setFont(font);
    font.setBold(true);
    curGroupBox->setFont(font);
}

int Widget::getDropActionIndex(Qt::DropAction actionType)
{
    //根据Qt::DropAction的枚举值，获取下拉列表框中的索引
    switch (actionType)
    {
    case Qt::CopyAction:
        return 0;
    case Qt::MoveAction:
        return 1;
    case Qt::LinkAction:
        return 2;
    case Qt::IgnoreAction:
        return 3;
    default:
        return 0;
    }
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //安装事件过滤器
    ui->listSource->installEventFilter(this);
    ui->listWidget->installEventFilter(this);
    ui->treeWidget->installEventFilter(this);
    ui->tableWidget->installEventFilter(this);

    //设置4个项数据组件的拖放操作相关属性
    ui->listSource->setAcceptDrops(true);
    ui->listSource->setDragDropMode(QAbstractItemView::DragDrop);
    ui->listSource->setDragEnabled(true);
    ui->listSource->setDefaultDropAction(Qt::CopyAction);

    ui->listWidget->setAcceptDrops(true);
    ui->listWidget->setDragDropMode(QAbstractItemView::DragDrop);
    ui->listWidget->setDragEnabled(true);
    ui->listWidget->setDefaultDropAction(Qt::CopyAction);

    ui->treeWidget->setAcceptDrops(true);
    ui->treeWidget->setDragDropMode(QAbstractItemView::DragDrop);
    ui->treeWidget->setDragEnabled(true);
    ui->treeWidget->setDefaultDropAction(Qt::CopyAction);

    ui->tableWidget->setAcceptDrops(true);
    ui->tableWidget->setDragDropMode(QAbstractItemView::DragDrop);
    ui->tableWidget->setDragEnabled(true);
    ui->tableWidget->setDefaultDropAction(Qt::MoveAction);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_radio_Source_clicked()
{//listSource单选按钮
    m_itemView = ui->listSource;            //当前设置属性的组件
    refreshToUI(ui->groupBox_1);            //属性刷新显示到界面上
}


void Widget::on_radioButton_clicked()
{
    m_itemView = ui->listWidget;
    refreshToUI(ui->groupBox);
}


void Widget::on_radio_Tree_clicked()
{
    m_itemView = ui->treeWidget;
    refreshToUI(ui->groupBox_2);
}


void Widget::on_radio_Table_clicked()
{
    m_itemView = ui->tableWidget;
    refreshToUI(ui->groupBox_3);
}


void Widget::on_chkBox_AcceptDrops_clicked(bool checked)
{
    //acceptDrop复选框
    m_itemView->setAcceptDrops(checked);
}


void Widget::on_chkBox_DragEnabled_clicked(bool checked)
{
    //dragEnable复选框
    m_itemView->setDragEnabled(checked);
}


void Widget::on_combo_Mode_currentIndexChanged(int index)
{
    //下拉框列表
    QAbstractItemView::DragDropMode mode = (QAbstractItemView::DragDropMode) index;
    m_itemView->setDragDropMode(mode);
}


void Widget::on_combo_DefaultActionIndex_currentIndexChanged(int index)
{
    //先将下拉列表里的index转化为action的类型
    Qt::DropAction actionType = getDropActionType(index);
    //再将得到的action类型赋予m_itemView的action
    m_itemView->setDefaultDropAction(actionType);
}

Qt::DropAction Widget::getDropActionType(int index)
{
    switch (index)
    {
    case 0:
        return Qt::CopyAction;
    case 1:
        return Qt::MoveAction;
    case 2:
        return Qt::LinkAction;
    case 3:
        return Qt::IgnoreAction;
    default:
        return Qt::CopyAction;
    }
}

