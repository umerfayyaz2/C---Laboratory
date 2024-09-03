#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *getKthFromEnd(ListNode *head, int k)
{
    ListNode *slow_ptr = head;
    ListNode *fast_ptr = head;

    for (int i = 0; i < k; i++)
    {
        if (fast_ptr == nullptr)
        {
            return nullptr;
        }
        fast_ptr = fast_ptr->next;
    }

    while (fast_ptr != nullptr)
    {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next;
    }

    return slow_ptr;
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 2;
    ListNode *result = getKthFromEnd(head, k);
    if (result != nullptr)
    {
        cout << "The value of the " << k << "th node from the end is: " << result->val << endl;
    }
    else
    {
        cout << "Error: k is greater than the length of the linked list." << endl;
    }

    return 0;
}
