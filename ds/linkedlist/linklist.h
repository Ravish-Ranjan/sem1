#ifndef LINKLIST_H
#define LINKLIST_H

#include <iostream>

template <typename T>
class NodeSin{
    public:
        T value;
        NodeSin *next = nullptr;
        NodeSin(T value) : value(value){}
};

template <typename T>
class LL{
    public:
        NodeSin<T> *head = nullptr;
        NodeSin<T> *tail = nullptr;
        void inStart(T value){
            NodeSin<T>* newNode = new NodeSin<T>(value);
            if (head == nullptr) {
                head = tail = newNode;
            } else {
                newNode->next = head;
                head = newNode;
            }
        }
        void inEnd(T value){
            NodeSin<T> *newNode = new NodeSin<T>(value);
            if (head == nullptr)
                tail = head = newNode;
            else{
                tail->next = newNode;
                tail = newNode;
            }
        }
        void inAfter(T after, T value){
            if (head == nullptr) return;
            NodeSin<T>* cur = head;
            while (cur != nullptr && cur->value != after)
                cur = cur->next;
            if (cur != nullptr) {
                NodeSin<T>* newNode = new NodeSin<T>(value);
                newNode->next = cur->next;
                cur->next = newNode;
                if (cur == tail) tail = newNode;
            }
        }
        void inBefore(T before, T value){
            if (head == nullptr) return ;
            if (head->value == before) {
                this->inStart(value);
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
            NodeSin<T>* temp = head;
            T ret = temp->value;
            head = head->next;
            if (head == nullptr) tail = nullptr; // list became empty
            delete temp;
            return ret;
        }
        T delEnd(){
            if (head == nullptr) return T();
            if (head == tail) {
                T ret = head->value;
                delete head;
                head = tail = nullptr;
                return ret;
            }
            NodeSin<T>* cur = head;
            while (cur->next != tail)
                cur = cur->next;
            T ret = tail->value;
            delete tail;
            tail = cur;
            tail->next = nullptr;
            return ret;
        }
        T delAfter(T after){
            if (head == nullptr) return T();
            NodeSin<T>* cur = head;
            while (cur != nullptr && cur->value != after)
                cur = cur->next;
            if (cur == nullptr || cur->next == nullptr) return T();
            NodeSin<T>* temp = cur->next;
            T ret = temp->value;
            cur->next = temp->next;
            if (temp == tail) tail = cur;
            delete temp;
            return ret;
        }
        T delBefore(T before){
            if (head == nullptr || head->next == nullptr) return T();
            if (head->next->value == before) {
                return delStart();
            }
            NodeSin<T>* cur = head;
            while (cur->next->next != nullptr && cur->next->next->value != before)
                cur = cur->next;
            if (cur->next == nullptr || cur->next->next == nullptr) return T();
            NodeSin<T>* temp = cur->next;
            T ret = temp->value;
            cur->next = temp->next;
            if (temp == tail) tail = cur;
            delete temp;
            return ret;
        }
        T delValue(T value){
            if (head == nullptr) return T();
            if (head->value == value) return delStart();
            NodeSin<T>* cur = head;
            while (cur->next != nullptr && cur->next->value != value)
                cur = cur->next;
            if (cur->next == nullptr) return T();
            NodeSin<T>* temp = cur->next;
            T ret = temp->value;
            cur->next = temp->next;
            if (temp == tail) tail = cur;
            delete temp;
            return ret;
        }
        void clear(){
            NodeSin<T>* cur = head;
            while (cur != nullptr) {
                NodeSin<T>* temp = cur;
                cur = cur->next;
                delete temp;
            }
            head = tail = nullptr;
        }
        void print(std::string msg = "List"){
            std::cout << msg << " : ";
            NodeSin<T> *cur = head;
            while (cur != nullptr){
                std::cout << cur->value << "->" ;
                cur = cur->next;
            }
            std::cout << "null\n\n";
        }        
        bool find(T value,bool print = false){
            NodeSin<T>* cur = head;
            int count = 0;
            while (cur != nullptr) {
                if (cur->value == value) {
                    if (print)
                        std::cout << "value found at index " << count << std::endl;
                    return true;
                }
                cur = cur->next;
                count++;
            }
            if (print) std::cout << "value not found\n";
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
            if (secondList->head == nullptr) return;
            if(this->head == nullptr){
                this->head = secondList->head;
                this->tail = secondList->tail;
                return;
            }
            this->tail->next = secondList->head;
            this->tail = secondList->tail;
        }
        ~LL(){
            this->clear();
        }
};

#endif