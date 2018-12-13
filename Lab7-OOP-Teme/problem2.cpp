#include <iostream>
#include <string>

using namespace std;

class Student;

class Persoana{
public:
    string nume;
	Persoana() {};
    Persoana(string nume){
        this->nume = nume;
    }

};

class Sofer : public Persoana {
public:
	int an_permis = 0;
	Sofer(){};
    Sofer(string nume, int an_permis) : Persoana(nume){
		this->nume = nume;
		this->an_permis = an_permis;
	}
	friend class Student;
};

struct Grupa {
	string nume;
	int nr_studenti = 0;
	Student* head_student = nullptr;
};

class Student : public Persoana {
    public:
        int age;
        Student* next = nullptr;
        Sofer* sofer = new Sofer;

        Student(string nume, int age) : Persoana(nume){
            this->nume = nume;
            this->age = age;
			this->next = nullptr;
        }

        Student(string nume, int age, int an_permis) : Persoana(nume){
            this->nume = nume;
			this->sofer->an_permis = an_permis;
            this->age = age;
			this->next = nullptr;
        }

		static void addStudent(Grupa *& grupa) {
			string new_name;
			int new_age;
			cout << "Write the name of the new student: ";
			cin >> new_name;
			cout << "Write the age of the new student: ";
			cin >> new_age;
			bool decision;
			cout << "Type 1 if you wish to add a driver license for this student, else type 0: ";
			cin >> decision;
			if (decision) {
				int new_permis;
				cout << "Write the date of the new student's driver license: ";
				cin >> new_permis;
				Student* new_student = new Student(new_name, new_age, new_permis);
				grupa->nr_studenti++;
				if (grupa->head_student == nullptr) {
					grupa->head_student = new_student;
					return;
				}
				Student* iterator_student = grupa->head_student;
				while (iterator_student->next != nullptr) {
					iterator_student = iterator_student->next;
				}
				iterator_student->next = new_student;			
			}
			else {
				Student* new_student = new Student(new_name, new_age);
				grupa->nr_studenti++;
				if (grupa->head_student == nullptr) {
					grupa->head_student = new_student;
					return;
				}
				Student* iterator_student = grupa->head_student;
				while (iterator_student->next != nullptr) {
					iterator_student = iterator_student->next;
				}
				iterator_student->next = new_student;
			}
		}

		static void addStudent(Grupa *& grupa, string name, int age, int an_permis) {
			Student* new_student = new Student(name, age, an_permis);
			grupa->nr_studenti++;
			if (grupa->head_student == nullptr) {
				grupa->head_student = new_student;
				return;
			}
			Student* iterator_student = grupa->head_student;
			while (iterator_student->next != nullptr) {
				iterator_student = iterator_student->next;
			}
			iterator_student->next = new_student;
			grupa->nr_studenti++;
		}
	

		static void addStudent(Grupa *& grupa, string name, int age) {
			Student* new_student = new Student(name, age);
			grupa->nr_studenti++;
			if (grupa->head_student == nullptr) {
				grupa->head_student = new_student;
				return;
			}
			Student* iterator_student = grupa->head_student;
			while (iterator_student->next != nullptr) {
				iterator_student = iterator_student->next;
			}
			iterator_student->next = new_student;
			grupa->nr_studenti++;
		}
		

		static void displayGroup(Grupa *& grupa) {
			cout << endl;
			cout << "The group which will be displayed is " << grupa->nume << " and it has " << grupa->nr_studenti << " students " << endl;
			Student* iterator_student = grupa->head_student;
			while (iterator_student != nullptr) {
				if (iterator_student->sofer->an_permis != 0) {
					cout << "The student's name is " << iterator_student->nume << " and he/she is " << iterator_student->age << " and he/she has a driver license since " << iterator_student->sofer->an_permis << endl;
				}
				else {
					cout << "The student's name is " << iterator_student->nume << " and he/she is " << iterator_student->age << endl;
				}
				iterator_student = iterator_student->next;
			}
			cout << endl;
		}

		static void deleteStudent(Grupa *& grupa, string name) {
			Student* iterator_student = grupa->head_student;
			if (iterator_student->nume == name) {
				grupa->head_student = iterator_student->next;
				delete(iterator_student);
				return;
			}
			while (iterator_student->next->nume != name && iterator_student->next != nullptr) {
				iterator_student = iterator_student->next;
			}
			if (iterator_student->next == nullptr) {
				cout << endl;
				cout << "The student cannot be deleted as it has not been entered in the data base " << endl;
			}
			Student* aux_student = iterator_student->next;
			iterator_student->next = aux_student->next;
			aux_student->next = nullptr;
			delete(aux_student);
			cout << endl;
			cout << "The student has been successfully deleted" << endl;
			grupa->nr_studenti--;
		}

		static void changeGroupName(Grupa *& grupa){
			string new_nume;
			cout << "Type the new name for the group: ";
			cin >> new_nume;
			grupa->nume = new_nume;
			cout << "The name of the group has been successfully updated to " << grupa->nume << endl << endl;
		}

		static void moveStudent(Grupa *& grupa_src, Grupa *& grupa_dest, string name) {
			Student* iterator_student = grupa_src->head_student;
			if (iterator_student->nume == name) {
				grupa_src->head_student = iterator_student->next;
				if (iterator_student->sofer->an_permis != 0) {
					addStudent(grupa_dest, iterator_student->nume, iterator_student->age, iterator_student->sofer->an_permis);
				}
				else {
					addStudent(grupa_dest, iterator_student->nume, iterator_student->age);
				}
				delete(iterator_student);
				return;
			}
			while (iterator_student->nume != name && iterator_student != nullptr) {
				iterator_student = iterator_student->next;
			}
			if (iterator_student == nullptr) {
				cout << endl;
				cout << "The student cannot be deleted as it has not been entered in the data base " << endl;
				return;
			}
			if (iterator_student->nume == name) {
				if (iterator_student->sofer->an_permis != 0) {
					addStudent(grupa_dest, iterator_student->nume, iterator_student->age, iterator_student->sofer->an_permis);
				}
				else {
					addStudent(grupa_dest, iterator_student->nume, iterator_student->age);
				}
				deleteStudent(grupa_src, iterator_student->nume);
				return;
			}
			grupa_src->nr_studenti--;
			grupa_dest->nr_studenti++;
		}

 };

int main () {
	//Grupa 1.1
	Grupa* grupa1 = new Grupa;
	grupa1->nume = "1.1";
	int number_students;
	cout << "Write the number of students you want to add to the group" << endl;
	cin >> number_students;

	for (int i = 0; i < number_students; i++) {
		Student::addStudent(grupa1);
		cout << endl;
	}
	Student::displayGroup(grupa1);
	cout << endl;

	string deletedStudent;
	cout << "Write the name of the student you want to delete: ";
	cin >> deletedStudent;

	Student::deleteStudent(grupa1, deletedStudent);
	cout << endl;
	Student::displayGroup(grupa1);
	cout << endl;

	Student::changeGroupName(grupa1);


	//Grupa 1.2
	Grupa* grupa2 = new Grupa;
	grupa2->nume = "1.2";
	cout << "Write the number of students you want to add to the group" << endl;
	cin >> number_students;

	for (int i = 0; i < number_students; i++) {
		Student::addStudent(grupa2);
		cout << endl;
	}
	Student::displayGroup(grupa2);
	cout << endl;

	string moveName;
	cout << "Write the name of the student you wish to move from group 1 to group 2" << endl;
	cin >> moveName;

	Student::moveStudent(grupa1, grupa2, moveName);
	Student::displayGroup(grupa1);
	Student::displayGroup(grupa2);

	system("pause");
    return 0;
}
