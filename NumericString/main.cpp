#include <iostream>
#include "header.h"

using namespace std;

int main()
{
    const char *str1 = "-3.1416", *str2 = "12e+5.4", *str3 = "-1E-16";
    cout << is_numeric(str1) << " "
         << is_numeric(str2) << " "
         << is_numeric(str3) << endl;
    return 0;
}
