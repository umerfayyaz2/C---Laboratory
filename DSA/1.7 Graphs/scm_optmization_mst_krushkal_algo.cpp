#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <climits>
#include <string>
using namespace std;

// Edge structure to store connections and their costs
struct Edge
{
    int to;     // Destination node
    int weight; // Cost of transportation
};

// Graph class to represent locations and their connections
class Graph
{
private:
    unordered_map<int, vector<Edge>> adjList; // Adjacency list
    int totalNodes;                           // Total number of locations

public:
    Graph(int nodes) : totalNodes(nodes) {}

    // Add a transportation route between two locations
    void addEdge(int from, int to, int weight)
    {
        adjList[from].push_back({to, weight});
        adjList[to].push_back({from, weight}); // Bidirectional edge
    }

    // Prim's Algorithm to find the Minimum Spanning Tree
    int primMST()
    {
        // Priority queue for selecting the minimum weight edge at each step
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<bool> visited(totalNodes, false); // Track visited nodes
        int totalCost = 0;                       // Total cost of the MST

        // Start from the first node (node 0)
        pq.push({0, 0}); // (weight, node)

        while (!pq.empty())
        {
            auto [weight, node] = pq.top();
            pq.pop();

            // If the node has already been visited, skip it
            if (visited[node])
                continue;

            // Mark the node as visited and add the weight to the total cost
            visited[node] = true;
            totalCost += weight;

            // Add all unvisited neighbors of the current node to the priority queue
            for (const auto &edge : adjList[node])
            {
                if (!visited[edge.to])
                {
                    pq.push({edge.weight, edge.to});
                }
            }
        }

        // Check if all nodes were visited (connected graph)
        for (bool nodeVisited : visited)
        {
            if (!nodeVisited)
            {
                cout << "The graph is not fully connected. Some locations are unreachable." << endl;
                return -1;
            }
        }

        return totalCost;
    }
};

int main()
{
    // Number of locations (nodes)
    int totalLocations = 6;

    // Create a graph with the given number of locations
    Graph graph(totalLocations);

    // Add transportation routes with costs
    graph.addEdge(0, 1, 4); // Warehouse -> Factory1 (Cost: 4)
    graph.addEdge(0, 2, 3); // Warehouse -> Factory2 (Cost: 3)
    graph.addEdge(1, 2, 1); // Factory1 -> Factory2 (Cost: 1)
    graph.addEdge(1, 3, 2); // Factory1 -> Retailer1 (Cost: 2)
    graph.addEdge(2, 3, 4); // Factory2 -> Retailer1 (Cost: 4)
    graph.addEdge(3, 4, 2); // Retailer1 -> Retailer2 (Cost: 2)
    graph.addEdge(4, 5, 6); // Retailer2 -> Retailer3 (Cost: 6)

    // Calculate the minimum transportation cost
    int totalCost = graph.primMST();

    if (totalCost != -1)
    {
        cout << "Minimum transportation cost to optimize the supply chain: " << totalCost << endl;
    }
    else
    {
        cout << "Supply chain cannot be optimized due to disconnected locations." << endl;
    }

    return 0;
}
