#include <iostream>
using namespace std;

bool check_target_sum(int array_of_numbers[], int target_sum)
{
    int left = 0;
    int right = sizeof(array_of_numbers) / sizeof(array_of_numbers[0]) - 1; // it'll store the last index

    while (left < right)
    {
        int sum = array_of_numbers[left] + array_of_numbers[right]; // this will add the first and last index holded values into sum.

        if (sum == target_sum)
        {
            return true;
        }

        if (sum > target_sum)
            right--;
        else
            left++;
    }
    return false;
}