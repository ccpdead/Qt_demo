#include "widget.h"
#include "./ui_widget.h"
#include"dialoglist.h"
#include <QDataStream>
#include <QMessageBox>
#include <QDateTime>
#include <QColorDialog>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>

Widget::Widget(QWidget *parent,QString name)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->usrTblWidget->setColumnCount(1);
    //设置水平头
    QStringList list;
    list<<"在线人员";
    ui->usrTblWidget->setHorizontalHeaderLabels(list);
    //初始化操作
    udpSocket  = new QUdpSocket(this);
    //获取用户名
    uName = name;
    //端口号
    this->port = 8888;

    //绑定端口号 绑定模式为：共享地址 断线重连
    udpSocket->bind(this->port,QUdpSocket::ShareAddress | QUdpSocket::ReuseAddressHint);
    //发送新用户进入
    sndMsg(UsrEnter);
    //点击发送按钮 发送消息
    connect(ui->sendBtn,&QPushButton::clicked,this,[=](){
        sndMsg(Msg);
    });
    //监听别人发送的数据
    connect(udpSocket,&QUdpSocket::readyRead,this,&Widget::ReceiveMessage);//这里采用回调函数处理收到信息
//    connect(udpSocket,&QUdpSocket::readyRead,this,[=](){
//        qDebug()<<"ReceiveMessage";
//    });

    //点击退出按钮 关闭窗口
    connect(ui->exitBtn,&QPushButton::clicked,this,[=](){
        this->close();
    });

    //辅助功能--------
    //字体
    //字号
    //加粗
    //倾斜
    //下划线
    //字体颜色
    //清空聊天内容
    //保存聊天内容

}
//关闭函数的实现。
void Widget::closeEvent(QCloseEvent* e)
{

    //将信号与槽链接起来。
    emit this->closeWidget();

    sndMsg(UsrLeft);//发送用户离开
    //断开套子节
    udpSocket->close();
    udpSocket->destroyed();
    QWidget::closeEvent(e);
}

//接受udp信息
void Widget::ReceiveMessage()
{
    qDebug()<<"ReceiveMessage()";
    //拿到数据报文
    //获取数据长度
    qint64 size = udpSocket->pendingDatagramSize();
    QByteArray array = QByteArray(size,0);//创建数组
    udpSocket->readDatagram(array.data(),size);

    //解析数据
    //第一段 数据类型 第二段 用户名 第三段 内容
    QDataStream stream(&array,QIODevice::ReadOnly);

    //读到的数据类型
    int msgType;
    QString usrName;
    QString msg;

    //获取当前事件
    QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    stream>>msgType;//加载数据流
    switch(msgType){
    case Msg:
        qDebug()<<"Msg";
        //普通聊天
        stream>>usrName>>msg;
        //添加聊天信息
        ui->msgBrowser->setTextColor(Qt::blue);
        ui->msgBrowser->append("["+usrName+"]"+time);
        ui->msgBrowser->append(msg);

        break;
    case UsrEnter:
       qDebug()<<"usrEnter";
        stream>>usrName;
        usrEnter(usrName);
        break;
    case UsrLeft:
        qDebug()<<"usrLeft";
        stream>>usrName;
        usrLeft(usrName,time);
        break;
    default:
        break;
    }
}
//用户离开
void Widget::usrLeft(QString usrname,QString time)//处理用户离开
{
//    qDebug()<<"usrleft";
    //更新右侧tablewidget
    bool isEmpty1 = ui->usrTblWidget->findItems(usrname,Qt::MatchExactly).isEmpty();
    if(!isEmpty1)
    {
        int row = ui->usrTblWidget->findItems(usrname,Qt::MatchExactly).first()->row();
        ui->usrTblWidget->removeRow(row);

        //追加聊天记录
        ui->msgBrowser->setTextColor(Qt::gray);
        ui->msgBrowser->append(QString("%1 于 %2 离开").arg(usrname).arg(time));

        //在线人数增加
        ui->usrNumLbl->setText(QString("在线人数： %1人").arg(ui->usrTblWidget->rowCount()));

    }
}
//添加用户
void Widget::usrEnter(QString username)//处理新用户加入
{
//    qDebug()<<"usrEnter";
    //更新右侧tablewidget
    bool isEmpty1 = ui->usrTblWidget->findItems(username,Qt::MatchExactly).isEmpty();
    if(isEmpty1)
    {
        QTableWidgetItem * usr = new QTableWidgetItem(username);

        //插入行
        ui->usrTblWidget->insertRow(0);
        ui->usrTblWidget->setItem(0,0,usr);

        //追加聊天记录
        ui->msgBrowser->setTextColor(Qt::gray);
        ui->msgBrowser->append( QString("%1 上线了").arg(username));
        //在线人数更新
        ui->usrNumLbl->setText(QString("在线用户：%1人").arg(ui->usrTblWidget->rowCount()));

        //把自身信息广播出去
        sndMsg(UsrEnter);
    }
}
//广播udp信息
void Widget::sndMsg(MsgType type)//广播udp信息
{
//    qDebug()<<"sndMsg()";
    //发送的消息分为三种类型
    //发送的数据做分段处理 第一段 类型 第二段 用户名 第三段 具体内容
    QByteArray array;
    QDataStream stream(&array,QIODevice::WriteOnly);//建立数据流

    stream<<type<<getUsr();//第一段内容添加到流中 第二段 用户名

    switch(type){
    case Msg:
        //如果发送框为空
        if(ui->msgTxtEdit->toPlainText() == ""){
            QMessageBox::warning(this,"警告","发送内容不能为空");
            return ;
        }

        //第三段 数据
        stream<<getMsg();
        break;

    case UsrEnter://新用户进入
        break;

    case UsrLeft://用户离开
        break;
    default:
        break;
        //广播报文数据
    }
    udpSocket->writeDatagram(array,QHostAddress::Broadcast,port);
}

//获取用户名
QString Widget::getUsr()//获取用户名
{
    return this->uName;
}
//获取用户输入信息
QString Widget::getMsg()//获取聊天内容
{
    QString str = ui->msgTxtEdit->toHtml();//获取html格式的文字信息
    //清空输入框
    ui->msgTxtEdit->clear();
    ui->msgTxtEdit->setFocus();//让光标保持输入状态
    return str;
}


Widget::~Widget()
{
    delete ui;
}

