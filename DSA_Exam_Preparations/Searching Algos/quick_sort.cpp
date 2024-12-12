#include <iostream>
using namespace std;

int partition_func(int arr[], int start, int end)
{
    int pos = start;

    for (int i = start; i <= end; i++)
    {
        if (arr[i] <= arr[end])
        {
            swap(arr[i], arr[pos]);
        }
    }
    return pos - 1;
}

void quick_sort(int arr[], int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int pivot = partition_func(arr, start, end);

    quick_sort(arr, start, pivot); // for left halve
    quick_sort(arr, pivot + 1, end);
}

int main()
{
    int arr[] = {10, 1, 12, 2, 11, 13, 7, 3, 9, 8};
    int size_arr = sizeof(arr) / sizeof(arr[0]);

    quick_sort(arr, 0, size_arr - 1);

    for (int i = 0; i <= size_arr - 1; i++)
    {
        cout << arr[i];
    }

    return 0;
}