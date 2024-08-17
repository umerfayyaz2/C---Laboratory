#include <iostream>
using namespace std;

int sum_of_digits(int num)
{
    if (num == 0)
    {
        return 0;
    }

    int last_digit = num % 10;
    int remaining_digits = num / 10;

    return last_digit + sum_of_digits(remaining_digits);
}

int main()
{

    int *number = new int;
    cout << "Please enter a number to make a sum: ";
    cin >> *number;

    int *sum = new int;
    *sum = sum_of_digits(*number);

    cout << "The sum of digits is: " << *sum << endl;

    delete number;
    delete sum;

    return 0;
}