#include <iostream>
using namespace std;

bool is_palindrome(const string &text, int starting_index, int ending_index)
{
    if (starting_index >= ending_index)
    {
        return true;
    }

    if (text[starting_index] != text[ending_index])
    {
        return false;
    }

    return is_palindrome(text, starting_index + 1, ending_index - 1);
}

int main()
{

    string test_case;
    cout << "Please write something to check if it is a palindrome: ";
    cin >> test_case;
    cout << endl;

    bool checker = is_palindrome(test_case, 0, test_case.length() - 1);

    if (checker)
    {
        cout << "The word you entered ' " << test_case << " ' is a palindrome." << endl;
    }

    else
    {

        cout << "The word you entered ' " << test_case << " ' is not a palindrome.";
    }

    return 0;
}