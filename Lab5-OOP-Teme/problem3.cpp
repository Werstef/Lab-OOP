#include <iostream>

using namespace std;

class Form {
private:
    string color;

protected:
    string name;
    void setColor(string color)    {
        this->color = color;
    }
public:
    Form(string name){
        this->name = name;
    }
    string getName(){
        return this->name;
    }
    void setName(string name){
        this->name = name;
    }
    ~Form() {
		cout << "Form instance was deleted" << endl;
	}
};

class Rectangle:public Form {
protected:
    int width;
    int height;
public:
    Rectangle(string name, int width, int height) :Form(name){
        this->width = width;
        this->height = height;
    }
    void setWidth(int width){
        this->width = width;
    }
    int getWidth(){
        return this->width;
    }
    ~Rectangle() {
		cout << "Rectangle instance was deleted." << endl;
	}
};

int main(){
    Form *f = new Form("forma1");
    cout<<"forma: "<<f->getName()<<endl;
    delete f;

    Rectangle *r = new Rectangle("rectangle 1", 1, 2);
    cout<<"rectangle name: "<<r->getName()<<" width:"<<r->getWidth()<<endl;
    delete r;
    return 0;
}
