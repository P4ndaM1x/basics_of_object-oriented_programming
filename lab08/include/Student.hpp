// to include only once
#pragma once
// to handle output
#include <iostream>

// including Grade class functionality
#include "Grade.hpp"
// forward declaration of a Grade class
class Grade;

// student class declaration
class Student{

    public:
        // creates a Student class and initializes it with provided student ID
        Student(int);
        // deallocates used memory
        ~Student();

        // prints student ID and all his grades
        void print() const;
        // returns student ID
        int get_id() const;
        // sets student ID
        void set_id(int);
        // returns pointer to an array of student's grades
        int* get_grades() const;
        // sets pointer to an array of student's grades
        void set_grades(int*) const;
        // returns how many grades student have
        int get_grades_num() const;
        // adds 1 to variable storing length of an array of student's grades
        void increment_grades_num() const;
    
    private:
        // student ID
        int _id;
        // pointer to the array with student's grades
        int** _grades;
        // pointer to the number of student's grades
        int* _grades_num;
};

/* inline definitions */
inline int Student::get_id() const{
    return _id;
}
inline void Student::set_id(int id){
    _id = id;
}
inline int* Student::get_grades() const{
    return *_grades;
}
inline void Student::set_grades(int* grades) const{
    *_grades = grades;
}
inline int Student::get_grades_num() const{
    return *_grades_num;
}
/* inline definitions */