#include "ds.h"
#include <iostream>

int main(){
    Stack<int>* s = new Stack<int>();
    s->print();
    s->push(10);
    s->push(20);
    s->push(30);
    s->print();
    std::cout << "Peak : " << s->peak() << std::endl;
    s->pop();
    s->print();
    s->pop();
    s->print();
    
    return 0;
}