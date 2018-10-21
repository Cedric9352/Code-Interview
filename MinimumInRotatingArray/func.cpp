int min_in_order2(int *numbers, int start, int end)
{
    int result = numbers[start];
    for(int i = start+1; i <= end; ++i) {
        // find minimum number
        if(result > numbers[i]) {
            result = numbers[i];
        }
    }
    return result;
}
/**
 * hint: binary search in a sorted array
 */
int min_in_order(int *numbers, int length)
{
    int index1 = 0, index2 = length-1;
    int indexMid = index1;
    while(numbers[index1] >= numbers[index2]) {
        // find the number that larger than next
        if(index2 == index1+1) {
            indexMid = index2;
            break;
        }
        indexMid = ((index2-index1)>>1)+index1;
        if(numbers[index1] == numbers[index2] && numbers[index1] == numbers[indexMid]) {
            return min_in_order2(numbers, index1, index2);
        }
        if(numbers[index1] >= numbers[indexMid]) {
            index1 = indexMid;
        } else if(numbers[index2] <= numbers[indexMid]) {
            index2 = indexMid;
        }
    }
    return numbers[indexMid];
}

