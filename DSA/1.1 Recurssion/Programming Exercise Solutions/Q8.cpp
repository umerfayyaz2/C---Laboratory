#include <iostream>
using namespace std;

bool are_digits_increasig(int number)
{
    // base case: IF the number is a single digit return true.
    if (number < 10)
    {
        return true;
    }

    // To get last 2 digits of the number.

    int last_digit = number % 10;
    int second_last_digit = (number / 10) % 10;

    // Condition to check if the last-digit is greater tha the second-last digit
    if (last_digit > second_last_digit)
    {
        return are_digits_increasig(number / 10); // recursive case : to remove the last digit after each recursive call
    }

    else
    {
        return false;
    }
}

int main()
{
    int *num = new int;
    cout << "Enter a positive number: ";
    cin >> *num;
    cout << endl;

    if (are_digits_increasig(*num))
    {
        cout << "The digits of the number " << *num << " are in Increasing Order" << endl;
    }
    else
    {
        cout << "The digits of the number " << *num << " are not in Increasing Order";
    }

    delete num;

    return 0;
}
