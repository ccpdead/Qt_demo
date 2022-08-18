#include "mybotton.h"

mybotton::mybotton(QWidget *parent)
    : QPushButton{parent}
{

}
mybotton::~mybotton()//析构函数
{
    qDebug()<<"mybotton的析构";
}
