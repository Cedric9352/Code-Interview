#include <stdexcept>
#include "header.h"

TreeNode reconstruct_bt(int *preorder, int *inorder, int length)
{
    if(preorder == nullptr || inorder == nullptr || length <= 0) {
        return nullptr;
    }
    return core(preorder, preorder+length-1, inorder, inorder+length-1);
}


TreeNode core(int *pre_start, int *pre_end, int *in_start, int *in_end)
{
    int root_value = pre_start[0];
    TreeNode root = new BinaryTreeNode();
    root->m_nValue = root_value;
    root->m_pLeft = nullptr;
    root->m_pRight = nullptr;
    if(pre_start == pre_end) {
        if(in_start == in_end && *pre_start == *in_start) {
            return root;
        } else {
            throw std::runtime_error("invalid input");
        }
    }
    // find root location in in-order array
    int *in_root = in_start;
    while(in_root <= in_end && *in_root != root_value) {
        ++in_root;
    }
    if(in_root == in_end && *in_root != root_value) {
        throw std::runtime_error("invalid input");
    }
    int left_length = in_root - in_start;
    int *pre_left_end = pre_start + left_length;
    // reconstruct left tree
    if(left_length > 0) {
        root->m_pLeft = core(pre_start+1, pre_left_end, in_start, in_root-1);
    }
    // reconstruct right tree
    if(in_end-in_start > left_length) {
        root->m_pRight = core(pre_left_end+1, pre_end, in_root+1, in_end);
    }
    return root;
}
