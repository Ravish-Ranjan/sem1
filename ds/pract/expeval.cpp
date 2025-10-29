#include "../stack/stackll.h"
#include <iostream>
#include <string>
#include <vector>

int prec(char oper) {
    if (oper == '^') return 3;
    else if (oper == '*' || oper == '/') return 2;
    else if (oper == '+' || oper == '-') return 1;
    else return -1;
}

bool isNum(char ch) { 
    return ch >= '0' && ch <= '9'; 
}

bool isOper(char ch) {
    return (
        ch == '^' || ch == '*' || ch == '/' ||
        ch == '+' || ch == '-' ||
        ch == '(' || ch == ')'
    );
}

std::string matchingBracket(const std::string& ch) {
    if (ch == "(") return ")";
    if (ch == ")") return "(";
    return "";
}

bool isValidExp(const std::vector<std::string>& expList) {
    std::vector<std::string> stack;
    for (std::string item : expList) {
        if (item == "(") {
            stack.push_back(item);
        } else if (item == ")") {
            if (stack.size() <= 0) return false;
            std::string popped = stack.back();
            stack.pop_back();
            if (popped != matchingBracket(item)) return false;
        }
    }

    if (!stack.size() <= 0) return false;
    return true;
}

std::vector<std::string> parseString(std::string input) {
    std::vector<std::string> parsed;
    std::string str = "";

    for (int i = 0; i < input.length(); i++) {
        if (isOper(input[i])) {
            if (!str.empty()) {
                parsed.push_back(str);
                str.clear();
            }
            parsed.push_back(std::string(1, input[i]));
        } else if (isNum(input[i])) {
            str += input[i];
        }
    }
    if (!str.empty()) parsed.push_back(str);
    return parsed;
}

std::string calc(std::string op1,std::string op2,std::string oper){
    if (oper == "^") {
        int res = 1;
        for (int i = 0; i < std::stod(op2); i++) res *= std::stod(op1);
        return std::to_string(res);
    }
    if (oper == "*") 
        return std::to_string(std::stod(op1) * std::stod(op2)) ;
    if (oper == "/") 
        return std::to_string(std::stod(op1) / std::stod(op2)) ;
    if (oper == "+") 
        return std::to_string(std::stod(op1) + std::stod(op2)) ;
    if (oper == "-") 
        return std::to_string(std::stod(op1) - std::stod(op2)) ;
    return "";
}

std::vector<std::string> intopost(const std::vector<std::string>& expList){
    std::vector<std::string> nums;
    std::vector<std::string> opers;
    for(std::string item:expList){
        if (isNum(item[0])) nums.push_back(item);
        else if (item == "(") opers.push_back("(");
        else if (item == ")"){
            while (opers.size() > 0 && opers.back() != "("){
                nums.push_back(opers.back());
                opers.pop_back();
            }
            opers.pop_back();
        }
        else {
            while (
                opers.size() > 0 && opers.back() != "(" && (
                        prec(opers.back()[0]) > prec(item[0]) || (
                            prec(opers.back()[0]) == prec(item[0]) &&
                            !(item == "^")
                        )
                    )
            ){
                nums.push_back(opers.back());
                opers.pop_back();
            }
            opers.push_back(item);
        }
    }
    while (opers.size() > 0){
        nums.push_back(opers.back());
        opers.pop_back();
    }
    return nums;
}

std::string calcExp(const std::vector<std::string>& expList){
    std::vector<std::string> postfix = intopost(expList);
    std::vector<std::string> callStack;

    for (std::string item:postfix){
        if (isNum(item[0])) callStack.push_back(item);
        else if(isOper(item[0])){
            std::string op2 = callStack.back();
            if (callStack.size() <= 0) throw "Not a valid expression";
            callStack.pop_back();
            std::string op1 = callStack.back();
            if (callStack.size() <= 0) throw "Not a valid expression";
            callStack.pop_back();
            std::string res = calc(op1,op2,item);
            // std::cout << op1 << item << op2 << " = " << res << std::endl;
            callStack.push_back(res);
        }
    }
    if (callStack.size() != 1) throw "Not a valid expression";
    return callStack[0];
}

int main() {
    std::vector<std::string> res = parseString("4+9-8*4/6");
    
    std::cout << "Expression : ";
    for(std::string item:res)
        std::cout << item << " ";
    std::cout << std::endl;

    if (!isValidExp(res)) {
        std::cout << "Not a valid expression" << std::endl;
        return 0;
    }

    std::string result = calcExp(res);
    std::cout << "Result : " << result << std::endl;

    return 0;
}
