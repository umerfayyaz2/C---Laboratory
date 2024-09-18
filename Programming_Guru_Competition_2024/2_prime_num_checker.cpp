#include <iostream>
#include <cmath>
using namespace std;

// 0 = false , 1 = true

bool is_prime(int num)
{
    if (num <= 1)
        return 0;
    if (num == 2 || num == 3)
        return 1;

    for (int index = 2; index <= sqrt(num); index++)
    {
        if (num % index == 0)
            return 0;
    }

    return 1;
}

int main()
{
    int number;
    cout << "Enter a number to check if prime: ";
    cin >> number;

    if (is_prime(number))
        cout << "\nPrime.";
    else
    {
        cout << "\nNot Prime.";
    }

    return 0;
}