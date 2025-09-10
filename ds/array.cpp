#include <iostream>
#include <vector>

template <class T,int max_size = 0>
class Array{
    private:
        std::vector<T> arr ;
        int size = max_size;
    public:
        Array(const std::vector<T>& array){
            if(array.size() > max_size){
                throw "size exceeds max size";
                return ;
            }
            arr.resize(max_size);
            for (int i = 0; i < array.size(); i++)
                arr[i] = array[i];
            size = array.size();
        }
        void print(){
            std::cout << "Arr : " ;
            for (int i = 0; i < size;i++)
                std::cout << arr[i] << " ";
            std::cout << std::endl;
        }
        void append(T value){
            if(size >= max_size){
                throw "array size limit reached";
                return;
            }
            arr[size] = value;
            size++;
        }
        void insert(T value,int index){
            if(index > size || index < 0 || size == max_size){
                throw "array size limit reached";
            }
            for (int i = size;i > index;i--)
                arr[i] = arr[i-1];
            arr[index] = value;
            size++;
        }
        T deleteElem(int index){
            if(index >= size || index < 0){
                throw "index out of bound";
            }
            T deleted = arr[index];
            for (int i = index; i < size-1; i++)
                arr[i] = arr[i+1];
            size--;
            return deleted;
        }
        int search(T value){
            for (int i = 0; i < size; i++)
                if (arr[i] == value) return i;
            return -1;
        }
        T get(int index){
            if (index >= size || index < 0) {
                throw "index out of bound";
            }
            return arr[index];
        }
        void set(T value,int index){
            if (index >= size || index < 0){
                throw "index out of bound";
            }
            arr[index] = value;
        }
        T min(){
            if(size <= 0){
                throw "empty array";
            }
            T minVal = arr[0];
            for (int i = 0;i < size;i++)
                if (arr[i] < minVal) minVal = arr[i];
            
            return minVal;
        }
        T max(){
            if(size <= 0){
                throw "empty array";
            }
            T maxVal = arr[0];
            for (int i = 0;i < size;i++){
                if (arr[i] > maxVal) maxVal = arr[i];
            }
            return maxVal;
        }
};

int main(){
    std::vector<int> arrVec = {1,2,3,4,5,6,7,8};
    Array<int,10>* arr = new Array<int,10>(arrVec);
    
    std::cout << "Initially array" << std::endl;
    arr->print();
    
    std::cout << "\nAdding 9 in last" << std::endl;
    arr->append(9);
    arr->print();
    
    std::cout << "\nAdding 10 at index 1" << std::endl;
    arr->insert(10,1);
    arr->print();
    
    std::cout << "\nDeleting element at index 1" << std::endl;
    arr->deleteElem(1);
    arr->print();
    
    std::cout << "\nSearching 5 in array" << std::endl;
    int at = arr->search(5);
    if (at >= 0) std::cout << "Found at index : " << at << std::endl;
    else std::cout << "Not found"<< std::endl;
    
    std::cout << "\nSearching 11 in array" << std::endl;
    at = arr->search(11);
    if (at >= 0) std::cout << "Found at index : " << at << std::endl;
    else std::cout << "Not found"<< std::endl;

    std::cout << "\nGetting element at index 6" << std::endl;
    std::cout << "Element : " << arr->get(6) << std::endl;
    
    std::cout << "\nSetting 2 at index 0" << std::endl;
    arr->set(2,0);
    arr->print();

    std::cout << "\nMinimum in array : " << arr->min() << std::endl;

    std::cout << "\nMaximum in array : " << arr->max() << std::endl;
    return 0;
}