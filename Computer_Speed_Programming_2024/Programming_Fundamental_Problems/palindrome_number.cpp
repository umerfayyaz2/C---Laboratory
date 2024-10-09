#include <iostream>
using namespace std;

void check_palindrome_number(int number)
{
    int original_num = number;
    int reveresed_num = 0;

    while (number > 0)
    {
        int last_digit = number % 10; // usig % to extract last num
        reveresed_num = reveresed_num * 10 + last_digit;
        number = number / 10; // to remove the last digit
    }

    if (original_num == reveresed_num)
    {
        cout << original_num << " is a palindrome.\n";
    }
    else
    {
        cout << original_num << " is not a palindrome.\n";
    }
}

int main()
{
    int num;
    cout << "Enter an integer: ";
    cin >> num;                   // Input from user
    check_palindrome_number(num); // Check if the number is a palindrome
    return 0;
}