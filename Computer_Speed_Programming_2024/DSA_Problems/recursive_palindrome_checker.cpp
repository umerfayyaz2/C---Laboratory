#include <iostream>
using namespace std;

bool is_palindrome(const string &text, int start_index, int end_index)
{
    if (start_index >= end_index)
    {
        return true;
    }

    if (start_index != end_index)
    {
        return false;
    }

    return is_palindrome(text, start_index + 1, end_index - 1);
}

int main()
{

    string test_case;
    cout << "Please write something to check if it is a palindrome: ";
    cin >> test_case;
    cout << endl;

    bool checker = is_palindrome(test_case, 0, test_case.length() - 1);

    if (checker) // if checker is true
    {
        cout << "The word you entered ' " << test_case << " ' is a palindrome." << endl;
    }
    else
    {
        cout << "The word you entered ' " << test_case << " ' is not a palindrome." << endl;
    }

    return 0;
}