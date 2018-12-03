#include <iostream>
#include <string>

using namespace std;

class Mecanism {
protected:
    string instructiuni;
    int viteza;
public:
    Mecanism(int viteza, string instructiuni){
        this->viteza = viteza;
        this->instructiuni = instructiuni;
    }
    void setInstructiuni(string instructiuni){
        this->instructiuni = instructiuni;
    }
    string getInstructiuni(){
        return this->instructiuni;
    }
    void setViteza(int viteza){
        this->viteza = viteza;
    }
    int getViteza(){
        return this->viteza;
    }
};

class MasinaDeCalcul {
protected:
    int viteza_de_calcul;
public:
	MasinaDeCalcul(int viteza_de_calcul) {
		this->viteza_de_calcul = viteza_de_calcul;
	}

	void setVitezaDeCalcul(int viteza_de_calcul) {
		this->viteza_de_calcul = viteza_de_calcul;
	}

	int getVitezaDeCalcul() {
		return this->viteza_de_calcul;
	}
};

class Computer : public MasinaDeCalcul{
protected:
    int memorie;
public:
    	Computer(int viteza_de_calcul, int memorie) : MasinaDeCalcul(viteza_de_calcul) {
		this->memorie = memorie;
	}

	void setMemorie(int memorie) {
		this->memorie = memorie;
	}

	int getMemorie() {
		return this->memorie;
	}
};

class Robot :public Mecanism, public Computer{
protected:
    string instructiuni_robot;
public:
    Robot(int viteza, string instructiuni, int viteza_de_calcul, int memorie, string instructiuni_robot) : Mecanism(viteza, instructiuni), Computer(viteza, memorie){
        this->instructiuni_robot = instructiuni_robot;
    }
    void setInstructiuniRobot(string instructiuni_robot){
        this->instructiuni_robot = instructiuni_robot;
    }
    string getInstructiuniRobot(){
        return this->instructiuni_robot;
    }
};

int main () {

    Robot *robot1 = new Robot(20, "citire, afisare", 30, 2000, "merge, opreste, viraj la stanga, viraj la dreapta");
    cout << "Our robot has the mecanisms with speed of " << robot1->getViteza() << " and that can do these instructions " << robot1->getInstructiuni() << endl;
    cout << "Our robot has the calculus speed of " << robot1->getVitezaDeCalcul() <<" and a memory of "<< robot1->getMemorie() << endl;
    cout << "In the end, our robot can do the following instructions " << robot1->getInstructiuniRobot();

    return 0;
}
