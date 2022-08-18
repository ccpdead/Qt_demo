#include "widget.h"
#include <QPushButton>
#include "mybotton.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)//初始化列表。
{
    //第一种方式创建按钮。
    //按钮
    QPushButton * btn = new QPushButton;
    btn->show();//show是顶层方式弹出，如果在widget窗口显示，需要以来widget窗口。
    //设置父亲
    btn->setParent(this);
    //设置文字
    btn->setText("你好1");//讲char* 隐式类型转化为QString
    btn->move(0,0);
    //第二种方式创建按钮。
    QPushButton* btn2 = new QPushButton("你好2",this);
    //重置窗口大小
    this->resize(640,480);
    //移动第二个窗口位置。
    btn2->move(0,100);

    //重置窗口主题
    this->setWindowTitle("Qt的第一个窗口");

    //设置我的按钮
    mybotton * myBtn = new mybotton;
    myBtn->setText("我的按钮");
    myBtn->move(0,200);
    myBtn->setParent(this);

    //点击myBtn关闭窗口
    //参数1 信号发送者 参数2 发送的信号 参数3 信号的接收者 参数4 处理的槽函数
    connect(myBtn,&mybotton::clicked,this, &Widget::close);

}

Widget::~Widget()
{
}






























