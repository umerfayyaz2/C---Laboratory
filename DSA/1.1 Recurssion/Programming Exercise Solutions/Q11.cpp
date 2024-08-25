#include <iostream>
using namespace std;

double power_function(int base, int exponent)
{
    // Base Case: If the exponent is 0 , return 1
    if (exponent == 0)
    {
        return 1;
    }

    // if the exponent is positive
    if (exponent > 0)
    {
        return base * power_function(base, exponent - 1);
    }

    // if the exponent is negative
    if (exponent < 0)
    {
        return 1.0 / power_function(base, -exponent);
    }

    // If for some reason none of the above cases match (although theoretically impossible),
    // we'll return 0 as a fallback (not really needed).
    return 0;
}

int main()
{
    int x, y;

    // Input base (x) and exponent (y)
    cout << "Enter the base (non-zero integer): ";
    cin >> x;
    cout << "Enter the exponent (integer): ";
    cin >> y;

    // Calculate power using the recursive function
    double result = power_function(x, y);

    // Output the result
    cout << x << " raised to the power of " << y << " is: " << result << endl;

    return 0;
}