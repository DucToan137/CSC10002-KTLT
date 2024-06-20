#include<iostream>
using namespace std;

void testing(int *a, int *b){
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

int main(){
    int x = 5;
    int y = 10;
    testing(&x,&y);

    cout << "Result1: " << x << "\n";
    y = y -2;
    int  *z = &y;
    z++;

    cout << "Result2: " << y-- << "\n";
    cout << "Result3: " << *z << "\n";
    cout << "Result4: " << --z << "\n";

    

    return 0;
}