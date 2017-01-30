//#include "mandelbrotwidget.h"
//#include "complex.h"
//#include "recseqbrot.h"
#include "feature_wind.h"

#include <QApplication>
//#include <iostream>
#include <QtDebug>

using namespace std;

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);
//    MandelbrotWidget widget;
//    widget.show();

    Feature_Wind widget;
    widget.show();

    return app.exec();

}
