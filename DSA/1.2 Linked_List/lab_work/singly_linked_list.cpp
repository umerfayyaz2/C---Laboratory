#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value) : data(value), next(nullptr) {}
};

class SinglyLinkedList
{
private:
    Node *head; // Points to the first node
    Node *rear; // Points to the last node

public:
    SinglyLinkedList() : head(nullptr), rear(nullptr) {}

    // Insert at Head
    void insertAtHead(int value)
    {
        Node *newNode = new Node(value);
        if (!head)
        { // If the list is empty
            head = newNode;
            rear = newNode; // Both head and rear point to the only node
        }
        else
        {
            newNode->next = head; // Point new node to the current head
            head = newNode;       // Update head to the new node
        }
    }

    // Insert at Rear
    void insertAtRear(int value)
    {
        Node *newNode = new Node(value);
        if (!head)
        { // If the list is empty
            head = newNode;
            rear = newNode; // Both head and rear point to the only node
        }
        else
        {
            rear->next = newNode; // Attach new node at the end
            rear = newNode;       // Update rear to the new node
        }
    }

    // Remove from Head
    void removeFromHead()
    {
        if (!head)
        {
            cout << "List is empty. Nothing to remove from head." << endl;
            return;
        }
        Node *temp = head;
        if (head == rear)
        { // Only one element
            head = nullptr;
            rear = nullptr;
        }
        else
        {
            head = head->next; // Move head to the next node
        }
        delete temp;
    }

    // Remove from Rear
    void removeFromRear()
    {
        if (!head)
        {
            cout << "List is empty. Nothing to remove from rear." << endl;
            return;
        }
        if (head == rear)
        { // Only one element
            delete head;
            head = nullptr;
            rear = nullptr;
        }
        else
        {
            Node *temp = head;
            // Traverse to the second-last node
            while (temp->next != rear)
            {
                temp = temp->next;
            }
            delete rear;          // Delete the last node
            rear = temp;          // Update rear to the second-last node
            rear->next = nullptr; // Set new rear's next to nullptr
        }
    }

    // Display the List
    void display() const
    {
        if (!head)
        {
            cout << "List is empty." << endl;
            return;
        }
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "null" << endl;
    }
};

int main()
{
    SinglyLinkedList list;

    // Testing the functions
    list.insertAtHead(3);
    list.insertAtHead(2);
    list.insertAtHead(1);
    cout << "After inserting 1, 2, 3 at head:" << endl;
    list.display();

    list.insertAtRear(4);
    list.insertAtRear(5);
    cout << "After inserting 4, 5 at rear:" << endl;
    list.display();

    list.removeFromHead();
    cout << "After removing from head:" << endl;
    list.display();

    list.removeFromRear();
    cout << "After removing from rear:" << endl;
    list.display();

    return 0;
}