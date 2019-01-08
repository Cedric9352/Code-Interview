#include <iostream>
#include "header.h"

using namespace std;

int main()
{
    ListNode l1(1), l2(2), l3(3), l4(4), l5(5);
    l1.next = &l2; l2.next = &l3; l3.next = &l4; l4.next = &l5;
    ListNode *head = reverse_between(&l1, 2, 4);
    while(head != nullptr) {
        cout << head->val << "->";
        head = head->next;
    }
    cout << "." << endl;
    return 0;
}
