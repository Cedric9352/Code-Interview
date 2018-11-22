#include <iostream>
#include "header.h"

using namespace std;

int main()
{
    vector<int> nums = { 3, 4, -1, 1};
    cout << first_missing_positive(nums) << endl;
    return 0;
}
