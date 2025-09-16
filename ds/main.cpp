#include "./queue/queuell.h"
#include <iostream>

int main(){
    QueueLL<int> q;
    q.dequeue();

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.print();

    std::cout << "Head : " << q.peakHead() << std::endl;
    std::cout << "Tail : " << q.peakTail() << std::endl;
    std::cout << "Size : " << q.size() << std::endl;
    
    std::cout << "Dequeue : " << q.dequeue() << std::endl;

    q.dequeue();
    q.print();
    q.dequeue();
    q.print();
    q.dequeue();
    q.print();
    q.dequeue();
    q.print();



    return 0;
}