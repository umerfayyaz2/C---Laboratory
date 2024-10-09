#include <iostream>
using namespace std;

void check_even_odd_function(int number)
{
    if (number % 2 == 0)
    {
        cout << number << " is even.\n";
    }
    else
    {
        cout << number << " is odd.\n";
    }
}

int main()
{
    int num;
    cout << "Please enter a number to check if it's even or odd: ";
    cin >> num;

    check_even_odd_function(num);
    return 0;
}
