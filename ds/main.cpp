#include "ds.h"
#include <iostream>

int main(){
    QueueDLL<int>* q = new QueueDLL<int>();
    q->print();
    q->enqueue(10);
    q->print();
    q->enqueue(20);
    q->print();
    q->enqueue(30);
    q->print();
    q->dequeue();
    q->print();
    q->dequeue();
    q->print();
    q->dequeue();
    q->print();
    
    return 0;
}