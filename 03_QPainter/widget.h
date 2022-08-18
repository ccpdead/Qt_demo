#ifndef WIDGET_H
#define WIDGET_H

#include<QPaintEvent>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;

public:
    //绘图事件
    void paintEvent(QPaintEvent*);//注意，这里是对函数进行了重写
    int posX;
};
#endif // WIDGET_H
