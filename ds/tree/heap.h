#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <math.h>
#include <iostream>

enum HeapType {Min_Heap,Max_Heap};

template <typename T, HeapType H>
class Heap{
    private:
        std::vector<T> heap;
        
        int parent(int index){
            return std::floor((index - 1)/2);
        }
        
        int left(int index){
            return 2*index + 1;
        }

        int right(int index){
            return 2*index + 2;
        }

        void heapifyUp(int index){
            if (index >= heap.size() || index < 0) return;
            int p = parent(index);
            if (H == Min_Heap){
                if (p >= 0 && heap[p] > heap[index]){
                    std::swap(heap[p],heap[index]);
                    heapifyUp(p);
                }
            } else if (H == Max_Heap) {
                if (p >= 0 && heap[p] < heap[index]){
                    std::swap(heap[p],heap[index]);
                    heapifyUp(p);
                }
            }
        }
        
        void heapifyDown(int index){
            if (index >= heap.size() || index < 0) return;
            int l = left(index);
            int r = right(index);
            int alpha = index;
            if (H == Min_Heap){
                if (l < heap.size() && heap[alpha] > heap[l]){
                    alpha = l;
                }
                if (r < heap.size() && heap[alpha] > heap[r]){
                    alpha = r;
                }
            } else if (H == Max_Heap){
                if (l < heap.size() && heap[alpha] < heap[l]){
                    alpha = l;
                }
                if (r < heap.size() && heap[alpha] < heap[r]){
                    alpha = r;
                }
            }
            if (alpha != index){
                std::swap(heap[index],heap[alpha]);
                heapifyDown(alpha);
            }
        }
    public:
        void buildHeap(const std::vector<T>& data){
            if (!heap.empty()){
                std::cout << "Not an empty heap" << std::endl;
                return;
            }
            heap = data;
            int n = heap.size();
            for (int i = n/2 -1; i>=0; i--)
                heapifyDown(i);
        }
        
        void insert(T data){
            heap.push_back(data);
            heapifyUp(heap.size() - 1);
        }
        
        T getTop(){
            if (heap.empty()){
                std::cout << "Empty heap" << std::endl;
                return T();
            }
            return heap[0];
        }

        T extractTop(){
            if (heap.empty()) {
                std::cout << "Empty heap" << std::endl;
                return T();
            }
            T ret = heap[0];
            heap[0] = heap.back();
            heap.pop_back();
            if (!heap.empty()){
                heapifyDown(0);
            }
            return ret;
        }

        void replaceTop(T data){
            if (heap.empty()){
                std::cout << "Empty heap" << std::endl;
                return;
            }
            heap[0] = data;
            heapifyDown(0);
        }

        bool isEmpty(){
            return heap.size() == 0;
        }

        int size(){
            return heap.size();
        }

        void print(int index = 0, int space = 0, int levelSpace = 5) const {
            if (index >= heap.size()) return;
            print(2 * index + 2, space + levelSpace, levelSpace);
            std::cout << std::string(space,' ') << heap[index] << "\n";
            print(2 * index + 1, space + levelSpace, levelSpace);
        }
        
        bool find(T data){
            for (T elem:heap){
                if (elem == data) return true;
            }
            return false;
        }

        void clear(){
            heap.clear();
        }
        
        ~Heap(){
            this->clear();
        }
};



#endif