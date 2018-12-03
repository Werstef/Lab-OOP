#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <time.h>

using namespace std;


// Open with vs, it doesn't work in codeblocks

class Masina {
public:
	char* name;
	char* class_name = "Masina";
	Masina* next;
};

class Student {
public:
	char* name;
	char* class_name = "Student";
	Student* next_node;
};

class Log {
private:
	static Log* instance;
	Log(){};
public:

	static Log* getInstance() {
		if (instance == 0){
			instance = new Log();
		}
		return instance;
	};

	void Write(char* class_name, char* name) {
		fstream f;
		f.open("log.txt", fstream::app);

		time_t rawtime;
		struct tm timeinfo;
		char buffer[100];
		time(&rawtime);
		localtime_s(&timeinfo, &rawtime);
		strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &timeinfo);
		std::string str(buffer);

		f << str << " " << class_name << " " << name << endl;
		f.close();
	}

	void delete_file() {
		ofstream f("log.txt");
		f.close();
		cout << "S-a sters fisierul log.txt" << endl;
	}

};
Log* Log::instance = 0;

int main () {

	Log::getInstance()->delete_file();

	Student *student = new Student();
	student->name = "Stefan";
	Log::getInstance()->Write(student->class_name, student->name);

	Masina* masina = new Masina();
	masina->name = "BMW";
	Log::getInstance()->Write(masina->class_name, masina->name);

    cout << "S-a scris in fisierul log.txt" << endl;



    return 0;
}

