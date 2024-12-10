#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Class to represent household utility bills
class UtilityBills
{
private:
    vector<float> bills; // Vector to store the utility bill amounts

public:
    // Function to add a bill amount
    void add_bill(float amount)
    {
        bills.push_back(amount);
    }

    // Function to sort the bills using Bubble Sort
    void sort_bills()
    {
        for (int i = 0; i < bills.size() - 1; i++)
        {
            for (int j = 0; j < bills.size() - 1 - i; j++)
            {
                if (bills[j] > bills[j + 1])
                {
                    float temp = bills[j];
                    bills[j] = bills[j + 1];
                    bills[j + 1] = temp;
                }
            }
        }
    }

    // Function to display all bills
    void display_bills() const
    {
        cout << "Utility Bills: ";
        for (float bill : bills)
        {
            cout << bill << " ";
        }
        cout << endl;
    }
};

int main()
{
    UtilityBills my_bills;

    // Adding some bill amounts
    my_bills.add_bill(75.50);
    my_bills.add_bill(120.00);
    my_bills.add_bill(50.75);
    my_bills.add_bill(200.00);
    my_bills.add_bill(85.25);

    cout << "Before Sorting:" << endl;
    my_bills.display_bills();

    // Sorting bills
    my_bills.sort_bills();

    cout << "After Sorting:" << endl;
    my_bills.display_bills();

    return 0;
}
