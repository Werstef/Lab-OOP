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

};


class Operatii{
private:


public:
    Operatii(double parametru){
        double numar = modul(parametru);
        afisare(numar);
    }
    Operatii(NrComplex parametru){
        double numar = modul(parametru);
        afisare(numar, parametru);
    }

    double modul(double parametru){
        if( parametru > 0)
            return parametru;
        else
            return -parametru;
    }

    double modul(NrComplex parametru){
        return sqrt(parametru.getRe() * parametru.getRe() + parametru.getIm() * parametru.getIm());
    }


    afisare(double parametru){
        cout << "Modulul numarului real este " << parametru << endl;
    }

    afisare(double modul, NrComplex parametru){
        cout << "Modulul numarului complex cu partea reala "<< parametru.getRe() <<" si partea imaginara " << parametru.getIm() <<" este " << modul << endl;
    }
};


int main () {

    NrComplex nrcomplex(2, 2);
    double x = 3.5;

    Operatii numar1(nrcomplex);
    Operatii numar2(x);

    return 0;
}
