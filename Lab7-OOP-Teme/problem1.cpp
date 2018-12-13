#include <iostream>
#include <string>

using namespace std;


class Persoana{
    protected:
        string name;
        int age;
    public:
        Persoana(string name, int age){
            this->name = name;
            this->age = age;
        }
        void setName(string name){
            this->name = name;
        }
        string getName(){
            return this->name;
        }
        void setAge(int age){
            this->age = age;
        }
        int getAge(){
            return this->age;
        }
    };

class Sofer : public Persoana{
    protected:
        int an_eliberare_permis;
    public:
        Sofer* next_sofer = nullptr;
        static Sofer* head_sofer;
        Sofer(string name, int age, int an_eliberare_permis) : Persoana(name, age){
            this->name = name;
            this->age = age;
            this->an_eliberare_permis = an_eliberare_permis;
            this->next_sofer = nullptr;
        }

        void setAnPermis(int an_eliberare_permis){
            this->an_eliberare_permis = an_eliberare_permis;
        }
        int getAnPermis(){
            return this->an_eliberare_permis;
        }

         static void addSofer(Sofer *& head_sofer){
            string new_name;
            cout << "Write the name of the new driver: ";
            cin >> new_name;
			int new_age;
            cout << "Write the age of the new driver: ";
            cin >> new_age;
            int driver_license;
            cout <<"Write the year when the driver got his license: ";
            cin >> driver_license;
            Sofer* new_sofer = new Sofer(new_name, new_age, driver_license);
            Sofer* iterator_sofer = head_sofer;
            if(iterator_sofer == nullptr){
                head_sofer = new_sofer;
                return;
            }
            else{
                while(iterator_sofer->next_sofer != nullptr){
                    iterator_sofer = iterator_sofer->next_sofer;
                }
                iterator_sofer->next_sofer = new_sofer;
            }
        }

         static void deleteSofer(Sofer *& head_sofer, string name) {
            Sofer* iterator_sofer = head_sofer;
            if (head_sofer->getName() == name){
                head_sofer = head_sofer->next_sofer;
                delete(iterator_sofer);
                cout <<"The driver has been successfully deleted" << endl;
                return;
            }
            while(iterator_sofer->next_sofer->getName() != name && iterator_sofer->next_sofer != nullptr){
                iterator_sofer = iterator_sofer->next_sofer;
            }
			if (iterator_sofer->next_sofer == nullptr) {
				cout << endl;
				cout << "The driver cannot be deleted as it has not been entered in the data base " << endl;
				return;
			}
            Sofer* aux_sofer = iterator_sofer->next_sofer;
            iterator_sofer->next_sofer = aux_sofer->next_sofer;
            aux_sofer->next_sofer = nullptr;
            delete(aux_sofer);
			cout << endl;
            cout <<"The driver has been successfully deleted" << endl;
        }

         static void displaySofer(Sofer *& head_sofer){
            Sofer* iterator_sofer = head_sofer;
            while(iterator_sofer != nullptr){
                cout <<"The name of the driver is " << iterator_sofer->getName() << " and is " << iterator_sofer->getAge() <<" old and has a driver license since "<< iterator_sofer->getAnPermis() << endl;
                iterator_sofer = iterator_sofer->next_sofer;
            }
			cout << endl;
        }
    };

Sofer* Sofer::head_sofer = nullptr;


class Angajat: public Sofer{
    protected:
        string job;
    public:
        Angajat* next_angajat = nullptr;
        static Angajat* head_angajat;

        Angajat(string name, int age, int an_eliberare_permis, string job) : Sofer(name, age, an_eliberare_permis){
            this->name = name;
            this->age = age;
            this->an_eliberare_permis = an_eliberare_permis;
            this->job = job;
			this->next_angajat = nullptr;
        }

        void setJob(string job){
            this->job = job;
        }
        string getJob(){
            return this->job;
        }

         static void addAngajat(Angajat *& head_angajat) {
            string new_name;
            int new_age;
            int new_permis;
			string job;
            cout << "Write the name of the new employee: ";
            cin >> new_name;
            cout << "Write the age of the new employee: ";
            cin >> new_age;
            cout << "Write the date of the new employee's driver license: ";
            cin >> new_permis;
			cout << "Write the job that the new employee has: ";
			cin >> job;

            Angajat* new_angajat = new Angajat(new_name, new_age, new_permis, job);
            Angajat* iterator_angajat = head_angajat;

            if(iterator_angajat == nullptr){
                head_angajat = new_angajat;
                return;
            }
            else{
                while(iterator_angajat->next_angajat != nullptr){
                    iterator_angajat = iterator_angajat->next_angajat;
                }
                iterator_angajat->next_angajat = new_angajat;
            }
        }

         static void deleteAngajat(Angajat *& head_angajat, string name){
            Angajat* iterator_angajat = head_angajat;
            if (head_angajat->getName() == name){
                head_angajat = head_angajat->next_angajat;
                delete(iterator_angajat);
                return;
            }
            while(iterator_angajat->next_angajat->getName() != name && iterator_angajat->next_angajat != nullptr){
                iterator_angajat = iterator_angajat->next_angajat;
            }
			if (iterator_angajat->next_angajat == nullptr) {
				cout << endl;
				cout << "The employee cannot be deleted as it has not been entered in the data base " << endl;
				return;
			}
            Angajat* aux_angajat = iterator_angajat->next_angajat;
            iterator_angajat->next_angajat = aux_angajat->next_angajat;
            aux_angajat->next_angajat = nullptr;
            delete(aux_angajat);
			cout << endl;
            cout <<"The employee has been successfully deleted" << endl;
        }

         static void displayAngajati(Angajat *& head_angajat)  {
            Angajat* iterator_angajat = head_angajat;
            while(iterator_angajat != nullptr){
                cout <<"The name of the employee is " << iterator_angajat->getName() << " and is " << iterator_angajat->getAge() <<" old and has a driver license since "<< iterator_angajat->getAnPermis() << endl;
                cout <<"He/She works as a/an "<< iterator_angajat->getJob()<< endl;
                iterator_angajat = iterator_angajat->next_angajat;
            }
			cout << endl;
        }

    };

 Angajat* Angajat::head_angajat = nullptr;

class Parinte: public Angajat{
    public:
        int number_kids;
        class Copil : public Persoana{
        protected:
            string favourite_color;
        public:
            Copil* next_copil = nullptr;
            Copil(string name, int age, string favourite_color) : Persoana(name, age){
                this->name = name;
                this->age = age;
                this->favourite_color = favourite_color;
				this->next_copil = nullptr;
            }
            void setColor(string favourite_color){
                this->favourite_color = favourite_color;
            }
            string getColor(){
                return this->favourite_color;
            }

			static void displayCopii(Copil *& head_copil){
                Copil* iterator_copil = head_copil;
                while(iterator_copil != nullptr){
                    cout <<"The name of the child is " << iterator_copil->getName() <<" and he is " << iterator_copil->getAge() <<" years old." << endl;
                    cout <<"His/Her favorite color is " << iterator_copil->getColor();
					iterator_copil = iterator_copil->next_copil;
                }

            }

        };

        Copil* head_copil = nullptr;
        Parinte* next_parinte = nullptr;
        static Parinte* head_parinte;

        Parinte(string name, int age, int an_eliberare_permis, string job, int number_kids) : Angajat(name, age, an_eliberare_permis, job){
            this->name = name;
            this->age = age;
            this->an_eliberare_permis = an_eliberare_permis;
            this->job = job;
            this->number_kids = number_kids;
			this->next_parinte = nullptr;
        }

        static void addChildren(int number_kids, Copil *& head_copil){
            cout << "You will now add the children of this parent, you will add "  << number_kids <<" children" << endl << endl;
            string new_name;
            int new_age;
            string new_color;
            cout << "Write the name of the new child: ";
            cin >> new_name;
            cout << "Write the age of the new child: ";
            cin >> new_age;
            cout << "Write the favorite color of the new child: ";
            cin >> new_color;
            cout << endl;
            Copil* new_copil = new Copil(new_name, new_age, new_color);
            head_copil = new_copil;
            Copil* iterator_copil = head_copil;
            for(int i = 1; i < number_kids; i++){
                cout << "Write the name of the new child: ";
                cin >> new_name;
                cout << "Write the age of the new child: ";
                cin >> new_age;
                cout << "Write the favorite color of the new child: ";
                cin >> new_color;
                cout << endl;
                Copil* new_copil = new Copil(new_name, new_age, new_color);
                iterator_copil->next_copil = new_copil;
                iterator_copil = iterator_copil->next_copil;
            }
        }

        static void addParinte(Parinte *& head_parinte){
            string new_name;
            int new_age;
            int new_permis;
            string new_job;
			int number_kids;
            cout << "Write the name of the new parent: ";
            cin >> new_name;
            cout << "Write the age of the new parent: ";
            cin >> new_age;
            cout << "Write the date of the new parent's driver license: ";
            cin >> new_permis;
            cout << "Write the job where this parent works: ";
            cin >> new_job;
			cout << "Write the number of kids this parent has: ";
			cin >> number_kids;
            Parinte* new_parinte = new Parinte(new_name, new_age, new_permis, new_job, number_kids);
            if(head_parinte == nullptr){
                head_parinte = new_parinte;
            }
            else{
                Parinte* iterator_parinte = head_parinte;
                while(iterator_parinte->next_parinte != nullptr){
                    iterator_parinte = iterator_parinte->next_parinte;
                }
                iterator_parinte->next_parinte = new_parinte;
            }
			new_parinte->addChildren(number_kids, new_parinte->head_copil);
        }

        static void displayParents(Parinte *& head_parinte){
            Parinte* iterator_parinte = head_parinte;
            while(iterator_parinte != nullptr){
                cout <<"The name of the parent is " << iterator_parinte->getName() << " and is " << iterator_parinte->getAge() <<" old and has a driver license since "<< iterator_parinte->getAnPermis() << endl;
                cout <<"He/She works as a/an "<< iterator_parinte->getJob() << " and he/she has " << iterator_parinte->number_kids << " child/children " << endl;
				iterator_parinte = iterator_parinte->next_parinte;
			}
        }

        static void displayKids(Parinte *& head_parinte){
            Parinte* iterator_parinte = head_parinte;
            while(iterator_parinte != nullptr){
				Copil::displayCopii(iterator_parinte->head_copil);
                iterator_parinte = iterator_parinte->next_parinte;
            }
        }

    };

Parinte* Parinte::head_parinte = nullptr;

int main () {
	// Soferi
    int number_drivers;
    cout << "Write the number of drivers you want to add" << endl;
    cin >> number_drivers;

    for(int i = 0; i < number_drivers; i++){
        Sofer::addSofer(Sofer::head_sofer);
		cout << endl;
    }
    Sofer::displaySofer(Sofer::head_sofer);
	cout << endl;

	string deletedDriver;
	cout << "Write the name of the driver you want to delete: ";
	cin >> deletedDriver;

	Sofer::deleteSofer(Sofer::head_sofer, deletedDriver);
	cout << endl;
	Sofer::displaySofer(Sofer::head_sofer);
	cout << endl;

	// Angajati
	int number_employees;
	cout << "Write the number of employees you want to add" << endl;
	cin >> number_employees;

	for (int i = 0; i < number_employees; i++) {
		Angajat::addAngajat(Angajat::head_angajat);
		cout << endl;
	}
	Angajat::displayAngajati(Angajat::head_angajat);
	cout << endl;

	string deletedEmployee;
	cout << "Write the name of the employee you want to delete: ";
	cin >> deletedEmployee;

	Angajat::deleteAngajat(Angajat::head_angajat, deletedEmployee);
	cout << endl;
	Angajat::displayAngajati(Angajat::head_angajat);
	cout << endl;

	// Patinti, Copii
	int number_parents;
	cout << "Write the number of parents you want to add" << endl;
	cin >> number_parents;

	for (int i = 0; i < number_parents; i++) {
		Parinte::addParinte(Parinte::head_parinte);
		cout << endl;
	}
	Parinte::displayParents(Parinte::head_parinte);
	cout << endl;
	Parinte::displayKids(Parinte::head_parinte);
	cout << endl;




	system("pause");

    return 0;
}
