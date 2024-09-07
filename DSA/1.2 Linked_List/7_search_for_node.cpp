#include <iostream>

struct NodeType
{
    int value;
    NodeType *next;
};

int search_for_node(NodeType *&head, int target)
{
    int position = 1;         // Works as index in Linked_list
    NodeType *current = head; // indicates the current position of node

    while (current != nullptr)
    {
        if (current->value == target)
        {
            return position;
        }
        else
        {
            position++;
            current = current->next;
        }
    }
    return -1; // if the linked list is empty.
}
