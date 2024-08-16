#include <iostream>
using namespace std;

int sum_squares(int num)
{
    if (num == 0) // base case
    {
        return 0;
    }

    return num * num + sum_squares(num - 1); // Recursive case : It'll add the square  to the num of squares until num = 0
}

int main()
{

    int num;

    cout << "Please Enter a Non-Neg(-) Number: ";
    cin >> num;
    cout << endl;

    if (num < 0) // Input validation condition
    {
        cout << "Error: The entered digit must be a non negative number." << endl;
    }

    int result = sum_squares(num);

    cout << "The result of sum of squares until " << num << " is: " << result;

    return 0;
}