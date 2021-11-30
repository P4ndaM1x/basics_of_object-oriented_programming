// to only include once
#pragma once
// max length of table containing numbers in structure myContainer
#define MAX_LENGTH 30
// to handle output
#include <iostream>

// defining container structure
struct myContainer{

    // how many positions in table are really in use
    int N = 0;
    // prefilling table with zeros
    int tab[MAX_LENGTH] = {0};
    // defaultly myContainer has no spouse
    myContainer *spouse = NULL;
    // defaultly myContainer has no parents
    myContainer *parents[2] = {NULL};

};

// simple function printing "tab" from selected myContainer structure
void printContainer(myContainer);

// recursive function returning fibonacci number on selected position in series
int fibonacci(int);

// fills "tab" with specified number of fibonacci series elements
// returns true if everything went well or false if something went wrong
bool fillContainerWithFibonacci(myContainer *, int);

// simple function displaying if provided structure has spouse
void checkContainerSpouse(myContainer *);

// filling "spouse" with each other addresses of provided structures
void marry(myContainer *, myContainer *);

// filling "spouse" in provided structures with NULL
void divorce(myContainer *, myContainer *);

// returns myContainer structure if provided structures are married
// returned child has "N" equal to sum of "N" of its parents
// returned child has "tab" equal to marged "tab"s of its parents 
myContainer formChild(myContainer *, myContainer *);

// simple function printing parents of selected myContainer structure
void printParents(myContainer *);