#include <iostream>
using namespace std;

// Node structure for doubly linked list
struct Node
{
    int data;
    Node *next;
    Node *prev;

    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

// Doubly Linked List class
class DoublyLinkedList
{
private:
    Node *head;
    Node *tail;

public:
    // Constructor to initialize the doubly linked list
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Destructor to free up memory
    ~DoublyLinkedList()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *next = current->next;
            delete current;
            current = next;
        }
    }

    // 1. Insert at front
    void insertAtFront(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = tail = newNode; // If list is empty, both head and tail point to the new node
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // 2. Insert at rear
    void insertAtRear(int value)
    {
        Node *newNode = new Node(value);
        if (tail == nullptr)
        {
            head = tail = newNode; // If list is empty, both head and tail point to the new node
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // 3. Remove from front
    void removeFromFront()
    {
        if (head == nullptr)
        {
            cout << "List is empty." << endl;
            return;
        }
        Node *temp = head;
        if (head == tail)
        { // Only one element in the list
            head = tail = nullptr;
        }
        else
        {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
    }

    // 4. Remove from rear
    void removeFromRear()
    {
        if (tail == nullptr)
        {
            cout << "List is empty." << endl;
            return;
        }
        Node *temp = tail;
        if (head == tail)
        { // Only one element in the list
            head = tail = nullptr;
        }
        else
        {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
    }

    // 5. Display the list
    void display()
    {
        if (head == nullptr)
        {
            cout << "List is empty." << endl;
            return;
        }
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // 6. Search for a value in the list
    bool search(int key)
    {
        Node *current = head;
        while (current != nullptr)
        {
            if (current->data == key)
            {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    // 7. Search and remove a value from the list
    void searchAndRemove(int key)
    {
        if (head == nullptr)
        {
            cout << "List is empty." << endl;
            return;
        }

        Node *current = head;

        // If the node to be removed is at the front
        if (head->data == key)
        {
            Node *temp = head;
            head = head->next;
            if (head != nullptr)
            {
                head->prev = nullptr;
            }
            delete temp;
            return;
        }

        // Traverse the list to find the node to remove
        while (current != nullptr && current->data != key)
        {
            current = current->next;
        }

        // If the key is found
        if (current != nullptr)
        {
            if (current->next != nullptr)
            {
                current->next->prev = current->prev;
            }
            if (current->prev != nullptr)
            {
                current->prev->next = current->next;
            }
            delete current;
        }
        else
        {
            cout << "Value not found in the list." << endl;
        }
    }
};

int main()
{
    DoublyLinkedList list;

    // Test the DoublyLinkedList functions
    list.insertAtFront(10);
    list.insertAtFront(20);
    list.insertAtRear(30);
    list.insertAtRear(40);
    list.display(); // Expected output: 20 10 30 40

    list.removeFromFront();
    list.display(); // Expected output: 10 30 40

    list.removeFromRear();
    list.display(); // Expected output: 10 30

    cout << "Search 30: " << (list.search(30) ? "Found" : "Not Found") << endl; // Found
    cout << "Search 50: " << (list.search(50) ? "Found" : "Not Found") << endl; // Not Found

    list.searchAndRemove(30);
    list.display(); // Expected output: 10

    list.searchAndRemove(50); // Expected output: Value not found in the list.

    return 0;
}
