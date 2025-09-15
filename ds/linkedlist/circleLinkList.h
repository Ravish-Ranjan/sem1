#ifndef CIRCLELINKLIST_H
#define CIRCLELINKLIST_H

#include <iostream>
#include <string>
#include "./linkList.h"

template <typename T>
class CLL{
    public:
        NodeSin<T>* tail = nullptr;
        NodeSin<T>* head = nullptr;
        void inStart(T value){
            NodeSin<T>* newNode = new NodeSin<T>(value);
            if (this->head == nullptr){
                newNode->next = newNode;
                this->head = this->tail = newNode;
                return;
            }
            newNode->next = this->head;
            this->head = newNode;
            this->tail->next = this->head;
        }   
        void inEnd(T value){
            NodeSin<T>* newNode = new NodeSin<T>(value);
            if (this->tail == nullptr){
                newNode->next = newNode;
                this->head = this->tail = newNode;
                return ;
            }
            newNode->next = this->head;
            this->tail->next = newNode;
            this->tail = newNode;
        }
        void inAfter(T value,T after){
            if (this->head == nullptr){
                std::cout << "Empty list" << std::endl;
                return;
            }
            if(this->head->next == this->head){
                if(this->head->value == after){
                    this->inEnd(value);
                } 
                return;
            }
            NodeSin<T> *cur = head;
            while (cur->next != this->head && cur->value != after)
                cur = cur->next;
            if (cur->value == after){
                NodeSin<T> *newNode = new NodeSin<T>(value);
                newNode->next = cur->next;
                cur->next = newNode;
                if(cur == this->tail){
                    this->tail = newNode;
                }
            }
        }

        T delStart(){
            if(this->head == nullptr){
                std::cout << "Empty list" << std::endl;
                return T();
            }
            if(this->head->next == this->head){
                NodeSin<T>* temp = this->head;
                T ret = temp->value;
                this->head = this->tail = nullptr;
                delete temp;
                return ret;
            }
            NodeSin<T>* temp = this->head;
            this->head = this->head->next;
            this->tail->next = this->head;
            T ret = temp->value;
            delete temp;
            return ret;
        }
        T delEnd(){
            if(this->tail == nullptr){
                std::cout << "Empty list" << std::endl;
                return T();
            }
            if(this->tail->next == this->tail){
                NodeSin<T>* temp = this->tail;
                T ret = this->tail->value;
                this->head = this->tail = nullptr;
                delete temp;
                return ret;
            }
            NodeSin<T>* cur = this->head;
            while(cur->next != this->tail) 
                cur = cur->next;
            NodeSin<T>* temp = this->tail;
            cur->next = this->head;
            this->tail = cur;
            T ret = temp->value;
            delete temp;
            return ret;
        }
        T delAfter(T after){
            if(this->head == nullptr){
                std::cout << "Empty list" << std::endl;
                return T();
            }
            if(this->head->next == this->head){
                if(this->head->value == after){
                    T ret = this->head->value;
                    this->head = this->tail = nullptr;
                    return ret;
                }
                return T();
            }
            NodeSin<T>* cur = this->head;
            while (cur->next != this->head && cur->value != after)
                cur = cur->next;
            if(cur->value == after){
                if(cur == this->tail) 
                    return this->delStart();
                if(cur == this->head){
                    if(this->head->next == this->tail){
                        NodeSin<T>* temp = this->tail;
                        this->head->next = this->head;
                        this->tail = this->head;
                        T ret = temp->value;
                        delete temp;
                        return ret;
                    }
                    NodeSin<T>* temp = this->head->next;
                    this->head = this->head->next;
                    this->tail->next = this->head;
                    T ret = temp->value;
                    delete temp;
                    return ret;
                }
            }
        }

        void clear(){
            if (head == nullptr) return;
            NodeSin<T>* cur = head;
            do {
                NodeSin<T>* temp = cur;
                cur = cur->next;
                delete temp;
            } while (cur != head);
            this->head = this->tail = nullptr;
        }
        void print(std::string msg="List : "){
            if(this->head == nullptr){
                std::cout << "null\n\n";
                return;
            }
            NodeSin<T> *cur = head;
            std::cout << msg << "->";
            while (cur->next != this->head){
                std::cout << cur->value << "->";
                cur = cur->next;
            }
            std::cout << "loopback\n\n";
        }
        bool find(T value,bool print = false){
            if (head == nullptr) return false;
            NodeSin<T>* cur = head;
            int count = 0;
            do {
                if (cur->value == value) {
                    if (print)
                        std::cout << "value found at position " << count << std::endl;
                    return true;
                }
                cur = cur->next;
                count++;
            } while (cur != head);
            return false;
        }
        int size(){
            if(head == nullptr) return 0;
            int count = 1;
            NodeSin<T>* cur = head;
            while(cur->next != this->head){
                count++;
                cur = cur->next;
            }
            return count;
        }
        ~CLL(){
            this->clear();
        }
};

#endif