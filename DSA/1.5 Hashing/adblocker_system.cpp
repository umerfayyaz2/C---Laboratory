#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

// AdBlocker class to manage blocked URLs or domains
class AdBlocker
{
private:
    unordered_set<string> blockedURLs; // Set to store blocked URLs/domains

public:
    // Function to add a URL or domain to the blocked list
    void blockURL(const string &url)
    {
        blockedURLs.insert(url);
        cout << "Blocked: " << url << endl;
    }

    // Function to remove a URL or domain from the blocked list
    void unblockURL(const string &url)
    {
        if (blockedURLs.erase(url))
        {
            cout << "Unblocked: " << url << endl;
        }
        else
        {
            cout << "URL not found in blocked list: " << url << endl;
        }
    }

    // Function to check if a URL or domain is blocked
    bool isBlocked(const string &url)
    {
        return blockedURLs.find(url) != blockedURLs.end();
    }

    // Function to display all blocked URLs/domains
    void showBlockedURLs() const
    {
        if (blockedURLs.empty())
        {
            cout << "No URLs are currently blocked." << endl;
        }
        else
        {
            cout << "Blocked URLs/Domains:" << endl;
            for (const auto &url : blockedURLs)
            {
                cout << "- " << url << endl;
            }
        }
    }
};

// Main function to demonstrate the Ad Blocker system
int main()
{
    AdBlocker adBlocker;

    // Adding some URLs/domains to the blocked list
    adBlocker.blockURL("example.com");
    adBlocker.blockURL("ads.example.com");
    adBlocker.blockURL("tracker.net");

    // Displaying all blocked URLs/domains
    adBlocker.showBlockedURLs();

    // Checking if specific URLs are blocked
    string testURL1 = "example.com";
    string testURL2 = "safe-site.org";

    if (adBlocker.isBlocked(testURL1))
    {
        cout << testURL1 << " is blocked." << endl;
    }
    else
    {
        cout << testURL1 << " is not blocked." << endl;
    }

    if (adBlocker.isBlocked(testURL2))
    {
        cout << testURL2 << " is blocked." << endl;
    }
    else
    {
        cout << testURL2 << " is not blocked." << endl;
    }

    // Removing a URL from the blocked list
    adBlocker.unblockURL("ads.example.com");

    // Displaying all blocked URLs/domains after removal
    adBlocker.showBlockedURLs();

    return 0;
}
