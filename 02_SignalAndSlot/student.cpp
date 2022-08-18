#include "student.h"
#include<QDebug>

student::student(QObject *parent)
    : QObject{parent}//参数化列表
{

}

//槽函数的实现
void student::treat()
{
    qDebug()<<"请老师吃饭";
}
void student::treat(QString foodName)
{
    //这里通过toUtf8和data方法，将QString 转化为 char*类型
    qDebug()<<"请老师吃饭"<<" 老师吃"<<foodName.toUtf8().data();
}
