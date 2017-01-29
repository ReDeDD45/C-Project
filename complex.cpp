#define _USE_MATH_DEFINES
using namespace std;

#include <iostream>
#include "Complex.h"
#include <cmath>

// Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°  Constructors Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°

//Default constructor
Complex::Complex()
{
    _real = 0;
    _imaginary = 0;
}

//Default destructor
Complex::~Complex()
{

}

//Private constructor
Complex::Complex(double r, double im)
{
    _real = r;
    _imaginary = im;
}

//Cartesian constructor
Complex Complex::FromCartesian(double r, double im)
{
    return Complex(r, im);
}

//Polar constructor
Complex Complex::FromPolar(double radius, double angle)
{
    if (radius != 0){
        return Complex(radius*cos(angle), radius*sin(angle));
    }
    else {
        return Complex();
    }
}

//Copy-Constructor
Complex::Complex(const Complex& source)
{
    _real = source._real;
    _imaginary = source._imaginary;
}

// Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°  Getters & Setters Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°
const double Complex::GetReal()
{
    return _real;
}
const double Complex::GetImaginary()
{
    return _imaginary;
}

const double Complex::GetRadius()
{
    return sqrt(_real*_real + _imaginary*_imaginary);
}
const double Complex::GetAngle()
{
    if ((_imaginary == 0) && (_real < 0)) {
        return M_PI;
    }
    else
    {
        return 2 * atan(_imaginary / (this->GetRadius() + _real));;
    }
}

void Complex::SetReal(double newReal)
{
    _real = newReal;
}

void Complex::SetImaginary(double newIm)
{
    _imaginary = newIm;
}

Complex Complex::Pow(const double& powerValue)
{
    double realResult, imResult, radiusResult, angleResult;

    radiusResult = pow(this->GetRadius(),powerValue);

    if (radiusResult == 0) {
        return Complex();
    }
    else {
        angleResult = powerValue * (this->GetAngle());

        realResult = radiusResult*cos(angleResult);
        imResult = radiusResult*sin(angleResult);

        return Complex::FromCartesian(realResult, imResult);
    }
}

// Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°  += & -= operators Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°
void Complex::operator += (const Complex& cToAdd)
{
    _real += cToAdd._real;
    _imaginary += cToAdd._imaginary;
}

void Complex::operator += (const double& dToAdd)
{
    _real += dToAdd;
}

void Complex::operator -= (const Complex& cToSubtract)
{
    _real -= cToSubtract._real;
    _imaginary -= cToSubtract._imaginary;
}

void Complex::operator -= (const double& dToSubtract)
{
    _real -= dToSubtract;
}

void Complex::operator = (const Complex& cSource)
{
    _real = cSource._real;
    _imaginary = cSource._imaginary;
}

void Complex::operator = (const double& realSource)
{
    _real = realSource;
    _imaginary = 0;
}

// Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°  += & -= & = operators Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°

// Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â° Display Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°
void Complex::Display()
{
    cout << _real << " + " << _imaginary << "i" << endl;
}

// Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°  + & - operators Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°Â°
Complex operator + (const Complex& c1, const double& realToAdd)
{
    Complex result = Complex();
    result += c1;
    result += realToAdd;
    return result;
}

Complex operator + (const double& realToAdd, const Complex& c2)
{
    return c2 + realToAdd;
}


Complex operator + (const Complex& c1, const Complex& c2)
{
    Complex result = Complex(c1);
    result += c2;
    return result;
}

Complex operator - (const Complex& c1, const double& realToSubtract)
{
    Complex result = Complex(c1);
    result -= realToSubtract;
    return result;
}

Complex operator - (const double& realFirst, const Complex& c2)
{
    Complex result = Complex();
    result.SetReal(realFirst - result.GetReal());
    result.SetImaginary(-result.GetImaginary());
    return result;
}


Complex operator - (const Complex& c1, const Complex& c2)
{
    Complex result = Complex(c1);
    result -= c2;
    return result;
}

Complex operator * (const double& real, Complex& cInput)
{
    double realResult, imResult;
    realResult = real * cInput.GetReal();
    imResult = real * cInput.GetImaginary();
    return Complex::FromCartesian(realResult, imResult);
}

Complex operator * (Complex& cInput, const double& real)
{
    return real * cInput;
}

Complex operator * (Complex& cInput, Complex& cInput2)
{
    double realResult, imResult;
    realResult = (cInput.GetReal() * cInput2.GetReal()) - (cInput.GetImaginary() * cInput2.GetImaginary());
    imResult = (cInput.GetReal() * cInput2.GetImaginary()) + (cInput.GetImaginary() * cInput2.GetReal());
    return Complex::FromCartesian(realResult, imResult);
}

