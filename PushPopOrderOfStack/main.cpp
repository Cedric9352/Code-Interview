#include <iostream>
#include "header.h"

using namespace std;

int main()
{
    const int push[5] = {1,2,3,4,5}, pop1[5] = {4,5,3,2,1}, pop2[5] = {4,3,5,1,2};
    cout << is_push_pop_order(push, pop1, 5) << endl;
    cout << is_push_pop_order(push, pop2, 5) << endl;
    return 0;
}
