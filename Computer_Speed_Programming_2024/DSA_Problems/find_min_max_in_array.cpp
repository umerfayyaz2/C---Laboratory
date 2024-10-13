#include <iostream>
#include <climits>
using namespace std;

void find_min_max_value(const int arr[], int arr_size, int curr_index, int &min_val, int &max_val)
{
    if (curr_index == arr_size)
    {
        return;
    }

    if (arr[curr_index] < min_val)
    {
        min_val = arr[curr_index];
    }

    if (arr[curr_index] > max_val)
    {
        max_val = arr[curr_index];
    }

    find_min_max_value(arr, arr_size, curr_index + 1, min_val, max_val);
}