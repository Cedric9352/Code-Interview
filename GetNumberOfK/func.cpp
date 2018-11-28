#include "header.h"

namespace {
    int get_first_k(int *data, int length, int k, int start, int end)
    {
        if(start > end) { return -1; }
        int mid = (start+end)/2;
        int mid_val = data[mid];
        if(mid_val == k) {
            if((mid > 0 && data[mid-1] != k) || mid == 0) { return mid; }
            else { end = mid-1; }
        } else if(mid_val < k) {
            start = mid+1;
        } else { end = mid-1; }
        return get_first_k(data, length, k, start, end);
    }

    int get_last_k(int *data, int length, int k, int start, int end)
    {
        if(start > end) { return -1; }
        int mid = (start+end)/2;
        int mid_val = data[mid];
        if(mid_val == k) {
            if((mid < length-1 && data[mid+1] != k) || mid == length-1) { return mid; }
            else { start = mid+1; }
        } else if(mid_val < k) {
            start = mid+1;
        } else { end = mid-1; }
        return get_last_k(data, length, k, start, end);
    }
}

int get_number_of_k(int *data, int length, int k)
{
    int res = 0;
    if(data != nullptr && length != 0) {
        int first = get_first_k(data, length, k, 0, length-1);
        int last = get_last_k(data, length, k, 0, length-1);
        if(first != -1 && last != -1) { return last-first+1; }
    }
    return res;
}
