#include <iostream>
#include <stack>
#include <string>

using namespace std;

class TabManager
{
private:
    stack<string> tabStack; // Stack to manage browser tabs

public:
    // Function to open a new tab
    void openTab(const string &tabName)
    {
        tabStack.push(tabName);
        cout << "Opened tab: " << tabName << endl;
    }

    // Function to close the last opened tab
    void closeTab()
    {
        if (!tabStack.empty())
        {
            cout << "Closed tab: " << tabStack.top() << endl;
            tabStack.pop();
        }
        else
        {
            cout << "No tabs to close!" << endl;
        }
    }

    // Function to display the currently opened tabs
    void showTabs()
    {
        if (tabStack.empty())
        {
            cout << "No tabs open!" << endl;
            return;
        }

        cout << "Currently opened tabs (last opened first):" << endl;
        stack<string> tempStack = tabStack; // Temporary stack to display tabs
        while (!tempStack.empty())
        {
            cout << tempStack.top() << endl;
            tempStack.pop();
        }
    }
};

int main()
{
    TabManager browser;

    // Example usage
    browser.openTab("Co-pilot");
    browser.openTab("ChatGPT");
    browser.openTab("Claude");

    browser.showTabs();

    browser.closeTab();
    browser.showTabs();

    browser.closeTab();
    browser.closeTab();
    browser.closeTab();

    return 0;
}
