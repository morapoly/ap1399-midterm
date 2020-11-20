template <class T>
APMaxHeap<T>::APMaxHeap(){
    // arr = nullptr;
}

template <class T>
APMaxHeap<T>::APMaxHeap(const APMaxHeap<T> &ap){
    arr = ap.arr;
}

template <class T>
APMaxHeap<T>& APMaxHeap<T>::push(T &&node_value){
    int j{ int(arr.size())+1 };
    T* temp = &node_value;
    if (arr.size()==0) arr.push_back(&node_value);
    else{
        if ( node_value < *arr[j/2-1] ) arr.push_back(&node_value);
        else{
            arr.push_back(&node_value);
            while( j/2-1 >= 0 && *arr[j-1] > *arr[j/2-1] ){
                temp = arr[j/2-1];
                arr[j/2-1] = arr[j-1];
                arr[j-1] = temp;
                j = j/2;
            }
        }
    }
    return *this;
}

template <class T>
APMaxHeap<T>& APMaxHeap<T>::pop(){
    arr.pop_back();
    return *this;
}

template <class T>
const APMaxHeap<T>& APMaxHeap<T>::operator+(T node_value){
    // auto nv = std::forward<T>(node_value);
    // APMaxHeap<T> temp = *this;
    push(std::forward<T>(node_value));  // Conversion from Rvalue to Lvalue
    return *this;
}

template <class T>
APMaxHeap<T>& APMaxHeap<T>::operator=(APMaxHeap<T> &ap){
    *this = ap;
    return ap;
}

template <class T>
std::vector<T> APMaxHeap<T>::show() const{
    std::vector<T> temp;
    std::cout << "APMaxHeap:" << std::endl;
    if (arr.size() == 0){
        std::cout << "Empty!" << std::endl;
    }
    for (size_t i{}; i < arr.size(); i++){
        std::cout <<  *arr[i] << ", ";
        temp.push_back(*arr[i]);
    }
    std::cout << std::endl;
    return temp;
}