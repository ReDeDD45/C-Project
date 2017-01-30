#ifndef FEATURE_WIND_H
#define FEATURE_WIND_H

#include <QApplication>
#include <QWidget>
#include <QLCDNumber>
#include <QSlider>
#include <QPushButton>
#include <QMessageBox>

#include "mandelbrotwidget.h"

class Feature_Wind: public QWidget

{
    Q_OBJECT

public:
    Feature_Wind();
    int getValue();

public slots :
    void open_MsgBox();
    void open_NewMandelbrot();

signals :

private:
    QLCDNumber *_lcd;
    QSlider *_slider;
    QPushButton* _p_button;
    MandelbrotWidget* _Mandel_wind;
};

#endif // FEATURE_WIND_H
