#ifndef QUEUELL_H
#define QUEUELL_H

#include "../linkedlist/linkList.h"

template <typename T>
class QueueLL{
    private:
        LL<T>* queue = nullptr;
        NodeSin<T>* head = nullptr;
        NodeSin<T>* tail = nullptr;
    public:
        QueueLL(){
            this->queue = new LL<T>();
            this->head = this->queue->head;
            this->tail = this->queue->tail;
        }
        bool isEmpty(){
            return this->head == nullptr;
        }
        bool isFull(){
            try {
                NodeSin<T>* newNode = new NodeSin<T>(10);
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
            T ret = this->queue->delStart();
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
            if(this->isEmpty()){
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
        ~QueueLL(){
            this->queue->clear();
            delete this->head;
            delete this->tail;
        }
};

#endif