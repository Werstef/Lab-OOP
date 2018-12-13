#include <iostream>
#include <string>

using namespace std;

class Weapon{
public:
    string nume;
    Weapon( string nume ){
        this->nume = nume;
    }
    virtual ~Weapon(){
        cout<<"Arma a fost distrusa \n";
    }
    string getNume(){
        return this->nume;
    }

    virtual void nu_exista() = 0;

    virtual string tip_arma() =0;

};

class Sling : public Weapon{
public:
    string material;

    Sling( string nume, string material): Weapon (nume){
        this->nume =  nume;
        this->material = material;
    }

    virtual ~Sling (){
        cout<<"Prastia a fost distrusa \n";
    }

    string getMaterial(){
        return this->material;
    }

    void nu_exista(){
        if( material != "plastic" && material != "lemn" )
            cout<<"Nu e buna! \n";
        else
            cout<<"Este performanta \n";
    }

    string tip_arma(){
        return this->nume;
    }

};

class AtomicBomb : public Weapon{
public:
    int putere;
    AtomicBomb( string nume, int putere ): Weapon(nume){
        this->nume = nume;
        this->putere = putere;
    }
    virtual ~AtomicBomb(){
        cout<<"Bomba atomica a fost distrusa \n";
    }
    string getNume(){
        return this->nume;
    }
    int getPutere(){
        return this->putere;
    }

    void nu_exista(){
        if( getPutere() >= 1000)
            cout<<"Nu exista \n";
        else
            cout<<"Exista \n";
    }

    string tip_arma(){
        return getNume();
    }

};

class Gun : public Weapon{ ///abstracta
public:
    int calibru;
    Gun(string nume, int calibru): Weapon(nume){
        this->nume =  nume;
        this->calibru = calibru;
    }

    virtual ~Gun(){
        cout<<"Arma de foc a fost distrusa \n";
    }

    int getCalibru(){
        return this->calibru;
    }

    virtual bool calibru_inexistent() = 0;

};

class Rifle : public Gun{
public:
    int an_fabricatie;

    Rifle (string nume, int calibru, int an_fabricatie): Gun(nume,calibru){
        this->an_fabricatie = an_fabricatie;
        this->nume =  nume;
        this->calibru = calibru;
    }

    virtual ~Rifle (){
        cout<<"Pusca a fost distrusa \n";
    }

    int getAnFabricatie(){
        return this->an_fabricatie;
    }

    bool calibru_inexistent(){
        return (getCalibru() >=100);
    }

    string tip_arma(){
        return getNume();
    }

    void nu_exista(){
        if(getAnFabricatie() <= 1800)
            cout<<"E prea veche \n";
        else
            cout<<"Pusca este corespunzatoare \n";
    }

};

class MachineGun : public Rifle{
public:

    int cartuse_minut;

    MachineGun (int cartuse_minut, string nume, int calibru, int an_fabricatie): Rifle(nume,calibru,an_fabricatie){
        this->nume =  nume;
        this->calibru = calibru;
        this->an_fabricatie = an_fabricatie;
        this->cartuse_minut = cartuse_minut;
    }

    virtual ~MachineGun(){
        cout<<"Mitraliera a fost distrusa \n";
    }

    int getCartuseMinut (){
        return this->cartuse_minut;
    }

    void nu_exista(){
        if(getCartuseMinut() >= 1000)
            cout<<"E prea rapida \n";
        else
            cout<<"Mitraliera este corespunzatoare \n";
    }



};

int main(){

    cout<<"Calibrul este in milimetrii \n";

    Sling* prastie = new Sling("prastie", "hartie");
    AtomicBomb* bomba_atomica = new AtomicBomb ("bomba", 20000);
    Rifle* pusca =  new Rifle ("Kar98k", 8, 1936 );
    MachineGun* mitraliera = new MachineGun (100,"UMP48", 9, 1985);

    Weapon* arma_1 = prastie;
    Weapon* arma_2 = bomba_atomica;

    Gun* arma_3 = pusca;
    Gun* arma_4 = mitraliera;

    cout<<endl;

    arma_1->nu_exista();
    cout<<arma_1->tip_arma()<<endl;
    delete arma_1;

    cout<<endl;

    arma_2->nu_exista();
    cout<<arma_2->tip_arma()<<endl;
    delete arma_2;

    cout<<endl;

    arma_3->nu_exista();
    cout<<arma_3->tip_arma()<<endl;
    cout<<arma_3->calibru_inexistent()<<endl;
    delete arma_3;

    cout<<endl;

    arma_4->nu_exista();
    cout<<arma_4->tip_arma()<<endl;
    cout<<arma_4->calibru_inexistent()<<endl;
    delete arma_4;


    return 0;

}

