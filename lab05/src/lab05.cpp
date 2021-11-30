#include "lab05.hpp"

void printContainer(myContainer a){

    if(a.N == 0){
        std::cout << "Cannot print empty Container." << std::endl;
        return;
    }
    
    std::cout << "[";
    for(int i=0; i<a.N-1; i++){
        std::cout << a.tab[i] << ", ";
    }
    std::cout << a.tab[a.N-1] << "]";
    return;
}

int fibonacci(int n){
    if(n == 0 || n == 1)
        return 1;
    return fibonacci(n-1)+fibonacci(n-2);
}

bool fillContainerWithFibonacci(myContainer *a, int n){

    if(n<1){
        std::cout << "Wrong number of dimensions." << std::endl;
        return false;
    }
    if(a == NULL){
        std::cout << "Empty pointer provided." << std::endl;
        return false;
    }
    if(n>30){
        std::cout << "That's too mach for me!" << std::endl;
        return false;
    }

    a->N = n;
    for(int i=0; i<a->N; i++)
        a->tab[i] = fibonacci(i);

    return true;
}

void checkContainerSpouse(myContainer *a){

    if(a->spouse == NULL){
        printContainer(*a);
        std::cout << " has no spouse." << std::endl;
        return;
    }

    printContainer(*a);
    std::cout << " is paired with ";
    printContainer(*(a->spouse));
    std::cout << std::endl;
    return;
}

void marry(myContainer *a, myContainer *b){

    if(a == b){
        std::cout << "Can't marry myself" << std::endl;
        return;
    }
    if(a->N == b->N){
        bool same = true;
        for(int i=0; i<a->N; i++){
            if(a->tab[i] != b->tab[i]){
                same = false;
                break;
            }
        }
        if(same == true){
            std::cout << "Can't marry my twin" << std::endl;
            return;
        }
    }

    a->spouse = b;
    b->spouse = a;
    return;
}

void divorce(myContainer *a, myContainer *b){

    a->spouse = NULL;
    b->spouse = NULL;
    return;
}

myContainer formChild(myContainer *a, myContainer *b){

    myContainer child;
    child.N = 0;
    if(a == NULL && b == NULL){
        std::cout << "I ain't God." << std::endl;
        return child;
    }

    if((a==NULL && b!=NULL) || (a!=NULL && b==NULL)){
        std::cout << "No partenogenesis possible." << std::endl;
        return child;
    }

    if(!(a == b->spouse && b == a->spouse)){
        std::cout << "Only spouses may have children." << std::endl;
        return child;
    }

    child.N = a->N + b->N;
    int i=0;
    for(; i<a->N; i++)
        child.tab[i] = a->tab[i];
    for(int j=0; j<b->N; j++, i++)
        child.tab[i] = b->tab[j];

    child.parents[0] = a;
    child.parents[1] = b;

    return child;
}

void printParents(myContainer *a){

    if(a->parents[0] == NULL && a->parents[1] == NULL){
        printContainer(*a);
        std::cout << " has no parents." << std::endl;
        return;
    }

    std::cout << "Parents of "; printContainer(*a);
    std::cout << " are "; printContainer(*(a->parents[0]));
    std::cout << " and "; printContainer(*(a->parents[1]));
    std::cout << std::endl << std::endl;
    return;
}