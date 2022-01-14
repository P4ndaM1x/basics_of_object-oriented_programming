#include "GradeBook.hpp"

GradeBook::GradeBook() 
    : _n{0}, _grades{nullptr} 
{}

void GradeBook::Insert(const Grade grade){
    const Grade* temp = new Grade(grade.GetStudent(), grade.GetGrade());
    const Grade** old_grades = _grades;
    _grades = new const Grade*[_n+1];
    for(int i=0; i<_n; i++)
        _grades[i] = old_grades[i];
    delete[] old_grades;
    _grades[_n++] = temp;
}

void GradeBook::Insert(const Grade* grade){
    const Grade** old_grades = _grades;
    _grades = new const Grade*[_n+1];
    for(int i=0; i<_n; i++)
        _grades[i] = old_grades[i];
    delete[] old_grades;
    _grades[_n++] = grade;
}

const Grade* GradeBook::GetPtrConst(int i){
    return _grades[i];
}

Grade* GradeBook::GetPtr(int i){
    return const_cast<Grade*>(_grades[i]);
}

void GradeBook::Print(std::string label) const{
    for(int i=0; i<_n; i++){
        std::cout << label;
        _grades[i]->Print();
    }
}

GradeBook::~GradeBook(){ 
    for(int i=0; i<_n; i++)
        delete _grades[i];
    delete[] _grades;
}