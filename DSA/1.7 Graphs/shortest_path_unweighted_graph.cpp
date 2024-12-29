#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <string>
#include <climits>
using namespace std;

// Class to represent the graph
class Graph
{
private:
    unordered_map<string, vector<string>> adjList; // Adjacency list to represent the graph

public:
    // Add an edge between two nodes (bidirectional)
    void addEdge(const string &node1, const string &node2)
    {
        adjList[node1].push_back(node2);
        adjList[node2].push_back(node1);
    }

    // Find the shortest path between two nodes using BFS
    vector<string> findShortestPath(const string &start, const string &end)
    {
        if (adjList.find(start) == adjList.end() || adjList.find(end) == adjList.end())
        {
            cout << "One or both of the nodes are not in the graph!" << endl;
            return {};
        }

        unordered_map<string, string> parent; // To store the parent of each node in the path
        unordered_map<string, bool> visited;  // To mark visited nodes
        queue<string> q;                      // Queue for BFS

        q.push(start);
        visited[start] = true;
        parent[start] = ""; // Start node has no parent

        while (!q.empty())
        {
            string current = q.front();
            q.pop();
            // If we reach the destination, reconstruct the path
            if (current == end)
            {
                vector<string> path;
                for (string node = end; !node.empty(); node = parent[node])
                {
                    path.push_back(node);
                }
                reverse(path.begin(), path.end());
                return path;
            }

            // Visit all neighbors
            for (const string &neighbor : adjList[current])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    parent[neighbor] = current; // Set parent of neighbor
                    q.push(neighbor);
                }
            }
        }

        return {}; // Return empty vector if no path is found
    }
};

int main()
{
    Graph graph;

    // Add edges to the graph
    graph.addEdge("A", "B");
    graph.addEdge("A", "C");
    graph.addEdge("B", "D");
    graph.addEdge("C", "E");
    graph.addEdge("D", "F");
    graph.addEdge("E", "F");
    graph.addEdge("F", "G");

    // Input start and end points
    string start = "A";
    string end = "G";

    // Find the shortest path
    vector<string> path = graph.findShortestPath(start, end);

    if (!path.empty())
    {
        cout << "Shortest path from " << start << " to " << end << ": ";
        for (const string &node : path)
        {
            cout << node << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "No path exists between " << start << " and " << end << "." << endl;
    }

    return 0;
}
