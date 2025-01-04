#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
using namespace std;

// Url graph
class URLGraph
{
private:
    unordered_map<string, vector<string>> adjList; // Adjacency list for redirections
    unordered_map<string, bool> visited;           // Track visited nodes
    unordered_map<string, bool> recursionStack;    // Track nodes in the current recursion stack

    // Helper function: DFS to detect cycles
    bool isCyclicUtil(const string &url)
    {
        // Mark the current URL as visited and part of the recursion stack
        visited[url] = true;
        recursionStack[url] = true;

        // Visit all neighbors (redirections) of the current URL
        for (const string &neighbor : adjList[url])
        {
            // If the neighbor is in the recursion stack, a cycle is detected
            if (!visited[neighbor] && isCyclicUtil(neighbor))
            {
                return true;
            }
            else if (recursionStack[neighbor])
            {
                return true;
            }
        }

        // Remove the current URL from the recursion stack
        recursionStack[url] = false;
        return false;
    }

public:
    // Add a redirection from one URL to another
    void addRedirection(const string &from, const string &to)
    {
        adjList[from].push_back(to);
    }

    // Function to detect cycles in the graph
    bool detectCycle()
    {
        // Initialize visited and recursionStack maps
        for (const auto &entry : adjList)
        {
            visited[entry.first] = false;
            recursionStack[entry.first] = false;
        }

        // Check for cycles starting from each URL
        for (const auto &entry : adjList)
        {
            if (!visited[entry.first] && isCyclicUtil(entry.first))
            {
                return true;
            }
        }

        return false;
    }
};

int main()
{
    // Create a URL graph
    URLGraph urlGraph;

    // Add URL redirections (edges)
    urlGraph.addRedirection("A", "B");
    urlGraph.addRedirection("B", "C");
    urlGraph.addRedirection("C", "D");
    urlGraph.addRedirection("D", "B"); // This creates a cycle: B -> C -> D -> B

    // Detect cycles in the graph
    if (urlGraph.detectCycle())
    {
        cout << "Cycle detected in URL redirections! Infinite redirection loop found." << endl;
    }
    else
    {
        cout << "No cycles detected. URL redirections are safe." << endl;
    }

    return 0;
}
