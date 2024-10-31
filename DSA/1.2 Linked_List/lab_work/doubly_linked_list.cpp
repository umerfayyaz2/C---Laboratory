#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList
{
private:
    Node *head;

public:
    DoublyLinkedList() : head(nullptr) {}

    // Insert at Head
    void insertAtHead(int value)
    {
        Node *newNode = new Node(value);
        if (!head)
        { // If the list is empty
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Insert at Rear
    void insertAtRear(int value)
    {
        Node *newNode = new Node(value);
        if (!head)
        { // If the list is empty
            head = newNode;
        }
        else
        {
            Node *temp = head;
            // Traverse to the last node
            while (temp->next)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
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
        if (head->next == nullptr)
        { // Only one node
            head = nullptr;
        }
        else
        {
            head = head->next;
            head->prev = nullptr;
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
        if (!head->next)
        { // Only one node
            delete head;
            head = nullptr;
        }
        else
        {
            Node *temp = head;
            // Traverse to the second-last node
            while (temp->next->next)
            {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = nullptr;
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
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    DoublyLinkedList list;

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