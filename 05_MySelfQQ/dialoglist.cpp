#include "dialoglist.h"
#include "ui_dialoglist.h"
#include<QToolButton>
#include<QMessageBox>
#include"widget.h"

Dialoglist::Dialoglist(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Dialoglist)
{
    ui->setupUi(this);
    //设置图像框标题
    this->setWindowTitle("MySelfQQ");
    //设置图标
    this->setWindowIcon(QPixmap(":/images/qq.png"));

    //准备图标
    QList<QString>nameList;
    nameList<<"斧头帮主"<<"一梦如兰"<<"北京出版人"<<"Chery"<<"淡然"<<
              "娇娇"<<"落水无痕"<<"青墨"<<"无语";
    //图标资源
    QStringList iconNameList;
    iconNameList<<"ftbz"<<"ymrl"<<"qq"<<"Cherry"<<"dr"<<"jj"<<"lswh"<<"qmnn"<<"wy";

    QVector<QToolButton*>vToolBtn;

    for(int i = 0;i<9;i++)
    {
        //设置头像
        QToolButton* btn = new QToolButton;
        //设置文字
        btn->setText(nameList[i]);
        //加载头像
        QString str = QString(":/images/%1.png").arg(iconNameList.at(i));
        btn->setIcon(QPixmap(str));
        //设置头像大小
        btn->setIconSize(QPixmap(str).size());
        //设置按键风格
        btn->setAutoRaise(true);//设置透明风格
        //设置文字和图片一起显示
        btn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        //将当前图标加载到垂直布局中
        ui->verticalLayout_2->addWidget(btn);

        //使用容器保存9个按钮，方便后续操作
        vToolBtn.push_back(btn);
        //九个图标打开状态初始化
        isShow.push_back(false);
    }

    //对9个按钮添加信号槽
    for(int i =0;i<vToolBtn.size();i++)
    {

        connect(vToolBtn[i],&QToolButton::clicked,this,[=](){
            if(isShow[i])
            {
                QString str = QString("%1窗口已被打开").arg(vToolBtn[i]->text());
                QMessageBox::warning(this,"警告",str);
                return ;
            }
            isShow[i] = true;
            //弹出对话框
            //构造聊天窗口的时候告诉窗口名称 参数1 顶层弹出方式，主窗口关闭不影响子窗口 参数2 窗口名称
            Widget* widget = new Widget(0,vToolBtn[i]->text());
            //设置窗口标题
            widget->setWindowTitle(vToolBtn[i]->text());
            widget->setWindowIcon(vToolBtn[i]->icon());
            widget->show();

            //关闭窗口后对窗口状态标志位进行改变。
            connect(widget,&Widget::closeWidget,this,[=](){
                isShow[i] = false;
            });
        });

    }
}

Dialoglist::~Dialoglist()
{
    delete ui;
}
