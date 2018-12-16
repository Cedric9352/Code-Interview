#include <iostream>
#include "header.h"

using namespace std;

int main()
{
    vector<int> colors = {2, 0, 2, 1, 1, 0};
    sort_colors(colors);
    for(auto c : colors) { cout << c << " "; }
    cout << endl;
    return 0;
}
