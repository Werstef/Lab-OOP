
#include <iostream>
#include <math.h>
using namespace std;


template <class T>
T Minim(T a, T b){
    double module1 = sqrt(a->getRe() * a->getRe() + a->getIm() * a->getIm());
    double module2 = sqrt(b->getRe() * b->getRe() + b->getIm() * b->getIm());
    T result;
    result = (module1 > module2) ? b : a;
    return result;
}

class ComplexNumber{
protected:
    double re;
    double im;
public:
    ComplexNumber(double re, double im){
        this->re = re;
        this->im = im;
    }
    void setRe(double re){
        this->re = re;
    }
    double getRe(){
        return this->re;
    }
    void setIm(double im){
        this->im = im;
    }
    double getIm(){
        return this->im;
    }

};

int main () {

	ComplexNumber* complex1 = new ComplexNumber(1, 2);
	ComplexNumber* complex2 = new ComplexNumber(1, 4);
	ComplexNumber* complex3 = Minim(complex1, complex2);
	cout << "The minimum complex number has the real value " << complex3->getRe() <<" and the imaignary value " << complex3->getIm() << endl;
return 0; }
