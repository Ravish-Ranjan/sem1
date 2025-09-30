#include "./tree/avl.h"
#include <iostream>

int main(){
    AVL<int>* t = new AVL<int>();
    std::cout << "first" <<std::endl;
    t->printTree(t->root);
    t->root = t->insert(10,t->root);
    std::cout << "second" <<std::endl;
    t->printTree(t->root);
    t->root = t->insert(20,t->root);
    std::cout << "third" <<std::endl;
    t->printTree(t->root);
    t->root = t->insert(30,t->root);
    std::cout << "fourth" <<std::endl;
    t->printTree(t->root);
    return 0;
}