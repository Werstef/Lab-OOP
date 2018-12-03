#include <iostream>
using namespace std;

class Student{

private:
    int grade;
    char* last_name;
    char* first_name;
    int group;
    Curs* list_curses;
    Student* next;
public:
    static int number_of_instances ;
    Student(){
        grade = 10;
        number_of_instances++;
    }
    Student(int grade){
        this->grade = grade;
        number_of_instances++;
    }
    ~Student(){
       /* number_of_instances--; */
        cout<< "Instance Destroyed" << endl;
    }
    setGrade(int grade){
        this->grade = grade;
    }
    int getGrade(){
        return this->grade;
    }
    setNext(Student* next){
        this->next = next;
    }

    Student* getNext(){
        return this->next;
    }

    setLastName(char* last_name){
        this->last_name = last_name;
    }

    char* getLastName(){
        return this->last_name;
    }

    setFirstName(char* first_name){
        this->first_name = first_name;
    }

    char* getFirstName(){
        return this->first_name;
    }

    setGroup(int group){
        this->group = group;
    }

    int getGroup(){
        return this->group;
    }

    Curs* getListCurses(){
        return this->list_curses;
    }

};

class Curs{
private:
    char* name;
    char* profesor;
    Student* list_members;
    Curs* next
public:

    setName(char* name){
        this->name = name;
    }

    char* getName(){
        return this->name;
    }

    setProfesor(char* profesor){
        this->profesor = profesor;
    }

    char* getProfesor(){
        return this->profesor;
    }

    Student* getListMembers(){
        return this->list_members;
    }

};

void create_list_student(){

    cout<<"Type the number of instances you want to create" << endl;
    int number_list_members;
    cin>> number_list_members;

    Student* iterator_list;

    cout<<"Write the grade for the student" << endl;
    int grade_student;
    cin >> grade_student;

    cout<<"Write the Last name of the student" << endl;
    char* student_first_name;
    cin >> student_first_name;

    cout<<"Write the First Name of the student" << endl;
    char* student_last_name;
    cin >> student_last_name;

    cout<<"Write the Group of the student" << endl;
    int group;
    cin >> group;

    Student* head_student = new Student(grade_student);
    head_student->setNext(NULL);
    head_student->setLastName(student_last_name);
    head_student->setFirstName(student_first_name);
    head_student->setGroup(student_group);
    iterator_list = head_student;
//continuare functie
    for(int iterator = 0; iterator < number_list_members - 1; iterator++){

        cout<<"Write the grade for the student" << endl;
        int grade_student;
        cin >> grade_student;


        Student* new_student = new Student(grade_student);

        if(iterator == 0){
            head_student->setNext(new_student);
        }
        else{
            iterator_list->setNext(new_student);

        }

        new_student->setNext(NULL);
        iterator_list = new_student;
    }

}

void display_list_student(Student* head_student, int number_list_members){

    Student* iterator_list = head_student;

    while(1 > 0){
        int starting_position;
        cout << "Alege de la al catelea nod sa inceapa afisarea"<< endl ;
        cin >> starting_position;
        cout << endl ;
        if( starting_position > number_list_members){
            cout << "Ati dat un numar mai mare decat numarul de componente al listei, incercati din nou" << endl;
            continue;
        }
        for(int iterator = 0; iterator < starting_position - 1; iterator ++){
            iterator_list = iterator_list->getNext();
        }
        for(int iterator = 0; iterator <  number_list_members ; iterator ++){
            cout << iterator_list->getGrade() << " ";
            iterator_list = iterator_list->getNext();
        }
        for(int iterator = 0; iterator <= number_list_members - starting_position; iterator ++){
            iterator_list = iterator_list->getNext();
        }
        cout << endl;
    }
}

int Student::number_of_instances = 0;

int main () {


    cout<<"Type the number of instances you want to create" << endl;
    int number_list_members;
    cin>> number_list_members;

    Student* iterator_list;

    cout<<"Write the grade for the student" << endl;
    int grade_student;
    cin >> grade_student;

    Student* head_student = new Student(grade_student);
    head_student->setNext(NULL);
    iterator_list = head_student;

    for(int iterator = 0; iterator < number_list_members - 1; iterator++){

        cout<<"Write the grade for the student" << endl;
        int grade_student;
        cin >> grade_student;


        Student* new_student = new Student(grade_student);

        if(iterator == 0){
            head_student->setNext(new_student);
        }
        else{
            iterator_list->setNext(new_student);

        }

        new_student->setNext(NULL);
        iterator_list = new_student;
    }

    iterator_list->setNext(head_student);
    display_list(head_student, number_list_members);

    return 0;
}


