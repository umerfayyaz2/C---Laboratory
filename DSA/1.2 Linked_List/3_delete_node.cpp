#include <iostream>
using namespace std;

struct Node
{
    int info;        // Info: to store info
    Node *next_node; // next_node_node: to store the address of next_node node
};

// Function to delete a node with a specific value from the list
void delete_node(Node *&head, int value)
{
    // Step 1: If the list is empty, do nothing
    if (head == nullptr)
    {
        cout << "List is empty!" << endl;
        return;
    }

    // Step 2: If the node to be deleted is the head node
    if (head->info == value)
    {
        Node *temp = head;      // Store head node
        head = head->next_node; // Move head to the next_node node
        delete temp;            // Delete the old head node
        return;
    }

    // Step 3: Traverse the list to find the node before the one to delete
    Node *temp = head;
    while (temp->next_node != nullptr && temp->next_node->info != value)
    {
        temp = temp->next_node;
    }

    // Step 4: If the node to delete is found
    if (temp->next_node != nullptr)
    {
        Node *node_to_delete = temp->next_node;      // Node to be deleted
        temp->next_node = node_to_delete->next_node; // Update link to bypass the deleted node
        delete node_to_delete;                       // Free memory
    }
}