#include <iostream>
using namespace std;

struct linked_list
{
    int val;
    linked_list *next;

    linked_list(int v) : val(v), next(nullptr) {}
};

// function to reverse the linked list
linked_list *reverse_list(linked_list *head)
{
    linked_list *prev = nullptr;
    linked_list *current = head;
    linked_list *next = nullptr;

    // taversing the list to reverse the pointers
    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

void display_list(linked_list *head)
{
    linked_list *temp = head;

    while (temp != nullptr)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}