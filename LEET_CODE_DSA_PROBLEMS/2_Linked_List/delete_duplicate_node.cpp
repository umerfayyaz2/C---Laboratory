#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *delete_duplicates(ListNode *head)
{
    ListNode *current = head;

    while (current != NULL && current->next != NULL)
    {
        if (current->val == current->next->val)
        {
            ListNode *duplicate = current->next;
            current->next = current->next->next;
            delete duplicate;
        }
        else
        {
            current = current->next;
        }
    }

    return head;
}