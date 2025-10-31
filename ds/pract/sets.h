#ifndef SET_H
#define SET_H

#include <vector>

template <typename T>
bool find(const std::vector<T> arr,T elem){
    for(T item:arr) if (item == elem) return true;
    return false;
}

template <typename T>
std::vector<T> set_intersection(std::vector<T>& set1,std::vector<T>& set2){
    if (set1.size() == 0 || set2.size() == 0) return {};
    std::vector<T> inter;

    int set1_len = set1.size();
    int set2_len = set2.size();

    for (int i = 0; i < set1_len; i++){
        T cand1 = set1.front();
        for (int j = 0; j < set2_len; j++){
            T cand2 = set2.front();
            if (cand1 == cand2) inter.push_back(cand1);
            set2.erase(set2.begin());
            set2.push_back(cand2);
        }
        set1.erase(set1.begin());
        set1.push_back(cand1);
    }
    return inter;
}

template <typename T>
std::vector<T> set_difference(std::vector<T>& set1,std::vector<T>& set2){
   if (set1.size() == 0 || set2.size() == 0) return {};
    std::vector<T> setdif;

    int set1_len = set1.size();
    int set2_len = set2.size();

    for (int i = 0; i < set1_len; i++){
        T cand1 = set1.front();
        bool isEqual = false;
        for (int j = 0; j < set2_len; j++){
            T cand2 = set2.front();
            if (cand1 == cand2) isEqual = true;
            set2.erase(set2.begin());
            set2.push_back(cand2);
        }
        if (!isEqual) setdif.push_back(cand1);
        set1.erase(set1.begin());
        set1.push_back(cand1);
    }
    return setdif;
}

template <typename T>
std::vector<T> set_union(std::vector<T>& set1,std::vector<T>& set2){
    if (set1.size() == 0 || set2.size() == 0)
        return set1.size() > set2.size()? set1:set2;
    
    std::vector<T> inter = set_intersection(set1,set2);
    std::vector<T> uni;
    for(T item:set1) if (!find(inter,item)) uni.push_back(item);
    for(T item:set2) if (!find(inter,item)) uni.push_back(item);
    for(T item:inter) uni.push_back(item);
    return uni;
}

#endif