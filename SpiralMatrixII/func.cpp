#include "header.h"

void set_loop(std::vector<std::vector<int>> &matrix, const std::vector<int> &nums, int start, int &index, int rows, int cols)
{
    int endX = cols-1-start, endY = rows-1-start;
    // no limit
    if(endX >= start) {
        for(int i = start; i <= endX; ++i) {
            matrix[start][i] = nums[index];
            ++index;
        }
    }
    // only under condition of at least 2 columns
    if(endY > start) {
        for(int i = start+1; i <= endY; ++i) {
            matrix[i][endX] = nums[index];
            ++index;
        }
    }
    // only under condition of at least 2 columns and 2 rows
    if(endX > start && endY > start) {
        for(int i = endX-1; i >= start; --i) {
            matrix[endY][i] = nums[index];
            ++index;
        }
    }
    // only under condition of at least 2 columns and 3 rows
    if(endX > start && endY-1 > start) {
        for(int i = endY-1; i > start; --i) {
            matrix[i][start] = nums[index];
            ++index;
        }
    }
}

void spiral_matrix_ii(std::vector<std::vector<int>> &matrix, const std::vector<int> &nums, int rows, int cols)
{
    int start = 0, index = 0;
    while(2*start < rows && 2*start < cols) {
        set_loop(matrix, nums, start, index, rows, cols);
        ++start;
    }
}
