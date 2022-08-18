#include "widget.h"
#include"dialoglist.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialoglist w;//实例化窗口为自定义的窗口类型。
//    Widget w;
    w.show();
    return a.exec();
}
