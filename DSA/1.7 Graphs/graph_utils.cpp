#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Graph
{
private:
    // Adjacency list to represent the graph
    unordered_map<int, vector<int>> adjList;

public:
    // Function to create the graph by adding edges
    void createGraph()
    {
        int numEdges, src, dest;
        cout << "Enter the number of edges: ";
        cin >> numEdges;

        for (int i = 0; i < numEdges; i++)
        {
            cout << "Enter the source and destination of edge " << i + 1 << ": ";
            cin >> src >> dest;
            adjList[src].push_back(dest);
            // If undirected graph, uncomment below line
            // adjList[dest].push_back(src);
        }
    }

    // Function to clear the graph and deallocate memory
    void clearGraph()
    {
        adjList.clear(); // Clear all the data in the adjacency list
        cout << "Graph cleared!" << endl;
    }

    // Function to print the graph
    void printGraph() const
    {
        cout << "Graph adjacency list representation:" << endl;
        for (const auto &pair : adjList)
        {
            cout << pair.first << " -> ";
            for (const auto &vertex : pair.second)
            {
                cout << vertex << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph g;

    // Create graph by adding edges
    g.createGraph();

    // Print the graph
    g.printGraph();

    // Clear the graph
    g.clearGraph();

    return 0;
}
