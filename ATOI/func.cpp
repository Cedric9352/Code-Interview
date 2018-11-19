#include "header.h"

/**
 * hint: only one thing to be notice: you can not use number*10 + character-to-int > MAX_INT, hence the left operand is already larger than int
 * you should use number > (MAX_INT-character-to-int)/10
 */
int my_atoi(std::string str) {
    int MAX_INT = 0x7fffffff;
    int MIN_INT = 0x80000000;
    int firstNonSpace = 0, firstNonZero = 0, end = 0;
    int res = 0;
    bool isNegative = false, isBeginZero = true;
    if(str == "") {
        return 0;
    }
    // find out the first non-whitespace character
    for(std::size_t i = 0; i < str.length(); ++i) {
        if(str[firstNonSpace] != ' ') {
            break;
        }
        ++firstNonSpace;
    }
    str = str.substr(firstNonSpace);
    // check out the sign
    if(str[0] == '+' || str[0] == '-') {
        if(str[0] == '-') {
            isNegative = true;
        }
        str = str.substr(1);
    }
    // check out first non-zero valid number
    for(std::size_t i = 0; i < str.length(); ++i) {
        if(str[i] < '0' || str[i] > '9') {
            break;
        }
        if(str[i] == '0' && isBeginZero) {
            ++firstNonZero;
        } else {
            isBeginZero = false;
        }
        ++end;
    }
    str = str.substr(firstNonZero, end-firstNonZero);
    for(std::size_t i = 0; i < str.length(); ++i) {
        if(!isNegative) {
            if((MAX_INT-(str[i]-'0'))/10 < res) { return MAX_INT; }
            else { res = 10*res+(str[i]-'0'); }
        } else {
            if((MIN_INT+(str[i]-'0'))/10 > res) { return MIN_INT; }
            else { res = 10*res-(str[i]-'0'); }
        }
    }
    return res;
}
