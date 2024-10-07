#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to print the linked list
void printList(ListNode *head)
{
    ListNode *current = head;
    while (current != nullptr)
    {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

// Function to perform selection sort on the linked list
ListNode *selectionSortList(ListNode *head)
{
    if (!head)
        return head; // Edge case: empty list

    ListNode *sortedHead = head;

    // Traverse through the entire list
    while (sortedHead)
    {
        ListNode *minNode = sortedHead;
        ListNode *current = sortedHead->next;

        // Find the minimum element in the remaining unsorted part
        while (current)
        {
            if (current->val < minNode->val)
            {
                minNode = current;
            }
            current = current->next;
        }

        // Swap the values of the current node and the minimum node
        if (minNode != sortedHead)
        {
            int temp = sortedHead->val;
            sortedHead->val = minNode->val;
            minNode->val = temp;
        }

        // Move sortedHead to the next node for sorting the next part
        sortedHead = sortedHead->next;
    }

    return head;
}

// Function to create a linked list from an array of values
ListNode *createList(const vector<int> &values)
{
    if (values.empty())
        return nullptr;

    ListNode *head = new ListNode(values[0]);
    ListNode *current = head;

    for (int i = 1; i < values.size(); ++i)
    {
        current->next = new ListNode(values[i]);
        current = current->next;
    }

    return head;
}

int main()
{
    // Example usage:
    vector<int> values = {4, 2, 1, 3}; // Example list to sort
    ListNode *head = createList(values);

    cout << "Original list: ";
    printList(head);

    // Sort the linked list using selection sort
    head = selectionSortList(head);

    cout << "Sorted list: ";
    printList(head);

    return 0;
}
