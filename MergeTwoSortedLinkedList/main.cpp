#include <iostream>
#include "header.h"

using namespace std;

int main()
{
    ListNode *pHead1 = new ListNode(1), *pHead2 = new ListNode(2);
    pHead1->next = new ListNode(3);
    pHead2->next = new ListNode(4);
    ListNode* res = merge(pHead1, pHead2);
    cout << res << endl;
    return 0;
}
