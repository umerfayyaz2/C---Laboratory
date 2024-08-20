#include <iostream>
using namespace std;

void print_stars(int count) // Helper Function to print stars in recursively
{
    if (count == 0)
    {
        return;
    }

    cout << "*";
    print_stars(count - 1); // this recursive call will print 1 star each time the function is called on one line only.
}

void print_star_pattern(int number_of_stars) // this function will handle the overall stars pattern in both decending and ascending order
{
    if (number_of_stars == 0)
    {
        return; // base case where the stack starts to un-wind and starts backtracking
    }

    print_stars(number_of_stars); // this will print stars in descending order
    cout << endl;

    print_star_pattern(number_of_stars - 1); // this will print the next line with -1 stars

    print_stars(number_of_stars); // this will print stars in ascending order
    cout << endl;
}

int main()
{
    int stars;
    cout << "Enter the number of lines you want the stars to be printed on: ";
    cin >> stars;
    cout << endl;

    print_star_pattern(stars);

    cout << "Pattern printed successfully! :)";

    return 0;
}