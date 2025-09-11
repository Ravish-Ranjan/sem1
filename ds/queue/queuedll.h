#ifndef QUEUELL_H
#define QUEUELL_H

#include "../linkedlist/doubleLinkList.h"

template <typename T>
class QueueDLL{
    private:
        DLL<T>* queue = nullptr;
    public:
        NodeDob<T>* head = nullptr;
        NodeDob<T>* tail = nullptr;
        QueueDLL(){
            this->queue = new DLL<T>();
            this->head = queue->head;
            this->tail = queue->tail;
        }
        bool isEmpty(){
            return this->head == nullptr;
        }
        bool isFull(){
            try            {
                NodeDob<T>* newNode = new NodeDob<T>(10);
                delete newNode;
                return false;
            }
            catch(const std::exception& e)            {
                return true;
            }
        }
        void enqueue(T value){
            this->queue->inEnd(value);
        }
        T dequeue(){
            return this->queue->delStart();
        }
        T peakHead(){
            if (this->head == nullptr){
                std::cout << "Empty queue" << std::endl;
                return T();
            }
            return this->head->value;
        }
        T peakTail(){
            if(this->tail == nullptr){
                std::cout << "Empty queue" << std::endl;
                return T();
            }
            return this->tail->value;
        }
        void print(){
            this->queue->print("Queue");
        }
        int size(){
            return this->queue->size();
        }
        ~QueueDLL(){
            this->queue->clear();
        }
};

#endif