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
    // Adjacency list: city -> (neighbor, weight)
    unordered_map<string, vector<pair<string, int> > > adjList;

public:
    // Add a connection between two cities with a travel cost or time
    void addEdge(const string &city1, const string &city2, int weight)
    {
        adjList[city1].push_back({city2, weight});
        adjList[city2].push_back({city1, weight}); // Bidirectional edge
    }

    // Find the fastest or cheapest path using Dijkstra's Algorithm
    pair<int, vector<string> > findShortestPath(const string &start, const string &end)
    {
        if (adjList.find(start) == adjList.end() || adjList.find(end) == adjList.end())
        {
            cout << "One or both of the cities are not in the graph!" << endl;
            return {INT_MAX, {}};
        }

        // Priority queue for Dijkstra's Algorithm: (current_distance, city_name)
        priority_queue<pair<int, string>, vector<pair<int, string> >, greater<pair<int, string> > > pq;

        // Distance map to store the shortest distance to each city
        unordered_map<string, int> distance;

        // Parent map to reconstruct the shortest path
        unordered_map<string, string> parent;

        // Initialize distances to infinity
        for (const auto &city : adjList)
        {
            distance[city.first] = INT_MAX;
        }
        distance[start] = 0; // Distance to the start city is 0

        pq.push({0, start});
        parent[start] = ""; // Start city has no parent

        while (!pq.empty())
        {
            auto [currentDist, currentCity] = pq.top();
            pq.pop();

            // If we reach the destination, no need to process further
            if (currentCity == end)
            {
                break;
            }

            // Process all neighbors of the current city
            for (const auto &[neighbor, weight] : adjList[currentCity])
            {
                int newDist = currentDist + weight;
                if (newDist < distance[neighbor])
                {
                    distance[neighbor] = newDist;
                    parent[neighbor] = currentCity;
                    pq.push({newDist, neighbor});
                }
            }
        }

        // If the end city is unreachable, return infinity and an empty path
        if (distance[end] == INT_MAX)
        {
            return {INT_MAX, {}};
        }

        // Reconstruct the shortest path
        vector<string> path;
        for (string city = end; !city.empty(); city = parent[city])
        {
            path.push_back(city);
        }
        reverse(path.begin(), path.end());

        return {distance[end], path};
    }
};

int main()
{
    Graph graph;

    // Add edges to the graph (city1, city2, travel cost or time)
    graph.addEdge("A", "B", 100);
    graph.addEdge("A", "C", 200);
    graph.addEdge("B", "D", 150);
    graph.addEdge("C", "D", 50);
    graph.addEdge("B", "E", 300);
    graph.addEdge("D", "E", 100);
    graph.addEdge("D", "F", 200);
    graph.addEdge("E", "F", 150);

    // Input start and end cities
    string start = "A";
    string end = "F";

    // Find the fastest or cheapest path
    auto [cost, path] = graph.findShortestPath(start, end);

    if (cost != INT_MAX)
    {
        cout << "Cheapest path from " << start << " to " << end << ": ";
        for (const string &city : path)
        {
            cout << city << " ";
        }
        cout << "\nTotal cost: " << cost << endl;
    }
    else
    {
        cout << "No path exists between " << start << " and " << end << "." << endl;
    }

    return 0;
}
