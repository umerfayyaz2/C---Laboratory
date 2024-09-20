#include <iostream>
using namespace std;

int reverse_number(int num)
{
    int reveresed = 0; // this will store the reversed number

    while (num != 0)
    {
        int digit = n % 10;
        reveresed = reveresed * 10 + digit;
        n /= 10;
    }

    return reveresed;
}
