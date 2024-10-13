#include <iostream>
using namespace std;

void print_stars(int num_of_lines, int num_of_stars)
{
    if (num_of_stars == 0)
    {
        return;
    }

    for (int i = 0; i < num_of_stars; i++)
    {
        cout << "*";
    }
    cout << endl;

    print_stars(num_of_lines, num_of_stars - 1);

    for (int i = 0; i < num_of_stars; i++)
    {
        cout << "*";
    }
    cout << endl;
}
