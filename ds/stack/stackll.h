#ifndef STACKLL_H
#define STACKLL_H

#include <iostream>
#include "../linkedlist/linklist.h"

template <class T>
class StackLL{
    private:
        LL<T>* stack = nullptr;
    public:
        NodeSin<T>* top = nullptr;
        Stack(){
            this->stack = new LL<T>();
            this->top = stack->head;
        }
        bool isEmpty(){
            return top == nullptr;
        }
        bool isFull(){
            try            {
                NodeSin<T>* newNode = new NodeSin<T>(10);
                delete newNode;
                return false;
            }
            catch(const std::exception& e)            {
                return true;
            }
        }
        void push(T value){
            if (this->isFull()){
                std::cout << "Stack Overflow" << std::endl;
                return;
            } else {
                this->stack->inStart(value);
                this->top = stack->head;
            }
        }
        T pop(){
            if(this->isEmpty()){
                std::cout << "Stack Underflow" << std::endl;
            } else {
                top = top->next;
                return this->stack->delStart();
            }
        }
        T peak(){
            if (this->isEmpty()){
                std::cout << "Empty stack" << std::endl;
                return T();
            } 
            return this->top->value;
        }
        int size(){
            return this->stack->getSize();
        }
        void print(){
            std::cout << "Stack : <-";
            NodeSin<T>* cur = stack->head;
            while (cur != nullptr){
                std::cout << "|" << cur->value;
                cur = cur->next;
            }
            std::cout << "]" << std::endl;
        }
        ~StackLL(){
            this->stack->clear();
        }
};

#endif