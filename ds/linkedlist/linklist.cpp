#include <iostream>

template <class T>
class Node{
    public:
        T value;
        Node *next = nullptr;
        Node(T value) : value(value){}
        void print(){
            std::cout << "(" << this->value << ")->" << this->next << std::endl;
        }
};

template <class T>
class LL{
    public:
        Node<T> *head = nullptr;
        void inStart(T value){
            Node<T> *newNode = new Node<T>(value);
            if (head == nullptr){
                head = newNode;
            }
            else{
                newNode->next = head;
                head = newNode;
            }
        }
        void inEnd(T value){
            Node<T> *newNode = new Node<T>(value);
            if (head == nullptr){
                head = newNode;
            }
            else{
                Node<T> *cur = head;
                while (cur->next != nullptr){
                    cur = cur->next;
                }
                cur->next = newNode;
            }
        }
        T delStart(){
            if (head != nullptr){
                Node<T> *temp = head;
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
                Node<T> *temp = head;
                head = nullptr;
                T ret = temp->value;
                delete temp;
                return ret;
            }
            else{
                Node<T> *cur = head;
                while (cur->next->next != nullptr)
                    cur = cur->next;
                Node<T> *temp = cur->next;
                cur->next = nullptr;
                T ret = temp->value;
                delete temp;
                return ret;
            }
        }
        void clear(){
            Node<T> *cur = head;
            while (cur->next != nullptr){
                Node<T> *temp = cur;
                cur = cur->next;
                delete temp;
            }
            head = nullptr;
        }
        void print(){
            Node<T> *cur = head;
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
            Node<T> *cur = head;
            while (cur->next != nullptr && cur->value != after)
                cur = cur->next;
            if (cur->value == after){
                Node<T> *newNode = new Node<T>(value);
                newNode->next = cur->next;
                cur->next = newNode;
            }
        }
        T delAfter(T after){
            if (head == nullptr)
                return T();
            Node<T> *cur = head;
            while (cur->next != nullptr && cur->value != after)
                cur = cur->next;
            if (cur->next == nullptr)
                return T();
            else if (cur->value == after){
                Node<T> *temp = cur->next;
                cur->next = cur->next->next;
                T ret = temp->value;
                delete temp;
                return ret;
            }
        }
        bool find(T value,bool print = false){
            if (head == nullptr)
                return false;
            Node<T> *cur = head;
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
            Node<T>* cur = head;
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

// int main(){
//     LL<int> l1 = LL<int>();
//     std::cout << "insert start 10" << std::endl;
//     l1.inStart(10);
//     l1.print();
//     std::cout << "insert start 20" << std::endl;
//     l1.inStart(20);
//     l1.print();
//     std::cout << "delete start" << std::endl;
//     l1.delStart();
//     l1.print();
//     std::cout << "insert end 30" << std::endl;
//     l1.inEnd(30);
//     l1.print();
//     std::cout << "insert end 40" << std::endl;
//     l1.inEnd(40);
//     l1.print();
//     std::cout << "delete end" << std::endl;
//     l1.delEnd();
//     l1.print();
//     std::cout << "insert 20 after 10" << std::endl;
//     l1.inAfter(10, 20);
//     l1.print();
//     std::cout << "delete after 10" << std::endl;
//     l1.delAfter(10);
//     l1.print();
//     std::cout << "finding 20" << std::endl;
//     l1.find(20);
//     std::cout << "finding 100" << std::endl;
//     l1.find(100);
//     std::cout << "clear list" << std::endl;
//     l1.clear();
//     l1.print();
//     std::cout << "list size" << std::endl;
//     std::cout << "Size : " << l1.getSize() << std::endl;

//     return 0;
// }