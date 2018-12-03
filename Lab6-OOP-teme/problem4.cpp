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
    Operatii(double parametru1, double parametru2){
        double suma1 = suma(parametru1, parametru2);
        cout << "Suma celor doua numere reale este " << suma1 << endl;
        double dif1 = dif(parametru1, parametru2);
        cout << "Diferenta celor doua numere reale este " << dif1 << endl;
        double produs1 = produs(parametru1, parametru2);
        cout << "Produsul celor doua numere reale este " << produs1 << endl;
        double div1 = div(parametru1, parametru2);
        cout << "Impartirea celor doua numere reale este " << div1 << endl;
    }
    Operatii(NrComplex parametru1, NrComplex parametru2){
        NrComplex* suma1 = suma(parametru1, parametru2);
        cout << "Suma celor doua numere complexe are partea reala "<< suma1->getRe() << " si partea imaginara " << suma1->getIm() << endl;
        NrComplex* dif1 = dif(parametru1, parametru2);
        cout << "Diferenta celor doua numere complexe are partea reala "<< dif1->getRe() << " si partea imaginara " << dif1->getIm() << endl;
        NrComplex* produs1 = produs(parametru1, parametru2);
        cout << "Produsul celor doua numere complexe are partea reala "<< produs1->getRe() << " si partea imaginara " << produs1->getIm() << endl;
        NrComplex* div1 = div(parametru1, parametru2);
        cout << "Impartirea celor doua numere complexe are partea reala "<< div1->getRe() << " si partea imaginara " << div1->getIm() << endl;
    }

    static double suma(double parametru1, double parametru2){
        return parametru1 + parametru2;
    }

     static NrComplex* suma(NrComplex parametru1, NrComplex parametru2){
        NrComplex* suma_parametrii = new NrComplex(parametru1.getRe() + parametru2.getRe(), parametru1.getIm() + parametru2.getIm());
        return suma_parametrii;
    }

     static double dif(double parametru1, double parametru2){
        return parametru1 - parametru2;
    }

     static NrComplex* dif(NrComplex parametru1, NrComplex parametru2){
        NrComplex* dif_parametrii = new NrComplex(parametru1.getRe() - parametru2.getRe(), parametru1.getIm() - parametru2.getIm());
        return dif_parametrii;
    }

     static double produs(double parametru1, double parametru2){
        return parametru1 * parametru2;
    }

     static NrComplex* produs(NrComplex parametru1, NrComplex parametru2){
        NrComplex* produs_parametrii = new NrComplex(parametru1.getRe() * parametru2.getRe() - parametru1.getIm() * parametru2.getIm(), parametru1.getRe() * parametru2.getIm() + parametru1.getIm() * parametru2.getRe());
        return produs_parametrii;
    }

     static double div(double parametru1, double parametru2){
        return parametru1 / parametru2;
    }

     static NrComplex* div(NrComplex parametru1, NrComplex parametru2){
        NrComplex numar2(parametru2.getRe(), -parametru2.getIm());
        NrComplex* div1_parametrii = produs(parametru1, numar2);
        NrComplex* div_parametrii = new NrComplex(div1_parametrii->getRe() / (parametru2.getRe() * parametru2.getRe() + parametru2.getIm() * parametru2.getIm()), div1_parametrii->getIm() / (parametru2.getRe() * parametru2.getRe() + parametru2.getIm() * parametru2.getIm()) );
        return div_parametrii;
    }

     static afisare(double parametru){
        cout << "Modulul numarului real este " << parametru << endl;
    }

     static afisare(double modul, NrComplex parametru){
        cout << "Modulul numarului complex cu partea reala "<< parametru.getRe() <<" si partea imaginara " << parametru.getIm() <<" este " << modul << endl;
    }
};


int main () {

    NrComplex nrcomplex1(2, 2);
    NrComplex nrcomplex2(3, 3);
    double x = 3.5;
    double y = 2;

    Operatii numar1(nrcomplex1, nrcomplex2);
    Operatii numar2(x, y);

    return 0;
}



