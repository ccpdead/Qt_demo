#ifndef MYBOTTON_H
#define MYBOTTON_H

#include <QWidget>
#include <QPushButton>

class mybotton : public QPushButton
{
    Q_OBJECT
public:
    explicit mybotton(QWidget *parent = nullptr);//防止隐式转换

    ~mybotton();//析构函数

signals:

};

#endif // MYBOTTON_H
