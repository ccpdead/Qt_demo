#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include"teacher.h"
#include"student.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    //下课了，触发信号
    void classIsOver();

    teacher *zt;
    student *st;
};
#endif // WIDGET_H
