// all necessary C libraries
#include "stdlib.h"
#include "stdbool.h"
#include "stdio.h"

// array cannot be longer than that
#define MAX_ARRAY_LENGTH 50

// defining structure containing everything what's needed
struct myArray{

    // stores actual length of an array
    int N;
    // an array with numbers
    int tab[MAX_ARRAY_LENGTH];
    // points to spouse
    struct myArray *spouse;
};

// lots of self-explanatory functions
void prepareArray(struct myArray *);
void printArray(struct myArray);
bool fillArrayWithFibonacci(struct myArray *, int);
void revert(struct myArray *);
void extend(struct myArray *, int);
void truncate(struct myArray *, int);
void checkArraySpouse(struct myArray *);
void marry(struct myArray *, struct myArray *);
void divorce(struct myArray *, struct myArray *);