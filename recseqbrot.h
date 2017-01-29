#ifndef RecSeqBrot_H
#define RecSeqBrot_H

#include "RecSequence.h"
#include "Complex.h"


class RecSeqBrot :
        public RecSequence
{
private:
    Complex c;
    int nPower;

public:
    RecSeqBrot() :RecSequence() {
        c = Complex();
        nPower = 2;
    }

    RecSeqBrot(Complex& u0Source, int NSource, Complex& cSource, int nPowerSource) :RecSequence(u0Source, NSource) {
        c = cSource;
        nPower = nPowerSource;
    }

    RecSeqBrot(Complex& cSource, int nPowerSource) :RecSequence() {
        c = cSource;
        nPower = nPowerSource;
    }

    ~RecSeqBrot()  {

    }

    void Next() {

        uCurrent = ((uCurrent.Pow(nPower)) + c);

    }

    int IsConvergent() {

//        int i = 0;
//        while ((uCurrent.GetRadius() < 2) && (i <= N)) {


//            this->Next();
//            i++;

//        }

//        if (i > N) {
//            return 0;
//        }
//        else {
//            return i;
//        }

        //SetUCurrent(u0);   //On "redemarre" la série au départ
        //this->Next();      //On ne teste pas le cas u1 = c

        int numIterations = 0;
        this ->SetUCurrent(u0);

        do {
            ++numIterations;
            this->Next();
            if (uCurrent.GetRadius() > 2)
                break;

            ++numIterations;
            this->Next();
            if (uCurrent.GetRadius() > 2)
                break;
        } while (numIterations <= N);

        return numIterations;

}


};

#endif


