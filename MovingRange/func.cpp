#include "header.h"

int moving_count(int threshold, int rows, int cols)
{
    if(threshold <0 || rows <= 0 || cols <= 0) {
        return 0;
    }
    bool visited[rows*cols] = {false};
    return core(threshold, rows, cols, 0, 0, visited);
}
/**
 * hint: when moving to (i, j), check if one can move to (i+1, j), (i-1, j), (i, j+1), (i, j-1), a DFS problem
 */
int core(int &threshold, int &rows, int &cols, int row, int col, bool *visited)
{
    int count = 0;
    if(!visited[row*cols+col] && (row >= 0 && row < rows) &&
       (col >= 0 && col < cols)) {
        int digit_sum = get_digit_sum(row) + get_digit_sum(col);
        if(digit_sum <= threshold) {
            visited[row*cols+col] = true;
            count = 1 + core(threshold, rows, cols, row+1, col, visited) +
                core(threshold, rows, cols, row, col+1, visited) +
                core(threshold, rows, cols, row-1, col, visited) +
                core(threshold, rows, cols, row, col-1, visited);
        }
    }
    return count;
}

int get_digit_sum(int num)
{
    int sum = 0;
    while(num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}
