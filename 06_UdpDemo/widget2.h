#ifndef WIDGET2_H
#define WIDGET2_H

#include <QWidget>
#include<QUdpSocket>

namespace Ui {
class widget2;
}

class widget2 : public QWidget
{
    Q_OBJECT

public:
    explicit widget2(QWidget *parent = nullptr);
    ~widget2();

private:
    Ui::widget2 *ui;
public:
    //创建套子节
    QUdpSocket* udp;
};

#endif // WIDGET2_H
