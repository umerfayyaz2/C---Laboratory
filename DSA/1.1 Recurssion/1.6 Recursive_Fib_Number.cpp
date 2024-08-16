#include <iostream>
using namespace std;

int recursive_fibonacci_number(int a, int b, int position)
{
    if (position == 1) // base case 1
        return a;
    else if (position == 2) // base case 2 --- both cases should be true
        return b;

    else
        return recursive_fibonacci_number(a, b, position - 1), recursive_fibonacci_number(a, b, position - 2); // recursive case
}

int main()
{

    int number;
    cout << "Please enter a valid non-zero number to find the Fibonnaci value of it: ";
    cin >> number;

    if (number <= 0)
    {
        cout << "Error: Please enter a non-zero digit.\n";
    }

    else
        cout << "The Fibonacci Value for the number " << number << " is: " << recursive_fibonacci_number(2, 5, 4);

    return 0;
}