#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

const int TABLE_SIZE = 17;  // Size of the hash table
const int HOP_DISTANCE = 4; // Neighborhood size for hopscotch hashing

// Struct to store keyword information with popularity
struct KeywordInfo
{
    string keyword;
    int popularity;
    bool occupied; // Indicates if this slot is occupied

    KeywordInfo() : keyword(""), popularity(0), occupied(false) {}
};

// Hopscotch Hash Table Class for keyword lookup
class KeywordLookup
{
private:
    vector<KeywordInfo> table;

    // Hash function for a keyword
    int hash(const string &keyword)
    {
        int hash_value = 0;
        for (char ch : keyword)
        {
            hash_value = (hash_value * 31 + ch) % TABLE_SIZE;
        }
        return hash_value;
    }

public:
    KeywordLookup() : table(TABLE_SIZE) {}

    // Add keyword with popularity score
    bool addKeyword(const string &keyword, int popularity)
    {
        int index = hash(keyword);
        int start_index = index;

        for (int i = 0; i < TABLE_SIZE; i++)
        {
            if (!table[index].occupied)
            {
                table[index] = {keyword, popularity, true};
                return true;
            }

            int current_dist = abs(index - start_index);
            if (current_dist < HOP_DISTANCE)
            {
                index = (index + 1) % TABLE_SIZE; // Linear probing for hopscotch hashing
            }
            else
            {
                cerr << "Error: Unable to add keyword due to displacement limit. Rehashing may be needed." << endl;
                return false;
            }
        }
        return false;
    }

    // Retrieve keywords starting with a given prefix for autocomplete suggestions
    vector<string> getAutocompleteSuggestions(const string &prefix)
    {
        vector<string> suggestions;

        for (const auto &entry : table)
        {
            if (entry.occupied && entry.keyword.find(prefix) == 0)
            { // Check if prefix matches
                suggestions.push_back(entry.keyword);
            }
        }

        // Sort suggestions by popularity (descending) for better user experience
        sort(suggestions.begin(), suggestions.end(), [&](const string &a, const string &b)
             {
            int popA = 0, popB = 0;
            for (const auto& entry : table) {
                if (entry.keyword == a) popA = entry.popularity;
                if (entry.keyword == b) popB = entry.popularity;
            }
            return popA > popB; });

        return suggestions;
    }

    // Update keyword popularity score if it exists
    bool updateKeywordPopularity(const string &keyword, int new_popularity)
    {
        int index = hash(keyword);

        for (int i = 0; i < HOP_DISTANCE; i++)
        {
            int current_index = (index + i) % TABLE_SIZE;
            if (table[current_index].occupied && table[current_index].keyword == keyword)
            {
                table[current_index].popularity = new_popularity;
                return true;
            }
        }
        cerr << "Error: Keyword not found for update." << endl;
        return false;
    }
};

int main()
{
    KeywordLookup keywordLookup;

    // Adding keywords with popularity
    keywordLookup.addKeyword("laptop", 90);
    keywordLookup.addKeyword("lamp", 50);
    keywordLookup.addKeyword("laptop stand", 70);
    keywordLookup.addKeyword("latte", 30);
    keywordLookup.addKeyword("laser printer", 65);

    // Autocomplete suggestions for prefix "la"
    auto suggestions = keywordLookup.getAutocompleteSuggestions("la");
    cout << "Autocomplete suggestions for 'la': ";
    for (const auto &suggestion : suggestions)
    {
        cout << suggestion << ", ";
    }
    cout << endl;

    // Update popularity of a keyword
    keywordLookup.updateKeywordPopularity("laptop", 95);

    // Verify updated popularity by getting suggestions again
    suggestions = keywordLookup.getAutocompleteSuggestions("la");
    cout << "Updated autocomplete suggestions for 'la': ";
    for (const auto &suggestion : suggestions)
    {
        cout << suggestion << ", ";
    }
    cout << endl;

    return 0;
}
