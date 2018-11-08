#include <iostream>
#include "header.h"

using namespace std;

int main()
{
    ListNode *pHead = new ListNode(1);
    pHead->next = new ListNode(2);
    pHead->next->next = new ListNode(3);
    pHead->next->next->next = new ListNode(4);
    pHead->next->next->next->next = pHead->next;
    ListNode *pNode = entry_node_of_loop(pHead);
    cout << pNode->val << endl;
    delete pHead;
    return 0;
}
