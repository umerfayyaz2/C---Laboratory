#include <iostream>
using namespace std;

void print_star_pattern(int number_of_stars)
{
    if (number_of_stars > 0) // base case
    {
        // Print the stars in descending order
        for (int index = 0; index < number_of_stars; index++)
        {
            cout << '*';
        }
        cout << endl;

        // Recursive call to handle the next line
        print_star_pattern(number_of_stars - 1);

        // Print the stars in ascending order
        for (int index = 0; index < number_of_stars; index++)
        {
            cout << '*';
        }
        cout << endl;
    }
}

int main()
{
    int stars;
    cout << "Enter number of pattern lines for the stars to be printed on: ";
    cin >> stars;
    cout << endl;

    // Call the function to print the star pattern
    print_star_pattern(stars);

    cout << "Pattern printed successfully!" << endl;

    return 0;
}
