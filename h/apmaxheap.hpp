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

template <>     // Class template specializaton for class Student (template overloading)
APMaxHeap<Student>& APMaxHeap<Student>::push(Student &&node_value){
    int j{ int(arr.size())+1 };
    Student* temp = &node_value;
    if (arr.size()==0) arr.push_back(&node_value);
    else{
        if ( node_value.getAverage() < arr[j/2-1]->getAverage() ) arr.push_back(&node_value);
        else{
            arr.push_back(&node_value);
            while( j/2-1 >= 0 && arr[j-1]->getAverage() > arr[j/2-1]->getAverage() ){
                temp = arr[j/2-1];
                arr[j/2-1] = arr[j-1];
                arr[j-1] = temp;
                j = j/2;
            }
        }
    }
    return *this;
}

template <>     // Implementation of new function specialized for class Student
APMaxHeap<Student>& APMaxHeap<Student>::push(Student &node_value){
    int j{ int(arr.size())+1 };
    Student* temp = &node_value;
    if (arr.size()==0) arr.push_back(&node_value);
    else{
        if ( node_value.getAverage() < arr[j/2-1]->getAverage() ) arr.push_back(&node_value);
        else{
            arr.push_back(&node_value);
            while( j/2-1 >= 0 && arr[j-1]->getAverage() > arr[j/2-1]->getAverage() ){
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
    size_t j{1};
    T* temp;
    if (arr.size() == 0) return *this;
    else if (arr.size() == 1){
        arr.pop_back();
        return *this;
    }
    else{
        arr[0] = arr[arr.size()-1];
        arr.pop_back();
        while( 2*j <= arr.size() ){
            // Left child comparisson
            if( *arr[2*j-1] > *arr[j-1] && *arr[2*j-1] > *arr[2*j] ){          
                temp = arr[j-1];
                arr[j-1] = arr[2*j-1];
                arr[2*j-1] = temp;
                j = 2*j;
            }
            // Right child comparisson
            else if( *arr[2*j] > *arr[j-1] ){
                temp = arr[j-1];
                arr[j-1] = arr[2*j];
                arr[2*j] = temp;
                j = 2*j+1;
            }
            else break;
        }
    }
    return *this;
}

template <>     // Class template specializaton for class Student (template overloading)
APMaxHeap<Student>& APMaxHeap<Student>::pop(){
    size_t j{1};
    Student* temp;
    if (arr.size() == 0) return *this;
    else if (arr.size() == 1){
        arr.pop_back();
        return *this;
    }
    else{
        arr[0] = arr[arr.size()-1];
        arr.pop_back();
        while( 2*j <= arr.size() ){
            // Left child comparisson
            if( arr[2*j-1]->getAverage() > arr[j-1]->getAverage() && arr[2*j-1]->getAverage() > arr[2*j]->getAverage() ){
                temp = arr[j-1];
                arr[j-1] = arr[2*j-1];
                arr[2*j-1] = temp;
                j = 2*j;
            }
            // Right child comparisson
            else if( arr[2*j]->getAverage() > arr[j-1]->getAverage() ){
                temp = arr[j-1];
                arr[j-1] = arr[2*j];
                arr[2*j] = temp;
                j = 2*j+1;
            }
            else break;
        }
    }
    return *this;
}

template <class T>
APMaxHeap<T> APMaxHeap<T>::operator+(T &&node_value){
    APMaxHeap<T> temp{*this};
    temp.push(std::forward<T>(node_value));  // Conversion from Rvalue to Lvalue  **
    return temp;
}

template <class T>
APMaxHeap<T> APMaxHeap<T>::operator=(APMaxHeap<T> &&ap){
    arr = ap.arr;
    return *this;
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

template <>     // Class template specializaton for class Student (template overloading)
std::vector<Student> APMaxHeap<Student>::show() const{
    std::vector<Student> temp;
    std::cout << "APMaxHeap:" << std::endl;
    if (arr.size() == 0){
        std::cout << "Empty!" << std::endl;
    }
    for (size_t i{}; i < arr.size(); i++){
        std::cout << arr[i]->getID() << ", ";
        temp.push_back(*arr[i]);
    }
    std::cout << std::endl;
    return temp;
}