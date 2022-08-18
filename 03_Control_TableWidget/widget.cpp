#include "widget.h"
#include "./ui_widget.h"
#include<QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //QTableWidget控件的使用
    //告诉空间有多少列
    QStringList list;
    list<<"姓名"<<"性别"<<"年龄";

    ui->tableWidget->setColumnCount(list.size());
    //设置水平头
    ui->tableWidget->setHorizontalHeaderLabels(list);
    //设置行数
    ui->tableWidget->setRowCount(5);


    //设置正文
    //ui->tableWidget->setItem(0,0,new QTableWidgetItem("亚瑟"));
    //准备数据
    QStringList nameList;
    nameList<<"亚瑟"<<"妲己"<<"安其拉"<<"李白"<<"小明";
    QList<QString>sexList;
    sexList<<"man"<<"women"<<"man"<<"man"<<"women";

    for(int i = 0;i<5;i++)
    {
        int col = 0;
        ui->tableWidget->setItem(i,col++,new QTableWidgetItem(nameList[i]));
        //添加性别
        ui->tableWidget->setItem(i,col++,new QTableWidgetItem(sexList.at(i)));
        //添加年龄
        //int 转 Qstring number
        ui->tableWidget->setItem(i,col++,new QTableWidgetItem(QString::number(i+18)));
    }

    //点击按钮 添加赵云
    connect(ui->addTable,&QPushButton::clicked,[=](){
        //先判断是否已存在赵云，若有则不添加
        bool isEmpty = ui->tableWidget->findItems("赵云",Qt::MatchExactly).empty();
        if(isEmpty)
        {
            ui->tableWidget->insertRow(0);//添加行
            ui->tableWidget->setItem(0,0,new QTableWidgetItem("赵云"));
            ui->tableWidget->setItem(0,1,new QTableWidgetItem("男"));
            ui->tableWidget->setItem(0,2,new QTableWidgetItem(QString::number(20)));

        }else
        {
            QMessageBox::warning(this,"警告","赵云已存在");
        }
    });

    //点击按钮 删除赵云
    connect(ui->deletTable,&QPushButton::clicked,[=](){
        //先判断是否已存在赵云，若有则不添加
        bool isEmpty = ui->tableWidget->findItems("赵云",Qt::MatchExactly).empty();
        if(isEmpty)
        {
            QMessageBox::warning(this,"警告","不存在赵云");
        }else
        {
            //找到赵云所在行
            int row = ui->tableWidget->findItems("赵云",Qt::MatchExactly).first()->row();
            //找到行，删除
            ui->tableWidget->removeRow(row);
        }
    });
}

Widget::~Widget()
{
    delete ui;
}

