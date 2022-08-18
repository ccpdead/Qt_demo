#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<QDebug>
#include<QDialog>
#include<QMessageBox>
#include<QColorDialog>
#include<QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);//添加ui类到对象树中
    //设置图标
    //使用资源文件”：+前缀名+文件名
    ui->actionopen->setIcon(QIcon(":/image/rocket.jpg"));
    ui->actionnew->setIcon(QIcon(":/image/wechat_reader.ico"));

    //点击新建菜单项 弹出对话框
    connect(ui->actionnew,&QAction::triggered,this,[=](){
//        //模态对话框
//        QDialog dlg(this);
//        dlg.resize(100,200);
//        dlg.exec();//阻塞模式

//        //非模态对话框
//        QDialog *dlg2 = new QDialog(this);
//        dlg2->resize(200,100);
//        dlg2->show();
//        //设置属性 保证对话框关闭后指针被清楚
//        dlg2->setAttribute(Qt::WA_DeleteOnClose);

        qDebug()<<"弹出对话框";

        //使用标准对话框
        //QMessageBox::critical(this, "错误","critical");
        //信息对话框
        //QMessageBox::information(this,"消息","info");
        //询问对话框
        //参数1 父亲 2，标题 3，提示内容 4，案件按钮 5，关联回车案件
//        if(QMessageBox::Save == QMessageBox::question(this,"问题","question",QMessageBox::Save | QMessageBox::Cancel))
//        {
//            qDebug()<<"保存";
//        }else
//        {
//            qDebug()<<"取消保存";
//        }
//        //警告对话框
//        QMessageBox::warning(this, "警告","warning");
         //选择颜色对话框
//         QColor color = QColorDialog::getColor(QColor(255,0,0));
//         qDebug()<<color.red()<<color.green()<<color.blue();
        //文件对话框
//        QString path = QFileDialog::getOpenFileName(this,"打开文件","","(*.txt *.png)");


});//隐含函数

}

MainWindow::~MainWindow()
{
    delete ui;
}

