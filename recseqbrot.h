#ifndef RecSeqBrot_H
#define RecSeqBrot_H

#include "RecSequence.h"
#include "Complex.h"


class RecSeqBrot {

private:
    Complex u0;
    Complex uCurrent;
    int N;
    Complex c;
    int nPower;

public:
    RecSeqBrot() {
        u0 = Complex();
        uCurrent = u0;
        N = 10000;
        c = Complex();
        nPower = 2;
    }

    RecSeqBrot(int NSource, Complex& cSource) {
        u0 = Complex();
        uCurrent = u0;
        N = NSource;
        c = cSource;
        nPower = 2;
    }

    RecSeqBrot(Complex& u0Source, int NSource, Complex& cSource, int nPowerSource)  {
        u0 = u0Source;
        uCurrent = u0;
        N = NSource;
        c = cSource;
        nPower = nPowerSource;
    }

    ~RecSeqBrot()  {

    }

    void SetU0(Complex& uSource){
        u0 = uSource;
    }

    void SetUCurrent(Complex& uSource){
        uCurrent = uSource;
    }

    void SetN(int NSource){
        N = NSource;
    }

    void SetCValue(Complex& cSource) {
        c = cSource;
    }

    void SetNPowerValue(int nPowerSource) {
        nPower = nPowerSource;
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


