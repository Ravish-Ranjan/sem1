#include "./tree/binaryTree.h"
#include <iostream>

int main(){
    BinTree<int>* b = new BinTree<int>();
    b->printTree(b->root);
    std::cout << "------------" << std::endl;
    b->root = b->insert(30,b->root);
    b->root = b->insert(10,b->root);
    b->root = b->insert(20,b->root);
    b->root = b->insert(50,b->root);
    b->printTree(b->root);
    std::cout << "------------" << std::endl;
    std::cout << "Preorder : " ;
    b->preOrder(b->root) ;
    std::cout << std::endl;
    std::cout << "Inorder : " ;
    b->inOrder(b->root) ;
    std::cout << std::endl;
    std::cout << "Postorder : " ;
    b->postOrder(b->root) ;
    std::cout << std::endl;
    std::cout << "Leaves : " << b->countLeave(b->root) << std::endl;
    std::cout << "Height : " << b->height(b->root) << std::endl;
    
    b->root = b->deleteNode(10,b->root);
    std::cout << "------------" << std::endl;
    b->printTree(b->root);
    std::cout << "Height : " << b->height(b->root) << std::endl;
    std::cout << "------------" << std::endl;
    b->root = b->deleteNode(30,b->root);
    b->printTree(b->root);
    std::cout << "Height : " << b->height(b->root) << std::endl;
    std::cout << "------------" << std::endl;

    return 0;
}