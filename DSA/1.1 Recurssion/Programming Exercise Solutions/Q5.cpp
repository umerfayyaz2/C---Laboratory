#include <iostream>
using namespace std;

int sum_of_array(int arr[], int size)
{
    if (size == 0)
    {
        return 0;
    }

    return arr[size - 1] + sum_of_array(arr, size - 1);
}

int main()
{
    int size;
    cout << "Enter the size of array: ";
    cin >> size;
    cout << endl;

    if (size < 0)
    {
        cout << "Error: Number must be positive." << endl;
    }

    int *arr = new int[size];

    for (int index = 0; index < size; index++)
    {
        cout << "Enter number " << index + 1 << " for sum: ";
        cin >> arr[index];
        cout << endl;
    }

    int sum_results = sum_of_array(arr, size);

    cout << "The resulting sum: " << sum_results << endl;

    delete[] arr;

    return 0;
}