#include<iostream>
#include <string>
#include <math.h>
#include <time.h>
#include <cstdlib>

using namespace std;

// open with visual studio

class ComplexNumber {
protected:
	double re;
	double im;
public:
	ComplexNumber(double re, double im) {
		this->re = re;
		this->im = im;
	}
	void setRe(double re) {
		this->re = re;
	}
	double getRe() {
		return this->re;
	}
	void setIm(double im) {
		this->im = im;
	}
	double getIm() {
		return this->im;
	}

};


class Random {
public:
	static int get_random(int n) {
		srand((int)time(0));
		return (rand() % static_cast<int>(101));
	}
	static double get_random(double n) {
		srand((int)time(0));
		return  (double)rand() / static_cast<double>(101);
	}
	static ComplexNumber* get_random(ComplexNumber* number) {
		number->setRe(get_random(1.1));
		number->setIm(get_random(1.1)*get_random(1.1) / get_random(1));
		return number;
	}
};


int main() {

	ComplexNumber* complex1 = new ComplexNumber(0, 0);

	int integer1 = Random::get_random(1);
	cout << "A random integer number is " << integer1 << endl;
	double double1 = Random::get_random(1.1);
	cout << "A random double number is " << double1 << endl;
	complex1 = Random::get_random(complex1);
	cout << "A random complex number is " << complex1->getRe() << " + i " << complex1->getIm();

	cout << endl;


	system("pause");

	return 0;
}

