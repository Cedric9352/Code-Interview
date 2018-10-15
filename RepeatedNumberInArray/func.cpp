/**
 * hint: exchange a[i] and a[a[i]], hence a[i] is at right place
 */
bool duplicate(int *numbers, int length, int *duplication)
{
    // validate parameters
    if(length <= 0 || numbers == nullptr) {
        return false;
    }
    for(int i = 0; i < length; ++i) {
        if(numbers[i] < 0 || numbers[i] > length-1) {
            return false;
        }
    }
    // main
    for(int i = 0; i < length; ++i) {
        while(numbers[i] != i) {
            if(numbers[i] == numbers[numbers[i]]) {
                *duplication = numbers[i];
                return true;
            }
            int tmp = numbers[i];
            numbers[i] = numbers[tmp];
            numbers[tmp] = tmp;
        }
    }
    return false;
}
/**
 * hint: median split array into 2 pieces, count each one's occurrence
 */
int get_duplicate(const int *numbers, int length)
{
    // validate parameters
    if(length <= 0 || numbers == nullptr) {
        return false;
    }
    for(int i = 0; i < length; ++i) {
        if(numbers[i] < 0 || numbers[i] > length-1) {
            return false;
        }
    }
    // main
    int start = 1, end = length;
    while(end >= start) {
        int mid = ((end-start)>>1)+start;
        int count = 0;
        for(int i = 0; i < length; ++i) {
            if(numbers[i] >= start && numbers[i] <= mid) {
                ++count;
            }
        }
        if(end == start) {
            if(count > 1) {
                return start;
            } else {
                break;
            }
        }
        if(count > mid-start+1) {
            end = mid;
        } else {
            start = mid+1;
        }
    }
    return -1;
}
