#include "student.h"

Student::Student(long id, double avg){
    this->id = id;
    average = avg;
}

long Student::getID(){
    return id;
}

double Student::getAverage(){
    return average;
}

void Student::operator+=(double shift_value){
    average = average + shift_value;
}

std::ostream &operator<<(std::ostream &os, Student &s){
    os << s.getID() << ", " << s.getAverage();
    return os;
}