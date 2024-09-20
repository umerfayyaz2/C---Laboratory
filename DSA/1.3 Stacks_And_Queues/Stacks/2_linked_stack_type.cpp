#include <iostream>
#include <cassert> // for assert
using namespace std;

// Definition of the node
template <class Type>
struct node_type
{
    Type info;
    node_type<Type> *link;
};

// Abstract stackADT class (for reference)
template <class Type>
class stack_adt
{
public:
    virtual bool is_empty_stack() const = 0;
    virtual bool is_full_stack() const = 0;
    virtual void initialize_stack() = 0;
    virtual void push(const Type &new_element) = 0;
    virtual Type top() const = 0;
    virtual void pop() = 0;
};

// Linked stack implementation of stackADT
template <class Type>
class linked_stack_type : public stack_adt<Type>
{
public:
    // Constructor
    linked_stack_type();

    // Copy Constructor
    linked_stack_type(const linked_stack_type<Type> &other_stack);

    // Destructor
    ~linked_stack_type();

    // Overload the assignment operator
    const linked_stack_type<Type> &operator=(const linked_stack_type<Type> &other_stack);

    // Function to determine whether the stack is empty
    bool is_empty_stack() const;

    // Function to determine whether the stack is full (returns false for linked stack)
    bool is_full_stack() const;

    // Function to initialize the stack to an empty state
    void initialize_stack();

    // Function to add newItem to the stack
    void push(const Type &new_item);

    // Function to return the top element of the stack
    Type top() const;

    // Function to remove the top element of the stack
    void pop();

private:
    node_type<Type> *stack_top; // pointer to the top of the stack

    // Function to make a copy of otherStack
    void copy_stack(const linked_stack_type<Type> &other_stack);
};

// Default constructor
template <class Type>
linked_stack_type<Type>::linked_stack_type()
{
    stack_top = nullptr; // initialize stackTop to nullptr (empty stack)
}

// Copy constructor
template <class Type>
linked_stack_type<Type>::linked_stack_type(const linked_stack_type<Type> &other_stack)
{
    stack_top = nullptr;
    copy_stack(other_stack); // copy the elements of otherStack
}

// Destructor
template <class Type>
linked_stack_type<Type>::~linked_stack_type()
{
    initialize_stack(); // deallocate memory
}

// Overload assignment operator
template <class Type>
const linked_stack_type<Type> &linked_stack_type<Type>::operator=(const linked_stack_type<Type> &other_stack)
{
    if (this != &other_stack)
    { // avoid self-assignment
        copy_stack(other_stack);
    }
    return *this;
}

// Function to determine whether the stack is empty
template <class Type>
bool linked_stack_type<Type>::is_empty_stack() const
{
    return (stack_top == nullptr); // stack is empty if stackTop is nullptr
}

// Function to determine whether the stack is full
template <class Type>
bool linked_stack_type<Type>::is_full_stack() const
{
    return false; // in linked stack, the stack is never full (unless memory is exhausted)
}

// Function to initialize the stack to an empty state
template <class Type>
void linked_stack_type<Type>::initialize_stack()
{
    node_type<Type> *temp; // pointer to delete the node
    while (stack_top != nullptr)
    {
        temp = stack_top;
        stack_top = stack_top->link;
        delete temp; // deallocate memory
    }
}

// Function to add newItem to the stack
template <class Type>
void linked_stack_type<Type>::push(const Type &new_item)
{
    node_type<Type> *new_node = new node_type<Type>; // create a new node
    new_node->info = new_item;                       // store the new item
    new_node->link = stack_top;                      // link the new node to the current stack top
    stack_top = new_node;                            // update stackTop to point to the new node
}

// Function to return the top element of the stack
template <class Type>
Type linked_stack_type<Type>::top() const
{
    assert(stack_top != nullptr); // check if stack is empty
    return stack_top->info;       // return the top element
}

// Function to remove the top element of the stack
template <class Type>
void linked_stack_type<Type>::pop()
{
    if (stack_top != nullptr)
    {
        node_type<Type> *temp = stack_top; // set temp to point to the top node
        stack_top = stack_top->link;       // update stackTop to point to the next node
        delete temp;                       // deallocate memory
    }
    else
    {
        cout << "Cannot remove from an empty stack." << endl;
    }
}

// Function to copy otherStack to this stack
template <class Type>
void linked_stack_type<Type>::copy_stack(const linked_stack_type<Type> &other_stack)
{
    if (stack_top != nullptr)
    {
        initialize_stack(); // if this stack is non-empty, empty it
    }

    if (other_stack.stack_top == nullptr)
    {
        stack_top = nullptr; // if otherStack is empty, set this stack to empty
    }
    else
    {
        node_type<Type> *current = other_stack.stack_top; // pointer to traverse the otherStack
        stack_top = new node_type<Type>;                  // create the node
        stack_top->info = current->info;                  // copy the first element
        stack_top->link = nullptr;                        // set the link field to nullptr
        node_type<Type> *last = stack_top;                // pointer to keep track of the last node

        current = current->link; // move to the next node
        while (current != nullptr)
        {
            node_type<Type> *new_node = new node_type<Type>; // create a new node
            new_node->info = current->info;                  // copy info
            new_node->link = nullptr;                        // set link to nullptr
            last->link = new_node;                           // link the last node to the newNode
            last = new_node;                                 // move last to the new node
            current = current->link;                         // move current to the next node
        }
    }
}

// Main function to demonstrate the linked stack
int main()
{
    linked_stack_type<int> stack;

    // Push elements onto the stack
    stack.push(10);
    stack.push(20);
    stack.push(30);

    // Display top element
    cout << "Top element: " << stack.top() << endl;

    // Pop top element
    stack.pop();
    cout << "Top element after pop: " << stack.top() << endl;

    // Push a new element
    stack.push(40);
    cout << "Top element after push: " << stack.top() << endl;

    return 0;
}