#include <iostream>
#include "header.h"

using namespace std;

int main()
{
    char matrix[13] = {'a', 'b', 't', 'g',
                        'c', 'f', 'c', 's',
                        'j', 'd', 'e', 'h'};
    char str[5] = {'b', 'f', 'c', 'd'};
    cout << has_path(matrix, 3, 4, str) << endl;
    return 0;
}
