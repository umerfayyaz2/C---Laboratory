#include <iostream>

struct Node
{
    int value;  // Data part of the node
    Node *next; // Pointer to the next node
    Node *prev; // Pointer to the previous node

    // Constructor to initialize a node with a given valueue
    Node(int value) : value(value), next(nullptr), prev(nullptr) {}
};

void add_node(Node *node, Node *node_to_add)
{
    Node *prev_node = node->prev;  // Step 1: Get the previous node of 'node'
    node_to_add->next = node;      // Step 2: Set the new node's next to the current node
    node_to_add->prev = prev_node; // Step 3: Set the new node's prev to the previous node of 'node'
    prev_node->next = node_to_add; // Step 4: Update the previous node's next pointer to the new node
    node->prev = node_to_add;      // Step 5: Update the current node's previous pointer to the new node
}
