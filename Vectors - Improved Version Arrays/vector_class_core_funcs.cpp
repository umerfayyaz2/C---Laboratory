#include <iostream>
#include <stdexcept>

template <typename T>
class MyVector
{
private:
    T *data;         // Pointer to the array of elements
    size_t capacity; // Total allocated space
    size_t size;     // Current number of elements

public:
    MyVector() : capacity(1), size(0)
    {
        data = new T[capacity]; // Allocate initial space
    }

    ~MyVector()
    {
        delete[] data; // Free memory
    }

    // Insert an element at the end
    void push_back(const T &value)
    {
        if (size == capacity)
        {
            resize();
        }
        data[size++] = value; // Insert value and increment size
    }

    // Access element at index with bounds checking
    T &at(size_t index)
    {
        if (index >= size)
        {
            throw std::out_of_range("Index out of bounds");
        }
        return data[index];
    }

    // Return current size
    size_t getSize() const
    {
        return size;
    }

private:
    // Resize the internal storage
    void resize()
    {
        capacity *= 2;                // Double the capacity
        T *newData = new T[capacity]; // Allocate new array
        for (size_t i = 0; i < size; ++i)
        {
            newData[i] = data[i]; // Copy old data to new array
        }
        delete[] data;  // Free old array
        data = newData; // Point to new array
    }
};
