#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>

class student : public QObject//所有的槽与信号都需要继承于QObject
{
    Q_OBJECT
public:
    explicit student(QObject *parent = nullptr);

signals:
    //自定义信号

public slots:
    //自定义槽函数
    void treat();
    void treat(QString foodName);



};

#endif // STUDENT_H
