#include <iostream>
using namespace std;

int factorial(int num)
{
    if (num == 0 || num == 1)
        return 1; // Base Case
    else
        return num * factorial(num - 1); // General Case
}

/*
Let’s say we call factorial(5):

- num is 5.
- Since 5 is greater than 1, we skip the base case.
- We calculate 5 * factorial(4).
- Now we need to find factorial(4).

- Repeat the process until we reach the base case:
  - factorial(4) = 4 * factorial(3)
  - factorial(3) = 3 * factorial(2)
  - factorial(2) = 2 * factorial(1)
  - factorial(1) = 1 (base case)

- Backtracking:
  - factorial(2) = 2 * 1 = 2
  - factorial(3) = 3 * 2 = 6
  - factorial(4) = 4 * 6 = 24
- Finally, factorial(5) = 5 * 24 = 120 Answer
*/

int main()
{

    int n = 5;

    cout << "Factorial of " << n << " is = " << factorial(n) << endl; // answer = 120

    return 0;
}