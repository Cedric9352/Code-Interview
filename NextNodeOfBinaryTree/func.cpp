#include "header.h"

/**
 * hint: if one has right child, then it is its right child;
 *       else find the first parent which points to its parent's left child, then this parent's parent is answer
 */
TreeNode get_next_node(TreeNode pNode)
{
    if(pNode == nullptr) {
        return nullptr;
    }
    TreeNode pNext = nullptr;
    if(pNode->m_pRight != nullptr) {
        TreeNode pTmp = pNode->m_pRight;
        while(pTmp->m_pLeft != nullptr) {
            pTmp = pTmp->m_pLeft;
        }
        pNext = pTmp;
    } else if(pNode->m_pParent != nullptr) {
        TreeNode pCurrent = pNode, pParent = pNode->m_pParent;
        while(pParent != nullptr && pCurrent == pParent->m_pRight) {
            pCurrent = pParent;
            pParent = pParent->m_pParent;
        }
        pNext = pParent;
    }
    return pNext;
}
