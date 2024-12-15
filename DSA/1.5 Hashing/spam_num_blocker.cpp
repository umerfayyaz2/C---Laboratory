#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

// Class to represent the spam-blocking system
class SpamBlocker
{
private:
    unordered_set<string> blocked_numbers; // Hash set to store blocked phone numbers

public:
    // Function to block a number
    void block_number(const string &number)
    {
        if (blocked_numbers.find(number) == blocked_numbers.end())
        {
            blocked_numbers.insert(number);
            cout << "Number " << number << " has been blocked." << endl;
        }
        else
        {
            cout << "Number " << number << " is already blocked." << endl;
        }
    }

    // Function to unblock a number
    void unblock_number(const string &number)
    {
        if (blocked_numbers.find(number) != blocked_numbers.end())
        {
            blocked_numbers.erase(number);
            cout << "Number " << number << " has been unblocked." << endl;
        }
        else
        {
            cout << "Number " << number << " is not in the blocked list." << endl;
        }
    }

    // Function to check if a number is blocked
    bool is_blocked(const string &number) const
    {
        return blocked_numbers.find(number) != blocked_numbers.end();
    }

    // Function to display all blocked numbers
    void display_blocked_numbers() const
    {
        if (blocked_numbers.empty())
        {
            cout << "No numbers are currently blocked." << endl;
        }
        else
        {
            cout << "Blocked Numbers:" << endl;
            for (const auto &number : blocked_numbers)
            {
                cout << number << endl;
            }
        }
    }
};

// Main function to demonstrate the SpamBlocker class
int main()
{
    SpamBlocker blocker;

    // Adding some numbers to the blocked list
    blocker.block_number("1234567890");
    blocker.block_number("9876543210");
    blocker.block_number("5555555555");

    // Display blocked numbers
    blocker.display_blocked_numbers();

    // Check if a number is blocked
    string number_to_check = "1234567890";
    if (blocker.is_blocked(number_to_check))
    {
        cout << "Number " << number_to_check << " is blocked." << endl;
    }
    else
    {
        cout << "Number " << number_to_check << " is not blocked." << endl;
    }

    // Unblock a number
    blocker.unblock_number("9876543210");
    blocker.display_blocked_numbers();

    // Attempt to unblock a number not in the list
    blocker.unblock_number("1111111111");

    return 0;
}
