#include "widget2.h"
#include "ui_widget2.h"

widget2::widget2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widget2)
{
    ui->setupUi(this);
    this->setWindowTitle("小红");

    //初始化属性
    ui->myPort->setText("8888");
    ui->toPort->setText("9999");
    ui->toIp->setText("127.0.0.1");

    //创建套接字
    udp = new QUdpSocket(this);

    //绑定自身端口号
    udp->bind(ui->myPort->text().toInt());//通过toInt方法将字符串转化为整数
    //点击发送按钮，发送报文
    connect(ui->sendBtn,&QPushButton::clicked,this,[=](){
        //书写报文 参数1 内容 2 对方ip 3 对方端口
        udp->writeDatagram(ui->input->toPlainText().toUtf8(),
                           QHostAddress(ui->toIp->text()),
                           ui->toPort->text().toInt()
                           );
        ui->record->append("send--->>: "+ui->input->toPlainText());
        //清空输入框
        ui->input->clear();
    });

    //接收数据并显示
    connect(udp,&QUdpSocket::readyRead,this,[=](){
        //获取到的报文长度
        qint64 size = udp->pendingDatagramSize();
        QByteArray array = QByteArray(size,0);//创建数组存放数据

        //读取报文
        udp->readDatagram(array.data(),size);

        //将数据同步在聊天记录中
        ui->record->append("received-----<<"+array);
    });



}

widget2::~widget2()
{
    delete ui;
}
