#ifndef HEADER_H
#define HEADER_H
typedef struct BinaryTreeNode* TreeNode

TreeNode get_next_node(TreeNode pNode);
#endif // HEADER_H
struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;
    BinaryTreeNode *m_pParent;
};
