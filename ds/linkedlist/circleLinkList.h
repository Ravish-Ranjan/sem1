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
        void inAfter(T after,T value){
            if (this->head == nullptr) return;
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
        void inBefore(T before,T value){
            if (this->head == nullptr) return;
            
            if(this->head->value == before){
                this->inStart(value);
                return;
            }
            
            if(this->head->next == this->head) return; 
            
            NodeSin<T>* cur = this->head;
            while(cur->next != this->head && cur->next->value != before){
                cur = cur->next;
            }
            
            if(cur->next->value == before){
                NodeSin<T>* newNode = new NodeSin<T>(value);
                newNode->next = cur->next;
                cur->next = newNode;
            }
        }

        T delStart(){
            if(this->head == nullptr) return T();
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
            if(this->tail == nullptr) return T();
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
            if(this->head == nullptr) return T();
            if(this->head->next == this->head) return T();

            NodeSin<T>* cur = this->head;
            do {
                if(cur->value == after){
                    NodeSin<T>* temp = cur->next;
                    T ret = temp->value;
                    
                    if(temp == this->head){
                        this->head = this->head->next;
                        this->tail->next = this->head;
                    }
                    else if(temp == this->tail){
                        this->tail = cur;
                        cur->next = this->head;
                    }
                    else {
                        cur->next = temp->next;
                    }
                    
                    delete temp;
                    return ret;
                }
                cur = cur->next;
            } while(cur != this->head);
            return T();
        }
        T delBefore(T before){
            if(this->head == nullptr) return T();
            
            if(this->head->next == this->head) return T();
            
            if(this->head->value == before){
                return this->delEnd();
            }
            
            NodeSin<T>* cur = this->head;
            NodeSin<T>* prev = nullptr;
            
            do {
                if(cur->next->value == before){
                    T ret = cur->value;
                    if(cur == this->head){
                        this->head = this->head->next;
                        this->tail->next = this->head;
                    }
                    else if(cur == this->tail){
                        NodeSin<T>* temp = this->head;
                        while(temp->next != this->tail)
                            temp = temp->next;
                        temp->next = this->head;
                        this->tail = temp;
                    }
                    else {
                        NodeSin<T>* temp = this->head;
                        while(temp->next != cur){
                            temp = temp->next;
                        }
                        temp->next = cur->next;
                    }
                    
                    delete cur;
                    return ret;
                }
                cur = cur->next;
            } while(cur != this->head);
            return T();
        }
        T delValue(T value){
            if(this->head == nullptr) return T();
            
            if(this->head->next == this->head && this->head->value == value){
                T ret = this->head->value;
                delete this->head;
                this->head = this->tail = nullptr;
                return ret;
            }
            
            if(this->head->value == value)
                return this->delStart();
            
            NodeSin<T>* cur = this->head;
            do {
                if(cur->next->value == value){
                    NodeSin<T>* temp = cur->next;
                    T ret = temp->value;
                    
                    if(temp == this->tail){
                        this->tail = cur;
                        cur->next = this->head;
                    }
                    else {
                        cur->next = temp->next;
                    }
                    
                    delete temp;
                    return ret;
                }
                cur = cur->next;
            } while(cur != this->head);
            return T();
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
        void print(std::string msg="List"){
            if(this->head == nullptr){
                std::cout << msg << " : " << "null\n\n";
                return;
            }
            NodeSin<T> *cur = head;
            std::cout << msg << " : " << "->";
            while (cur->next != this->head){
                std::cout << cur->value << "->";
                cur = cur->next;
            }
            std::cout << cur->value << "->" << "loopback\n\n";
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
        void merge(CLL<T>&secondList){
            if (secondList.head == nullptr) return;
            if (this->head == nullptr){
                this->head = secondList.head;
                this->tail = secondList.tail;
                return;
            }
            this->tail->next = secondList.head;
            secondList.tail->next = this->head;
            this->tail = secondList.tail;
        }
        void rotateRight(int times=1){
            if (
                this->head == nullptr || 
                this->head == this->tail
            ) return;

            times %= this->size();
            while (times--) {
                head = tail;
                NodeSin<T>* cur = head;
                while (cur->next != tail)
                    cur = cur->next;
                tail = cur;
            }
        }
        void rotateLeft(int times=1){
            if (
                this->head == nullptr || 
                this->head == this->tail
            ) return;

            times %= this->size();
            while (times--) {
                head = head->next;
                tail = tail->next;
            }
        }
        
        ~CLL(){
            this->clear();
        }
};

#endif