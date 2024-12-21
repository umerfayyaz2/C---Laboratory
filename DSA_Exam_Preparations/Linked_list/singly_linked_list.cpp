#include <iostream>
using namespace std;

// struct for singly link list node
struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
}

// class for singly linked list
class singly_linked_list
{
    Node *head;

public:
    // constructor
    singly_linked_list() : head(nullptr) {}

    // function to insert at front
    void insert_at_front(int val)
    {
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }
    // function to insert node at the end
    void insert_at_end(int val)
    {
        Node *newNode = new Node(val);
        if (!head)
        {
            head = newNode;
        }
        else
        {
            Node *current = head;
            while (current->next)
            {
                current = current->next;
            }
            current->next = newNode;
        }

        // function to remove from rear
        void remove_from_rear()
        {
            if (!head)
            {
                cout << "List is empty" << endl;
                return;
            }
            else if (head->next == nullptr)
            {
                delete head;
                head = nullptr;
            }
            else
            {
                Node *current = head;
                while (current->next->next)
                {
                    current = current->next;
                }
                delete current->next;
                current->next = nullptr;
            }
        }

        // function to remove from front
        void remove_from_front()
        {
            if (!head)
            {
                cout << "List is empty" << endl;
                return;
            }
            else
            {
                Node *temp = head;
                head = head->next;
                delete temp;
            }
        }
        // function to search element in link list
        bool search_element(int val)
        {
            Node *current = head;
            while (current)
            {
                if (current->data == val)
                {
                    return true;
                }
                current = current->next;
            }
            return false;
        }

        // function to search and remove element from list
        void search_and_remove(int val)
        {
            if (!head)
            {
                cout << "List is empty" << endl;
                return;
            }
            if (head->data == val)
            {
                remove_from_front();
                return;
            }
            Node *current = head;
            while (current->next && current->next->data != val)
            {
                current = current->next;
            }
            if (current->next)
            {
                Node *temp = current->next;
                current->next = current->next->next;
                delete temp;
            }
            else
            {
                cout << "Element not found in list" << endl;
            }

            // function to display elements in list
            void display_list()
            {
                Node *current = head;
                while (current)
                {
                    cout << current->data << " -> ";
                    current = current->next;
                }
                cout << "NULL" << endl;
            }

            // destructor
            ~singly_linked_list()
            {
                while (head)
                {
                    Node *temp = head;
                    head = head->next;
                    delete temp;
                }
            }
        }
    }
}