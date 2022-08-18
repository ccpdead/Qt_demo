#include "widget.h"
#include "./ui_widget.h"
#include<QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //设置参数为50;
    connect(ui->btnSet,&QPushButton::clicked,this,[=](){
        ui->widget->setValue_btn(50);
    });
    //获取参数值并显示
    connect(ui->btnGet,&QPushButton::clicked,this,[=](){
       qDebug()<<"当前值为"<< ui->widget->getValue_btn();
    });
}

Widget::~Widget()
{
    delete ui;
}

