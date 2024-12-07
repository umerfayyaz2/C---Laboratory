#include <iostream>
using namespace std;

int linear_search(int arr[], int size_of_array, int target_key)
{

    for (int i = 0; i < size_of_array; i++)
    {
        if (arr[i] == target_key)
        {
            return i;
        }
    }
    return -1;
}

int main()
{

    int arr[] = {12, 13, 11, 9, 5};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    int key;

    cout << "Enter the key to search index in array: ";
    cin >> key;
    cout << endl;

    int result = linear_search(arr, arr_size, key);

    if (result != -1)
    {
        cout << "Element found at index: " << result;
    }
    else
    {
        cout << "Error: Element not present in array";
    }

    return 0;
}