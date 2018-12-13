#include <iostream>
#include <string>

using namespace std;

class Plant{
public:
    int inaltime;
    Plant( int inaltime ){
        this->inaltime = inaltime;
    }
    virtual ~Plant(){
        cout<<"Planta a fost arsa \n";
    }
    int getInaltime(){
        return this->inaltime;
    }

    virtual bool eStricata() = 0;

};

class FoodSource{
public:
    int grasimi;
    FoodSource( int grasimi){
        this->grasimi = grasimi;

    }
    virtual ~FoodSource(){
        cout<<"Nu mancati carne!!! \n ";
    }

    int getGrasimi(){
        return this->grasimi;
    }
    virtual int getEnergie() = 0;


};

class Carrot: public Plant{
public:
    int calorii;
    Carrot(int calorii, int inaltime): Plant(inaltime){
        this->calorii = calorii;
        this->inaltime = inaltime;
    }

    int getCalorii(){
        return this->calorii;
    }

    virtual ~Carrot(){
        cout<<"mesaj: Morcov \n";
    }
    bool eStricata(){
        return ( getInaltime()<=7 );
    }

};

class Chicken: public FoodSource{
public:
    int greutate;

    Chicken(int greutate, int grasimi): FoodSource(grasimi){
        this->greutate = greutate;
        this->grasimi = grasimi;
    }
    virtual ~Chicken(){
        cout<<"Nu e de mancare!\n ";
    }

    int getGreutate(){
        return this->greutate;
    }

    int getEnergie(){
        return getGreutate()*getGrasimi();
    }

};


class Apple: public Plant, public FoodSource{
public:
    int vitamine;
    Apple (int vitamine, int inaltime, int grasimi): Plant(inaltime), FoodSource(grasimi){
        this->inaltime =  inaltime;
        this->vitamine =  vitamine;
        this->grasimi  = grasimi;
    }
    int getVitamine (){
        return this->vitamine;
    }

    bool eStricata(){
        return ( getVitamine () <=4 );
    }

    int getEnergie(){
        return getVitamine()*getGrasimi();
    }

    virtual ~Apple(){
        cout<<"An apple a day keeps the doctor away \n";
    }

};

int main (){
    cout<<"Greuatea este in grame, inaltimea in cm! \n";

    Carrot* morcov = new Carrot(100, 40);
    Chicken* kfc = new Chicken(150, 300);
    Apple* mar = new Apple(20, 5, 15);

    FoodSource* sursa= kfc;
    Plant* planta = morcov;

    cout<<sursa->getEnergie()<<endl;
    if(planta->eStricata())
        cout<< "Planta e stricata :("<<endl;
    else
        cout<<"Planta nu e stricata :)"<<endl;

    delete sursa;
    delete planta;

    sursa= mar;

    cout<<endl<<sursa->getEnergie()<<endl;
    if(mar->eStricata())
        cout<< "Planta e stricata :("<<endl;
    else
        cout<<"Planta nu e stricata :)"<<endl;

    return 0;

}

