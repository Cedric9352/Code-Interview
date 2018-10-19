#ifndef HEADER_H
#define HEADER_H
typedef struct BinaryTreeNode* TreeNode;

TreeNode reconstruct_bt(int *preorder, int *inorder, int length);
TreeNode core(int *pre_start, int *pre_end, int *in_start, int *in_end);
#endif // HEADER_H
struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;
};
