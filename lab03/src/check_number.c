#include "check_number.h"

char find_ctrl(const char * card){

    int len = strlen(card);
    if(len != 13 && len != 15 && len != 16)
        exit(EXIT_FAILURE);
    
    char str[] = "0000000000000000";
    int sum = 0;

    for(int i=16-len; i<16; i++)
        str[i] = card[i-16+len];

    for(int i=0; i<16; i++){
        if(i%2 == 0){
            int temp = 2*(str[i]-'0');
            if(temp < 10)
                sum += temp;
            else
                sum += 1 + temp%10;
        }
        else{
            sum+=str[i]-'0';
        }
    }
    return sum%10+'0';
}

bool number_correct(const char * card){

    if(find_ctrl(card) == '0')
        return true;
    return false;
}