#include <iostream>
#include <string>

#include "header_problem2.h"

using namespace std;



int main(){
    Form *f = new Form();
    f->setName("forma1");
    cout<<"forma: "<<f->getName()<<endl;

    Rectangle *r = new Rectangle();
    r->setWidth(23);
    r->setName("rectangle 1");
    cout<<"rectangle name: "<<r->getName()<<" width:"<<r->getWidth()<<endl;
    r->setColor2("Albastru");
    cout<< r->getColor2() << endl;
    return 0;
}
