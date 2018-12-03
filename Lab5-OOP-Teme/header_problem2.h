#include <iostream>

using namespace std;

#ifndef HEADER2
#define HEADER2

class Form{
private:
    string color;
protected:
    string name;
    string getColor();
    void setColor(string color);
public:
    string getName();
    void setName(string name);
};

class Rectangle:public Form{
protected:
    int width;
    int height;
public:
    void setWidth(int width);
    int getWidth();
    void setHeight(int height);
    int getHeight();
    string getColor2();
    void setColor2(string color);
};

#endif // HEADER2
