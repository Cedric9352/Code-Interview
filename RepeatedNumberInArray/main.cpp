#include <iostream>
#include "header.h"

using namespace std;

int main()
{
    int numbers[8] = {2, 3, 5, 4, 3, 2, 6, 7};
    int duplication;
    cout << duplicate(numbers, 8, &duplication) << '\n';
    cout << get_duplicate(numbers, 8) << endl;
    return 0;
}
