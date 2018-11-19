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

bool alegere(){
    bool alegere1;
    cout << "Write 1 if you want to compare the names or 0 if you want to compare the marks" << endl;
    cin >> alegere1;
    return alegere1;
}

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
                cout<<"student "<<i<<" name:";
                cin>>studentName;
                cout<<"note ";
                cin>>note;
                studentsList[i] = Student(note, studentName);
        }
    }

    void bubble_sort(){
        int i, j;
        if(alegere()){
            for (i = 0; i < studentsNumber-1; i++)
                for (j = 0; j < studentsNumber-i-1; j++)
                    if (studentsList[j].getName() > studentsList[j+1].getName())
                        swap(studentsList[j], studentsList[j+1]);
        }
        else{
            for (i = 0; i < studentsNumber-1; i++)
                for (j = 0; j < studentsNumber-i-1; j++)
                    if (studentsList[j].getNote() > studentsList[j+1].getNote())
                        swap(studentsList[j], studentsList[j+1]);
        }
    }
};

int main()
{
    StudentsGroup *studentsGroup = new StudentsGroup(3);
    studentsGroup->readStudentGroup();
    studentsGroup->showStudentsInGroup();
    studentsGroup->bubble_sort();
    studentsGroup->showStudentsInGroup();
    return 0;
}



