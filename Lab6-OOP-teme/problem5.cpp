#include <iostream>
#include <math.h>

using namespace std;

class NrComp {
protected:
    double re;
	double im;
public:
	NrComp(double re, double im) {
		this->re= re;
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

	friend double operator~(const NrComp &numar);
	friend NrComp operator^(const NrComp &numar, const int power);
};

double operator~(NrComp &numar) {
	return sqrt(numar.getRe() * numar.getIm() + numar.getRe() * numar.getIm());
}

NrComp operator^(NrComp &numar, const int power) {
	NrComp numar_aux = numar;
	double re_aux;
	double im_aux;
	for (int i = 1; i < power; i++) {
		re_aux = numar_aux.getRe() * numar.getRe() - numar_aux.getIm() * numar.getIm();
		im_aux = numar_aux.getRe() * numar.getIm() + numar_aux.getIm() * numar.getRe();

		numar_aux.setRe(re_aux);
		numar_aux.setIm(im_aux);
	}
	return numar_aux;
}

int main () {
	NrComp numar(3.0, 4.0);

	cout << "Modulus of our number is " << ~numar << endl;

	numar = numar^2;

	cout << "The number at the power of 2 is " <<numar.getRe() << " + " << numar.getIm() << "i" << endl;

    return 0;
}
