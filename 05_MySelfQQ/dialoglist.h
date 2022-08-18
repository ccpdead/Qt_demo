#ifndef DIALOGLIST_H
#define DIALOGLIST_H

#include <QWidget>

namespace Ui {
class Dialoglist;
}

class Dialoglist : public QWidget
{
    Q_OBJECT

public:
    explicit Dialoglist(QWidget *parent = nullptr);
    ~Dialoglist();

private:
    Ui::Dialoglist *ui;
    QVector<bool>isShow;
};

#endif // DIALOGLIST_H
