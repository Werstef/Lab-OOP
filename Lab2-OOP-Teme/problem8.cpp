#include <iostream>

using namespace std;

struct pisica{
    char *nume;
    char *stapan;
    int varsta;
};

struct persoana{
    char *nume;
    char *prenume;
    int varsta;
};

struct masina{
    char *marca;
    char *nr_inmatriculare;
    int varsta;
};

template<typename T>
bool compare_age(T variabila1, T variabila2){
   // return variabila1.varsta > variabila2.varsta ? variabila2 : variabila1; /// a)
    if(variabila1.varsta == variabila2.varsta)
        return true;
    else
        return false;
}

template<typename T>
T min_age(T variabila1, T variabila2){
    return variabila1.varsta > variabila2.varsta ? variabila2 : variabila1;

}


int main () {

    pisica a;
    pisica b;

    a.varsta = 20;
    b.varsta = 15;
    cout << compare_age(a, b) << endl << min_age(a, b).varsta;

    return 0;
}
