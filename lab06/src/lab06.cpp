#include "lab06.hpp"

const double* initGeometricalSequence(double first, double ratio, int length){

    if(length < 1){
        std::cout << "Size must be non-zero (and positive)" << std::endl;
        return NULL;
    }

    double *seq = new double[length];

    seq[0] = first;
    for(int i=1; i<length; i++)
        seq[i] = ratio*seq[i-1];
    
    return seq;
}

const double* initArithmeticSequence(double first, double diff, int length){
    
     if(length < 1){
        std::cout << "Size must be non-zero (and positive)" << std::endl;
        return NULL;
    }

    double *seq = new double[length];

    seq[0] = first;
    for(int i=1; i<length; i++)
        seq[i] = diff+seq[i-1];
    
    return seq;
}

void printSequence(const double* seq, int length){
    
    if(length < 1){
        std::cout << "Nothing to print." << std::endl;
        return; 
    }
    
    std::cout << "(";
    for(int i=0; i<length-1; i++)
        std::cout << seq[i] << ",";
    std::cout << seq[length-1] << ")" << std::endl;
    return;
}

void deleteSequence(const double** seq){

    if(*seq != NULL){
        delete[] *seq;
        *seq = NULL;
        std::cout << "Sequence deleted." << std::endl;
    }
    else{
        std::cout << "Nothing to delete." << std::endl;
    }
    return;
}

void addSequence(const double*** seq_list, double** len_list, const double* seq, int len){

    seq_counter++;

    const double** old_seq_list = *seq_list;
    double* old_len_list = *len_list;

    *seq_list = new const double*[seq_counter];
    *len_list = new double[seq_counter];

    for(int i=0; i<seq_counter-1; i++){
        (*seq_list)[i] = old_seq_list[i];
        (*len_list)[i] = old_len_list[i];
    }

    delete[] old_len_list;
    delete[] old_seq_list;

    (*seq_list)[seq_counter-1] = seq;
    (*len_list)[seq_counter-1] = len;
    return;
}

void printSequence(const double** seq_list, double* len_list){

    for(int i=0; i<seq_counter; i++){
        std::cout << "Sequence " << i+1 << ": ";
        printSequence(seq_list[i], len_list[i]);
    }
    return;
}

void deleteSequence(const double** seq_list, double* len_list){

    for(int i=0; i<seq_counter; i++){
        delete[] seq_list[i];
        std::cout << "Sequence deleted." << std::endl;
    }
    seq_counter = 0;

    delete[] len_list;
    delete[] seq_list;
    return;
}