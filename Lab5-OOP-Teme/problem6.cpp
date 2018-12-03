#include <iostream>
#include <string>

using namespace std;

class Desert{
protected:
	string nume;
	int nrCalorii;
public:

	Desert(string nume, int nrCalorii) {
		this->nume = nume;
		this->nrCalorii = nrCalorii;
	}

	void setNume(string nume) {
		this->nume = nume;
	}

	void setNrCalorii(int nrCalorii) {
		this->nrCalorii = nrCalorii;
	}

	string getNume() {
		return this->nume;
	}

	int getNrCalorii() {
		return this->nrCalorii;
	}

	void ModPreparare() {
		cout << "You put things in the oven and hope they don't burn" << endl;
	}
};

class Prajitura:public Desert {
protected:
    	string ingrediente;
public:
	Prajitura(string nume, int nrCalorii, string ingrediente) : Desert(nume, nrCalorii) {
		this->ingrediente = ingrediente;
	}

	void setIngrediente(string ingrediente) {
		this->ingrediente = ingrediente;
	}

	string getIngrediente() {
		return this->ingrediente;
	}

	void ModPreparare() {
		cout << "You put the cake in the oven and hope it doesn't burn" << endl;
	}
};

class Briosa :public Prajitura {
protected:
    string forma;
public:
	Briosa(string nume, int nrCalorii, string ingrediente, string forma) : Prajitura(nume, nrCalorii, ingrediente) {
		this->forma = forma;
	}

	void setForma(int forma) {
		this->forma = forma;
	}

	string getForma() {
		return this->forma;
	}
    void ModPreparare() {
		cout << "You put the muffin in the oven and hope it doesn't burn" << endl;
	}
};

class Tort :public Desert {
protected:
    string ingrediente;
public:
	void setIngrediente(string ingrediente) {
		this->ingrediente = ingrediente;
	}

	void ModPreparare() {
		cout <<"You put the second cake in the oven and hope it doesn't burn "<< endl;
	}

	string getIngrediente() {
		return this->ingrediente;
	}
};

int main(){
	Desert *desert1 = new Desert("Tiramisu", 1020);
	cout << "The name of the desert we want to prepare is " << desert1->getNume() << endl;
	cout << "The number of its calories is " << desert1->getNrCalorii() << endl;
	desert1->ModPreparare();
	cout << endl;

	Prajitura *prajitura1 = new Prajitura("Prajitura Buturuga", 2060, "Faina, lapte, unt, oua, cacao, ciocolata, oleaca tuica");
	cout << "The name of the cake we want to prepare is " << prajitura1->getNume() << endl;
	cout << "The number of its calories is " << prajitura1->getNrCalorii() << endl;
	cout << "The list of ingredients for our cake is " << prajitura1->getIngrediente() << endl;
	prajitura1->ModPreparare();
    cout << endl;

	Briosa *briosa1 = new Briosa("Briosa Pavlova", 1520, "Faina, Lapte, Oua, Cacao, Vanilie, Scortisoara", "Rotunda");
	cout << "The name of the muffin we want to prepare is " << briosa1->getNume() << endl;
	cout << "The number of its calories is " << briosa1->getNrCalorii() << endl;
	cout << "The list of ingredients for our muffin is " << briosa1->getIngrediente() << endl;
	cout << "The shape of our muffin is " << briosa1->getForma() << endl;
	briosa1->ModPreparare();
}
