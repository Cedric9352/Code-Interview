#include <iostream>
#include "header.h"

void print_number(const char *number, int len)
{
    bool isBeginingZero = true;
    for(int i = 0; i != len; i++) {
        if(isBeginingZero && number[i] != '0') {
            isBeginingZero = false;
        }
        if(!isBeginingZero) {
            printf("%c", number[i]);
        }
    }
    if(!isBeginingZero) {
        printf("\n");
    }
}

void print_one_to_max_n_digits(int n)
{
    if(n <= 0) {
        return;
    }
    char *number = new char[n];
    core(number, n, 0);
    delete number;
}
/**
 * hint: 1 to n-digits permutation
 */
void core(char *number, int len, int index)
{
    if(index == len) {
        print_number(number, len);
    } else {
        for(int i = 0; i <= 9; i++) {
            number[index] = '0' + i;
            core(number, len, index+1);
        }
    }
}
