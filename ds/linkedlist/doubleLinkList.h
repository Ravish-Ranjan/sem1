#ifndef DOUBLELINKLIST_H
#define DOUBLELINKLIST_H

#include <iostream>

template <typename T>
class NodeDob{
    public:
        T value;
        NodeDob* next = nullptr;
        NodeDob* prev = nullptr;
        NodeDob(T value) : value(value){}
};


template <class T>
class DLL{
    public:
        NodeDob<T>* head = nullptr;
        NodeDob<T>* tail = nullptr;
        // insert at start
        void inStart(T value){
            NodeDob<T>* newNode = new NodeDob<T>(value);
            if (head == nullptr){
                head = tail = newNode;
            } else {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
        }
        // insert at end
        void inEnd(T value){
            NodeDob<T>* newNode = new NodeDob<T>(value);
            if (tail == nullptr){
                head = tail = newNode;
            } else {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
        }
        // insert after value
        void inAfter(T after, T value) {
            if (!head) return;
    
            NodeDob<T>* cur = head;
            while (cur && cur->value != after) cur = cur->next;
            if (!cur) return;
    
            NodeDob<T>* newNode = new NodeDob<T>(value);
            newNode->next = cur->next;
            newNode->prev = cur;
            if (cur->next) cur->next->prev = newNode;
            else tail = newNode;
            cur->next = newNode;
        }
        // Insert before value
        void inBefore(T before, T value) {
            if (!head) return;
    
            NodeDob<T>* cur = head;
            while (cur && cur->value != before) cur = cur->next;
            if (!cur) return ;
    
            NodeDob<T>* newNode = new NodeDob<T>(value);
            newNode->next = cur;
            newNode->prev = cur->prev;
            if (cur->prev) cur->prev->next = newNode;
            else head = newNode;
            cur->prev = newNode;
        }

        // delete at start
        T delStart(){
            if(head == nullptr) return T();
            NodeDob<T>* temp = head;
            if(head->next == nullptr){
                head = tail = nullptr;
            } else {
                head->next->prev = nullptr;
                head = temp->next;
            }
            T ret = temp->value;
            delete temp;
            return ret;
        }
        // delete at end
        T delEnd(){
            if (tail == nullptr) return T();
            NodeDob<T>* temp = tail;
            if(tail->prev == nullptr){
                head = tail = nullptr;
            } else {
                tail->prev->next = nullptr;
                tail = temp->prev;
            }
            T ret = temp->value;
            delete temp;
            return ret;
        }
        // delete by value
        T delValue(T value){
            if (tail == nullptr) return T();
            NodeDob<T>* cur = head;
            while (cur != nullptr && cur->value != value)
                cur = cur->next;
            if (cur == nullptr) return T();
    
            if (cur->prev != nullptr) cur->prev->next = cur->next;
            else head = cur->next; 
            if (cur->next != nullptr) cur->next->prev = cur->prev;
            else tail = cur->prev; 
            T ret = cur->value;
            delete cur;
            return ret;
        }
        // delete after value
        T delAfter(T after){
            if (tail == nullptr) return T();
            NodeDob<T>* cur = head;
            while (cur != nullptr && cur->value != after)
                cur = cur->next;
            if (cur == nullptr || cur->next == nullptr) return T();
    
            NodeDob<T>* temp = cur->next;
            cur->next = temp->next;
            if (temp->next != nullptr) temp->next->prev = cur;
            else tail = cur; 
            T ret = temp->value;
            delete temp;
            return ret;
        }
        // delete before value
        T delBefore(T before){
            if(tail == nullptr) return T();
            NodeDob<T>* cur = head;
            while (cur != nullptr && cur->value != before)
                cur = cur->next;
            if (cur == nullptr || cur->prev == nullptr) return T();
    
            NodeDob<T>* temp = cur->prev;
            cur->prev = temp->prev;
            if (temp->prev != nullptr) temp->prev->next = cur;
            else head = cur; 
            T ret = temp->value;
            delete temp;
            return ret;
        }

        // print
        void print(std::string msg = "List"){
            std::cout << msg << " : nullptr ";
            if(head == nullptr){
                std::cout << std::endl;
                return;
            }
            NodeDob<T>*cur = head;
            while(cur->next != nullptr){
                std::cout << "-" << cur->value << "-";
                cur = cur->next;
            }
            std::cout << cur->print() << "nullptr" << std::endl;
        }
        // find
        bool find(T value, bool print = false) {
            NodeDob<T>* cur = head;
            while (cur) {
                if (cur->value == value) {
                    if (print) std::cout << "Found: " << value << std::endl;
                    return true;
                }
                cur = cur->next;
            }
            if (print) std::cout << "Element not found" << std::endl;
            return false;
        }
        // clear
        void clear(){
            NodeDob<T> *cur = head;
            while (cur->next != nullptr){
                NodeDob<T> *temp = cur;
                cur = cur->next;
                delete temp;
            }
            head = tail = nullptr;
        }
        // size
        int size(){
            if(head == nullptr) return 0;
            int count = 1;
            NodeDob<T>* cur = head;
            while(cur->next != nullptr){
                count++;
                cur = cur->next;
            }
            return count;
        }
        // merge
        void merge(const DLL<T>* secondList){
            if (secondList->head == nullptr) return;
            if (this->head == nullptr){
                this->head = secondList->head;
                this->tail = secondList->tail;
                return;
            }
            this->tail->next = secondList->head;
            secondList->head->prev = this->tail;
            this->tail = secondList->tail;
        }
        // destructor
        ~DLL(){
            this->clear();
        }
};

#endif