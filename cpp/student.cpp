#include "student.h"

Student::Student(long id, double avg){
    this->id = id;
    average = avg;
}

long Student::getID() const{
    return id;
}

double Student::getAverage() const{
    return average;
}

void Student::operator+=(double shift_value){
    average = average + shift_value;
}

std::ostream &operator<<(std::ostream &os, const Student &s){
    os << s.getID() << ", " << s.getAverage();
    return os;
}