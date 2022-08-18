#include "widget.h"
#include<QPushButton>
#include<QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    zt = new teacher(this);//通过this将函数挂在在对象树上
    st = new student(this);

    //触发信号
    classIsOver();
    //点击按钮触发信号
    QPushButton* btn = new QPushButton;
    btn->setParent(this);//设置主父亲
    btn->setText("下课");


    //连接信号和槽函数
    //connect(zt,&teacher::hungry,st,&student::treat);

    //有参信号触发方法
    void(teacher:: *teachersignal)(void) = &teacher::hungry;
    void(student:: *studentsignal)(void)=  &student::treat;

    //连接信号与信号
    connect(btn, &QPushButton::clicked,zt,teachersignal);
    //连接信号与槽函数
    connect(zt,teachersignal,st,studentsignal);

    //lambda表达式
    QPushButton* myBtn = new QPushButton("增加100",this);
    QPushButton* myBtn2 = new QPushButton("显示m",this);
    myBtn->move(100,0);
    myBtn2->move(100,100);
    int m = 10;
    //使用mutable可以改变传递值得变量
    connect(myBtn,&QPushButton::clicked,this,[m]()mutable{
        m = 100+10;
        qDebug()<<m;
    });
    connect(myBtn2,&QPushButton::clicked,this,[=](){
        qDebug()<<m;
    });

    //lambda表达式调用connect时可只写三个参数，默认第三个参数是this指针
    QPushButton *btn3=new QPushButton("点击修改内容",this);
    btn3->move(0,100);
    connect(btn3, &QPushButton::clicked,this,[=](){
        btn3->setText("哈哈");
    });

    //点击按钮关闭窗口
    QPushButton* myBtn3 = new QPushButton("关闭",this);
    myBtn3->move(0,200);
    connect(myBtn3,&QPushButton::clicked,this,[=](){
        this->close();
    });

}

Widget::~Widget()
{
}
void Widget::classIsOver()
{
    //发送自定义的信号
    emit    zt->hungry();//触发无参信号
    emit    zt->hungry("宫爆鸡丁");//触发有参信号
}

