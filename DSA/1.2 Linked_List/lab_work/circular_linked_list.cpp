#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value) : data(value), next(nullptr) {}
};

class CircularLinkedList
{
private:
    Node *head;
    Node *rear;

public:
    CircularLinkedList() : head(nullptr), rear(nullptr) {}

    // Insert at Head
    void insertAtHead(int value)
    {
        Node *newNode = new Node(value);
        if (!head)
        { // If list is empty
            head = newNode;
            rear = newNode;
            newNode->next = head; // Points back to itself
        }
        else
        {
            newNode->next = head; // New node points to current head
            head = newNode;
            rear->next = head; // Rear now points to new head
        }
    }

    // Insert at Rear
    void insertAtRear(int value)
    {
        Node *newNode = new Node(value);
        if (!head)
        { // If list is empty
            head = newNode;
            rear = newNode;
            newNode->next = head; // Points back to itself
        }
        else
        {
            rear->next = newNode; // Rear points to new node
            rear = newNode;       // Update rear to new node
            rear->next = head;    // Rear points back to head, maintaining circular structure
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
        if (head == rear)
        { // Only one node
            delete head;
            head = nullptr;
            rear = nullptr;
        }
        else
        {
            Node *temp = head;
            head = head->next; // Move head to next node
            rear->next = head; // Rear points to new head
            delete temp;
        }
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
        { // Only one node
            delete head;
            head = nullptr;
            rear = nullptr;
        }
        else
        {
            Node *temp = head;
            // Traverse to second-last node
            while (temp->next != rear)
            {
                temp = temp->next;
            }
            delete rear;       // Delete last node
            rear = temp;       // Update rear to second-last node
            rear->next = head; // Rear points to head, maintaining circular structure
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
        do
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head); // Continue until we loop back to head
        cout << "(back to head)" << endl;
    }
};

int main()
{
    CircularLinkedList list;

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