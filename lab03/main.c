// Problem description //
/*
    The task is to write the credit card number verification algorithm.

    Correct card numbers may have a different number of digits, e.g.:
    VISA - 13 or 16
    MasterCard - 16
    AmericanExpress - 15.

    The card number can be verified using the Luhn algorithm.
    If the card number is shorter than 16 digits, zeros are added before the number.
    All of the number digits are multiplied by weighting factors -
    2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1 in that exact order.
    Digits in multiplication results are added together.
    The card number is correct if the last digit of the summation result is equal to 0.
  
    Example:
    2 1 2 1 2 1 2 1 2 1 2 1 2 1 2 1 -> weights
    1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 2 -> card no
    ---------------------------------
    2*1 1*2 2*3 1*4 2*5 1*6 2*7 1*8 2*9 1*0 2*1 1*2 2*3 1*4 2*5 1*2  
    2   2   6   4  10   6  14   8  18   0   2   2   6   4  10   2 
    2 + 2 + 6 + 4+1+0 + 6+1+4 + 8+1+8 + 0 + 2 + 2 + 6 + 4+1+0 + 2   = 60
    ---------------------------------         
    60 mod 10 = 0 ----> check digit valid


    Write two functions (include them in the "check_number.h" header):
    1. find_ctrl - to calculate the check digit,
    2. number_correct - checking the correctness of the card number.
  
    Remarks:
    - the main.cpp file must not be modified
    - the VERIFY variable cannot be defined in any header file
    - the project must contain CMakeLists.txt file
    - use of /include and /src directories is mandatory
*/

// Actual code //
#include <stdio.h>
#include "check_number.h"

int main(){
    const char* visa = "4222222222222";
    char ctrl = find_ctrl(visa);
    
    printf("%s\t%c\n", visa, ctrl);
    
    visa = "4111111111111111";
    ctrl = find_ctrl(visa);
    printf("%s\t%c\n", visa, ctrl);
    
    #ifdef VERIFY
        visa = "4012888888881881"; 
        if( number_correct(visa) ){
            printf("number %s is correct\n", visa);
        }
    #endif
    
    visa = "4222222723122"; 
    if( !number_correct(visa) ){
        printf("number %s is not correct\n", visa);
    }
    
    return 0;
}

// Expected output //
/*
    4222222222222	0
    4111111111111111    0
    number 4012888888881881 is correct
    number 4222222723122 is not correct
*/