#include <iostream>

void merge_func(int arr[], int start, int mid, int end)
{
    int temp_arr[end - start + 1]; // this array will store our sorted array values
    // we will create left & right pointers for element comparison for L & R halve
    int left = start, right = mid + 1, index = 0;

    while (left <= mid && right <= end)
    {
        if (arr[left] <= arr[right])
        {
            temp_arr[index] = arr[left];
            index++, left++;
        }
        else
        {
            temp_arr[index] = arr[right];
            index++, right++;
        }
    }

    // these while loops will check if any L or R halves elements are still left un-sorted
    while (left <= mid)
    {
        temp_arr[index] = arr[left];
        index++, left++;
    }

    while (right <= end)
    {
        temp_arr[index] = arr[right];
        index++, right++;
    }

    // final copy from temporary array to original array

    for (int i = 0; i < index; i++)
    {
        arr[start + i] = temp_arr[i];
    }
}

void merge_sort(int arr[], int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int mid = start + (end - start) / 2;

    merge_sort(arr, start, mid);   // for left halve division
    merge_sort(arr, mid + 1, end); // for right halve division

    merge_func(arr, start, mid, end); // to merge the left & right halves into a single array
}