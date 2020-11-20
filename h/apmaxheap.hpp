// #include "apmaxheap.h"
// class APMaxHeap;

template <class T>
APMaxHeap<T>::APMaxHeap(){
    // arr = nullptr;
}

template <class T>
APMaxHeap<T>::APMaxHeap(const APMaxHeap<T> &ap){
    arr2 = ap.arr2;
}

template <class T>
APMaxHeap<T>& APMaxHeap<T>::push(T node_value){
    int* temp = new int{node_value};
    // int temp{node_value};
    arr.push_back(temp);
    arr2.push_back(node_value);
    delete[] temp;
    return *this;
}

template <class T>
APMaxHeap<T>& APMaxHeap<T>::pop(){
    arr2.pop_back();
    return *this;
}

template <class T>
APMaxHeap<T>& APMaxHeap<T>::operator+(T node_value){
    arr2.push_back(node_value);
    return *this;
}

template <class T>
APMaxHeap<T>& APMaxHeap<T>::operator=(APMaxHeap<T> &ap){
    *this = ap;
    return ap;
}

template <class T>
std::vector<T> APMaxHeap<T>::show() const{
    std::cout << "APMaxHeap:" << std::endl;
    if (arr2.size() == 0){
        std::cout << "Empty!" << std::endl;
    }
    // std::vector<T> temp;
    for (size_t i{}; i < arr.size(); i++){
        std::cout <<  arr[i] << ", ";
    }
    std::cout << std::endl;
    return arr2;
}