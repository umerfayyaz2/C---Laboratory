#include <iostream>
#include <cmath> // For fabs function
using namespace std;

// Recursive function to calculate the square root using Newton's method
double recursive_sqrt(double x, double a, double epsilon)
{
    // Base case: If the approximation is close enough, return it
    if (fabs(a * a - x) <= epsilon)
    {
        return a;
    }

    // Recursive case: Improve the approximation
    a = (a + x / a) / 2;
    return recursive_sqrt(x, a, epsilon);
}

int main()
{
    double x, epsilon;

    cout << "Enter a nonnegative number to find the square root: ";
    cin >> x;

    if (x < 0)
    {
        cout << "Square root of a negative number is not real." << endl;
        return 1;
    }

    cout << "Enter the tolerance (epsilon): ";
    cin >> epsilon;

    // Start with an initial guess for the square root
    double initial_guess = x / 2.0;

    // Call the recursive square root function
    double result = recursive_sqrt(x, initial_guess, epsilon);

    // Output the result
    cout << "The square root of " << x << " within the tolerance " << epsilon << " is approximately: " << result << endl;

    return 0;
}
