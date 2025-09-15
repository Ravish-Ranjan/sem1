#ifndef LINKLIST_H
#define LINKLIST_H

#include <iostream>
#include <string>

template <typename T>
class NodeSin{
    public:
        T value;
        NodeSin *next = nullptr;
        NodeSin(T value) : value(value){}
        void print(){
            std::cout << this->value << "->";
        }
};

template <typename T>
class LL{
    public:
        NodeSin<T> *head = nullptr;
        void inStart(T value){
            NodeSin<T> *newNode = new NodeSin<T>(value);
            if (head != nullptr){
                newNode->next = head;
            }
            head = newNode;
        }
        void inEnd(T value){
            NodeSin<T> *newNode = new NodeSin<T>(value);
            if (head == nullptr)
                head = newNode;
            else{
                NodeSin<T> *cur = head;
                while (cur->next != nullptr)
                    cur = cur->next;
                cur->next = newNode;
            }
        }
        void inAfter(T after, T value){
            if (head == nullptr)return;
            NodeSin<T> *cur = head;
            while (cur->next != nullptr && cur->value != after)
                cur = cur->next;
            if (cur->value == after){
                NodeSin<T> *newNode = new NodeSin<T>(value);
                newNode->next = cur->next;
                cur->next = newNode;
            }
        }
        void inBefore(T before, T value){
            if (head == nullptr) return ;
            if (head->value == before) {
                NodeSin<T>* newNode = new NodeSin<T>(value);
                newNode->next = head;
                head = newNode;
                return;
            }
            NodeSin<T> * cur = head;
            while (cur->next != nullptr && cur->next->value != before)
                cur = cur->next;
            if (cur->next == nullptr) return;
            NodeSin<T>* newNode = new NodeSin<T>(value);
            newNode->next = cur->next;
            cur->next = newNode;
        }
        T delStart(){
            if (head == nullptr) return T();
            NodeSin<T> *temp = head;
            head = head->next;
            T ret = temp->value;
            delete temp;
            return ret;
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
        T delBefore(T before){
            if (head == nullptr || head->next == nullptr) return T();
            if (head->next->value == before) {
                NodeSin<T>* temp = head;
                head = head->next;
                T ret = temp->value;
                delete temp;
                return ret;
            }
            NodeSin<T>* cur = head;
            while (
                cur->next != nullptr &&
                cur->next->next != nullptr && 
                cur->next->next->value != before
            )
                cur = cur->next;
            if (cur->next == nullptr || cur->next->next == nullptr) return T();
            NodeSin<T>* temp = cur->next;
            cur->next = cur->next->next;
            T ret = temp->value;
            delete temp;
            return ret;
        }
        T delValue(T value){
            if (head == nullptr) return T();
            if (head->value == value) {
                NodeSin<T>* temp = head;
                head = head->next;
                T ret = temp->value;
                delete temp;
                return ret;
            }
            NodeSin<T>* cur = head;
            while (cur->next != nullptr && cur->next->value != value)
                cur = cur->next;
            if (cur->next == nullptr) return T();
            NodeSin<T>* temp = cur->next;
            cur->next = cur->next->next;
            T ret = temp->value;
            delete temp;
            return ret;
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
        void print(std::string msg="List : "){
            NodeSin<T> *cur = head;
            std::cout << msg;
            while (cur != nullptr){
                cur->print();
                cur = cur->next;
            }
            std::cout << "null\n\n";
        }        
        bool find(T value,bool print = false){
            if (head == nullptr){
                if(print)
                    std::cout << "value not found " << std::endl;
                return false;
            }
            NodeSin<T> *cur = head;
            int count = 0;
            while (cur->next != nullptr && cur->value != value){
                count++;
                cur = cur->next;
            }
            if (cur->value == value){
                if(print)
                    std::cout << "value found at index " << count << std::endl;
                return true;
            }
            if (cur->next == nullptr){
                if(print)
                    std::cout << "value not found " << std::endl;
                return false;
            }
            return false;
        }
        int size(){
            if(head == nullptr) return 0;
            int count = 1;
            NodeSin<T>* cur = head;
            while (cur->next != nullptr){
                count++;
                cur = cur->next;
            }
            return count;
        }
        void merge(const LL<T> *secondList){
            if(this->head == nullptr){
                this->head = secondList->head;
                return;
            }
            NodeSin<T>* cur = this->head;
            while(cur->next != nullptr) cur = cur->next;
            cur->next = secondList->head;
        }
        ~LL(){
            this->clear();
        }
};

#endif