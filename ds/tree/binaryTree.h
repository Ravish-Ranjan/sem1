#ifndef BINARYTREE_H
#define BINARYTREE_H

template <typename T>
class BinNode{
    public:
        T value;
        BinNode* left = nullptr;
        BinNode* right = nullptr;
        BinNode(T value): value(value){}
};

template <typename T>
class BinTree{
    public:
        BinNode<T>* root = nullptr;
};

#endif