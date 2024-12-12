#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {}
};

class linked_list
{
private:
    Node *head;

public:
    linked_list() : next(nullptr) {}

    // 1-Insert at front function
    void insert_at_front(int val)
    {
        Node *new_node = new Node(val);
        new_node->next = head; // if head is pointing to some node then our new node will point to that node now
        head = new_node;       // and then our head will point to our new node which will be our new first node now
    }

    // 2-Insert at rear (last node)
    void insert_at_rear(int val)
    {
        Node *new_node = new Node(val);

        if (head == nullptr)
        {
            head = new_node; // if there is no node then our new node will be our first node
            return;
        }

        // otherwise if we have already a linked list
        Node *current = head;

        while (current->next != nullptr)
        {
            current = current->next; // this will find our last node and then it'll will exit when it'll reach our last node
        }

        current->next = new_node;
    }

    // 3- Delete from front function
    void remove_from_front()
    {
        if (head == nullptr)
        {
            cout << "List is empty." << endl;
            return;
        }

        Node *temp = head; // temp points to head
        head = head->next; // head points to the second node now
        delete temp;       // and we delete temp , which also deletes the head and the head pointing value
    }

    // 4- Delete from rear function
    void remove_from_rear()
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }

        if (head->next == nullptr) // if head contains only one node
        {
            delete head;
            head = nullptr; // to avoid dangling
            return;
        }

        Node *current = head;
        while (current->next != nullptr && current->next->next != nullptr)
        {
            current = current->next; // traverse until it find null }
        }

        // when it finds the null value the below code executes
        delet current->next;
        current->next = nullptr;
    }

    // 6- display the list function
    void display()
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return; // no need to show any error msg
        }

        Node *current = head;

        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // 7 - Search for a key in list
    void search(int key)
    {
        Node *current = head;

        while (current != nullptr)
        {
            if (current->data == key)
            {
                cout << "Found key: " << key << endl;
                return true;
            }
        }
        cout << "No key found." << endl;
        return false;
    }

    // 8- Search and remove function
    void search_and_remove(int key)
    {
        if (head == nullptr)
        {
            cout << "List is empty." << endl;
            return;
        }

        // if the key is found at head
        if (head->data == key)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node *current = head;
        while (current->next != nullptr && current->next->next != nullptr)
        {
            current = current->next; // when null is found this while loop will terminate
        }

        // if the key is finally found
        if (current->next != nullptr)
        {
            Node *temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
        else
        {
            cout << "value not found in the list" << endl;
        }
    }
}