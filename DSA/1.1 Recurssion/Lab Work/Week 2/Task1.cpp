#include <iostream>
using namespace std;

bool func(string arr)
{
    int left = 0;
    int right = arr.length() - 1;

    while (left < right)
    {
        if (arr[left] != arr[right])
        {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main()
{

    return 0;
}