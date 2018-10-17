#include <iostream>
#include "header.h"

using namespace std;

int main()
{
    int preorder[3] = {1, 2, 3}, inorder[3] = {2, 1, 3};
    TreeNode root = reconstruct_bt(preorder, inorder, 3);
    cout << root->m_nValue << " " << root->m_pLeft->m_nValue << " " << root->m_pRight->m_nValue << endl;
    return 0;
}
