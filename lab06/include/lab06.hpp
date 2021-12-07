// to only include this header once
#pragma once
// to handle output
#include <iostream>

// variable counting how many sequences were added by addSequence()
int seq_counter = 0;

// returns pointer to the array containing geometrical sequence
// 1. argument - first number in sequence
// 2. argument - sequence ratio
// 3. argument - how many numbers in sequence (length of an array)
const double* initGeometricalSequence(double, double, int);

// returns pointer to the array containing arithmetic sequence
// 1. argument - first number in sequence
// 2. argument - sequence difference
// 3. argument - how many numbers in sequence (length of an array)
const double* initArithmeticSequence(double, double, int);

// prints first int numbers from provided sequence
void printSequence(const double*, int);

// deallocates memory used by provided sequence
void deleteSequence(const double**);

// adds the sequence to the list of sequences
// 1. argument - address of pointer to array of pointers to sequences
// 2. argument - address of pointer to array of sequence lengths
// 3. argument - pointer to added sequence
// 4. argument - length of added sequence
void addSequence(const double***, double**, const double*, int);

// prints all sequences from the list of sequences
// 1. argument - pointer to array of pointers to sequences
// 2. argument - pointer to array of sequence lengths
void printSequence(const double**, double*);

// deallocates memory used to store sequences in the list
// 1. argument - pointer to array of pointers to sequences
// 2. argument - pointer to array of sequence lengths
void deleteSequence(const double**, double*);