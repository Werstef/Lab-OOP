#include <iostream>
#include <math.h>

using namespace std;

class ComplexNumber {
protected:
    double re;
	double im;
public:
	ComplexNumber(double re, double im) {
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

};

double operator~(ComplexNumber &number) {
	return sqrt(number.getRe() * number.getIm() + number.getRe() * number.getIm());
}

ComplexNumber operator^(ComplexNumber &number, const int power) {
	ComplexNumber number_aux = number;
	double re_aux;
	double im_aux;
	for (int i = 1; i < power; i++) {
		re_aux = number_aux.getRe() * number.getRe() - number_aux.getIm() * number.getIm();
		im_aux = number_aux.getRe() * number.getIm() + number_aux.getIm() * number.getRe();

		number_aux.setRe(re_aux);
		number_aux.setIm(im_aux);
	}
	return number_aux;
}

int main () {
	ComplexNumber number(3.0, 4.0);

	cout << "Modulus of our number is " << ~number << endl;

	number = number^2;

	cout << "The number at the power of 2 has the real part " << number.getRe() <<" and the imaginary part " << number.getIm()  << endl;

    return 0;
}
