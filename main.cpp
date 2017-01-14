#include "mandelbrotwidget.h"


#include <QApplication>
#include <iostream>

#include "recseqbrot.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MandelbrotWidget widget;
    widget.show();
    return app.exec();

}
