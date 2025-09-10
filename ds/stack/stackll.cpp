#include <iostream>
#include "../linkedlist/linklist.cpp"

template <class T>
class Stack{
    private:
        LL<T>* stack = nullptr;
    public:
        Node<T>* top = nullptr;
        Stack(){
            this->stack = new LL<T>();
            this->top = stack->head;
        }
        bool isEmpty(){
            return top == nullptr;
        }
        bool isFull(){
            try            {
                Node<T>* newNode = new Node<T>(10);
                delete newNode;
                return false;
            }
            catch(const std::exception& e)            {
                return true;
            }
        }
        void push(T value){
            if (this->isFull()){
                throw std::runtime_error("Stack Overflow");
            } else {
                this->stack->inStart(value);
                this->top = stack->head;
            }
        }
        T pop(){
            if(this->isEmpty()){
                throw std::runtime_error("Stack Underflow");
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
            Node<T>* cur = stack->head;
            while (cur != nullptr){
                std::cout << "|" << cur->value;
                cur = cur->next;
            }
            std::cout << "]" << std::endl;
        }
};

int main(){
    Stack<int>* s = new Stack<int>();
    s->print();
    s->push(10);
    s->print();
    s->push(20);
    s->print();
    s->push(30);
    s->print();
    int ret = s->pop();
    s->print();
    std::cout << "return : " << ret << std::endl;
    s->pop();
    s->print();
    s->pop();
    s->print();
    // s->pop();
    // std::cout << "Peak : " << s->peak() << std::endl; 
    // s->print();
    s->push(40);
    s->print();
    ret = s->peak();
    std::cout << "top : " << ret << std::endl;

    return 0;
}