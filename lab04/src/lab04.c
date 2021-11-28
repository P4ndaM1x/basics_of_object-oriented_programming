#include "lab04.h"

void prepareArray(struct myArray *a){
    
    // setting default values
    a->N = 0;
    for(int i=0; i<MAX_ARRAY_LENGTH; i++)
        a->tab[i] = 0;
    a->spouse = NULL;
}

void printArray(struct myArray a){

    // what to do if array empty
    if(a.N == 0){
        printf("Cannot print empty array.\n");
        return;
    }

    // pretty printing
    printf("[%d", a.tab[0]);
    for(int i=1; i<a.N; i++)
        printf(",%d", a.tab[i]);
    printf("]");

    return;
}

bool fillArrayWithFibonacci(struct myArray *a, int n){

    // validating parameters of functiboundary conditionson
    if(n==0){
        printf("Wrong number of dimensions.\n");
        return false;
    }
    if(a == NULL){
        printf("Empty pointer provided.\n");
        return false;
    }

    // setting boundary conditions
    a->N = n;
    a->tab[0] = 1;
    if(n>1)
        a->tab[1] = 1;
    
    // filling array with fibonacci sequence
    if(n>2)
        for(int i=2; i<n; i++)
            a->tab[i] = a->tab[i-1] + a->tab[i-2];

    return true;
}

void revert(struct myArray *a){

    // fancy way to revert array from edges
    int first = 0;
    int last = a->N-1;
    while(first<last){
        int temp = a->tab[first];
        a->tab[first++] = a->tab[last];
        a->tab[last--] = temp;
    }

    printArray(*a);
    printf(" (reverting done)\n");

    return;
}

void extend(struct myArray *a, int n){

    // to not exceed array length limit
    if(n+a->N > MAX_ARRAY_LENGTH){
        printf("Wow, you've just gone crazy (%d>%d).\n", n+a->N, MAX_ARRAY_LENGTH);
        return;
    }

    // updating info about array length
    a->N += n;

    printArray(*a);
    printf(" (extending by %d done)\n", n);

    return;
}

void truncate(struct myArray *a, int n){

    // to not save negative value as array length
    if(n+a->N < 0){
        printf("Hey, array can't be that small (%d<0).\n", a->N-n);
        return;
    }

    // updating info about array length
    a->N -= n;

    printArray(*a);
    printf(" (truncation by %d done)\n", n);

    return;
}

void checkArraySpouse(struct myArray *a){

    // printing info about spouse
    if(a->spouse == NULL){
        printArray(*a);
        printf(" has no spouse.\n");
    }

    return; 
}

void marry(struct myArray *a, struct myArray *b){

    // validating potential spouse
    if(a == b){
        printf("Can't marry myself\n");
        return;
    }
    else{
        if(a->N == b->N){
            bool same = true;
            for(int i=0; i<a->N; i++){
                if(a->tab[i] != b->tab[i]){
                    same = false;
                    break;
                }
            }
            if(same == true){
                printf("Can't marry my twin\n");
                return;
            }
        }
    } 

    // printing info about spouse
    a->spouse = b;
    checkArraySpouse(a);
    printArray(*a); printf(" is paired with "); printArray(*b); printf("\n");
    b->spouse = a;
    checkArraySpouse(b);
    printArray(*b); printf(" is paired with "); printArray(*a); printf("\n");

    return;
}

void divorce(struct myArray *a, struct myArray *b){

    a->spouse = NULL;  
    checkArraySpouse(a);
    b->spouse = NULL;  
    checkArraySpouse(b);

    return;
}