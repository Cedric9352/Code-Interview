#include <iostream>
#include "header.h"

using namespace std;

int main()
{
    Node head, n1, n2, n3, n4;
    n4.val = 6;
    n4.next = nullptr;
    n3.val = 2;
    n3.next = &n4;
    n2.val = 1;
    n2.next = &n3;
    n1.val = 3;
    n1.next = &n2;
    head.val = 5;
    head.next = &n1;
    for(ListNode n = &head; n != nullptr; n = n->next) {
        cout << n->val << "->";
    }
    cout << "." << endl;
    quick_sort(&head);
    for(ListNode n = &head; n != nullptr; n = n->next) {
        cout << n->val << "->";
    }
    cout << "." << endl;
    return 0;
}
