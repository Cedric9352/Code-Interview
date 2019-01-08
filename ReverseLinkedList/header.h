#ifndef HEADER_H
#define HEADER_H
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
ListNode* reverse_between(ListNode*, int, int);
#endif // HEADER_H
