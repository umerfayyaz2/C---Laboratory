#include <iostream>
using namespace std;

int cal_sum_of_digits(int num)
{
    int sum = 0;

    while (num > 0)
    {
        sum += num % 10; // this will add last digit into sum
        num /= 10;       // thi will remove last digit from num
    }

    return sum;
}

int main()
{

    int number;

    cout << "Please enter numbers  to calculate their sum: ";
    cin >> number;

    cout << "\nThe Sum of Digits : " << cal_sum_of_digits(number);

    return 0;
}