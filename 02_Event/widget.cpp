#include "widget.h"
#include "./ui_widget.h"
#include<QTimer>
#include<QMessageBox>
#include<QMouseEvent>
#include<QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //启动定时器
    id1 = startTimer(1000);//每隔1000ms启动一次计时器
    id2 = startTimer(2000);

    //定时器第二种方式
    QTimer* timer1 = new QTimer(this);
    timer1->start(500);//每隔0.5秒发送一次信号
    connect(timer1,&QTimer::timeout,this,[=](){
        static int num = 0;
        ui->label_4->setText(QString::number(num++));
    });

    //暂停计时器
    connect(ui->pushButton,&QPushButton::clicked,this,[=](){
        timer1->stop();
        QMessageBox::warning(this,"警告","暂停计时器");

    });



}

Widget::~Widget()
{
    delete ui;
}

void Widget::timerEvent(QTimerEvent* e)
{
    if(e->timerId() == id1)
    {
        static int num = 0;
        ui->label_2->setText(QString::number(num++));
    }
    if(e->timerId() == id2)
    {
        static int num2 = 0;
        ui->label_3->setText(QString::number(num2++));
    }
}

//通过事件过滤器来拦截event信号
bool Widget::eventFilter(QObject* obj, QEvent* e)
{
    if(obj == ui->label)
    {
        qDebug()<<"lable";
        if(e->type() == QEvent::MouseButtonPress)
        {
            QMouseEvent * ev = static_cast<QMouseEvent *>(e);//进行类型转换，QEvent是QmousEvent的父类
            QString str= QString("事件过滤器  鼠标释放了 x = %1, y = %2").arg(ev->x()).arg(ev->y());
            qDebug()<<str;
            //只有鼠标被按下自己处理，返回true
            return true;//返回true表示已经被拦截
        }
    }
    //其他的让弗雷处理
    return QWidget::eventFilter(obj,e);
}

