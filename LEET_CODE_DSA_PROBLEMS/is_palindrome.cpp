#include <iostream>
using namespace std;

bool is_palindrome(string random_words)
{
    int left = 0;
    int right = sizeof(random_words) / sizeof(random_words[0]) - 1; // This will assign the last index to variable 'right'

    while (left < right)
    {
        if (random_words[left] != random_words[right])
        {
            return false;
        }

        left++;
        right--;
    }
    return true;
}