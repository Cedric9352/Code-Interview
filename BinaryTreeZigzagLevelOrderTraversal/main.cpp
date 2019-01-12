#include <iostream>
#include "header.h"

using namespace std;

int main()
{
    tree_node<int> *root = new tree_node<int>(3);
    tree_node<int> *left_child = new tree_node<int>(9);
    tree_node<int> *right_child = new tree_node<int>(20);
    tree_node<int> *right_child_left_child = new tree_node<int>(15);
    tree_node<int> *right_child_right_child = new tree_node<int>(7);
    root->_left = left_child; root->_right = right_child;
    right_child->_left = right_child_left_child; right_child->_right = right_child_right_child;
    vector<vector<int>> result = zigzagLevelOrder(root);
    for(vector<vector<int>>::size_type i = 0; i < result.size(); i++) {
        for(vector<int>::size_type j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    delete root;
    delete left_child; delete right_child;
    delete right_child_left_child; delete right_child_right_child;
    return 0;
}
