#include <iostream>
#include "header.h"

using namespace std;

int main()
{
    std::vector<int> nums = {0,0,1,2,2,5,6};
    cout << search(nums, 0) << endl;
    return 0;
}
