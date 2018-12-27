#include "header.h"

/**
 * hint: just insert, insert, insert!
 */
ListNode* partition(ListNode* head, int x)
{
	if(head != nullptr) {
		ListNode *first = head, *first_pre = nullptr;
		// find someone bigger than x
		while(first != nullptr && first->val < x) {
			first_pre = first;
			first = first->next;
		}
		if(first != nullptr) {
			ListNode *second = first->next, *second_pre = first;
			while(second != nullptr) {
				if(second->val < x) {
					// second is the head
					if(first_pre == nullptr) {
						head = second;
					} else {
						first_pre->next = second;
					}
					// do some exchange
					ListNode *second_post = second->next;
					second->next = first;
					second_pre->next = second_post;
					// first does not change after an insert
					// make first_pre points to the last inserted one
					// make second points to second_pre so that we can adapt to following code
					first_pre = second;
					second = second_pre;
				}
				second_pre = second;
				second = second->next;
			}
		}
	}
	return head;
}
