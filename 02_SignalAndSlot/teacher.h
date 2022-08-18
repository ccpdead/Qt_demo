#ifndef TEACHER_H
#define TEACHER_H

#include <QObject>

class teacher : public QObject//所有的槽与信号都需要继承于QObject
{
    Q_OBJECT
public:
    explicit teacher(QObject *parent = nullptr);

signals:
    //自定义信号写在signals下面
    //信号返回类型为void
    //信号只需声明，不用实现
    //信号可以有参数，可以重载
    void hungry();
    void hungry(QString foodName);

public slots:
    //自定义槽函数。

};

#endif // TEACHER_H
