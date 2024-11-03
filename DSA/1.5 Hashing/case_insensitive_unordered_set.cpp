#include <iostream>
#include <unordered_set>
#include <string>
#include <algorithm> // for transform and tolower
using namespace std;

// Function to convert a string to lowercase
string toLower(const string &s)
{
    string lowerStr = s;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

// Custom hash function for case-insensitive hashing
struct CaseInsensitiveHash
{
    size_t operator()(const string &s) const
    {
        hash<string> hf;       // Standard hash function
        return hf(toLower(s)); // Hash of the lowercase version
    }
};

// Custom equality function for case-insensitive comparison
struct CaseInsensitiveEqual
{
    bool operator()(const string &lhs, const string &rhs) const
    {
        return toLower(lhs) == toLower(rhs); // Check equality ignoring case
    }
};

int main()
{
    // Define the unordered_set with case-insensitive behavior
    unordered_set<string, CaseInsensitiveHash, CaseInsensitiveEqual> mySet;

    // Insert values
    mySet.insert("Hello");
    mySet.insert("world");
    mySet.insert("HELLO"); // Won't add because "Hello" is considered the same as "HELLO"

    // Check if "hello" exists
    if (mySet.find("hello") != mySet.end())
    {
        cout << "\"hello\" found in set!" << endl;
    }
    else
    {
        cout << "\"hello\" not found in set!" << endl;
    }

    return 0;
}
