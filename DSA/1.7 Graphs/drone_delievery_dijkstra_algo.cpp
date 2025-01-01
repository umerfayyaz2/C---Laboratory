#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <climits>
#include <string>
using namespace std;

// A class to represent the graph
class Graph
{
private:
    // Adjacency list: node -> (neighbor, weight)
    unordered_map<string, vector<pair<string, int>>> adjList;

public:
    // Add an edge between two points with a weight (distance or cost)
    void addEdge(const string &from, const string &to, int weight)
    {
        adjList[from].push_back({to, weight});
        adjList[to].push_back({from, weight}); // Bidirectional path
    }

    // Find the most efficient path using Dijkstra's Algorithm
    pair<int, vector<string>> findOptimalPath(const string &start, const string &destination)
    {
        if (adjList.find(start) == adjList.end() || adjList.find(destination) == adjList.end())
        {
            cout << "One or both points are not in the graph!" << endl;
            return {INT_MAX, {}};
        }

        // Priority queue for Dijkstra's Algorithm: (current_distance, node)
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;

        // Distance map to store the shortest distance to each node
        unordered_map<string, int> distance;

        // Parent map to reconstruct the path
        unordered_map<string, string> parent;

        // Initialize distances to infinity
        for (const auto &node : adjList)
        {
            distance[node.first] = INT_MAX;
        }
        distance[start] = 0; // Distance to the start node is 0

        pq.push({0, start});
        parent[start] = ""; // Start node has no parent

        while (!pq.empty())
        {
            auto [currentDist, currentNode] = pq.top();
            pq.pop();

            // If we reach the destination, no need to process further
            if (currentNode == destination)
            {
                break;
            }

            // Process all neighbors of the current node
            for (const auto &[neighbor, weight] : adjList[currentNode])
            {
                int newDist = currentDist + weight;
                if (newDist < distance[neighbor])
                {
                    distance[neighbor] = newDist;
                    parent[neighbor] = currentNode;
                    pq.push({newDist, neighbor});
                }
            }
        }

        // If the destination is unreachable, return infinity and an empty path
        if (distance[destination] == INT_MAX)
        {
            return {INT_MAX, {}};
        }

        // Reconstruct the path
        vector<string> path;
        for (string node = destination; !node.empty(); node = parent[node])
        {
            path.push_back(node);
        }
        reverse(path.begin(), path.end());

        return {distance[destination], path};
    }
};

int main()
{
    Graph graph;

    // Add edges to the graph (point1, point2, distance or cost)
    graph.addEdge("Warehouse", "Location1", 50);
    graph.addEdge("Warehouse", "Location2", 100);
    graph.addEdge("Location1", "Location3", 30);
    graph.addEdge("Location2", "Location3", 60);
    graph.addEdge("Location3", "Destination", 70);
    graph.addEdge("Location2", "Destination", 120);

    // Input start and destination points
    string start = "Warehouse";
    string destination = "Destination";

    // Find the most efficient path
    auto [cost, path] = graph.findOptimalPath(start, destination);

    if (cost != INT_MAX)
    {
        cout << "Optimal path from " << start << " to " << destination << ": ";
        for (const string &point : path)
        {
            cout << point << " ";
        }
        cout << "\nTotal cost: " << cost << endl;
    }
    else
    {
        cout << "No path exists between " << start << " and " << destination << "." << endl;
    }

    return 0;
}
