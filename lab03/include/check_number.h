// all necessary C libraries
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// function used to find check digit in the Luhn algorithm
/*
    the argument is a pointer to string containing the card number
    returns found check digit
*/
char find_ctrl(const char *);

// function used to check card number correctness
/*
    the argument is a pointer to string containing the card number
    returns true if the number is correct
    returns false if the number in not correct
*/
bool number_correct(const char *);