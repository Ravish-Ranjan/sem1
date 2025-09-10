#include <iostream>
#include "numbers.h"


int main(){
    std::cout << "Succ : " << succ(10) << std::endl;
    std::cout << "Pred : " << pred(10) << std::endl;
    std::cout << "Add : " << add(10,20) << std::endl;
    std::cout << "Sub : " << sub(20,10) << std::endl;
    std::cout << "Mul : " << mul(10,3) << std::endl;
    std::cout << "Div : " << divi(10,3) << std::endl;
    std::cout << "Mod : " << mod(10,3) << std::endl;
    return 0;
}