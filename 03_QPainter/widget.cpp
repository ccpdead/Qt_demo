#include "widget.h"
#include "./ui_widget.h"
#include<QPainter>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    posX = 10;
    connect(ui->pushButton_1,&QPushButton::clicked,[=](){

        posX +=50;

        //手动调用绘图更新事件
        update();
    });

}
//成员方法
void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    //如果出屏幕，强制回到开始
    if(posX >this->width())
    {
        posX = 10;
    }
    //显示图片
    painter.drawPixmap(posX,100,QPixmap(":/rocket.jpg"));




//    //创建画家
//    QPainter painter(this);

//    //设置画笔
//    QPen pen(QColor(255,0,0));
//    pen.setWidth(2);//设置画笔宽度
//    pen.setStyle(Qt::DotLine);//设置画笔风格
//    //画刷填充颜色
//    QBrush brush(Qt::cyan);//设置填充的颜色
//    brush.setStyle(Qt::Dense4Pattern);//设置笔刷格式


//    //让画家使用画笔
//    painter.setPen(pen);
//    //让画家使用笔刷
//    painter.setBrush(brush);


//    //高级设置
//    //绘画直线
//    painter.drawLine(0,0,100,100);
//    //设置抗锯齿
//    painter.setRenderHint(QPainter::Antialiasing);
//    //绘画圆
//    painter.drawEllipse(QPoint(100,100),50,50);
//    //绘画矩形
//    painter.drawRect(20,20,50,50);
//    //画字体
//    painter.drawText(QRect(10,100,150,50),"hello world");

}


//析构函数
Widget::~Widget()
{
    delete ui;
}

