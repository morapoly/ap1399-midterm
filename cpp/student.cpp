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