#include <iostream>
using namespace std;

int factorial_num(int num)
{
    if (num == 0)
    {
        return 1;
    }
    else
    {
        return num * factorial_num(num - 1);
    }
}

int main()
{
    int n;
    cout << "Enter a number to find its factorial: ";
    cin >> n;

    if (n < 0)
    {
        cout << "\nFactorial of neg num is not possible";
    }
    else
    {
        int result = factorial_num(n);
        cout << "\nFactorial of " << n << " is: " << result;
    }

    return 0;
}