#ifndef HEADER_H
#define HEADER_H
#include <iostream>

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
std::ostream& operator<<(std::ostream&, ListNode*);
ListNode* merge(ListNode*, ListNode*);
#endif // HEADER_H
