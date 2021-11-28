// Task description //
/*
  Make a structure representing N-size array.
  Maximum size of the array should be determined by a fixed value of 50.
  The structure is also supposed to contain information about another structrure instance.
  Create appropriate files and implement necessary functions to achieve output given at the and of this file.

  The task verifies knowledge of data types, arrays, structures, loops,
  pointers, functions, control statements and output handling in C language.
  You cannot modify the main.c file!
*/

// Actual code //
#include <stdio.h>
#include "lab04.h"

int main(){

  printf("\n>> Let's start it!\n");
  struct myArray a;
  prepareArray(&a);
  printArray(a);
  printf(">> OK, I forgot to define the number of elements. What about now?\n");
  a.N = 6;
  printArray(a);

  printf("\n\n>> So far, so good... Do you remember Fibonacci? Try it.\n");
  struct myArray b;
  prepareArray(&b);
  printf(fillArrayWithFibonacci(&b, 0) ? "OK!\n" : "Trying again.\n");
  printf(fillArrayWithFibonacci(0, 17) ? "OK!\n" : "One more time.\n");
  printf(fillArrayWithFibonacci(&b, 17) ? "OK!\n" : "I give up.\n");
  printArray(b);

  printf("\n\n>> Let's try to do some fancy staff.\n");
  revert(&b);
  extend(&b, 190);
  extend(&b, 3);
  truncate(&b, 5);
  revert(&b);
  truncate(&b, 9);

  printf("\n>> What if the two arrays couple? Let's check it.\n");
  checkArraySpouse(&a);
  checkArraySpouse(&b);
  printf(">> Will you marry me?\n");
  struct myArray c = a;
  prepareArray(&c);
  marry(&a, &c);
  printf(">> Again, will you marry me?\n");
  marry(&a, &a);
  printf(">> Last time, will you marry me?\n");
  marry(&a, &b);
  checkArraySpouse(&a);
  checkArraySpouse(&b);
  printf(">> \"It's your fault! I quit!\"\n");
  divorce(&a, &b);
  checkArraySpouse(&a);
  checkArraySpouse(&b);

  printf("\n>> The end.\n");
  return 0;
}

// Expected output //
/*

  >> Let's start it!
  Cannot print empty array.
  >> OK, I forgot to define the number of elements. What about now?
  [0,0,0,0,0,0]

  >> So far, so good... Do you remember Fibonacci? Try it.
  Wrong number of dimensions.
  Trying again.
  Empty pointer provided.
  One more time.
  OK!
  [1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597]

  >> Let's try to do some fancy staff.
  [1597,987,610,377,233,144,89,55,34,21,13,8,5,3,2,1,1] (reverting done)
  Wow, you've just gone crazy (207>50).
  [1597,987,610,377,233,144,89,55,34,21,13,8,5,3,2,1,1,0,0,0] (extending by 3 done)
  [1597,987,610,377,233,144,89,55,34,21,13,8,5,3,2] (truncation by 5 done)
  [2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597] (reverting done)
  [2,3,5,8,13,21] (truncation by 9 done)

  >> What if the two arrays couple? Let's check it.
  [0,0,0,0,0,0] has no spouse.
  [2,3,5,8,13,21] has no spouse.
  >> Will you marry me?
  [0,0,0,0,0,0] is paired with Cannot print empty array.

  Cannot print empty array.
  is paired with [0,0,0,0,0,0]
  >> Again, will you marry me?
  Can't marry myself
  >> Last time, will you marry me?
  [0,0,0,0,0,0] is paired with [2,3,5,8,13,21]
  [2,3,5,8,13,21] is paired with [0,0,0,0,0,0]
  >> "It's your fault! I quit!"
  [0,0,0,0,0,0] has no spouse.
  [2,3,5,8,13,21] has no spouse.
  [0,0,0,0,0,0] has no spouse.
  [2,3,5,8,13,21] has no spouse.

  >> The end.
*/