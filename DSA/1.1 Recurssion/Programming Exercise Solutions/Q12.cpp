#include <iostream>
using namespace std;

int Greatest_Common_Divisor(int x, int y)
{
    // Base Case: If y is 0, return x as the Greatest_Common_Divisor
    if (y == 0)
    {
        return x;
    }

    // Recursive Case: Greatest_Common_Divisor(y, x % y)
    return Greatest_Common_Divisor(y, x % y);
}

int main()
{
    int x, y;

    // Input two integers x and y
    cout << "Enter two integers: ";
    cin >> x >> y;

    // Calculate Greatest_Common_Divisor using the recursive function
    int result = Greatest_Common_Divisor(x, y);

    // Output the result
    cout << "The greatest common divisor of " << x << " and " << y << " is: " << result << endl;

    return 0;
}
