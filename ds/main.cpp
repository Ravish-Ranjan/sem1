#include <iostream>
#include "./tree/heap.h"

int main(){
    Heap<int,Min_Heap> h;
    h.buildHeap({1,2,3,4,5,6,7,8,9,10});
    h.print();
    std::cout << "Top : " << h.getTop() << std::endl;
    h.extractTop();
    h.print();
    h.insert(1);
    h.print();
    std::cout << "isEmpty : " << h.isEmpty() << std::endl;
    std::cout << "top : " << h.getTop() << std::endl;
    h.print();
    h.replaceTop(100);
    h.print();
    std::cout << "size : " << h.size() << std::endl;
    return 0;
}