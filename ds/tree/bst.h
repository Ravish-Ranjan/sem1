#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>

template <typename T>
class BinNode{
    public:
        T data;
        BinNode* left = nullptr;
        BinNode* right = nullptr;
        BinNode(T data): data(data){}
};

template <typename T>
class BST{
    public:
        BinNode<T>* root = nullptr;
        
        BinNode<T>* insert(T data, BinNode<T>* root) {
            if (root == nullptr) {
                return new BinNode<T>(data);
            }
            if (data < root->data) {
                root->left = this->insert(data,root->left);
            } else if (data > root->data) {
                root->right = this->insert(data,root->right);
            }
            return root;
        }
        
        BinNode<T>* minValueNode(BinNode<T>* node) {
            BinNode<T>* current = node;
            while (current && current->left != nullptr) {
                current = current->left;
            }
            return current;
        }

        BinNode<T>* deleteNode(T data,BinNode<T>* root ) {
            if (root == nullptr) {
                std::cout << data << "not found" << std::endl;
                return root;
            }
            if (data < root->data) {
                root->left = deleteNode(data, root->left);
            } else if (data > root->data) {
                root->right = deleteNode(data,root->right);
            } else {
                if (root->left == nullptr) {
                    BinNode<T>* temp = root->right;
                    delete root;
                    return temp;
                } else if (root->right == nullptr) {
                    BinNode<T>* temp = root->left;
                    delete root;
                    return temp;
                }
        
                BinNode<T>* temp = minValueNode(root->right);
        
                root->data = temp->data;
                root->right = deleteNode(temp->data,root->right);
            }
            return root;
        }

        BinNode<T>* search(T data, BinNode<T>* root) {
            if (root == nullptr || root->data == data) return root;
            if (data > root->data)
                return search(data,root->right);
            return search(data,root->left);
        }
        
        void preOrder(BinNode<T>* root) {
            if (root == nullptr) return;
            std::cout << root->data << " ";
            preOrder(root->left);
            preOrder(root->right);
        }
        
        void inOrder(BinNode<T>* root ) {
            if (root == nullptr) return;
            inOrder(root->left);
            std::cout << root->data << " ";
            inOrder(root->right);
        }
        
        void postOrder(BinNode<T>* root ) {
            if (root == nullptr) return;
            postOrder(root->left);
            postOrder(root->right);
            std::cout << root->data << " ";
        }
        
        void printTree( BinNode<T>* root ,int space = 0) {
            if (root == nullptr)
                return;
            space += 10;
            printTree(root->right,space);
            std::cout << std::endl;
            for (int i = 10; i < space; i++) std::cout << " ";
            std::cout << root->data << std::endl;
            printTree(root->left,space);
        }

        int height(BinNode<T>* root) {
            if (root == nullptr) return -1;
            return std::max(height(root->left),height(root->right))+1;
        }

        int countLeave(BinNode<T>* root) {
            if (root == nullptr) return 0;
            if (root->left == nullptr && root->right == nullptr) return 1;
            return countLeave(root->left) + countLeave(root->right);
        }

        void clear(BinNode<T>* root){
            if (root == nullptr) return;
            clear(root->left);
            clear(root->right);
            delete root;
        }

        ~BST(){
            this->clear();
        }
};

#endif