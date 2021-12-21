// Task description //
/*
  Create two classes - Grade and Student with their functionalities according to this file.
  
  Remarks:
    - arrays should dynamically change their size
    - use of the mutable type specifier is forbidden
    - the main.cpp file must not be modified
    - the program should not leak any memory
*/

// Actual code //
#include <iostream>
#include "Grade.hpp"
#include "Student.hpp"

int main() {

  using std::cout;

  cout<<"DENIS\n";

  const Student denis (2);
  denis.print();
  const Grade denisMath (4, denis);
  denis.print();
  const Grade denisPhysics (5, denis);
  denis.print();
  denisPhysics.print();

  cout<<"MARK\n";

  const Student mark (3);
  mark.print();
  const Grade markPhysics (3, mark);
  mark.print();
  markPhysics.print();

  cout<<"DENIS and MARK\n";

  mark.print();
  denis.print();

  return 0;
}

// Expected output //
/*
  DENIS
  Student print ID=2 grades:
  Student print ID=2 grades: 4
  Student print ID=2 grades: 4 5
  Grade print value=5 studentID=2
  MARK
  Student print ID=3 grades:
  Student print ID=3 grades: 3
  Grade print value=3 studentID=3
  DENIS and MARK
  Student print ID=3 grades: 3
  Student print ID=2 grades: 4 5
*/