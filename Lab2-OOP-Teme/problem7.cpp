#include <iostream>

using namespace std;

template<typename T>
void interchange(T &value1, T &value2){
    T aux;
    aux = value1;
    value1 = value2;
    value2 = aux;
}


int main () {

    char* a = "Andrei";
    char* b = "Stefan";

    interchange(a, b);
    cout << a << endl << b;
    return 0;
}
