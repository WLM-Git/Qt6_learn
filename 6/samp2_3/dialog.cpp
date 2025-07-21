#include "dialog.h"
#include <QFont>
#include <QHBoxLayout>
#include <QVBoxLayout>

void Dialog::iniUI()
{
    //创建Underline、Italic、Bold 3个复选框，并水平布局
    chkBoxUnder = new QCheckBox("Underline");
    chkBoxItalic = new QCheckBox("Italic");
    chkBoxBold = new QCheckBox("Bold");
    QHBoxLayout *HLay1 = new QHBoxLayout();
    HLay1->addWidget(chkBoxUnder);
    HLay1->addWidget(chkBoxItalic);
    HLay1->addWidget(chkBoxBold);

    //创建Black、Red、Blue 3个单选按钮，并水平布局
    radioBlack = new QRadioButton("Black");
    radioRed = new QRadioButton("Red");
    radioBlue = new QRadioButton("Blue");
    QHBoxLayout *HLay2 = new QHBoxLayout();
    HLay2->addWidget(radioBlack);
    HLay2->addWidget(radioRed);
    HLay2->addWidget(radioBlue);

    //创建“确认”、“取消”、“退出” 3个按钮，并水平布局
    btnOK = new QPushButton("确定");
    btnCancel = new QPushButton("取消");
    btnClose = new QPushButton("退出");
    QHBoxLayout *HLay3 = new QHBoxLayout();
    HLay3->addWidget(btnOK);
    HLay3->addWidget(btnCancel);
    HLay3->addWidget(btnClose);

    //创建文本框，并设置初始字体
    txtEdit = new QPlainTextEdit;
    txtEdit->setPlainText("Hello world\n 手工创建");
    //获取这个文本框的字体
    QFont font = txtEdit->font();
    //修改字体大小为20
    font.setPointSize(20);
    //设置这个文本框的字体属性
    txtEdit->setFont(font);

    //创建垂直布局，并设置为主布局
    QVBoxLayout *VLay = new QVBoxLayout(this);
    //添加txtEdit
    VLay->addLayout(HLay1);
    //添加按键组
    VLay->addLayout(HLay2);
    //添加文本框
    VLay->addWidget(txtEdit);
    //设置为窗口的主布局
    VLay->addLayout(HLay3);

}

void Dialog::iniSignalSlots()
{
    //3个设置颜色的单选按钮
    connect(radioBlue, SIGNAL(clicked()), this, SLOT(do_setFontColor()));
    connect(radioRed, SIGNAL(clicked()), this, SLOT(do_setFontColor()));
    connect(radioBlack, SIGNAL(clicked()), this, SLOT(do_setFontColor()));
    //3个设置字体的复选框
    connect(chkBoxUnder, SIGNAL(clicked(bool)), this, SLOT(do_chkBoxUnder(bool)));
    connect(chkBoxItalic, SIGNAL(clicked(bool)), this, SLOT(do_chkBoxItalic(bool)));
    connect(chkBoxBold, SIGNAL(clicked(bool)), this, SLOT(do_chkBoxBold(bool)));
    //3个按钮与窗口的槽函数关联
    connect(btnOK, SIGNAL(clicked()), this, SLOT(accept()));
    connect(btnCancel, SIGNAL(clicked()), this, SLOT(reject()));
    connect(btnClose, SIGNAL(clicked()), this, SLOT(close()));
}

void Dialog::do_chkBoxUnder(bool checked)
{
    QFont font = txtEdit->font();
    font.setUnderline(checked);
    txtEdit->setFont(font);
}

void Dialog::do_chkBoxItalic(bool checked)
{
    QFont font = txtEdit->font();
    font.setItalic(checked);
    txtEdit->setFont(font);
}

void Dialog::do_chkBoxBold(bool checked)
{
    QFont font = txtEdit->font();
    font.setBold(checked);
    txtEdit->setFont(font);
}

void Dialog::do_setFontColor()
{
    QPalette plet = txtEdit->palette();
    if (radioBlue->isChecked())
    {
        plet.setColor(QPalette::Text,Qt::blue);
    }
    else if (radioBlack->isChecked())
    {
        plet.setColor(QPalette::Text,Qt::black);
    }
    else if (radioRed->isChecked())
    {
        plet.setColor(QPalette::Text,Qt::red);
    }
    else
    {
        plet.setColor(QPalette::Text,Qt::black);
    }

    txtEdit->setPalette(plet);

}

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    //界面创建与布局
    iniUI();
    //信号槽的关联
    iniSignalSlots();
    //设置窗口标题
    setWindowTitle("手工创建UI");
}

Dialog::~Dialog() {}
