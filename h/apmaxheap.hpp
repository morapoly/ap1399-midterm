template <class T>
APMaxHeap<T>::APMaxHeap(const APMaxHeap<T> &ap){
    arr = ap.arr;
}

template <class T>
APMaxHeap<T>& APMaxHeap<T>::push(T &&node_value){
    int i{ int(arr.size())+1 };
    T* temp = &node_value;
    if (arr.size()==0) arr.push_back(&node_value);
    else{
        if ( node_value < *arr[i/2-1] ) arr.push_back(&node_value);
        else{
            arr.push_back(&node_value);
            while( i/2-1 >= 0 && *arr[i-1] > *arr[i/2-1] ){
                temp = arr[i/2-1];
                arr[i/2-1] = arr[i-1];
                arr[i-1] = temp;
                i = i/2;
            }
        }
    }
    return *this;
}

template <>     // Implementation of new push function specialized for class Student
APMaxHeap<Student>& APMaxHeap<Student>::push(Student &node_value){
    int i{ int(arr.size())+1 };
    Student* temp = &node_value;
    if (arr.size()==0) arr.push_back(&node_value);
    else{
        if ( node_value.getAverage() < arr[i/2-1]->getAverage() ) arr.push_back(&node_value);
        else{
            arr.push_back(&node_value);
            while( i/2-1 >= 0 && arr[i-1]->getAverage() > arr[i/2-1]->getAverage() ){
                temp = arr[i/2-1];
                arr[i/2-1] = arr[i-1];
                arr[i-1] = temp;
                i = i/2;
            }
        }
    }
    return *this;
}

template <>     // Class template specializaton for class Student (template overloading)
APMaxHeap<Student>& APMaxHeap<Student>::push(Student &&node_value){
    return push(node_value);
}

template <class T>
APMaxHeap<T>& APMaxHeap<T>::pop(){
    size_t i{1};
    T* temp;
    if (arr.size() == 0) return *this;
    else if (arr.size() == 1){
        arr.pop_back();
        return *this;
    }
    else{
        arr[0] = arr[arr.size()-1];
        arr.pop_back();
        while( 2*i <= arr.size() ){
            // Left child comparisson
            if( *arr[2*i-1] > *arr[i-1] && *arr[2*i-1] > *arr[2*i] ){          
                temp = arr[i-1];
                arr[i-1] = arr[2*i-1];
                arr[2*i-1] = temp;
                i = 2*i;
            }
            // Right child comparisson
            else if( *arr[2*i] > *arr[i-1] ){
                temp = arr[i-1];
                arr[i-1] = arr[2*i];
                arr[2*i] = temp;
                i = 2*i+1;
            }
            else break;
        }
    }
    return *this;
}

template <>     // Class template specializaton for class Student (template overloading)
APMaxHeap<Student>& APMaxHeap<Student>::pop(){
    size_t i{1};
    Student* temp;
    if (arr.size() == 0) return *this;
    else if (arr.size() == 1){
        arr.pop_back();
        return *this;
    }
    else{
        arr[0] = arr[arr.size()-1];
        arr.pop_back();
        while( 2*i <= arr.size() ){
            // Left child comparisson
            if( arr[2*i-1]->getAverage() > arr[i-1]->getAverage() && arr[2*i-1]->getAverage() > arr[2*i]->getAverage() ){
                temp = arr[i-1];
                arr[i-1] = arr[2*i-1];
                arr[2*i-1] = temp;
                i = 2*i;
            }
            // Right child comparisson
            else if( arr[2*i]->getAverage() > arr[i-1]->getAverage() ){
                temp = arr[i-1];
                arr[i-1] = arr[2*i];
                arr[2*i] = temp;
                i = 2*i+1;
            }
            else break;
        }
    }
    return *this;
}

template <class T>
APMaxHeap<T> APMaxHeap<T>::operator+(T &&node_value){
    APMaxHeap<T> temp{*this};
    temp.push(std::forward<T>(node_value));  // "std::forward" returs Rvalue
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