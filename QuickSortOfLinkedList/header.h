#ifndef HEADER_H
#define HEADER_H
typedef struct Node* LinkedList;
typedef struct Node* ListNode;

ListNode partition(ListNode start, ListNode end);
void core(ListNode start, ListNode end);
void quick_sort(LinkedList l);
#endif // HEADER_H
struct Node
{
    int val;
    Node *next;
};

