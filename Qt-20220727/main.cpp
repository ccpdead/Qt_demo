#include "widget.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

//argc:命令行变量数量，argv:命令行变量数组
int main(int argc, char *argv[])
{
    //应用程序对象，有且仅有一个。
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "Qt-20220727_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    //widget对象w，基类是QWidget
    Widget w;
    //默认窗口不会弹出，调用show方法弹出窗口。
    w.show();
    //a.exec()进入消息循环机制pause
    return a.exec();
}
