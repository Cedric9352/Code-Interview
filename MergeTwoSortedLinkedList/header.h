#ifndef HEADER_H
#define HEADER_H
#include <iostream>

/**
 * class ListNode
 */
class ListNode
{
public:
    ListNode(int val = 0): val(val), next(nullptr) { }
    ~ListNode();
    int val;
    ListNode *next;
};
/**
 * output operator of ListNode
 */
std::ostream& operator<<(std::ostream&, ListNode*);
/**
 * public method for ListNode
 */
ListNode* merge(ListNode*, ListNode*);
#endif // HEADER_H
