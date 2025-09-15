#ifndef QUEUECLL_H
#define QUEUECLL_H

#include "../linkedlist/circleLinkList.h"

template <typename T>
class QueueCLL{
    private:
        CLL<T>* queue = nullptr;
        NodeSin<T>* head = nullptr;
        NodeSin<T>* tail = nullptr;
    public:
        QueueCLL(){
            this->queue = new CLL<T>();
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
            std::cout << "inserting " << value << std::endl;
            if (isFull()){
                std::cout << "Queue full" << std::endl;
                return;
            }
            this->queue->inEnd(value);
            this->tail = this->queue->tail;
        }
        T dequeue(){
            if (this->isEmpty()){
                std::cout << "Empty queue" << std::endl;
                return T();
            }
            if (this->head->next == this->head){
                T ret = this->queue->delStart();
                this->head = nullptr;
                this->tail = nullptr;
                return ret;
            }
            T ret = this->queue->delStart();
            this->head = this->queue->head;
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
            return this->queue->getSize();
        }
        void rotateRight(){
            this->head = this->head->next;
            this->tail = this->tail->next;
        }
        ~QueueCLL(){
            this->queue->clear();
            delete this->head;
            delete this->tail;
        }
};

#endif