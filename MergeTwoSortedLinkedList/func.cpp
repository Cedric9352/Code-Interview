#include "header.h"

/**
 * destructor of ListNode
 */
ListNode::~ListNode()
{
    ListNode *ptr = this->next;
    this->next = nullptr;
    while(ptr != nullptr) {
        ListNode *tmp = ptr->next;
        delete ptr;
        ptr = tmp;
    }
}
/**
 * output operator of ListNode
 */
std::ostream& operator<<(std::ostream &os, ListNode* pHead)
{
    while(pHead != nullptr) {
        os << pHead->val << "->";
        pHead = pHead->next;
    }
    os << ".";
    return os;
}
/**
 * hint: recursively merge two linked-list by choosing larger one
 */
ListNode* merge(ListNode *pHead1, ListNode *pHead2)
{
    if(pHead1 == nullptr) {
        return pHead2;
    } else if(pHead2 == nullptr) {
        return pHead1;
    }
    ListNode *pMergedHead = nullptr;
    if(pHead1->val < pHead2->val) {
        pMergedHead = pHead1;
        pMergedHead->next = merge(pHead1->next, pHead2);
    } else {
        pMergedHead = pHead2;
        pMergedHead->next = merge(pHead1, pHead2->next);
    }
    return pMergedHead;
}
