#include <iostream>
using namespace std;

struct Node
{
    int info;        // Info: to store data
    Node *next_node; // next_node: to store the address of next node
};

// Function to insert a node at the end of the list
void insert_at_end(Node *&head, int newInfo)
{
    // Step 1: Create a new node
    Node *newNode = new Node;
    newNode->info = newInfo;
    newNode->next_node = nullptr; // New node points to nullptr (end of list)

    // Step 2: If the list is empty, make the new node the head
    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    // Step 3: Traverse to the last node
    Node *temp = head;
    while (temp->next_node != nullptr)
    {
        temp = temp->next_node;
    }

    // Step 4: Make the last node's next point to the new node
    temp->next_node = newNode;
}