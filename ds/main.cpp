#include "./tree/avl.h"
#include <iostream>

int main(){
    AVL<int>* t = new AVL<int>();
    t->root = t->insert(10,t->root);
    t->root = t->insert(20,t->root);
    t->root = t->insert(30,t->root);
    t->root = t->insert(40,t->root);
    t->root = t->insert(50,t->root);
    t->root = t->insert(60,t->root);
    std::cout << "--------------------" << std::endl;
    t->printTree(t->root);
    std::cout << "--------------------" << std::endl;
    std::cout << "PreOrder : ";
    t->preOrder(t->root); 
    std::cout << std::endl;
    std::cout << "InOrder : "; 
    t->inOrder(t->root); 
    std::cout << std::endl;
    std::cout << "PostOrder : "; 
    t->postOrder(t->root); 
    std::cout << std::endl;
    t->root = t->remove(70,t->root);
     std::cout << "--------------------" << std::endl;
    t->printTree(t->root);
    std::cout << "--------------------" << std::endl;
    t->root = t->remove(10,t->root);
     std::cout << "--------------------" << std::endl;
    t->printTree(t->root);
    std::cout << "--------------------" << std::endl;
    t->root = t->remove(60,t->root);
     std::cout << "--------------------" << std::endl;
    t->printTree(t->root);
    std::cout << "--------------------" << std::endl;
    t->root = t->insert(10,t->root);
    t->root = t->insert(60,t->root);
     std::cout << "--------------------" << std::endl;
    t->printTree(t->root);
    std::cout << "--------------------" << std::endl;
    
    return 0;
}