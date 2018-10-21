#include <iostream>
#include "header.h"

using namespace std;

int main()
{
    int sorted_array[5] = {3, 4, 5, 1, 2};
    cout << min_in_order(sorted_array, 5) << endl;
    return 0;
}
