#include "widget.h"
#include"widget2.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    widget2 w2;
    w2.show();
    return a.exec();
}
