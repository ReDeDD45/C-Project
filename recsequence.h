#ifndef RecSequence_H
#define RecSequence_H


#include "Complex.h"

class RecSequence
{
protected:
    Complex u0;
    Complex uCurrent;
    int N;

public:
    RecSequence() {
        u0 = Complex();
        uCurrent = u0;
        N = 10000;
    }

    RecSequence(Complex& u0Source, int NSource) {
        u0 = u0Source;
        uCurrent = u0;
        N = NSource;
    }

    virtual void Next() = 0;
    virtual int IsConvergent() = 0;

};

#endif
