#include "header.h"
/**
 * make val between p and q larger than val, and smaller than val before p
 */
ListNode partition(ListNode start, ListNode end)
{
    ListNode p = start, q = start->next;
    int val = start->val;
    while(q != end) {
        if(q->val < val) {
            p = p->next;
            int tmp = q->val;
            q->val = p->val;
            p->val = tmp;
        }
        q = q->next;
    }
    int tmp = start->val;
    start->val = p->val;
    p->val = tmp;
    return p;
}

void core(ListNode start, ListNode end)
{
    if(start == end) {
        return;
    }
    ListNode node = partition(start, end);
    core(start, node);
    core(node->next, end);
}

void quick_sort(LinkedList l)
{
    core(l, nullptr);
}
