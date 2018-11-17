#include <iostream>
using namespace std;

class Student{

private:
    int grade;
    char* last_name;
    char* first_name;
    int group;
    int* array_of_courses;
    Student* next;
public:

    static int number_of_instances ;
    Student(){

        number_of_instances++;
    }
    Student(int grade){
        this->grade = grade;
        number_of_instances++;
    }
    ~Student(){
        number_of_instances--;
        ///cout<< "Instance Destroyed" << endl;
    }
    void setGrade(int grade){
        this->grade = grade;
    }
    int getGrade(){
        return this->grade;
    }
    void setNext(Student* next){
        this->next = next;
    }

    Student* getNext(){
        return this->next;
    }

    void setLastName(char* last_name){
        this->last_name = last_name;
    }

    char* getLastName(){
        return this->last_name;
    }

    void setFirstName(char* first_name){
        this->first_name = first_name;
    }

    char* getFirstName(){
        return this->first_name;
    }

    void setGroup(int group){
        this->group = group;
    }

    int getGroup(){
        return this->group;
    }

///    Curs* getListCourses(){
        return this->list_courses;
    }

///    void addCursToList(Curs *curs){

    }

};

class Curs{
private:
    int cod_course;
    char* name;
    char* profesor;
    Student* list_members;
    Curs* next;
public:

    void setName(char* name){
        this->name = name;
    }

    char* getName(){
        return this->name;
    }

    bool compareName(char* name){
        if(this->name == name){
            return true;
        }
        return false;
    }

    void setProfesor(char* profesor){
        this->profesor = profesor;
    }

    char* getProfesor(){
        return this->profesor;
    }

    void setNext(Curs* next){
        this->next = next;
    }

    Curs* getNext(){
        return this->next;
    }

 ///   Student* getListMembers(){
        return this->list_members;
    }

 ///   void addStudentToList(Student *student){
    ****
    }

};

Student* create_list_student(Curs* head_course){

    cout<<"Type the number of students you want to add" << endl;
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

    cout<<"How many courses does the student go to?" << endl;
    int number_of_courses;
    cin >> number_of_courses;
    for(int iterator = 0; iterator < number_of_courses; iterator ++){
        cout << "Write the course that the student goes to" << endl;
        char* course;
        cin >> course;
        bool course_attended;
        Curs* iterator_list_courses;
        iterator_list_courses = head_list_courses;
        for(int iterator = 0; iterator < existing_courses; iterator++){
            if(iterator_list_courses->compareName(course)){
                head_student->
                head_student->addCursToList(iterator_list_courses);
                iterator_list_courses = head_course;
                break;
            }
            iterator_list_courses = iterator_list_courses->getNext();
        }

    }



    iterator_list = head_student;
    for(int iterator = 0; iterator < number_list_members - 1; iterator++){

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
        int student_group;
        cin >> student_group;


        Student* new_student = new Student(grade_student);

        iterator_list->setNext(new_student);

        new_student->setNext(NULL);
        new_student->setLastName(student_last_name);
        new_student->setFirstName(student_first_name);
        new_student->setGroup(student_group);

        cout<<"How many courses does the student go to?" << endl;
        int number_of_courses;
        cin >> number_of_courses;
        for(int iterator = 0; iterator < number_of_courses; iterator ++){
            cout << "Write the course that the student goes to" << endl;
            char* course;
            cin >> course;
            bool course_attended;
            Curs* iterator_list_courses;
            iterator_list_courses = head_list_courses;
            for(int iterator = 0; iterator < existing_courses; iterator++){
                if(iterator_list_courses->compareName(course)){
                    iterator_list_courses->addStudentToList(new_student);
                    new_student->addCursToList(iterator_list_courses);
                    iterator_list_courses = head_course;
                    break;
                }
                iterator_list_courses = iterator_list_courses->getNext();
            }

        }

        iterator_list = new_student;
    }

    return head_student;
}

void delete_student(char* last_name, Student* head_student){

    Student* iterator_list_student = new Student();
    Student* previous_list_student = new Student();
    previous_list_student = head_student;
    iterator_list_student = head_student;

    while(iterator_list_student != NULL){
        if(iterator_list_student->getLastName() == last_name){
                if(iterator_list_student == head_student){
                    head_student = iterator_list_student->getNext();
                    delete(iterator_list_student);
                }
                else{
                    previous_list_student->setNext(iterator_list_student->getNext());
                    iterator_list_student->setNext(NULL);
                    free(iterator_list_student);
                }
        if(iterator_list_student != head_student){
            previous_list_student = previous_list_student->getNext();
        }

        }
    }
    delete(previous_list_student);

}

void edit_student(char* last_name, Student* head_student){

    Student* iterator_list_student = new Student();
    iterator_list_student = head_student;

    while(iterator_list_student != NULL){
        if(iterator_list_student->getLastName() == last_name){
            cout<<"Write the new Last Name of the student" << endl;
            char* last_name_modified;
            cin >> last_name_modified;

            cout<<"Write the new First Name of the student" << endl;
            char* first_name_modified;
            cin >> first_name_modified;

            cout<<"Write the new Group of the student" << endl;
            int group_modified;
            cin >> group_modified;

            cout<<"Write the new Grade of the student" << endl;
            int grade_modified;
            cin >> grade_modified;

            iterator_list_student->setFirstName(first_name_modified);
            iterator_list_student->setLastName(last_name_modified);
            iterator_list_student->setGroup(group_modified);
            iterator_list_student->setGrade(grade_modified);
            return;
        }
        iterator_list_student = iterator_list_student->getNext();
    }
}

Curs* crerate_list_courses(){

    cout << "Write the number of courses for this year" << endl;
    int number_of_courses;
    cin >> number_of_courses;

    Curs* head_course = new Curs();
    head_course->setNext(NULL);

    cout<< "Write the name of the course" << endl;
    char* course_name;
    cin >> course_name;

    cout << "Write the name of the teacher" << endl;
    char* prof_name;
    cin >> prof_name;

    head_course->setName(course_name);
    head_course->setProfesor(prof_name);

    Curs* iterator_courses = head_course;

    for(int iterator = 0; iterator < number_of_courses - 1; iterator++){
        Curs* new_course = new Curs();
        new_course->setNext(NULL);
        iterator_courses->setNext(new_course);

        cout<< "Write the name of the course" << endl;
        char* course_name;
        cin >> course_name;

        cout << "Write the name of the teacher" << endl;
        char* prof_name;
        cin >> prof_name;

        new_course->setName(course_name);
        new_course->setProfesor(prof_name);

        iterator_courses = iterator_courses->getNext();

    }

    return head_course;

}

Student* look_for_student(char* last_name, Student* head_student){

    Student* iterator_list_student = new Student();

    iterator_list_student = head_student;

    while(iterator_list_student != NULL){
        if(iterator_list_student->getLastName() == last_name){
            return iterator_list_student;
        }
        iterator_list_student = iterator_list_student->getNext();
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

    Curs *head_course;
    Curs *head_student;
    /// 1)
    head_course = crerate_list_courses();
    head_student = create_list_student(head_course);

    /// 2)
    cout<< "Write the last name of the student you want to delete" << endl;
    char* student_last_name;
    cin >> student_last_name;
    delete_student(student_last_name, head_student);


    cout<< "Write the last name of the student you want to edit" << endl;
    cin >> student_last_name;
    edit_student(student_last_name, head_student);

    /// 3)
    cout<< "The number of students is " << number_of_instances;

    /// 4)
    cout<< "Write the last name of the student you want to find" << endl;
    cin >> student_last_name;
    Student* found_student = new Student*;
    found_student = look_for_student(student_last_name, head_student);

    /// 5)


    display_list(head_student, number_list_members);

    return 0;
}

