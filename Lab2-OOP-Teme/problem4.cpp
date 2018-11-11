#include <iostream>

using namespace std;

unsigned char function(int variable){
     return variable & 0xFF;
}

unsigned char function(double variable){
    unsigned char x = (unsigned char)variable & 0xFF;
    return x;
}

// unsigned char x = (variable >> (8*0)) & 0xff;s

char function(char* variable){
    return variable[0];
}


int main () {

    int a = 2;
    double b = 2.5;
    char* c = "Mihai";


    cout << function(a) << endl;
    cout << function(b) << endl;
    cout << function(c) << endl;

    return 0;
}
