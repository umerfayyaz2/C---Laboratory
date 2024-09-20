#ifndef H_StackType
#define H_StackType

#include <iostream>
#include <cassert>
#include "stackADT.h"
using namespace std;

// The stackType class inherits from stackADT
template <class Type>
class stackType : public stack_adt<Type>
{
public:
    // Overload the assignment operator
    const stackType<Type> &operator=(const stackType<Type> &);

    // Implementations of the pure virtual functions from stackADT
    void initialize_stack();
    bool is_empty_stack() const;
    bool is_full_stack() const;
    void push(const Type &newItem);
    Type top() const;
    void pop();

    // Constructor, Copy Constructor, Destructor
    stackType(int stackSize = 100);
    stackType(const stackType<Type> &otherStack);
    ~stackType();

private:
    int max_stack_size; // Variable to store the maximum size of the stack
    int stack_top;      // Variable to point to the top of the stack
    Type *list;         // Pointer to an array to hold the stack elements

    // Private function to copy another stack into this stack
    void copy_stack(const stackType<Type> &otherStack);
};

// Implementation of the member functions

// Constructor to create a stack with the given size
template <class Type>
stackType<Type>::stackType(int stackSize)
{
    if (stackSize <= 0)
    {
        cout << "Stack size must be positive. Creating stack of size 100." << endl;
        max_stack_size = 100;
    }
    else
    {
        max_stack_size = stackSize;
    }
    stack_top = 0;                   // Initially, the stack is empty
    list = new Type[max_stack_size]; // Allocate memory for the stack
}

// Destructor to deallocate memory for the stack
template <class Type>
stackType<Type>::~stackType()
{
    delete[] list; // Deallocate memory used by the array
}

// Function to initialize the stack
template <class Type>
void stackType<Type>::initialize_stack()
{
    stack_top = 0; // Set stackTop to 0, meaning the stack is empty
}

// Function to check if the stack is empty
template <class Type>
bool stackType<Type>::is_empty_stack() const
{
    return (stack_top == 0); // The stack is empty if stackTop is 0
}

// Function to check if the stack is full
template <class Type>
bool stackType<Type>::is_full_stack() const
{
    return (stack_top == max_stack_size); // The stack is full if stackTop equals maxStackSize
}

// Function to add an item to the stack
template <class Type>
void stackType<Type>::push(const Type &newItem)
{
    if (!is_full_stack())
    {
        list[stack_top] = newItem; // Place the new item at the top of the stack
        stack_top++;               // Increment stackTop to point to the new top
    }
    else
    {
        cout << "Cannot add to a full stack." << endl;
    }
}

// Function to return the top element of the stack
template <class Type>
Type stackType<Type>::top() const
{
    assert(stack_top != 0);     // Check that the stack is not empty
    return list[stack_top - 1]; // Return the element at the top of the stack
}

// Function to remove the top element of the stack
template <class Type>
void stackType<Type>::pop()
{
    if (!is_empty_stack())
    {
        stack_top--; // Simply decrement stackTop to "remove" the top item
    }
    else
    {
        cout << "Cannot remove from an empty stack." << endl;
    }
}

// Copy constructor to create a copy of another stack
template <class Type>
stackType<Type>::stackType(const stackType<Type> &otherStack)
{
    list = nullptr;         // Initialize the list to nullptr
    copy_stack(otherStack); // Call the copyStack function to copy the other stack
}

// Function to copy the contents of another stack into this stack
template <class Type>
void stackType<Type>::copy_stack(const stackType<Type> &otherStack)
{
    delete[] list;                              // Deallocate the memory currently in use
    max_stack_size = otherStack.max_stack_size; // Copy the size
    stack_top = otherStack.stack_top;           // Copy the top index
    list = new Type[max_stack_size];            // Allocate new memory for the list
    for (int i = 0; i < stack_top; i++)
    {
        list[i] = otherStack.list[i]; // Copy each element from the other stack
    }
}

// Overload the assignment operator
template <class Type>
const stackType<Type> &stackType<Type>::operator=(const stackType<Type> &otherStack)
{
    if (this != &otherStack)
    {                           // Avoid self-assignment
        copy_stack(otherStack); // Call copyStack to copy the other stack
    }
    return *this;
}

#endif