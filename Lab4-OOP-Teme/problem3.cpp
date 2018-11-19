#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    int note;
    string name;
    Student* next;
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
    void setNext(Student* next){
        this->next = next;
    }
    Student* getNext(){
        return this->next;
    }
};

class StudentsGroup {
private:
    int studentsNumber;
    Student *student_group_head;
public:
    StudentsGroup(int studentsNumber){
        int i = 0;
        this->studentsNumber = studentsNumber;
        int note;
        string studentName;
        cout<<"student "<<i<<" name:";
        cin>>studentName;
        cout<<"note ";
        cin>>note;
        Student* head_student = new Student(note, studentName);
        student_group_head = head_student;

        Student* iterator_student = head_student;
        for(int i = 1; i < this->studentsNumber; i++){
            cout<<"student "<<i<<" name:";
            cin>>studentName;
            cout<<"note ";
            cin>>note;
            Student* new_student = new Student(note, studentName);
            new_student->setNext(NULL);
            iterator_student->setNext(new_student);
            iterator_student = iterator_student->getNext();

        }
        iterator_student = NULL;

    }

    void showStudentsInGroup(){
        int i = 0;
        Student* iterator_student = student_group_head;
        cout<<i<<" "<<iterator_student->getName()<<" "<<iterator_student->getNote()<<endl;
        for(int i=1; i < this->studentsNumber;i++){
            iterator_student = iterator_student->getNext();
            cout<<i<<" "<<iterator_student->getName()<<" "<<iterator_student->getNote()<<endl;
        }
    }

};

int main()
{
    StudentsGroup *studentsGroup = new StudentsGroup(2);
    studentsGroup->showStudentsInGroup();
    return 0;
}



