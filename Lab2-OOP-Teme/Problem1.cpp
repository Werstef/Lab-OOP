#include <iostream>
#include <math.h>
using namespace std;

int f1(float n, bool isRoundedTo100 = false){
    if( isRoundedTo100 == false){
        if( n + 0.5 >= floor(n)+1)
            return ceil(n);
        else
            return floor(n);
    }
    else{
        if( n < 10 )
            return 0;
        else{
            int variabila;
            variabila = floor(n);
            variabila = variabila%100;
            n = floor(n);
            if (variabila >= 50){
                n += 100 - variabila;
            }
            else
                n -= variabila;
        }
        return n;
    }

}




int main () {

    float x;
    cin>>x;

    cout<<f1(x, 1);
    return 0;
}
