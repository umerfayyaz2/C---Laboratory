#include <iostream>
using namespace std;

/*
Function Name and Parameters:
- The function is named tailFactorial.
- It takes two parameters: n (an integer representing the input for which factorial needs to be calculated) and accumulator (an optional parameter initialized to 1).

Base Case:
- The base case is when n equals 0.
- In this case, the function returns the value of the accumulator.

Recursive Case:
- If n is not 0, the function recursively calls itself with updated values:
  - n - 1 as the new value for n.
  - n * accumulator as the new value for the accumulator.
- This recursive call accumulates the product of all positive integers from n down to 1.

Tail Recursion:
- The recursive call is the last operation performed within the function.
- This makes it a tail-recursive function.
- Tail recursion can be optimized by the compiler, as it doesn’t require additional stack space for each recursive call.
*/

int tailRecursion(int n, int accumulator)
{
    if (n == 0)
        return accumulator;
    else
        return tailRecursion(n - 1, n * accumulator);
}

/*
Dry run of tailFactorial(3) to see how it works:

- Initial Call:
  - Function Call: tailFactorial(3)
  - Parameters: n = 3, accumulator = 1
  - Since n is not 0, it proceeds to the else branch.
  - Recursive Call: tailFactorial(2, 3 * 1) → which simplifies to tailFactorial(2, 3)

- Second Call:
  - Function Call: tailFactorial(2)
  - Parameters: n = 2, accumulator = 3
  - Since n is not 0, it proceeds to the else branch.
  - Recursive Call: tailFactorial(1, 2 * 3) → which simplifies to tailFactorial(1, 6)

- Third Call:
  - Function Call: tailFactorial(1)
  - Parameters: n = 1, accumulator = 6
  - Since n is not 0, it proceeds to the else branch.
  - Recursive Call: tailFactorial(0, 1 * 6) → which simplifies to tailFactorial(0, 6)

- Base Case Reached:
  - Function Call: tailFactorial(0)
  - Parameters: n = 0, accumulator = 6
  - Since n == 0, the function returns the value of the accumulator, which is 6.
*/
