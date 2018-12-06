#include <iostream>
#include "header.h"

using namespace std;

int main()
{
    vector<vector<int>> matrix = {{1,2,3},
                                  {4,5,6},
                                  {7,8,9}};
    rotate_image(matrix);
    rotate_image(matrix);
    for(auto row : matrix) {
        for(auto e : row) {
            cout << e << '\t';
        }
        cout << endl;
    }
    return 0;
}
