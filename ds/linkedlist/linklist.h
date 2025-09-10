#ifndef LINKLIN_H
#define LINKLIN_H

#include <iostream>

template <typename T>
class NodeSin{
    public:
        T value;
        NodeSin *next = nullptr;
        NodeSin(T value) : value(value){}
        void print(){
            std::cout << "(" << this->value << ")->" << this->next << std::endl;
        }
};

template <typename T>
class LL{
    public:
        NodeSin<T> *head = nullptr;
        void inStart(T value){
            NodeSin<T> *newNode = new NodeSin<T>(value);
            if (head == nullptr){
                head = newNode;
            }
            else{
                newNode->next = head;
                head = newNode;
            }
        }
        void inEnd(T value){
            NodeSin<T> *newNode = new NodeSin<T>(value);
            if (head == nullptr){
                head = newNode;
            }
            else{
                NodeSin<T> *cur = head;
                while (cur->next != nullptr){
                    cur = cur->next;
                }
                cur->next = newNode;
            }
        }
        T delStart(){
            if (head != nullptr){
                NodeSin<T> *temp = head;
                head = head->next;
                T ret = temp->value;
                delete temp;
                return ret;
            }
        }
        T delEnd(){
            if (head == nullptr)
                return T();
            else if (head->next == nullptr){
                NodeSin<T> *temp = head;
                head = nullptr;
                T ret = temp->value;
                delete temp;
                return ret;
            }
            else{
                NodeSin<T> *cur = head;
                while (cur->next->next != nullptr)
                    cur = cur->next;
                NodeSin<T> *temp = cur->next;
                cur->next = nullptr;
                T ret = temp->value;
                delete temp;
                return ret;
            }
        }
        void clear(){
            NodeSin<T> *cur = head;
            while (cur->next != nullptr){
                NodeSin<T> *temp = cur;
                cur = cur->next;
                delete temp;
            }
            head = nullptr;
        }
        void print(){
            NodeSin<T> *cur = head;
            std::cout << "List : ";
            while (cur != nullptr){
                std::cout << cur->value << "->";
                cur = cur->next;
            }
            if (cur == nullptr){
                std::cout << "null\n\n";
            }
        }
        void inAfter(T after, T value){
            if (head == nullptr)
                return;
            NodeSin<T> *cur = head;
            while (cur->next != nullptr && cur->value != after)
                cur = cur->next;
            if (cur->value == after){
                NodeSin<T> *newNode = new NodeSin<T>(value);
                newNode->next = cur->next;
                cur->next = newNode;
            }
        }
        T delAfter(T after){
            if (head == nullptr)
                return T();
            NodeSin<T> *cur = head;
            while (cur->next != nullptr && cur->value != after)
                cur = cur->next;
            if (cur->next == nullptr)
                return T();
            else if (cur->value == after){
                NodeSin<T> *temp = cur->next;
                cur->next = cur->next->next;
                T ret = temp->value;
                delete temp;
                return ret;
            }
        }
        bool find(T value,bool print = false){
            if (head == nullptr)
                return false;
            NodeSin<T> *cur = head;
            int count = 0;
            while (cur->next != nullptr && cur->value != value){
                count++;
                cur = cur->next;
            }
            if (cur->next == nullptr)
                ;
            return false;
            if (cur->value == value){
                if(print)
                    std::cout << "value found at position " << count << std::endl;
                return true;
            }
            return false;
        }
        int getSize(){
            if(head == nullptr) return 0;
            int count = 1;
            NodeSin<T>* cur = head;
            while (cur->next != nullptr){
                count++;
                cur = cur->next;
            }
            return count;
        }
        ~LL(){
            this->clear();
        }
};

#endif