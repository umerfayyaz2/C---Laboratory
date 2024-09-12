#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        // Create a new dummy node to simplify head manipulation
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        // This will point to the current pair
        ListNode *prev = dummy;

        // Traverse the list while there are pairs to swap
        while (prev->next && prev->next->next)
        {
            // Identify the two nodes to swap
            ListNode *first = prev->next;
            ListNode *second = prev->next->next;

            // Swapping the nodes
            first->next = second->next; // Link the first node to the next pair
            prev->next = second;        // Link the previous node to the second
            second->next = first;       // Link the second node to the first

            // Move prev two nodes ahead for the next swap
            prev = first;
        }

        // Return the new head, which is next of dummy node
        return dummy->next;
    }
};

// Helper function to print the linked list
void printList(ListNode *node)
{
    while (node)
    {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}

// Helper function to create a linked list from an array
ListNode *createList(const int *arr, int size)
{
    if (size == 0)
        return nullptr;

    ListNode *head = new ListNode(arr[0]);
    ListNode *current = head;

    for (int i = 1; i < size; i++)
    {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

int main()
{
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6
    int arr[] = {1, 2, 3, 4, 5, 6};
    ListNode *head = createList(arr, 6);

    Solution solution;
    head = solution.swapPairs(head);

    // Print the swapped list: should be 2 -> 1 -> 4 -> 3 -> 6 -> 5
    printList(head);

    return 0;
}
