#include <iostream>
using namespace std;

void sum_of_digits(int num)
{
    int sum = 0;

    while (num > 0)
    {
        int digit = num % 10;
        sum += digit;
        num = num / 10;
    }

    cout << "Sum of digits = " << sum << endl;
}

int main()
{

    int number;
    cout << "Please enter a positive number to calculate it's sum: ";
    cin >> number;

    sum_of_digits(number);
    return 0;
}