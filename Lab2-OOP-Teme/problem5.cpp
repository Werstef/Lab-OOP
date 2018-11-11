#include <iostream>
#include <math.h>

using namespace std;

struct nrComplex{
    double re;
    double im;
};

double function(double re){
    return re > 0 ? re:(-re);
}

double function(double re, double im){
    return sqrt(pow(re,2) + im * im);
}


int main () {

    nrComplex numar;
    numar.re = 3;
    numar.im = 4;

    cout<<function(numar.re) << endl ;
    cout<<function(numar.re, numar.im) << endl ;
    return 0;
}
