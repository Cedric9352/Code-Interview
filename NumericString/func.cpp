#include "header.h"

/**
 * split problem into three parts:
 * 1.non-numeric
 * 2.signed integer
 * 3.unsigned integer
 */
bool scan_unsigned_integer(const char **str)
{
    const char *before = *str;
    while(**str != '\0' && **str >= '0' && **str <= '9') {
        ++(*str);
    }
    return *str > before;
}
bool scan_integer(const char **str)
{
    if(**str == '+' || **str == '-') {
        ++(*str);
    }
    return scan_unsigned_integer(str);
}
bool is_numeric(const char *str)
{
    if(str == nullptr) {
        return false;
    }
    bool numeric = scan_integer(&str);
    if(*str == '.') {
        ++str;
        numeric &= scan_unsigned_integer(&str);
    }
    if(*str == 'e' || *str == 'E') {
        ++str;
        numeric &= scan_integer(&str);
    }
    return numeric && *str == '\0';
}
