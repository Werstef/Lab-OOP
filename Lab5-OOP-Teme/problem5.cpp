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
    void showMessage(){
        cout<<"mesaj din Form"<<endl;
    }
    void perimetru(){
        cout << "This function is supposed to be used in the inheritance classes" << endl;
    };
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
    int getHeight() {
		return this->height;
	}
    void showMessage(){
        Form::showMessage();
        cout<<"mesaj din Rectangle"<<endl;
    }
    int perimetru(){
        return (this->getHeight() + this->getWidth()) *2;
    }
};

class Square:public Form {
protected:
    int side;
public:
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
    int perimetru(){
        return 4 * this->getSide();
    }
};

int main()
{
    Form *f = new Form("forma1");
    cout<<"forma: "<<f->getName()<<endl;
    f->showMessage();

    Rectangle *r = new Rectangle("rectangle 1", 1, 2);
    cout<<"rectangle name: "<<r->getName()<<" width:"<<r->getWidth() <<" height:" << r->getHeight() <<endl;
    r->showMessage();
    cout << endl;
    cout << "The perimeter of the rectangle r is " << r->perimetru() << endl;

    Square *s = new Square("square 1", 20);
    cout<<"square name: "<<s->getName()<<" side:"<<s->getSide()<<endl;
    s->showMessage();
    cout << endl;
    cout << "The perimeter of the square s is " << s->perimetru() << endl;

    return 0;
}


