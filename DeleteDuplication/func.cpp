#include <iostream>
#include "header.h"

/**
 * destructor of ListNode
 */
ListNode::~ListNode()
{
    ListNode *ptr = this->next;
    // first make head pointing to null pointer
    this->next = nullptr;
    while(ptr != nullptr) {
        ListNode *tmp = ptr->next;
        delete ptr;
        ptr = tmp;
    }
}
ListNode* delete_duplication(ListNode *pHead)
{
    if(pHead != nullptr) {
        ListNode *pPreNode = nullptr, *pNode = pHead;
        while(pNode != nullptr) {
            ListNode *pNext = pNode->next;
            bool needToDelete = false;
            if(pNext != nullptr && pNext->value == pNode->value) {
                needToDelete = true;
            }
            if(!needToDelete) {
                pPreNode = pNode;
                pNode = pNext;
            } else {
                int value = pNode->value;
                while(pNode != nullptr && pNode->value == value) {
                    pNext = pNode->next;
                    delete pNode;
                    pNode = pNext;

                }
                if(pPreNode == nullptr) {
                    pHead = pNode;
                } else {
                    pPreNode->next = pNode;
                }
            }
        }
    }
    return pHead;
}
void print_list(ListNode *pHead)
{
    while(pHead != nullptr) {
        std::cout << pHead->value << "->";
        pHead = pHead->next;
    }
    std::cout << "." << std::endl;
}
