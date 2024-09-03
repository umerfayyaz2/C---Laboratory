#include <iostream>
using namespace std;

struct nodeType
{
    int val;
    nodeType *next;
    nodeType(int x) : val(x), next(NULL) {}
};

bool has_cycle(nodeType *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return false;
    }

    nodeType *slow = head;
    nodeType *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            return true;
        }
    }

    return false;
}

int main()
{

    nodeType *head = new nodeType(3);
    head->next = new nodeType(2);
    head->next->next = new nodeType(0);
    head->next->next->next = new nodeType(-4);
    head->next->next->next->next = head->next;

    if (has_cycle(head))
    {
        cout << "The linked list has a cycle.\n";
    }
    else
    {
        cout << "The linked list does not have a cycle.\n";
    }

    return 0;
}
