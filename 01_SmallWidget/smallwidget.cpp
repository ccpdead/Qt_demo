#include "smallwidget.h"
#include "ui_smallwidget.h"

SmallWidget::SmallWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SmallWidget)
{
    ui->setupUi(this);

    //QSpinBox移动 Slider跟着移动

    connect(ui->spinBox,&QSpinBox::valueChanged,ui->horizontalSlider,&QSlider::setValue);

    //Slider移动 SpinBox跟着移动
    connect(ui->horizontalSlider,&QSlider::valueChanged,ui->spinBox,&QSpinBox::setValue);
}
void SmallWidget::setValue_btn(int v)
{
    ui->spinBox->setValue(v);
}

int SmallWidget::getValue_btn(void)
{
    return ui->spinBox->value();
}


SmallWidget::~SmallWidget()
{
    delete ui;
}
