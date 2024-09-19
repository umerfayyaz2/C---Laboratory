#include <iostream>
#include <string>
using namespace std;

string reverse_string(string str)
{
    int left = 0;
    int right = str.length() - 1;

    while (left < right)
    {
        swap(str[left], str[right])
            left++;
        right--;
    }

    return str;
}