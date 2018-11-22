#include "header.h"

int first_missing_positive(std::vector<int> &nums)
{
    int len = nums.size();
    for(int i = 0; i < len; ++i) {
        // o(n)?
        while(nums[i] > 0 && nums[i] <= len && nums[i] != nums[nums[i]-1]) {
            std::swap(nums[i], nums[nums[i]-1]);
        }
    }
    for(int i = 0; i < len; ++i) {
        if(nums[i] != i+1) {
            return i+1;
        }
    }
    return len+1;
}
