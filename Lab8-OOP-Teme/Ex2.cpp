#include <string>
#include <list>
#include <iostream>

using namespace std;

class Persoana{
public:

    int varsta;
    string nume;

    Persoana(string numeParam, int varstaParam){
        nume = numeParam;
        varsta = varstaParam;
    }

    virtual void print(){
        cout << " Acesta este o persoana: " << nume <<" " << varsta<<endl;
    }


};

class Angajat : public Persoana{
public:
    string loc_de_munca;

    Angajat(string numeParam, int varstaParam, string ldmParam): Persoana(numeParam, varstaParam){
        nume = numeParam;
        varsta = varstaParam;
        loc_de_munca= ldmParam;
    }

    virtual void print(){
        cout << " Acesta este un ngajat: " << nume <<" "<< varsta<<" " << loc_de_munca<<endl;
    }


};


int main(){
    list <Persoana> persoane;
    int nrPersoane, nrAngajati;
    cout<<"numarul de persoane:"<<endl;
    cin >> nrPersoane;
    for (int i = 0; i < nrPersoane; i++){
        int varsta;
        string nume;
        cout<<"Numele si varsta:"<<endl;
        cin >> nume>>varsta;
        Persoana* persoana = new Persoana (nume, varsta);
        persoane.push_back( *persoana );
    }

    cout<<"numarul de angajati:"<<endl;
    cin >> nrAngajati;
    for (int i = 0; i < nrAngajati; i++){
        int varsta;
        string nume;
        string job;
        cout<<"Numele, varsta si locul de munca:"<<endl;
        cin >> nume >> varsta >> job;
        Angajat* angajat = new Angajat( nume, varsta, job );
        persoane.push_back( *angajat );
    }


    for ( it : persoane){
        it.print();
    }


    return 0;
}


