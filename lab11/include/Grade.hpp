// to only include once
#pragma once

// adding necessary libraries
#include <iostream>
#include <string>

// counter storing ID of the next created Grade
extern int ID;

// stores student's grade
class Grade{

    public:
        // creates class instance with name and grade of the student
        Grade(std::string = "", double = 0);
        // copy constructor that adds " COPY" to the name of the student
        Grade(const Grade&);
        // prints a grade along with its ID, student it belongs to and optional label
        void Print(std::string = "") const;
        // sets a name of the student's grade
        void SetStudent(std::string);
        // sets a grade and returns it
        double Value(double) const;
        // returns name of the student's grade
        std::string GetStudent() const;
        // returns student's grade
        double GetGrade() const;

    private:
        // student's grade
        mutable double _grade;
        // grade ID
        int _grade_id;
        // name of the student
        std::string _student;
};

// definitions of class constructors
inline Grade::Grade(std::string student, double grade) 
    : _grade{grade}, _student{student} 
{ _grade_id = ID++; }
inline Grade::Grade(const Grade& grade) 
    : _grade{grade._grade}, _grade_id{grade._grade_id}, _student{grade._student + " COPY"} 
{ ID--; }

// definitions of inline methods
inline void Grade::Print(std::string s) const{
    std::cout << s << "Student (" << _student << ") grade (ID=" << _grade_id << ") = " << _grade << std::endl;
}
inline void Grade::SetStudent(std::string student){
    _student = student;
}
inline double Grade::Value(double grade) const{
    _grade = grade;
    return _grade;
}
inline std::string Grade::GetStudent() const{
    return _student;
}
inline double Grade::GetGrade() const{
    return _grade;
}