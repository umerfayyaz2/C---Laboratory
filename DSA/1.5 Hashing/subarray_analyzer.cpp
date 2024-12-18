#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// SubarrayAnalyzer class to encapsulate the logic for finding subarrays
class SubarrayAnalyzer
{
private:
    vector<int> data; // The array to analyze
    int target_sum;   // The target sum to find

public:
    // Constructor
    SubarrayAnalyzer(const vector<int> &arr, int target) : data(arr), target_sum(target) {}

    // Function to count subarrays with the given sum
    int count_subarrays_with_sum()
    {
        unordered_map<int, int> prefix_sum_count; // Hash map to store prefix sums and their counts
        int current_sum = 0;                      // Running sum of the array
        int count = 0;                            // Count of subarrays with the target sum

        // Initialize the hash map with the base case
        prefix_sum_count[0] = 1;

        // Iterate through the array
        for (int num : data)
        {
            current_sum += num; // Update the running sum

            // Check if (current_sum - target_sum) exists in the hash map
            if (prefix_sum_count.find(current_sum - target_sum) != prefix_sum_count.end())
            {
                count += prefix_sum_count[current_sum - target_sum];
            }

            // Update the hash map with the current prefix sum
            prefix_sum_count[current_sum]++;
        }

        return count;
    }

    // Function to display the array
    void display_array() const
    {
        cout << "Array: ";
        for (int num : data)
        {
            cout << num << " ";
        }
        cout << endl;
    }
};

// Main function to demonstrate the functionality
int main()
{
    // Input array and target sum
    vector<int> arr = {10, 2, -2, -20, 10};
    int target = -10;

    // Create an instance of SubarrayAnalyzer
    SubarrayAnalyzer analyzer(arr, target);

    // Display the array
    analyzer.display_array();

    // Count and display the number of subarrays with the target sum
    int count = analyzer.count_subarrays_with_sum();
    cout << "Number of subarrays with sum " << target << ": " << count << endl;

    return 0;
}
