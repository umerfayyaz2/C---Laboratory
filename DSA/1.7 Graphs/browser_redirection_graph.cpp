#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>
using namespace std;

// Function to detect a cycle using Depth First Search (DFS)
bool detectCycleDFS(const string &currentURL, unordered_map<string, vector<string>> &redirectionGraph, unordered_set<string> &visited, unordered_set<string> &recursionStack)
{
    visited.insert(currentURL);
    recursionStack.insert(currentURL);

    // Check all redirections from the current URL
    for (const string &redirectedURL : redirectionGraph[currentURL])
    {
        // If the redirected URL is in the recursion stack, a cycle exists
        if (recursionStack.find(redirectedURL) != recursionStack.end())
            return true;

        // If the redirected URL hasn't been visited, continue DFS
        if (visited.find(redirectedURL) == visited.end())
        {
            if (detectCycleDFS(redirectedURL, redirectionGraph, visited, recursionStack))
                return true;
        }
    }

    // Remove the URL from the recursion stack after processing
    recursionStack.erase(currentURL);
    return false;
}

// Function to detect infinite redirection loops in the graph
bool hasInfiniteRedirectionLoop(unordered_map<string, vector<string>> &redirectionGraph)
{
    unordered_set<string> visited;        // Tracks visited nodes
    unordered_set<string> recursionStack; // Tracks the current recursion path

    // Check for cycles starting from each URL
    for (const auto &entry : redirectionGraph)
    {
        const string &startURL = entry.first;
        if (visited.find(startURL) == visited.end())
        {
            if (detectCycleDFS(startURL, redirectionGraph, visited, recursionStack))
                return true;
        }
    }
    return false;
}

// Main function to demonstrate cycle detection
int main()
{
    // Example redirection graph (Adjacency List representation)
    unordered_map<string, vector<string>> redirectionGraph = {
        {"A", {"B"}}, // A redirects to B
        {"B", {"C"}}, // B redirects to C
        {"C", {"A"}}, // C redirects to A (Cycle)
        {"D", {"E"}}, // D redirects to E
        {"E", {}}     // E has no redirections
    };

    // Check for infinite redirection loops
    if (hasInfiniteRedirectionLoop(redirectionGraph))
    {
        cout << "Infinite redirection loop detected!" << endl;
    }
    else
    {
        cout << "No infinite redirection loops found." << endl;
    }

    return 0;
}
