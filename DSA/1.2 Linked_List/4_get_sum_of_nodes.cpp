#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node *next;
};

int get_sum_of_nodes(Node *&head)
{
    int sum = 0;

    Node *temp_ptr = head; // this will traverse the linked list for us

    while (head != nullptr)
    {
        sum = temp_ptr->value;
        temp_ptr = temp_ptr->next;
    }

    return sum;
}