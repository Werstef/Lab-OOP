#include <iostream>
using namespace std;

class Student{

private:
     int grade;
public:
    static int number_of_instances ;
    Student(){
        grade = 10;
        number_of_instances++;
    }
    ~Student(){
        number_of_instances--;
        cout<< "Instance Destroyed" << endl;
    }
    setGrade(int grade){
        this->grade = grade;
    }
    int getGrade(){
        return this->grade;
    }

    int getNumberOfInstances(){
        return number_of_instances;
    }

};

int Student::number_of_instances = 0;

int main () {

    Student student1, student2;


    cout << student1.getNumberOfInstances() << endl;
    cout << student2.getNumberOfInstances() << endl;

    student1.~Student();

    cout << student2.getNumberOfInstances() << endl;

    return 0;

}


