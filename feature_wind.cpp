#include "feature_wind.h"
#include <string>
#include <string.h>
#include "mandelbrotwidget.h"

Feature_Wind::Feature_Wind() : QWidget()
{
    setFixedSize(200, 100);
    _slider = new QSlider(Qt::Horizontal, this);
    _slider->setRange(2,10);
    _slider->setGeometry(10, 60, 150, 20);
    _lcd= new QLCDNumber(this);
    _lcd->setSegmentStyle(QLCDNumber::Flat);
    _lcd->move(50, 20);
    _p_button=new QPushButton(this);


    QObject::connect(_slider,SIGNAL(valueChanged(int)), _lcd,SLOT(display(int)));
    //QObject::connect(_slider,SIGNAL(valueChanged(int)), _lcd,SLOT(display(int)));
    QObject::connect(_p_button, SIGNAL(clicked(bool)),this, SLOT(open_NewMandelbrot()));
}

int Feature_Wind::getValue()
{
    return (_slider->value());
}

void Feature_Wind::open_MsgBox()
{
    int value=getValue();
    QMessageBox::information(this, "valeur bande", (QString)value);
}

void Feature_Wind::open_NewMandelbrot()
{
    int value=getValue();
    _Mandel_wind = new MandelbrotWidget(0,value);
    _Mandel_wind->show();

    //QMessageBox::information(this, "valeur bande", (QString)value);
}
