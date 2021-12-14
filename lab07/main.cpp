// Task description //
/*
  The task is to implement a singly linked list.

  Create two classes: 
    - simple Node class that stores data and pointer to the next list element
    - OneWayList container that holds the pointer to the beginning of the list
  All functionalities should be implemented according to this file.

  Remarks:
    - all class fields (everything except methods) should be private
    - the const keyword should be used wherever its needed
    - the main.cpp file must not be modified
    - the program should not leak any memory 
*/

// Actual code //
#include "lab07.hpp"
#include <cstring>
#include <iostream>

const int kBufferSize = 500;

int main() {

  std::cout << "\t\t\tList #1" << std::endl;
  OneWayList testList;
  
  char buffer[kBufferSize];
  strcpy(buffer, "This");
  testList.add(buffer);
  strcpy(buffer, "is");
  testList.add(buffer);
  testList.add("test");
  testList.add("message");
  testList.add("of");
  testList.add("some");
  testList.add("non-zero");
  testList.add("length");

  OneWayList* ptr2list = &testList;

  std::cout << ptr2list->getHead()->getData() << std::endl;
  std::cout << ptr2list->getHead()->getNext()->getData() << std::endl;

  std::cout << ">> Is the list empty? " << std::boolalpha << ptr2list->empty() << std::endl;
  std::cout << ">> Let's print it:" << std::endl;
  ptr2list->dump();

  std::cout << "\n\n\t\t\tList #2" << std::endl;
  OneWayList drugaLista;
  strcpy(buffer, "Today's task");
  drugaLista.add(buffer);
  strcpy(buffer, "was incredibly easy! (?)");
  drugaLista.add(buffer);
  drugaLista.dump();

  std::cout << "\n\n\t\t\tCleaning" << std::endl;
  testList.clear();
  std::cout << ">> Is the list empty? " 
            << std::boolalpha << testList.empty() << std::endl;
            
  std::cout << ">> What happens if an empty list is dumped?" << std::endl;
  ptr2list->dump();
  
  drugaLista.dump();
  drugaLista.clear();
  drugaLista.clear();

  std::cout << std::endl;
}

// Expected output //
/*
              List #1
  This
  is
  >> Is the list empty? false
  >> Let's print it:
  This is test message of some non-zero length 

              List #2
  Today's task was incredibly easy! (?) 

              Cleaning
  >> Is the list empty? true
  >> What happens if an empty list is dumped?
  Today's task was incredibly easy! (?)
*/