#ifndef APMAXHEAP_H
#define APMAXHEAP_H

#include <iostream>
#include <vector>

template <class T>
class APMaxHeap{
    public:
        APMaxHeap() = default;
        ~APMaxHeap() = default;
        APMaxHeap(const APMaxHeap<T> &ap);
        APMaxHeap<T>& push(T &&node_value);
        APMaxHeap<Student>& push(Student &node_value);
        APMaxHeap<T>& pop();
        APMaxHeap<T> operator+(T &&node_value);
        APMaxHeap<T> operator=(APMaxHeap<T> &&ap);
        std::vector<T> show() const;
    private:
        std::vector<T*> arr;
};

#include "apmaxheap.hpp"

#endif