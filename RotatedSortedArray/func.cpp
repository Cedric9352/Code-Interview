#include "header.h"

/**
 * hint: first, find the pivot of sorted array;
         second, use binary-search to find the target
 */
static int findWhenEqual(std::vector<int> &nums, int start, int end)
{
    for(int i = start+1; i <= end; ++i) {
        if(nums[i] < nums[i-1]) {
            return i;
        }
    }
    return start;
}
static int findPivot(std::vector<int> &nums, int n)
{
    int start = 0, end = n-1, mid = 0;
    while(nums[start] >= nums[end]) {
        mid = (start+end)/2;
        if(start+1 == end) { mid = end; break; }
        if(nums[mid] == nums[start] && nums[mid] == nums[end]) { return findWhenEqual(nums, start, end); }
        if(nums[mid] >= nums[start]) { start = mid; }
        else { end = mid; }
    }
    return mid;
}
static bool binarySearch(std::vector<int> &nums, int target, int start, int end)
{
    int mid = 0;
    while(start <= end) {
        mid = (start+end)/2;
        if(nums[mid] == target) { return true; }
        else if(nums[mid] > target) { end = mid-1; }
        else { start = mid+1; }
    }
    return false;
}
bool search(std::vector<int> &nums, int target)
{
    int n = nums.size();
    if(n == 0) { return false; }
    if(n == 1) { return nums[0] == target; }
    int pivot = findPivot(nums, n);
    bool result = binarySearch(nums, target, 0, pivot-1);
    if(!result) { result |= binarySearch(nums, target, pivot, n-1); }
    return result;
}
