#include <iostream>
#include "header.h"

using namespace std;

int main()
{
    vector<int> nums = {1,2,3,4,5,6,7,8};
    vector<vector<int>> matrix;
    matrix.resize(4, vector<int>(2));
    spiral_matrix_ii(matrix, nums, 4, 2);
    for(int i = 0; i < 4; ++i) {
        for(int j = 0; j < 2; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
