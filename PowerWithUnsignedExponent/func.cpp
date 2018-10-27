#include "header.h"
/**
 * hint: a^n = a^(n/2) * a^(n/2) or a^((n-1)/2)) * a^((n-1)/2)) * a
 */
double power_with_unsigned_exponent(double base, unsigned int exponent)
{
    if(exponent == 0) {
        return 1.0;
    }
    if(exponent == 1) {
        return base;
    }
    double result = power_with_unsigned_exponent(base, exponent >> 1);
    result *= result;
    if((exponent & 0x1) == 1) {
        result *= base;
    }
    return result;
}
