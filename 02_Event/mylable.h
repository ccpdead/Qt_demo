#ifndef MYLABLE_H
#define MYLABLE_H

#include<QLabel>

class MyLable : public QLabel
{
    Q_OBJECT
public:
    explicit MyLable(QWidget *parent = nullptr);//防止隐式转换。


    //捕获事件
    //鼠标进入
    void enterEvent(QEnterEvent*);
    //鼠标离开
    void leaveEvent(QEvent*);
    //鼠标按下
    void mousePressEvent(QMouseEvent* ev);
    //鼠标释放
    void mouseReleaseEvent(QMouseEvent* ev);
    //鼠标移动
    void mouseMoveEvent(QMouseEvent* ev);
    //事件分发Event事件
    //这里重写了event事件处理函数，所以当函数中不做处理时，没有鼠标被触发
    bool event(QEvent* e);

    //signals:-----》信号

};

#endif // MYLABLE_H
