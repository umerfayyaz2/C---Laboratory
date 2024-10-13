#include <iostream>
#include <queue>
#include <stack>
#include <cctype> // for isalpha and tolower

using namespace std;

// Function to check if the input string is a palindrome
bool isPalindrome(const string &input)
{
    queue<char> letterQueue;
    stack<char> letterStack;

    // Process the input string: ignore non-alphabetic characters and convert to lowercase
    for (char ch : input)
    {
        if (isalpha(ch))
        {                               // Consider only alphabetic characters
            char lowerCh = tolower(ch); // Convert to lowercase
            letterQueue.push(lowerCh);
            letterStack.push(lowerCh);
        }
    }

    // Compare the queue and the stack
    while (!letterQueue.empty())
    {
        char queueFront = letterQueue.front();
        char stackTop = letterStack.top();

        // If any mismatch is found, it is not a palindrome
        if (queueFront != stackTop)
        {
            return false;
        }

        // Move to the next elements
        letterQueue.pop();
        letterStack.pop();
    }

    // If no mismatches were found, it is a palindrome
    return true;
}

int main()
{
    string inputText;

    // Read a line of text from the user
    cout << "Enter a line of text: ";
    getline(cin, inputText);

    // Check if the input text is a palindrome
    if (isPalindrome(inputText))
    {
        cout << "The entered text is a palindrome." << endl;
    }
    else
    {
        cout << "The entered text is not a palindrome." << endl;
    }

    return 0;
}
