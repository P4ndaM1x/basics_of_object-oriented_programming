// to include only once
#pragma once
// to handle output
#include <iostream>

// including Student class functionality
#include "Student.hpp"
// forward declaration of a Student class
class Student;

// grade class declaration
class Grade{

    public:
        // creates a Grade object and assigns proper attributes values
        // 1. argument - student's grade
        // 2. argument - reference to the owner of the grade
        Grade(int, const Student&);
        // prints a grade along with the ID of student it belongs to
        void print() const;
        // returns grade
        int get_grade();
        // returns student ID
        int get_student_id();

    private:
        // stores student's grade
        int _grade;
        // stores ID of the grade owner
        int _student_id;
};

/* inline definitions */
inline int Grade::get_grade(){
    return _grade;
}
inline int Grade::get_student_id(){
    return _student_id;
}
/* inline definitions */