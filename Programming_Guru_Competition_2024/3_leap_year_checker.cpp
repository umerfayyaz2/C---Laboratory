#include <iostream>
using namespace std;

bool check_leap_year(int year)
{
    if (year % 400 == 0 || year % 4 == 0)
    {
        return 0;
    }
    if (year % 100 == 0)
    {
        return 1;
    }
}

int main()
{

    int year;
    cout << "Please enter a year (yyyy) to check if leap year : ";
    cin >> year;

    if (check_leap_year(year))
    {
        cout << "\nIssaaa Leap Year";
    }
    else
    {
        cout << "\n Nottaa Leap Year";
    }

    return 0;
}