#include <iostream>
using namespace std;

struct Node
{
    int info;        // Info: to store data
    Node *next_node; // next_node: to store the address of next node
};

// Function to insert anode at the beginning of the next_nodeed_List
void insert_at_beginning(Node *&head, int newInfo)
{
    // Step 1: create a new node
    Node *newNode = new Node;
    newNode->info = newInfo;

    // Step 2: make the new node point to the current head
    newNode->next_node = head;

    // Step 3: update the head to point to the new node
    head = newNode;
}

// Function to display all the next_nodeed list
void display_list(Node *head)
{
    Node *temp = head;

    while (temp != nullptr)
    {
        cout << temp->info << " -> ";
        temp = temp->next_node;
    }

    cout << "nullptr\n";
}

int main()
{

    Node *head = nullptr; // Intilizing to nullptr to avoid random addressing

    insert_at_beginning(head, 2); // inserts 2 in the beginning => [2]
    insert_at_beginning(head, 1); // now it inserts 1 in the beginning => list becomes [ 1 , 2 ]

    display_list(head); // list: 1 -> 2 -> nullptr

    return 0;
}