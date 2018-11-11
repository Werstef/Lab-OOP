#include <iostream>
using namespace std;

class Student{

private:
     int grade;
     Student(int x){
        grade = 8;
     }

public:
    Student(){
        Student(6);
    }
    setGrade(int grade){
        this->grade = grade;
    }
    int getGrade(){
        return this->grade;
    }

};



int main () {

    Student student1;


    cout << student1.getGrade() << endl ;

}
