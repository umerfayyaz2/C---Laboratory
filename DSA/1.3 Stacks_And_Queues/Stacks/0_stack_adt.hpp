#ifndef stack_ADT
#define stack_ADT

template <class Type>
class stack_adt
{
public:
    // Pure virtual functions to be implemented by derived classes
    virtual void initialize_stack() = 0;
    virtual bool is_empty_stack() = 0;
    virtual bool is_full_stack() = 0;
    virtual void push(const Type &new_item) = 0;
    virtual Type top() const = 0; // accessor function only
    virtual void pop() = 0;
};

#endif