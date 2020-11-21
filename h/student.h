#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>

class Student{
    private:
        long id;
        double average;
    public:
        Student(long id, double avg);
        long getID();
        double getAverage();
        void operator+=(double shift_value);
        friend std::ostream &operator<<(std::ostream &os, Student &s);
};

#endif