// Task description //
/*
  Create two classes - "Grade" representing a student's grade and "GradeBook" that aggregates them.
  Implement all their functionalities according to this file.

  Remarks:
    - arrays should dynamically change their size
    - use of static variables is forbidden
    - the main.cpp file must not be modified
    - the program should not leak any memory
*/

// Actual code //
#include <iostream>
#include "GradeBook.hpp"

int ID = 1;

int main(){

  const Grade arek("Arkadiusz", 3.0);
  //arek.SetStudent("Arek"); // error: passing ‘const Grade’ as ‘this’ argument discards qualifiers
  arek.Print("[info]:: ");
  std::cout<<"[info]:: grade value "<< arek.Value(4.0) << std::endl;
  
  GradeBook grades; // stores grades in an array of const Grade*
  grades.Insert(arek);
  grades.GetPtrConst(0)->Value(5.0);
  //grades.GetPtrConst(0)->SetStudent("Arkadiusz"); // error: passing ‘const Grade’ as ‘this’ argument discards qualifiers
  grades.Print("[info]:: GradeBook:: ");
  std::cout<<"\n";
  grades.Insert(new Grade("An", 3.0));
  grades.GetPtr(1)->SetStudent("Anna");

  grades.Insert(new const Grade("Jowita", 3.5));
  grades.Print("[info]:: GradeBook:: ");
  //grades.GetPtr(2)->SetStudent("Joanna"); // undefined behavior!

  return 0;
}

// Expected output //
/*
  [info]:: Student (Arkadiusz) grade (ID=1) = 3
  [info]:: grade value 4
  [info]:: GradeBook:: Student (Arkadiusz COPY) grade (ID=1) = 5

  [info]:: GradeBook:: Student (Arkadiusz COPY) grade (ID=1) = 5
  [info]:: GradeBook:: Student (Anna) grade (ID=2) = 3
  [info]:: GradeBook:: Student (Jowita) grade (ID=3) = 3.5
*/