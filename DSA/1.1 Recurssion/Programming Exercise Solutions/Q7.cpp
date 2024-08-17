#include <iostream>
#include <climits>
using namespace std;

void find_min_max_value(const int arr[], int arr_size, int current_index, int &min_value, int &max_value)
{
    if (current_index == arr_size)
    {
        return;
    }

    if (arr[current_index] < min_value)
    {
        min_value = arr[current_index];
    }

    if (arr[current_index] > max_value)
    {
        max_value = arr[current_index];
    }

    find_min_max_value(arr, arr_size, current_index + 1, min_value, max_value);
}

int main()
{
    int size;
    cout << "Please enter the size of array: ";
    cin >> size;
    cout << endl;

    int *arr = new int[size];

    for (int index = 0; index < size; index++)
    {
        cout << "Enter Element " << index << " : ";
        cin >> arr[index];
    }

    int min_value = INT_MAX;

    int max_value = INT_MIN;

    find_min_max_value(arr, size, 0, min_value, max_value);

    cout << "The smallest element is: " << min_value << endl;

    cout << "The largest element is: " << max_value << endl;

    delete[] arr;

    return 0;
}