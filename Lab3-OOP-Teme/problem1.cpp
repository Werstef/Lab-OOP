#include <iostream>

using namespace std;

class Student{

private:
     int grade;

public:
    Student(){
        grade = 10;
    }
    Student(int grade){
        this->grade = grade;
    }
    setGrade(int grade){
        this->grade = grade;
    }
    int getGrade(){
        return this->grade;
    }

};


int main() {

    Student student1, *student2;

    student2 = new Student(6);


    cout << (*student2).getGrade() << endl;

    (*student2).setGrade(8);

    cout << (*student2).getGrade() << endl;


}
