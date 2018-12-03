#include <iostream>
#include <math.h>

using namespace std;

class NrComplex {
private:
    float re;
    float im;
public:

    NrComplex(float re, float im){
        this->re = re;
        this->im = im;
    }

    void setIm(float im){
        this->im = im;
    }
    float getIm(){
        return this->im;
    }

    void setRe(float re){
        this->re = re;
    }

    float getRe(){
        return this->re;
    }

    double operator~(NrComplex parametru){
        return sqrt(parametru.getRe() * parametru.getRe() + parametru.getIm() * parametru.getIm());
    }

    void operator^(NrComplex parametru){
        parametru.setRe(parametru.getRe() * parametru.getRe());
        parametru.setIm(parametru.getIm() * parametru.getIm());
    }

};



int main () {

    double x = 3;
    double y = 2;

    cout << x^2 << endl;

    NrComplex nr1(2, 3);

    cout << nr1~ << endl;

    return 0;
}
