#ifndef BFS_H
#define BFS_H

#include <vector>
#include <queue>
#include <iostream>

template <typename T>
class SinNode{
    public:
        T data;
        bool visited = false;
        SinNode<T>* next = nullptr;
        std::vector<SinNode<T>*> adj {};
        SinNode(T data): data(data){}
};


template <typename T>
void BFS(SinNode<T>* src){
    std::queue<SinNode<T>*> q;
    
    src->visited = true;
    q.push(src);

    while (q.size() > 0){
        SinNode<T>* node = q.front();
        q.pop();
        std::cout << "visited : " << node->data << std::endl;
        for (SinNode<T>* neigh:node->adj){
            if (!neigh->visited){
                neigh->visited = true;
                q.push(neigh);
            } else {
                std::cout << "cycle detected" << std::endl;
                return ;
            }
        }
    }

}


#endif