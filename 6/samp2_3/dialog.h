#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QCheckBox>
#include <QRadioButton>
#include <QPushButton>
#include <QPlainTextEdit>


class Dialog : public QDialog
{
    Q_OBJECT

private:
    //复选框
    QCheckBox *chkBoxUnder;
    QCheckBox *chkBoxItalic;
    QCheckBox *chkBoxBold;

    //三个单选按钮
    QRadioButton *radioBlack;
    QRadioButton *radioRed;
    QRadioButton *radioBlue;

    //三个按钮
    QPushButton *btnOK;
    QPushButton *btnCancel;
    QPushButton *btnClose;

    //一个文本框
    QPlainTextEdit *txtEdit;

    //UI创建与初始化函数
    void iniUI();
    //初始化信号与槽的连接
    void iniSignalSlots();

private slots:
    //三个复选框的槽函数
    void do_chkBoxUnder(bool checked);
    void do_chkBoxItalic(bool checked);
    void do_chkBoxBold(bool checked);

    //设置文字颜色槽函数
    void do_setFontColor();

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
};
#endif // DIALOG_H
