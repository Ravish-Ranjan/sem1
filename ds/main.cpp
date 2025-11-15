#include <iostream>
#include "./graph/bfs.h"

int main(){
    SinNode<char>* n1 = new SinNode<char>('a');
    SinNode<char>* n2 = new SinNode<char>('b');
    SinNode<char>* n3 = new SinNode<char>('c');
    SinNode<char>* n4 = new SinNode<char>('d');
    SinNode<char>* n5 = new SinNode<char>('e');
    SinNode<char>* n6 = new SinNode<char>('f');
    SinNode<char>* n7 = new SinNode<char>('g');

    n1->adj.push_back(n2); // 1-> 2
    n2->adj.push_back(n3); // 2 -> 3,4,5,7
    n2->adj.push_back(n4);
    n2->adj.push_back(n5);
    n2->adj.push_back(n7);
    n7->adj.push_back(n6); // 7 -> 6
    // n6->adj.push_back(n1);

    BFS<char>(n1);
    n1->visited = false;
    n2->visited = false;
    n3->visited = false;
    n4->visited = false;
    n5->visited = false;
    n6->visited = false;
    n7->visited = false;



    return 0;
}