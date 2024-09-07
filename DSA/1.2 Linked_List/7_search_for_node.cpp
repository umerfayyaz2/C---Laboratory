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
    bool is_list_empty = true;

    while (current != nullptr)
    {
        is_list_empty = false;

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

    if (is_list_empty)
    {
        return -1;
    }

    return -1; // if the linked list is empty.
}
