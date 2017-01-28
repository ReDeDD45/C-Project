#include "mandelbrotwidget.h"
#include "complex.h"
#include "recseqbrot.h"


#include <QApplication>
#include <iostream>
#include <QtDebug>

#include "recseqbrot.h"

using namespace std;

int main(int argc, char *argv[])
{

//    Complex cTest;
//    cTest = Complex::FromCartesian(0.0001,-0.0001);

//    cTest.Display();

//    cout << "radius : " << cTest.GetRadius() << endl;
//    cout << "angle : " << cTest.GetAngle() << endl;

//    (cTest.Pow(2)).Display();

//    cout << "radius : " << (cTest.Pow(2.0)).GetRadius() << endl;
//    cout << "angle : " << (cTest.Pow(2.0)).GetAngle() << endl;

//    (cTest.Pow(2).Pow(2)).Display();

//    cout << "radius : " << (cTest.Pow(2.0).Pow(2)).GetRadius() << endl;
//    cout << "angle : " << (cTest.Pow(2.0).Pow(2)).GetAngle() << endl;

    QApplication app(argc, argv);
    MandelbrotWidget widget;
    widget.show();
    return app.exec();

}
