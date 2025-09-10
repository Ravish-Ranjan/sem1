#include <iostream>
#include "functions.cpp"
using namespace std;

int main(){
    cout << "Succ : " << succ(10) << endl;
    cout << "Pred : " << pred(10) << endl;
    cout << "Add : " << add(10,20) << endl;
    cout << "Sub : " << sub(20,10) << endl;
    cout << "Mul : " << mul(10,3) << endl;
    cout << "Div : " << divi(10,3) << endl;
    cout << "Mod : " << mod(10,3) << endl;
    return 0;
}