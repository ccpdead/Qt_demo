#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QUdpSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT
    enum MsgType{Msg,UsrEnter,UsrLeft};//枚举值消息，用户加入，用户离开

public:
    //这里我们更改了构造函数，以保证符合要求。
    Widget(QWidget *parent,QString name);
    ~Widget();

private:
    Ui::Widget *ui;

signals:
    //定义关闭窗口的信号--->注意，信号只需要声明，不需要实现。
    void closeWidget();

public:
    //声明关闭窗口的事件--->注意，这里closeEvent有虚函数，这里进行重写操作。
    void closeEvent(QCloseEvent*);

    void sndMsg(MsgType type);//广播udp信息
    void usrEnter(QString username);//处理新用户加入
    void usrLeft(QString usrname,QString time);//处理用户离开

    QString getUsr();//获取用户名
    QString getMsg();//获取聊天内容

private:
    QUdpSocket* udpSocket;//udp套子节
    qint16  port;//端口
    QString uName;//用户名
    //方法
    void ReceiveMessage();//接受udp消息

};
#endif // WIDGET_H
