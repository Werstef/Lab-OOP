#include <iostream>
#include <string>

using namespace std;

class Form {
public:
    string name;

    Form(string name){
        this->name = name;
    }

    void showMessage(){
        cout<<"mesaj din Form"<<endl;
    }

    virtual int calculArie(){};

    virtual int calculPerimetru(){};

};

class Rectangle:public Form {
public:
    int width;
    int height;

    Rectangle(string name, int width, int height) :Form(name){
        this->width = width;
        this->height = height;
    }
    void setWidth(int width){
        this->width = width;
    }
    int getHeight(){
        return this->height;
    }
    int getWidth(){
        return this->width;
    }
    void showMessage(){
        Form::showMessage(); // operator :: folosit pentru a apela showMessage din clasa de baza
        cout<<"mesaj din Rectangle"<<endl;
    }

    int calculArie(){
        return this->getWidth() * this->getHeight();
    }

    int calculPerimetru() {
		return 2 * (this->getWidth() + this->getHeight());
	}

};

class Square:public Form {
public:
    int side;

    Square(string name, int side) :Form(name){
        this->side = side;
    }
    void setSide(int side){
        this->side = side;
    }
    int getSide(){
        return this->side;
    }
    void showMessage(){
        cout<<"mesaj din Square"<<endl;
    }

    int calculArie(){
        return this->getSide() * this->getSide();
    }
    int calculPerimetru() {
		return this->getSide() * 4;
	}

};

int main()
{
    Form *f = new Form("forma1");
    cout<<"forma: "<<f->name<<endl;
    f->showMessage();

    Rectangle *r = new Rectangle("rectangle 1", 1, 2);
    cout<<"rectangle name: "<<r->name<<" width:"<<r->getWidth()<<endl;
    r->showMessage();

    Square *s = new Square("square 1", 20);
    cout<<"square name: "<<s->name<<" side:"<<s->getSide()<<endl;
    s->showMessage();

    cout << endl << "Aria Rectangle: " << r->calculArie() << endl;
	cout << endl << "Aria Square: " << s->calculArie() << endl;

	cout << endl << "Perimetru Rectangle: " << r->calculPerimetru() << endl;
	cout << endl << "Perimetru Square: " << s->calculPerimetru() << endl;

	return 0;

}


