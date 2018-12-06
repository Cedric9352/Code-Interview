#include "header.h"

void rotate_core(std::vector<std::vector<int>> &matrix, int start, int length)
{
    for(int i = start; i < length-start-1; ++i) {
        int tmp = matrix[start][i];
        matrix[start][i] = matrix[length-i-1][start];
        matrix[length-i-1][start] = matrix[length-start-1][length-i-1];
        matrix[length-start-1][length-i-1] = matrix[i][length-start-1];
        matrix[i][length-start-1] = tmp;
    }
}
void rotate_image(std::vector<std::vector<int>> &matrix)
{
    int n = matrix.size();
    if(n != 0) {
        for(int i = 0; 2*i < n; ++i) { rotate_core(matrix, i, n); }
    }
}
