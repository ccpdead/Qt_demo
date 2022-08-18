#include "widget.h"
#include "./ui_widget.h"
#include<QFileDialog>//打开文件位置·
#include<QMessageBox>//返回警告信息
#include<QFile>//打开文件
//#include <QTextCodec>
#include<QFileInfo>

#include<QDebug>

#include<QDateTime>
#include<QTextStream>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //点击按钮 选择文件
    connect(ui->pushButton,&QPushButton::clicked,[=](){
        QString path = QFileDialog::getOpenFileName(this,"打开文件","D:\\C++\\某马C++24期完整版\\第06章. QT编译器\\06 qt（资料）\\06 QT\\04-Day16_C++_QT\\Doc");
        if(path.isEmpty())
        {
            QMessageBox::warning(this,"警告","文件无效");
        }
        else
        {
            //将路径存放在lineEdit中
            ui->lineEdit->setText(path);
            //QFile默认读取文件支持utf-8格式
            //更改格式为gbk
//            QTextCodec* codec = QTextCodec::

                    //参数路径位置
            QFile file(path);//此处实例化文件操作对象.
            //指定打开方式（只读）
            //file.open(QIODevice::ReadOnly);
            file.open(QFileDevice::ReadOnly);
            QByteArray array;
//            array = file.readAll();//将文章数据存入
            while(!file.atEnd())
            {
                array += file.readLine();
            }
            ui->textEdit->setText(array);
            file.close();

            //对文件进行写操作
//            file.open(QFileDevice::Append);//通过添加的方式打开文档
//            file.write("hello world");
//            file.close();//关闭文件

            //QFileInfo读取文件信息
            QFileInfo info(path);
            qDebug()<<"路径"<<info.filePath()<<"名称"<<
                      info.fileName()<<"文件大小"<<info.size()<<"后缀名"<<info.suffix();
            qDebug()<<"创建日期"<<info.birthTime().toString("yyyy-MM-dd hh:mm:ss");
            qDebug()<<"修改日期"<<info.lastModified().toString("dd.MM.yyyy");
        }
    });

    //文件流读写文件
    //分类：文本流（基础数据类型） 数据流（大型QImage）

    //文本流
//    QFile file("aaa.txt");
//    file.open(QFileDevice::WriteOnly);
//    QTextStream stream(&file);
//    stream<<QString("Hello World")<<123456;
//    file.close();
    //读取
//    file.open(QFileDevice::ReadOnly);
//    QString str;
//    str = stream.readAll();
//    qDebug()<<str;

    //数据流 二进制数据
    QFile file("bbb.txt");
    file.open(QFileDevice::WriteOnly);
    QDataStream stream(&file);
    stream<<QString("hello wolrd")<<123456;
    file.close();

    //读数据
    file.open(QFileDevice::ReadOnly);
    QString str;
    int num;
    stream>>str>>num;
    qDebug()<<str<<num;
}

Widget::~Widget()
{
    delete ui;
}
























