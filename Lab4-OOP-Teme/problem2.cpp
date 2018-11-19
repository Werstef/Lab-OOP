#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    int note;
    string name;
public:
    Student(int note = 0, string name="Joe Doe"){
        this->note = note;
        this->name = name;
    }
    void setNote(int n){
        this->note = n;
    }
    int getNote(){
        return this->note;
    }
    string getName(){
        return this->name;
    }
    void setName(string name){
        this->name = name;
    }
};

class StudentsGroup {
private:
    int studentsNumber;
    Student *studentsList;
public:
    StudentsGroup(int studentsNumber){
        this->studentsNumber = studentsNumber;
        studentsList = new Student[studentsNumber];
    }
    void showStudentsInGroup(){
        for(int i=0; i<this->studentsNumber;i++){
            cout<<i<<" "<<studentsList[i].getName()<<" "<<studentsList[i].getNote()<<endl;
        }
    }
    void readStudentGroup(){
        int note;
        string studentName;
        for(int i=0; i<this->studentsNumber;i++){
                cout<<"student "<<i<<" name: ";
                cin>>studentName;
                cout<<"note ";
                cin>>note;
                studentsList[i] = Student(note, studentName);
        }
    }

	void add_student() {
		this->studentsNumber ++;
		Student* studentsList_aux = new Student[studentsNumber];
		for (int i = 0; i < this->studentsNumber - 1; i++) {
			studentsList_aux[i] = studentsList[i];
		}
		int note;
		string studentName;
		cout << "Write the details of the student you want to add" << endl;
		cout << "student " << studentsNumber - 1 << " name: ";
		cin >> studentName;
		cout << "note ";
		cin >> note;
		studentsList_aux[studentsNumber - 1] = Student(note, studentName);
		delete[] studentsList;
		this->studentsList = studentsList_aux;
    }
};

int main()
{
    StudentsGroup *studentsGroup = new StudentsGroup(1);
    studentsGroup->readStudentGroup();
    studentsGroup->showStudentsInGroup();
    studentsGroup->add_student();
    studentsGroup->showStudentsInGroup();
    return 0;
}


