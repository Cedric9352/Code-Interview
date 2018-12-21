#include "header.h"

/**
 * hint: put flag on the side of matrix, when needs O(N) to achieve
 */
void set_zeroes(std::vector<std::vector<int>> &matrix)
{
    bool row_zero = false, col_zero = false;
    for(st2 i = 0; i < matrix.size(); ++i) {
        for(st j = 0; j < matrix[0].size(); ++j) {
            if(matrix[i][j] == 0) {
                matrix[0][j] = 0;
                matrix[i][0] = 0;
                if(i == 0) { row_zero = true; }
                if(j == 0) { col_zero = true; }
            }
        }
    }
    for(st2 i = 1; i < matrix.size(); ++i) {
        for(st j = 1; j < matrix[0].size(); ++j) {
            if(matrix[0][j] == 0 || matrix[i][0] == 0) { matrix[i][j] = 0; }
        }
    }
    if(row_zero) {
        for(st i = 0; i < matrix[0].size(); ++i) { matrix[0][i] = 0; }
    }
    if(col_zero) {
        for(st2 i = 0; i < matrix.size(); ++i) { matrix[i][0] = 0; }
    }
}
