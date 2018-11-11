#include <iostream>
using namespace std;


struct Student{
    int nota;
    int varsta;
    char* nume;

}s1, s2;

template <typename T>
T Max(T a, T b){
    return a.nota < b.nota ? b:a ;
}
// T c.nota =

int main () {


    s1.nota = 10;

    s2.nota = 5;


    cout << Max(s1, s2).nota;
    return 0;
}

