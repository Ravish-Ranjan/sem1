#include "./pract/sets.h"
#include <vector>
#include <iostream>

int main(){
    std::vector<int> set1 = {1,2,3,4,5,6,7};
    std::vector<int> set2 = {6,7,8,9,10,11,12};
    std::vector<int> res1 = set_intersection<int>(set1,set2);
    std::vector<int> res2 = set_union<int>(set1,set2);
    std::vector<int> res3 = set_difference<int>(set1,set2);
    std::vector<int> res4 = set_difference<int>(set2,set1);

    std::cout << "Set 1 : " ;
    for(int item:set1) std::cout << item << " ";

    std::cout << "\nSet 2 : " ;
    for(int item:set2) std::cout << item << " ";

    std::cout << "\n\nIntersection : " ;
    for(int item:res1) std::cout << item << " ";

    std::cout << "\nUnion : " ;
    for(int item:res2) std::cout << item << " ";

    std::cout << "\nSet1 - Set2 : " ;
    for(int item:res3) std::cout << item << " ";

    std::cout << "\nSet2 - Set1 : " ;
    for(int item:res4) std::cout << item << " ";

    return 0;
}