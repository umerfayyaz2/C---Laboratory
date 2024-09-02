#include <iostream>
#include <vector>

using namespace std;

vector<int> sorted_squares(vector<int> &nums)
{
    int size_of_nums = nums.size();
    vector<int> result(size_of_nums);
    int left_pointer = 0;
    int right_pointer = size_of_nums - 1;
    int current_position = size_of_nums - 1;

    while (left_pointer <= right_pointer)
    {
        int left_square = nums[left_pointer] * nums[left_pointer];
        int right_square = nums[right_pointer] * nums[right_pointer];

        if (left_square > right_square)
        {
            result[current_position] = left_square;
            left_pointer++;
        }
        else
        {
            result[current_position] = right_square;
            right_pointer--;
        }
        current_position--;
    }

    return result;
}

int main()
{
    vector<int> nums = {-4, -1, 0, 3, 10};
    vector<int> squared_sorted_array = sorted_squares(nums);

    cout << "Squared and Sorted Array: ";
    for (int num : squared_sorted_array)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
