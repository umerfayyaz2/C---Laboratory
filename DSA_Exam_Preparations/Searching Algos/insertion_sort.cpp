#include <iostream>

void insertion_sort(int arr[], int size)
{
    for (int curr_index = 1; curr_index < size; curr_index++)
    {
        int key = arr[curr_index];
        int prev_index = curr_index - 1;

        while (prev_index >= 0 && arr[prev_index] > key)
        {
            arr[prev_index + 1] = arr[prev_index];
            prev_index--; // this will move to prev idex
        }
        arr[prev_index + 1] = key;
    }
}