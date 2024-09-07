#include <iostream>

struct Node
{
    int value;
    Node *next;
};

int recursive_sum_of_nodes(Node *&head)
{
    if (head == nullptr)
    {
        return 0; // base case to terminate recursion
    }

    return head->value + recursive_sum_of_nodes(head->next); // recursive case;
}