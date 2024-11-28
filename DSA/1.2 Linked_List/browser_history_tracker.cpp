#include <iostream>
#include <string>

using namespace std;

// Node structure representing each webpage in history
struct HistoryNode
{
    string url;
    HistoryNode *prev;
    HistoryNode *next;

    // Constructor to initialize the node
    HistoryNode(const string &page) : url(page), prev(nullptr), next(nullptr) {}
};

// Class to manage the browser history
class BrowserHistory
{
private:
    HistoryNode *current; // Pointer to the current webpage

public:
    // Constructor to initialize an empty browser history
    BrowserHistory() : current(nullptr) {}

    // Function to visit a new webpage
    void visitPage(const string &url)
    {
        HistoryNode *newNode = new HistoryNode(url);

        // If there is a current page, update links to remove forward history
        if (current)
        {
            current->next = newNode;
            newNode->prev = current;
        }
        current = newNode;

        cout << "Visited: " << url << endl;
    }

    // Function to go back to the previous page
    void goBack()
    {
        if (current && current->prev)
        {
            current = current->prev;
            cout << "Back to: " << current->url << endl;
        }
        else
        {
            cout << "No previous page!" << endl;
        }
    }

    // Function to go forward to the next page
    void goForward()
    {
        if (current && current->next)
        {
            current = current->next;
            cout << "Forward to: " << current->url << endl;
        }
        else
        {
            cout << "No next page!" << endl;
        }
    }

    // Function to display the current page
    void showCurrentPage() const
    {
        if (current)
        {
            cout << "Current page: " << current->url << endl;
        }
        else
        {
            cout << "No page is currently open!" << endl;
        }
    }

    // Destructor to clean up memory
    ~BrowserHistory()
    {
        while (current && current->prev)
        {
            current = current->prev; // Move to the beginning
        }

        while (current)
        {
            HistoryNode *temp = current;
            current = current->next;
            delete temp;
        }
    }
};

int main()
{
    BrowserHistory browser;

    browser.visitPage("google.com");
    browser.visitPage("github.com");
    browser.visitPage("stackoverflow.com");

    browser.showCurrentPage(); // stackoverflow.com

    browser.goBack();          // github.com
    browser.showCurrentPage(); // github.com

    browser.goBack();          // google.com
    browser.showCurrentPage(); // google.com

    browser.goForward();       // github.com
    browser.showCurrentPage(); // github.com

    browser.visitPage("linkedin.com"); // Clears forward history
    browser.showCurrentPage();         // linkedin.com

    browser.goForward(); // No next page!
    return 0;
}
