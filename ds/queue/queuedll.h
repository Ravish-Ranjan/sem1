#ifndef QUEUEDLL_H
#define QUEUEDLL_H

#include "../linkedlist/doubleLinkList.h"

template <typename T>
class QueueDLL{
    private:
        DLL<T>* queue = nullptr;
        NodeDob<T>* head = nullptr;
        NodeDob<T>* tail = nullptr;
    public:
        QueueDLL(){
            this->queue = new DLL<T>();
            this->head = queue->head;
            this->tail = queue->tail;
        }
        bool isEmpty(){
            return this->head == nullptr;
        }
        bool isFull(){
            try{
                NodeDob<T>* newNode = new NodeDob<T>(10);
                delete newNode;
                return false;
            } catch(const std::exception& e){
                return true;
            }
        }
        void enqueue(T value){
            if (isFull()){
                std::cout << "Full queue" << std::endl;
                return;
            }
            this->queue->inEnd(value);
            this->head = this->queue->head;
            this->tail = this->queue->tail;
        }
        T dequeue(){
            if (this->isEmpty()){
                std::cout << "Empty queue" << std::endl;
                return T();
            }
            T ret = this->queue->delStart()
            this->head = this->queue->head;
            this->tail = this->queue->tail;
            return ret;
        }
        T peakHead(){
            if (this->isEmpty()){
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
            delete this->head;
            delete this->tail;
        }
};

#endif