#include <iostream>
#include "header.h"

using namespace std;

int main()
{
    int data[8] = {1, 2, 3, 3, 3, 3, 4, 4};
    cout << get_number_of_k(data, 8, 4) << endl;
    cout << get_number_of_k(data, 8, 3) << endl;
    return 0;
}
