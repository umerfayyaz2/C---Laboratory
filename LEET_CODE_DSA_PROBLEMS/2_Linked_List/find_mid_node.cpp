#include <iostream>
using namespace std;

struct nodeType
{
    int value;
    nodeType *next;
    nodeType(int x) : value(x), next(nullptr) {}
};

int find_middle_node(nodeType *head)
{
    nodeType *slow = head;
    nodeType *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->value;
}

#include <iostream>

struct nodeType
{
    int value;
    nodeType *next;
    nodeType(int x) : value(x), next(nullptr) {}
};

int ind_middle_node(nodeType *head)
{
    nodeType *slow = head;
    nodeType *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->value;
}

int main()
{
    nodeType *head = new nodeType(1);
    head->next = new nodeType(2);
    head->next->next = new nodeType(3);
    head->next->next->next = new nodeType(4);
    head->next->next->next->next = new nodeType(5);

    cout << "Middle node valueue: " << ind_middle_node(head) << endl;

    return 0;
}
