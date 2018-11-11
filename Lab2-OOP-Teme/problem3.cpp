#include <iostream>
#include <string.h>
using namespace std;

struct Student {

    int nota;
    int varsta;
    char* nume;
};

int f(int x){
    return sizeof(x);
}


int f(double x){
    return sizeof(x);
}


int f(char *x){
    return strlen(x);
}


int f(Student x){
    return sizeof(x);
}


int main () {

    int a = 20;
    double b = 2.5;
    char *c = "Andrei";
    Student d;

    cout << f(a) << endl;
    cout << f(b) << endl;
    cout << f(c) << endl;
    cout << f(d) << endl;

    return 0;
}
