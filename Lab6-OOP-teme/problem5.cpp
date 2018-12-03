#include <iostream>
#include <math.h>

using namespace std;

class NrComp {
public:
	double re;
	double im;
	NrComp(double re, double im) {
		this->re= re;
		this->im = im;
	}
	friend double operator~(const NrComp &numar);
	friend NrComp operator^(const NrComp &numar, const int power);
};

double operator~(const NrComp &numar) {
	return sqrt(numar.re * numar.im + numar.re * numar.im);
}

NrComp operator^(const NrComp &numar, const int power) {
	NrComp numar_aux = numar;
	double re_aux;
	double im_aux;
	for (int i = 1; i < power; i++) {
		re_aux = numar_aux.re * numar.re - numar_aux.im * numar.im;
		im_aux = numar_aux.re * numar.im + numar_aux.im * numar.re;

		numar_aux.re = re_aux;
		numar_aux.im = im_aux;
	}
	return numar_aux;
}

int main () {
	NrComp numar_c(3.0, 4.0);

	cout << "Modulus of our number is " << ~numar_c << endl;

	numar_c = numar_c^2;

	cout << "The number at the power of 2 is " <<numar_c.re << " + " << numar_c.im << "i" << endl;

    return 0;
}
