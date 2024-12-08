#include <iostream>
using namespace std;

void selection_sort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min_index = i;

        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        if (min_index != i)
        { // Only swap if the minimum element is not already at the correct position
            swap(arr[i], arr[min_index]);
        }
    }
}