#include <iostream>
using namespace std;

int binary_search(int arr[], int size_of_array, int key)
{
    int low = 0;
    int high = size_of_array - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            low = mid + 1;
        }
        else if (arr[mid] > key)
        {
            high = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 20, 30, 60};
    int size_arr = sizeof(arr) / sizeof(arr[0]);
    int key;

    cout << "Enter the value to search index for: ";
    cin >> key;
    cout << endl;

    int result = binary_search(arr, size_arr, key);

    if (result != -1)
    {
        cout << "Value found at index: " << result;
    }
    else
    {
        cout << "Error: Value not found.";
    }
    return 0;
}