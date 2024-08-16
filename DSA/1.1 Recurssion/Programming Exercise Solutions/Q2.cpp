#include <iostream>
using namespace std;

// Function to print stars in a line
void printStars(int numStars)
{
    for (int i = 0; i < numStars; i++)
    {
        cout << "* ";
    }
    cout << endl;
}

// Recursive function to print the pattern
void pattern(int n, int curr, bool isTop)
{
    if (curr == 0)
        return;

    // Print stars for the current line
    printStars(curr);

    if (isTop)
    {
        // Recursive call for top half
        if (curr < n)
            pattern(n, curr + 1, true);
        else
            pattern(n - 1, curr - 1, false); // Start the bottom half
    }
    else
    {
        // Recursive call for bottom half
        pattern(n, curr - 1, false);
    }
}

int main()
{
    int n;

    cout << "Enter the number of lines: ";
    cin >> n;

    // Start pattern with the first line
    pattern(n, 1, true);

    return 0;
}
