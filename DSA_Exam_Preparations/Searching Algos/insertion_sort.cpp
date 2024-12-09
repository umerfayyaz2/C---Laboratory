#include <iostream>

void insertion_sort(int arr[], int size)
{
    for (int curr = 1; curr < size; curr++) // curr index starts from the second elem
    {
        int key = arr[curr]; // the key is our curr indexed elem
        int prev = curr - 1; // prev is the index before curr

        while (prev >= 0 && arr[prev] > key)
        {
            arr[prev + 1] = arr[prev];
            prev = prev - 1; // base case
        }

        // Insert the key at the correct position
        arr[prev + 1] = key;
    }
}