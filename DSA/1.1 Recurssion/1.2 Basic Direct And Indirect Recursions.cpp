#include <iostream>
using namespace std;

// 1-Direct Recursion - The most simplest and direct form of recursion

int factorial(int n)
{
    if (n == 0 || n == 1)
        return 1; // <=== Base Case
    else
        return n * factorial(n - 1); // <=== Recursive case where the fuction is calling it self directly in it's body
}

// 2- In-Direct Recursion - (Invloves Chaining)

/*
<-------Algorithm------->

- FUNC A calls FUNC B
- FUNC B calls FUNC C
- FUNC C calls FUNC D
- Finally FUNC D calls FUNC A
*/

void FUNC_A()
{
    cout << "FUNC A is working \n";
    FUNC_B();
}

void FUNC_B()
{
    cout << "FUNC B is working \n";
    FUNC_C();
}

void FUNC_C()
{
    cout << "FUNC C is working \n";
    FUNC_D();
}

void FUNC_D()
{
    cout << "FUNC D is working & It's calling FUNC A as a recursive case. \n";
    FUNC_A(); // <=== Recursive Case
}

/*
- There’s no need to explicitly set a base case.
- Unlike direct recursion, where a base case is essential to terminate the recursion,
- indirect recursion relies on the cyclic nature of function calls.
*/
