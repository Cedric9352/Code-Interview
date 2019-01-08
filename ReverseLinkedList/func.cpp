#include "header.h"

/**
 * hint: when i == m, first points to the first element to be reversed,
 *       so we just insert one by one before it
 */
ListNode* reverse_between(ListNode* head, int m, int n)
{
    ListNode *pre_first = nullptr, *first = head, *post_first = nullptr;
    ListNode *last = head, *post_last = nullptr;
    ListNode *reversedHead = head;
    for(int i = 1; i < n; ++i) {
        if(i < m) {
            pre_first = first;
            first = first->next;
        }
        last = last->next;
        if(first != last) {
            // if pre_first is not nullptr, then pre_first should not change
            // but the pre_first->next changed in every loop, so we have to record it
            post_first = pre_first == nullptr ? reversedHead : pre_first->next;
            post_last = last->next;
            if(pre_first != nullptr) { pre_first->next = last; }
            last->next = post_first;
            first->next = post_last;
            // resume
            reversedHead = last;
            last = first;
        }
    }
    return pre_first == nullptr ? reversedHead : head;
}
