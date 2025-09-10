#include <iostream>

template <class T>
class Node{
    public:
        T value;
        Node* next = nullptr;
        Node* prev = nullptr;
        Node(T value) : value(value){}
        void print(){
            std::cout << "<-(" << this->value << ")->" << this->next << std::endl;
        }
};

template <class T>
class DLL{
    public:
        Node<T>* head = nullptr;
        Node<T>* tail = nullptr;
        // insert at start
        void inStart(T value){
            Node<T>* newNode = new Node<T>(value);
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
            Node<T>* newNode = new Node<T>(value);
            if (tail == nullptr){
                head = tail = newNode;
            } else {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
        }
        // insert after value
        void inAfter(T value,T after){
            if (head == nullptr)
                throw "Empty list";
            Node<T>* cur = head;
            while (cur->next != nullptr && cur->value != after)
                cur = cur->next;
            if(cur->next == nullptr) throw "Element not found";
            Node<T>* newNode = new Node<T>(value);
            newNode->prev=cur;
            newNode->next = cur->next;
            if(cur->next != nullptr)
                cur->next->prev = newNode;
            else tail = newNode;
            cur->next = newNode;
        }
        // insert before value
        void inBefore(T value,T before){
            if (tail == nullptr)
                throw "Empty list";
            Node<T>* cur = tail;
            while(cur->prev != nullptr && cur->value != before)
                cur = cur->prev;
            if(cur->next ==nullptr) throw "Element not found";
            Node<T>* newNode = new Node<T>(value);
            newNode->next = cur;
            newNode->prev = cur->prev;
            if (cur->prev != nullptr) cur->prev->next = newNode;
            else head = newNode; 
            cur->prev = newNode;
        }

        // delete at start
        T delStart(){
            if(head == nullptr)
                throw "Empty list";
            Node<T>* temp = head;
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
            if (tail == nullptr)
                throw "Empty list";
            Node<T>* temp = tail;
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
            if (tail == nullptr)
                throw "Empty list";
            Node<T>* cur = head;
            while (cur != nullptr && cur->value != value)
                cur = cur->next;
            if (cur == nullptr) throw "Element not found";
    
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
            if (tail == nullptr)
                throw "Empty list";
            Node<T>* cur = head;
            while (cur != nullptr && cur->value != after)
                cur = cur->next;
            if (cur == nullptr || cur->next == nullptr)
                throw "Nothing after given element";
    
            Node<T>* temp = cur->next;
            cur->next = temp->next;
            if (temp->next != nullptr) temp->next->prev = cur;
            else tail = cur; 
            T ret = temp->value;
            delete temp;
            return ret;
        }
        // delete before value
        T delBefore(T before){
            if(tail == nullptr)
                throw "Empty list";
            Node<T>* cur = head;
            while (cur != nullptr && cur->value != before)
                cur = cur->next;
            if (cur == nullptr || cur->prev == nullptr)
                throw "Nothing before given element";
    
            Node<T>* temp = cur->prev;
            cur->prev = temp->prev;
            if (temp->prev != nullptr) temp->prev->next = cur;
            else head = cur; 
            T ret = temp->value;
            delete temp;
            return ret;
        }

        // print
        void print(){
            std::cout << "List : nullptr ";
            if(head == nullptr){
                return;
            }
            Node<T>*cur = head;
            while(cur->next != nullptr){
                std::cout << "-" << cur->value << "- ";
                cur = cur->next;
            }
            std::cout << "-" << cur->value << "- " << "nullptr" << std::endl;
        }
        // find
        bool find(T value,bool print = false){
            if(head == nullptr) return false;
            Node<T>* cur = head;
            while(cur->next !=nullptr && cur->value != value)
                cur = cur->next;
            if(cur->next == nullptr) return false;
            if(cur->value == value){
                if(print)
                    std::cout << "Element found at after " << cur->prev->value<<" and before " << cur->next->value << std::endl;
                return true;
            }
        }
        // clear
        void clear(){
            Node<T> *cur = head;
            while (cur->next != nullptr){
                Node<T> *temp = cur;
                cur = cur->next;
                delete temp;
            }
            head = tail = nullptr;
        }
        // size
        int size(){
            if(head == nullptr) return 0;
            int count = 0;
            Node<T>* cur = head;
            while(cur->next != nullptr){
                count++;
                cur = cur->next;
            }
            return count;
        }
        // merge
        void merge(DLL<T>* secondDLL){
            this->tail->next = secondDLL->head;
            secondDLL->head->prev = this->tail;
        }
        // destructor
        ~DLL(){
            this->clear();
        }
};

int main(){
    DLL<int>* l1 = new DLL<int>();
    l1->inEnd(10);
    l1->inEnd(20);
    l1->inEnd(30);
    l1->inEnd(40);
    l1->inEnd(50);
    l1->print();
    
    DLL<int>* l2 = new DLL<int>();
    l2->inEnd(60);
    l2->inEnd(70);
    l2->inEnd(80);
    l2->inEnd(90);
    l2->inEnd(100);
    l2->print();

    l1->merge(l2);
    l1->print();
    return 0;

}