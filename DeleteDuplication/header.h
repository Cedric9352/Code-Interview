#ifndef HEADER_H
#define HEADER_H

/**
 * class ListNode
 */
class ListNode
{
public:
    ListNode(int val = 0, ListNode *ptr = nullptr): value(val), next(ptr) { }
    ~ListNode() = default;
    int value;
    ListNode *next;
};
void print_list(ListNode *pHead);
ListNode* delete_duplication(ListNode *pHead);
#endif // HEADER_H
