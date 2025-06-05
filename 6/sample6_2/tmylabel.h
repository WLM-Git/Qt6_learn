#ifndef TMYLABEL_H
#define TMYLABEL_H

#include <QLabel>

class TMyLabel : public QLabel
{
    Q_OBJECT
public:
    TMyLabel(QWidget *parent = nullptr);
    bool event(QEvent *e);                      //重新实现event()函数
};

#endif // TMYLABEL_H
