#include <iostream>
using namespace std;

void findLargestElement(int arr[], int size)
{
    // Step 1: Assume the first element is the largest
    int largest = arr[0];

    // Step 2: Loop through the array starting from the second element
    for (int i = 1; i < size; i++)
    {
        // Step 3: Compare each element with the current largest element
        if (arr[i] > largest)
        {
            largest = arr[i]; // Update largest if current element is greater
        }
    }

    // Step 4: Output the largest element
    cout << "The largest element in the array is: " << largest << endl;
}

int main()
{
    int size;

    // Taking input for the array size
    cout << "Enter the number of elements in the array: ";
    cin >> size;

    int arr[size];

    // Taking input for the array elements
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    // Call the function to find the largest element
    findLargestElement(arr, size);

    return 0;
}
