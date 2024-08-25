#include <iostream>
using namespace std;

// Recursive function for sequential search
int recursive_sequential_search(const int arr[], int size, int target, int current_index = 0)
{
    // Base case: If the current index is equal to the size of the array, the target is not found
    if (current_index == size)
    {
        return -1; // Return -1 if target is not found
    }

    // If the current element matches the target, return the current index
    if (arr[current_index] == target)
    {
        return current_index;
    }

    // Recursive case: Move to the next element
    return recursive_sequential_search(arr, size, target, current_index + 1);
}

int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[size];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    int target;
    cout << "Enter the target value to search for: ";
    cin >> target;

    // Call the recursive search function
    int result = recursive_sequential_search(arr, size, target);

    // Output the result
    if (result != -1)
    {
        cout << "Target found at index: " << result << endl;
    }
    else
    {
        cout << "Target not found in the array." << endl;
    }

    return 0;
}
