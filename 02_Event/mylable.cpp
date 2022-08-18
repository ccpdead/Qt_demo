#include "mylable.h"
#include<QDebug>
#include<QMouseEvent>


MyLable::MyLable(QWidget *parent) : QLabel(parent)
{

    //设置鼠标追踪，保证鼠标进入lable就开始检测移动
//    this->setMouseTracking(true);
}

//鼠标进入
void MyLable::enterEvent(QEnterEvent*)
{
    //qDebug()<<"鼠标进入了";
}
//鼠标离开
void MyLable::leaveEvent(QEvent*)
{
    //qDebug()<<"鼠标离开了";
}


//鼠标按下
void MyLable::mousePressEvent(QMouseEvent* ev)
{
    //qDebug()<<"鼠标按下了";
    //若使用等号判断，则在移动过程中无法进行判断的切换
    //if(ev->buttons() & Qt::LeftButton)//通过位操作符判断当前的键位值类进行判断是否切换建
//    if(ev->button() == Qt::LeftButton)
//    {
//        QString str=QString("鼠标按下了x = %1,y = %2").arg(ev->x()).arg(ev->y());
//        qDebug()<<str;
//    }

}
//鼠标释放
void MyLable::mouseReleaseEvent(QMouseEvent* ev)
{
    //qDebug()<<"鼠标释放了";
    if(ev->button() == Qt::LeftButton)
    {
        QString str= QString("鼠标释放了 x = %1, y = %2").arg(ev->x()).arg(ev->y());
        qDebug()<<str;
    }
}
//鼠标移动
void MyLable::mouseMoveEvent(QMouseEvent* ev)
{
    //qDebug()<<"鼠标移动了";
    QString str = QString("鼠标移动了 x = %1, y= %2").arg(ev->x()).arg(ev->y());
    qDebug()<<str;
}




//事件分发Event事件
bool MyLable::event(QEvent* e)
{
    if(e->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent * ev = static_cast<QMouseEvent *>(e);//进行类型转换，QEvent是QmousEvent的父类
        QString str= QString("Event   鼠标释放了 x = %1, y = %2").arg(ev->x()).arg(ev->y());
        qDebug()<<str;
        //只有鼠标被按下自己处理，返回true
        return true;//返回true表示已经被拦截
    }
    //其他事情由父亲做默认处理
    return QLabel::event(e);
}




















