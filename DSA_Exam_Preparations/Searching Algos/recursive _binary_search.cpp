#include <iostream>
using namespace std;

int rec_binary_search(int arr[], int low, int high, int key)
{
    if (low > high)
    {
        return -1;
    }

    int mid = low + (high - low) / 2;

    if (arr[mid] == key)
    {
        return mid;
    }

    if (arr[mid] < key)
    {
        // low = mid + 1;
        return rec_binary_search(arr, mid + 1, high, key);
    }
    else if (arr[mid] > key)
    {
        // high = mid - 1;
        return rec_binary_search(arr, low, mid - 1, key);
    }
}

int main()
{
    int arr[] = {1, 3, 5, 7, 9, 11};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key;

    cout << "Enter the key to search in array: ";
    cin >> key;

    int result = rec_binary_search(arr, 0, size - 1, key);

    if (result != -1)
    {
        cout << "Element found at index: " << result << endl;
    }
    else
    {
        cout << "Element not found!" << endl;
    }

    return 0;
}
