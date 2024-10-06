#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

// Recursive Sequential Search
int recursiveSequentialSearch(const vector<int> &list, int target, int index)
{
    if (index >= list.size())
        return -1;
    if (list[index] == target)
        return index;
    return recursiveSequentialSearch(list, target, index + 1);
}

// Recursive Binary Search
int recursiveBinarySearch(const vector<int> &list, int left, int right, int target, int &comparisons)
{
    if (left > right)
        return -1;
    int mid = left + (right - left) / 2;
    comparisons++;
    if (list[mid] == target)
        return mid;
    if (list[mid] > target)
        return recursiveBinarySearch(list, left, mid - 1, target, comparisons);
    else
        return recursiveBinarySearch(list, mid + 1, right, target, comparisons);
}

// Hybrid search: Binary search switching to sequential search for small arrays
int hybridSearch(const vector<int> &list, int left, int right, int target, int &comparisons)
{
    if (right - left < 15)
    {
        for (int i = left; i <= right; i++)
        {
            comparisons++;
            if (list[i] == target)
                return i;
        }
        return -1;
    }
    return recursiveBinarySearch(list, left, right, target, comparisons);
}

int main()
{
    srand(time(0));

    // Step 1: Create a list of 1000 random elements
    vector<int> list(1000);
    for (int &num : list)
    {
        num = rand() % 10000; // Random numbers between 0 and 9999
    }

    // Step 2: Sort the list
    sort(list.begin(), list.end());

    // Step 3: Choose a random target
    int target = list[rand() % 1000]; // Choose a random element from the list as target

    // Step 4: Perform binary search and count comparisons
    int binaryComparisons = 0;
    int binaryResult = recursiveBinarySearch(list, 0, list.size() - 1, target, binaryComparisons);

    // Step 5: Perform hybrid search and count comparisons
    int hybridComparisons = 0;
    int hybridResult = hybridSearch(list, 0, list.size() - 1, target, hybridComparisons);

    // Step 6: Output the results
    cout << "Target: " << target << endl;
    cout << "Binary Search: Comparisons = " << binaryComparisons;
    if (binaryResult != -1)
        cout << ", Found at index " << binaryResult << endl;
    else
        cout << ", Not Found" << endl;

    cout << "Hybrid Search: Comparisons = " << hybridComparisons;
    if (hybridResult != -1)
        cout << ", Found at index " << hybridResult << endl;
    else
        cout << ", Not Found" << endl;

    return 0;
}
