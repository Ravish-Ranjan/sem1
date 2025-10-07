#ifndef AVL_H
#define AVL_H

#include <iostream>

template <typename T>
class BinNode;

template <typename T>
int getHeight(BinNode<T>* root){
    if (root) return root->height;
    return 0;
}

int max(int a,int b){
    return a>=b ? a:b;
}

template <typename T>
int getBalance(BinNode<T>* root){
    if (root) return getHeight(root->left) - getHeight(root->right);
    return 0;
}

template <typename T>
class BinNode{
    public:
        T data;
        BinNode* left = nullptr;
        BinNode* right = nullptr;
        int height = 1;
        BinNode(T data):data(data){}
        int getBalance(BinNode<T>* root){
            return getHeight(root->left) - getHeight(root->right); 
        }
};

template <typename T>
class AVL{
    private:
        BinNode<T>* minValNode(BinNode<T>* root){
            BinNode<T>* cur = root;
            while (cur->left != nullptr) cur = cur->left;
            return cur;
        }

        BinNode<T>* leftRotate(BinNode<T>* x){
            BinNode<T>* y = x->right;
            BinNode<T>* T2 = y->left;
            y->left = x;
            x->right = T2;
            x->height = max(getHeight(x->left),getHeight(x->right)) + 1;
            y->height = max(getHeight(y->left),getHeight(y->right)) + 1;
            return y;
        }

        BinNode<T>* rightRotate(BinNode<T>* x){
            BinNode<T>* y = x->left;
            BinNode<T>* T2 = y->right;
            y->right = x;
            x->left = T2;
            x->height = max(getHeight(x->left),getHeight(x->right)) + 1;
            y->height = max(getHeight(y->left),getHeight(y->right)) + 1;
            return y;
        }
    public:
        BinNode<T>* root = nullptr;

        BinNode<T>* insert(T data,BinNode<T>* root){
            if (root == nullptr) return new BinNode<T>(data);
            else if (root->data > data) 
                root->left = insert(data,root->left);
            else if (root->data < data) 
                root->right = insert(data,root->right);
            else return root;

            root->height = 1 + max(getHeight(root->left),getHeight(root->right));

            int balance = getBalance(root);

            if (balance > 1 && data < root->left->data){
                return rightRotate(root);
            }
            if (balance < -1 && data > root->right->data){
                return leftRotate(root);
            }
            if (balance > 1 && data > root->left->data){
                root->left = leftRotate(root->left);
                return rightRotate(root);
            }
            if (balance < -1 && data < root->right->data){
                root->right = rightRotate(root->right);
                return leftRotate(root);
            }
            return root;
        } 

        BinNode<T>* remove(T data,BinNode<T>* root){
            if (root == nullptr) return root;
            else if (data < root->data)
                root->left = remove(data,root->left);
            else if (data > root->data)
                root->right = remove(data,root->right);
            else{
                if ((root->left == nullptr) || (root->right == nullptr)){
                    BinNode<T>* temp = root->left? root->left : root->right;
                    if (temp == nullptr){
                        temp = root;
                        root = nullptr;
                    } else {
                        *root = *temp;
                    }
                    delete temp;
                } else {
                    BinNode<T>* temp = minValNode(root->right);
                    root->data = temp->data;
                    root->right = remove(temp->data,root->right);
                }
            }

            if (root == nullptr) return root;
            root->height = 1 + max(getHeight(root->left),getHeight(root->right));
            int balance = getBalance(root);

            if (balance > 1 && getBalance(root->left) >= 0)
                return rightRotate(root);
            if (balance < -1 && getBalance(root->right) <= 0){
                return leftRotate(root);
            }
            if (balance > 1 && getBalance(root->left) < 0){
                root->left = leftRotate(root->left);
                return rightRotate(root);
            }
            if (balance < -1 && getBalance(root->right) > 0){
                root->right = rightRotate(root->right);
                return leftRotate(root);
            }
            return root;
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
        
        void printTree(BinNode<T>* root, int space = 0) {
            if (root == NULL) return;
            space += 10;
            printTree(root->right, space);
            std::cout << std::endl;
            for (int i = 10; i < space; i++) std::cout << " ";
            std::cout << root->data << std::endl;
            printTree(root->left, space);
        }

        void clear(BinNode<T>* root){
            if (root == nullptr) return;
            clear(root->left);
            clear(root->right);
            delete root;
        }

        ~AVL(){
            this->clear();
        }
};

#endif