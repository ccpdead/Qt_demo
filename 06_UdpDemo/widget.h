#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QUdpSocket>

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
    //创建套子节
    QUdpSocket* udp;
};
#endif // WIDGET_H
