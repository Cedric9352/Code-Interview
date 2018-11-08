#ifndef HEADER_H
#define HEADER_H

class ListNode
{
public:
    ListNode(int val = 0): val(val), next(nullptr) { }
    ~ListNode();
    int val;
    ListNode *next;
};
/**
 * public method for ListNode
 */
ListNode* meeting_node(ListNode *pHead);
ListNode* entry_node_of_loop(ListNode *pHead);
#endif // HEADER_H
