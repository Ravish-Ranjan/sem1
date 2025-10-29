#include "../stack/stackll.h"
#include <string>
#include <iostream>
#include <vector>

bool isPalindrome(const std::string& str){
    std::vector<char> stack;
    for(char c:str) stack.push_back(c);
    for(char c:str){
        if (c != stack.back()) return false;
        stack.pop_back();
    }
    return true;
}

int main(){
    std::string inp = "";
    std::cout << "Enter a string : ";
    std::cin >> inp;

    if (isPalindrome(inp)){
        std::cout << inp << " is a \033[32mPalindrome\033[0m" << std::endl;
    } else {
        std::cout << inp << " is not a \033[31mPalindrome\033[0m" << std::endl;
    }

    return 0;
}