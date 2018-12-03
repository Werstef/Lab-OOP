#include <iostream>
#include <string>

using namespace std;

class Form{
private:
    string color;
protected:
    string name;
    string getColor(){
        return this->color;
    }
    void setColor(string color){
        this->color = color;
    }
public:
    string getName(){
        return this->name;
    }
    void setName(string name){
        this->name = name;
    }
};

class Rectangle:public Form {
protected:
    int width;
    int height;
public:
    void setWidth(int width){
        this->width = width;
    }
    int getWidth(){
        return this->width;
    }

    void setHeight(int height){
        this->height = height;
    }
    int getHeight(){
        return this->height;
    }
};

int main()
{
    Form *f = new Form();
    f->setName("forma1");
    cout<<"forma: "<<f->getName()<<endl;

    Rectangle *r = new Rectangle();
    r->setWidth(23);
    r->setName("rectangle 1");
    cout<<"rectangle name: "<<r->getName()<<" width:"<<r->getWidth()<<endl;
    cout<< r->getColor() << endl;
    return 0;
}

