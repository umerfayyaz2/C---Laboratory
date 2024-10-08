#include <iostream>
#include <stack>
using namespace std;

// Definition of a singly linked list node
struct ListNode
{
    int data;
    ListNode *next;

    ListNode(int val) : data(val), next(nullptr) {}
};

// Class to define a linked list type
class linkedListType
{
private:
    ListNode *head;

public:
    linkedListType() : head(nullptr) {}

    // Function to insert a new node at the end
    void insertLast(int value)
    {
        ListNode *newNode = new ListNode(value);
        if (!head)
        {
            head = newNode;
        }
        else
        {
            ListNode *current = head;
            while (current->next)
            {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Function to print the linked list
    void printList() const
    {
        ListNode *current = head;
        while (current)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Iterative function to print the linked list backward using a stack
    void reversePrint() const
    {
        if (!head)
            return; // If the list is empty, return

        stack<int> s;
        ListNode *current = head;

        // Push the values into the stack
        while (current)
        {
            s.push(current->data);
            current = current->next;
        }

        // Pop from the stack to print values in reverse
        while (!s.empty())
        {
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;
    }

    // Recursive function to print the linked list backward
    void recursiveReversePrint() const
    {
        recursiveReversePrintHelper(head);
        cout << endl;
    }

private:
    // Helper function for recursive reverse print
    void recursiveReversePrintHelper(ListNode *node) const
    {
        if (!node)
            return;

        // First recursively go to the end of the list
        recursiveReversePrintHelper(node->next);

        // Print the data as recursion unwinds
        cout << node->data << " ";
    }
};

int main()
{
    // Test with unordered linked list
    linkedListType myList;

    // Insert elements into the linked list
    myList.insertLast(1);
    myList.insertLast(2);
    myList.insertLast(3);
    myList.insertLast(4);
    myList.insertLast(5);

    cout << "Original List: ";
    myList.printList(); // Expected: 1 2 3 4 5

    cout << "Iterative Reverse Print: ";
    myList.reversePrint(); // Expected: 5 4 3 2 1

    cout << "Recursive Reverse Print: ";
    myList.recursiveReversePrint(); // Expected: 5 4 3 2 1

    return 0;
}
