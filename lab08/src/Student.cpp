#include "Student.hpp"

Student::Student(int id){
    set_id(id);
    _grades_num = new int;
    *_grades_num = 0;
    _grades = new int*;
    *_grades = NULL;
}

Student::~Student(){
    if(_grades_num != 0)
        delete[] *_grades;
    delete _grades;
    delete _grades_num;
}

void Student::print() const{
    std::cout << "Student print ID=" << _id << " grades: ";
    for(int i=0; i<*_grades_num; i++)
        std::cout << (*_grades)[i] << " ";
    std::cout << std::endl;
}

void Student::increment_grades_num() const{
    (*_grades_num)++;
}