#include <iostream>
#include "header.h"

using namespace std;

int main()
{
    ListNode *pHead = new ListNode(1);
    pHead->next = new ListNode(1);
    pHead->next->next = new ListNode(2);
    pHead->next->next->next = new ListNode(3);
    pHead->next->next->next->next = new ListNode(3);
    print_list(pHead);
    pHead = delete_duplication(pHead);
    print_list(pHead);
    delete pHead;
    return 0;
}
