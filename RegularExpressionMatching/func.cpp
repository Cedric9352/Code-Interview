#include "header.h"

/**
 * if next character is *, then:
 * 1. match 1 character
 * 2. match n characters
 * 3. match 0 character
 */
bool core(const char *str, const char *pattern)
{
    if(*str == '\0' && *pattern == '\0') {
        return true;
    }
    if(*str != '\0' && *pattern == '\0') {
        return false;
    }
    // next character
    if(*(pattern+1) == '*') {
        if(*pattern == *str || (*pattern == '.' && *str != '\0')) {
            return core(str+1, pattern+2) ||
                    core(str+1, pattern) ||
                    core(str, pattern+2);
        } else {
            return core(str, pattern+2);
        }
    // current character, match
    } else if(*str == *pattern || (*pattern == '.' && *str != '\0')) {
        return core(str+1, pattern+1);
    // no match
    } else {
        return false;
    }
}
bool match(const char *str, const char *pattern)
{
    if(str == nullptr || pattern == nullptr) {
        return false;
    }
    return core(str, pattern);
}
