#include <iostream>
#include "header.h"

using namespace std;

int main()
{
    vector<vector<int>> matrix = {{1,1,1}, {1,0,1}, {1,1,1}};
    set_zeroes(matrix);
    for(st2 i = 0; i < matrix.size(); ++i) {
        for(st j = 0; j < matrix[0].size(); ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
