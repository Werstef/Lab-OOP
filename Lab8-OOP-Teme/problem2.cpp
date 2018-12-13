#include <iostream>
#include <string.h>
#include <list>

using namespace std;

class Student;

class Persoana{
public:

    int varsta;
    string nume;
    Persoana() {};
    Persoana(int varsta, string nume){
        this->varsta=varsta;
        this->nume=nume;
    }

};


class Sofer :public Persoana{
        public:

            string masina;
            Sofer(){};
            Sofer(string nume, int varsta, string masina): Persoana(varsta, nume){
                this->nume = nume;
                this->varsta = varsta;
                this->masina = masina;
            }

        void print(){
            cout << " Soferul: " << nume <<" " << varsta<<" " <<masina<<endl;
        }

        friend class Student;

};

class Student :public Persoana{
public:
    int cod;
    Sofer* sofer = new Sofer;

    Student (string nume, int varsta, int cod) : Persoana(varsta, nume){
        this->nume = nume;
        this->varsta = varsta;
        this->cod = cod;
    }

    Student(string nume, int varsta, int cod, string masina) : Persoana(varsta, nume){
        this->nume = nume;
        this->varsta = varsta;
        this->cod = cod;
        this->sofer->masina = masina;

    }

    void print(){
        cout << " Studentul: " << nume <<endl;
    }


};

void adaugare_student (list <Student> &lista_studenti){
    int varsta;
    string nume;
    int cod;
    cout<<"Numele, varsta, codul:"<<endl;
    cin >> nume>>varsta>>cod;
    Student* student = new Student ( nume, varsta, cod);
    lista_studenti.push_back( *student );

}

void adaugare_student_sofer (list <Student> &lista_studenti){
    int varsta;
    string nume;
    int cod;
    string masina;
    cout<<"Numele, varsta, codul si masina:"<<endl;
    cin >> nume>>varsta>>cod>>masina;
    Student* student = new Student ( nume, varsta, cod, masina);
    lista_studenti.push_back( *student );

}

void creeare_lista_studenti (int nrStudenti, list<Student> &lista_studenti){
    bool decizie;
    for (int i = 0; i < nrStudenti; i++){
        cout<<"Daca studentul este si sofer scrieti 1, altef 0: ";
        cin>>decizie;
        if (decizie)
            adaugare_student_sofer(lista_studenti);
        else
            adaugare_student(lista_studenti);
    }
}


void mutare_student ( int nr_student_mutat, list <Student> &lista_studenti1, list <Student> &lista_studenti2){

    list<Student>::iterator it = lista_studenti1.begin();
    advance(it, nr_student_mutat);
    lista_studenti2.push_back( *it );
    lista_studenti1.erase(it);

}

void editare_nume_student (int nr_student_modificat, list <Student> &lista_studenti){

    list<Student>::iterator it = lista_studenti.begin();
    advance(it, nr_student_modificat);

    string nume_nou;
    cout<<" Scrieti noul nume al studentului: ";
    cin>> nume_nou;
    it->nume=nume_nou;

}

void editare_cod_student (int nr_student_modificat, list <Student> &lista_studenti){

    list<Student>::iterator it = lista_studenti.begin();
    advance(it, nr_student_modificat);
    int cod_nou;
    cout<<" Scrieti noul cod al studentului: ";
    cin>> cod_nou;
    it->cod = cod_nou;

}

void editare_varsta_student (int nr_student_modificat, list <Student> &lista_studenti){

    list<Student>::iterator it = lista_studenti.begin();
    advance(it, nr_student_modificat);
    int varsta_noua;
    cout<<" Scrieti noua varsta al studentului: ";
    cin>> varsta_noua;
    it->varsta = varsta_noua;

}




void stergere_student( int nr_student_sters, list<Student> &lista_studenti){

    list<Student>::iterator it = lista_studenti.begin();
    advance(it, nr_student_sters);
    lista_studenti.erase(it);

}

void afisare_lista_studenti (list<Student> &lista_studenti){
    for ( it : lista_studenti)
        it.print();

}


int main (){

 /// Creearea si gestionarea grupei 1 de studenti:
    list <Student> grupa_1;
    int nrStudenti_g1;
    cout<<"Numarul de studenti din grupa 1:"<<endl;
    cin >> nrStudenti_g1;
    creeare_lista_studenti( nrStudenti_g1, grupa_1 );

    afisare_lista_studenti( grupa_1);

    int nr_student_sters;
    cout<<" Al catelea student vreti sa fie sters: ";
    cin>>nr_student_sters;
    nr_student_sters--;

    if (nr_student_sters < nrStudenti_g1 && nr_student_sters >=0){
        stergere_student(nr_student_sters, grupa_1);
    }
    afisare_lista_studenti( grupa_1);
    cout<<endl;


     /// Creearea si gestionarea grupei 2 de studenti:
    list <Student> grupa_2;
    int nrStudenti_g2;
    cout<<"Numarul de studenti din grupa 2:"<<endl;
    cin >> nrStudenti_g2;
    creeare_lista_studenti( nrStudenti_g2, grupa_2 );

    afisare_lista_studenti( grupa_2);

    cout<<" Al catelea student vreti sa fie sters: ";
    cin>>nr_student_sters;
    nr_student_sters--;

    if (nr_student_sters < nrStudenti_g2 && nr_student_sters >=0){
        stergere_student(nr_student_sters, grupa_2);
    }
    afisare_lista_studenti( grupa_2);
    cout<<endl;

    ///Mutarea unui student:
    int numar_student_mutat;
    bool decizie;
    cout<<"Daca vreti sa mutati un student din grupa 1 in 2 scrieti 1, altfel 0: ";
    cin>> decizie;
    cout<<"Scrieti al catelea student din lista vreti sa fie mutat: ";
    cin>>numar_student_mutat;
    numar_student_mutat--;

    if(decizie && numar_student_mutat>=0){
        mutare_student(numar_student_mutat, grupa_1, grupa_2);
    }
    else if (numar_student_mutat>=0){
        mutare_student(numar_student_mutat, grupa_2, grupa_1);
    }
    cout<<"Grupa 1: \n";
    afisare_lista_studenti( grupa_1);
    cout<<endl<<"Grupa 2: \n";
    afisare_lista_studenti( grupa_2);
    cout<<endl;

    ///Modificare student


    int numar_student_modificat;
    numar_student_modificat--;
    cout<<" Al catelea student vreti sa fie modificat? \n";
    cin>> numar_student_modificat;

    editare_nume_student(numar_student_modificat, grupa_1);
    editare_varsta_student(numar_student_modificat, grupa_1);
    editare_cod_student(numar_student_modificat, grupa_1);

    afisare_lista_studenti(grupa_1);

    return 0;
}
