#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

// TrieNode class represents each node in the Trie
class TrieNode
{
public:
    unordered_map<char, TrieNode *> children; // Maps characters to child nodes
    vector<string> phone_numbers;             // Stores phone numbers ending at or passing through this node

    TrieNode() = default;
};

// Trie class for managing the predictive typing feature
class PhoneTrie
{
private:
    TrieNode *root; // Root node of the Trie

public:
    PhoneTrie() { root = new TrieNode(); }

    // Insert a phone number into the Trie
    void insert(const string &phone_number)
    {
        TrieNode *current = root;
        for (char digit : phone_number)
        {
            if (current->children.find(digit) == current->children.end())
            {
                current->children[digit] = new TrieNode();
            }
            current = current->children[digit];
            current->phone_numbers.push_back(phone_number); // Add number to the node's list
        }
    }

    // Search for suggestions based on a prefix
    vector<string> search(const string &prefix)
    {
        TrieNode *current = root;
        for (char digit : prefix)
        {
            if (current->children.find(digit) == current->children.end())
            {
                return {}; // Prefix not found
            }
            current = current->children[digit];
        }
        return current->phone_numbers; // Return all numbers matching the prefix
    }
};

int main()
{
    PhoneTrie phone_trie;

    // Insert phone numbers into the Trie
    phone_trie.insert("1234567890");
    phone_trie.insert("1234560000");
    phone_trie.insert("9876543210");
    phone_trie.insert("1231231234");
    phone_trie.insert("1230004567");

    string input_prefix;
    cout << "Enter a prefix to search for phone numbers: ";
    cin >> input_prefix;

    // Fetch and display suggestions
    vector<string> suggestions = phone_trie.search(input_prefix);
    if (!suggestions.empty())
    {
        cout << "Suggestions for prefix '" << input_prefix << "':\n";
        for (const string &number : suggestions)
        {
            cout << number << endl;
        }
    }
    else
    {
        cout << "No suggestions found for prefix '" << input_prefix << "'." << endl;
    }

    return 0;
}
