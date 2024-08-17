#include <iostream>
using namespace std;

int reverse_digit(int number, int reversed_number = 0)
{
    if (number == 0)
    {
        return reversed_number;
    }

    int last_digit = number % 10;
    reversed_number = reversed_number * 10 + last_digit;

    return reverse_digit(number / 10, reversed_number);
}

int main()
{

    int *num = new int;
    cout << "Please numbers to make them reverse: ";
    cin >> *num;
    cout << endl;

    int *reversed_number = new int;
    *reversed_number = reverse_digit(*num);

    cout << "The reversed number is: " << *reversed_number << endl;

    delete num;
    delete reversed_number;

    return 0;
}