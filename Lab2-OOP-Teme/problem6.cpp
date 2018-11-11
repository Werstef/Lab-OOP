#include <iostream>

using namespace std;

template<typename T>
T maxim(T number1, T number2, T number3){
    T intermediar;
    if( number1 >= number2)
         intermediar = number1;
    else
         intermediar = number2;

    if(intermediar >= number3)
        return intermediar;
    else
        return number3;
}


int main () {

    double a = 2;
    double b = 3.1;
    double c = 5.1;

//intrebare char* afiseaza mereu ultima valoare
    cout<< maxim(a, b, c);
    return 0;
}


