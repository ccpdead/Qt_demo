#include "mainwindow.h"
#include<QMenuBar>
#include<QToolBar>
#include<QLabel>
#include<QStatusBar>
#include<QDockWidget>
#include<QTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(640,480);//重设窗口大小

    //创建菜单栏，有且只能有一个
    QMenuBar* bar = menuBar();
    //将创建的菜单栏放到当前窗口中
    this->setMenuBar(bar);

    //创建文件菜单
    QMenu* fileMenu = bar->addMenu("文件");
    QMenu* editMenu = bar->addMenu("菜单");

    //添加菜单项
    QAction* newAction = fileMenu->addAction("新建");
    //添加分割线
    fileMenu->addSeparator();
    QAction* openAction = fileMenu->addAction("打开");

    //工具栏
    QToolBar* toolBar = new QToolBar(this);
    //设置默认工具栏停靠位置
    addToolBar(Qt::LeftToolBarArea,toolBar);
    //只允许工具栏左右停靠
    toolBar->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea);
    //设置不允许浮动
    toolBar->setMovable(false);
    //工具栏添加菜单项
    toolBar->addAction(newAction);
    //添加分割线
    toolBar->addSeparator();
    toolBar->addAction(openAction);

    //状态栏 只能有一个
    QStatusBar* stBar=statusBar();
    setStatusBar(stBar);
    QLabel* label = new QLabel("提示信息",this);
    stBar->addWidget(label);//添加提示信息到左侧

    QLabel* label2 = new QLabel("右侧提示信息",this);
    stBar->addPermanentWidget(label2);

    //柳接部件 浮动窗口 可以有多个
    QDockWidget* dock = new QDockWidget;
    //添加柳接部件到窗口中
    addDockWidget(Qt::BottomDockWidgetArea, dock);

    //设置停靠范围
    dock->setAllowedAreas(Qt::TopDockWidgetArea | Qt::BottomDockWidgetArea);

    //核心部件
    QTextEdit* edit = new QTextEdit;//文本编辑框
    setCentralWidget(edit);



}

MainWindow::~MainWindow()
{
}

