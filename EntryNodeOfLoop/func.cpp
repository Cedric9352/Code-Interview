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
ListNode* meeting_node(ListNode *pHead)
{
    if(pHead == nullptr) {
        return nullptr;
    }
    ListNode *pSlow = pHead;
    ListNode *pFast = pSlow->next;
    while(pFast != nullptr && pSlow != nullptr) {
        if(pFast == pSlow) {
            return pFast;
        }
        // one move
        pSlow = pSlow->next;
        // two move
        pFast = pFast->next;
        if(pFast != nullptr) {
            pFast = pFast->next;
        }
    }
    return nullptr;
}
/**
 * hint: if n is total counts of nodes, m is nodes in loop, if first pointer move m steps,
 * then rest nodes is n-m-1, add meeting node, then n-m move to meeting node
 */
ListNode* entry_node_of_loop(ListNode *pHead)
{
    ListNode *meetingNode = meeting_node(pHead);
    if(meetingNode == nullptr) {
        return nullptr;
    }
    // NOTICE: count itself
    int nodesInLoop = 1;
    ListNode *pNode1 = meetingNode;
    while(pNode1->next != meetingNode) {
        pNode1 = pNode1->next;
        ++nodesInLoop;
    }
    // n-m move
    pNode1 = pHead;
    for(int i = 0; i < nodesInLoop; ++i) {
        pNode1 = pNode1->next;
    }
    // n-m move
    ListNode *pNode2 = pHead;
    while(pNode1 != pNode2) {
        pNode1 = pNode1->next;
        pNode2 = pNode2->next;
    }
    return pNode1;
}
