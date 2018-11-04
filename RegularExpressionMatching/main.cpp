#include <iostream>
#include "header.h"

using namespace std;

int main()
{
    const char *str = "aaa", *pattern = "ab*ac*a";
    cout << match(str, pattern);
    return 0;
}
