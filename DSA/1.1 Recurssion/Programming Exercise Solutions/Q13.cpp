#include <iostream>
using namespace std;

int ackermann(int m, int n)
{
    // Base case 1: If m is 0, return n + 1
    if (m == 0)
    {
        return n + 1;
    }
    // Base case 2: If m > 0 and n is 0, return ackermann(m-1, 1)
    else if (n == 0)
    {
        return ackermann(m - 1, 1);
    }
    // Recursive case: If m > 0 and n > 0, return ackermann(m-1, ackermann(m, n-1))
    else
    {
        return ackermann(m - 1, ackermann(m, n - 1));
    }
}

int main()
{
    int m, n;

    // Input values for m and n
    cout << "Enter nonnegative integers m and n: ";
    cin >> m >> n;

    // Calculate Ackermann's function
    int result = ackermann(m, n);

    // Output the result
    cout << "Ackermann(" << m << ", " << n << ") = " << result << endl;

    return 0;
}
