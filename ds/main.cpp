#include "./linkedlist/linkList.h"
#include <iostream>

int main(){
    LL<int> l;
    l.delAfter(10);
    l.delBefore(10);
    l.delEnd();
    l.delStart();
    l.delValue(10);
    l.print();

    l.inStart(10);
    l.inEnd(20);
    l.inStart(30);
    l.inEnd(40);

    l.inAfter(50,10);
    l.inAfter(30,1);
    l.inAfter(20,2);
    l.inAfter(40,3);
    l.print();

    return 0;
}