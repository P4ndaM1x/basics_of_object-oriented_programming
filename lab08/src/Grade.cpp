#include "Grade.hpp"

Grade::Grade(int grade, const Student& student){
    _grade = grade;
    _student_id = student.get_id();

    student.increment_grades_num();

    int* old_grades = student.get_grades();
    int* new_grades = new int[student.get_grades_num()];

    for(int i=0; i<student.get_grades_num()-1; i++)
        new_grades[i] = old_grades[i];
    new_grades[student.get_grades_num()-1] = _grade;

    student.set_grades(new_grades);

    delete[] old_grades;
}

void Grade::print() const{
    std::cout << "Grade print value=" << _grade << " studentID=" << _student_id << std::endl;
}