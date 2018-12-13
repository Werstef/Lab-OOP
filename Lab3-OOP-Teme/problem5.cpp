#include <iostream>
#include <string>

using namespace std;

class Course {
protected:
	string name_course;
	string name_profesor;
public:
    void setNameCourse(string name_course){
        this->name_course = name_course;
    }
    string getNameCourse(){
        return this->name_course;
    }
    void setNameProf(string name_profesor){
        this->name_profesor = name_profesor;
    }
    string getNameProf(){
        return this->name_profesor;
    }
};


class Student {
public:
	static int number_of_instances;
	int id;
	int group;
	class Course course;

	Student* next_student = NULL;
	Student* prev_student;

	Student() {
		number_of_instances ++;
        id = number_of_instances;
	}

	Student* createStudent(Student* student) {
		Student *new_student = new Student();

		new_student->prev_student = student;

		return new_student;
	}

	void display_list(Student* student) {
		while (student->next_student != NULL) {
			cout << "Student  " << student->id << endl;
			student = student->next_student;
		}
		cout << "Student " << student->id << endl;
	}

	Student* search_student(int id, Student* student) {
		while (student->next_student != NULL) {
			if (student->id == id) {
				cout << endl <<"Student "<<id<<" has been found"<<endl;
				return student;
			}
			student = student->next_student;
		}
	}

	void delete_student(Student* prev_student) {
		Student* student_aux = prev_student->next_student;
		prev_student->next_student = student_aux->next_student;
		student_aux->next_student->prev_student = prev_student;

		delete student_aux;
	}
	void courseStudents(string course, Student* student) {
		while (student->next_student != NULL) {
			if (student->course.getNameCourse() == course) {
				cout << endl << "Student " << student->id << " takes part in the course " << course;
			}
			student = student->next_student;
		}
		if (student->course.getNameCourse() == course) {
			cout << endl << "Student " << student->id << " takes part in the course " << course;
		}
	}
    ~Student(){
		number_of_instances --;
	}
};
int Student::number_of_instances = 0;

int main () {
	Student *student1 = new Student();
	student1->course.setNameCourse("OOP");
	Student *student_aux = new Student();
	student1->next_student = student_aux;
	for (int i = 0; i < 10 - 2; i++) {
		student_aux->next_student = student1->createStudent(student1);
		student_aux = student_aux->next_student;
	}
	cout << "There are " << Student::number_of_instances << " students in the list" << endl;
	student1->display_list(student1);
	student_aux = student1->search_student(3, student1);
	student_aux->course.setNameCourse("OOP");
	student_aux->delete_student(student_aux);
	cout << endl << "Student 4 has been deleted" << endl;
	cout << endl << "There are " << Student::number_of_instances << " students in the list" << endl;
	student1->display_list(student1);
	student1->courseStudents("OOP", student1);



    return 0;
}
