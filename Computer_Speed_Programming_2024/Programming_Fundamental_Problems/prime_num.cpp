#include <iostream>
#include <cmath> // For sqrt function
using namespace std;

void check_prime_num(int number)
{
    // Check if the number is less than 2
    if (number < 2)
    {
        cout << number << " is not a prime number." << endl;
        return;
    }

    // Check for factors from 2 to the square root of the number
    for (int i = 2; i <= sqrt(number); i++)
    {
        if (number % i == 0)
        {
            cout << number << " is not a prime number." << endl;
            return;
        }
    }

    // If no factors were found, it's prime
    cout << number << " is a prime number." << endl;
}

int main()
{
    int num;
    cout << "Enter an integer: ";
    cin >> num;           // Input from user
    check_prime_num(num); // Check if the number is prime
    return 0;
}
