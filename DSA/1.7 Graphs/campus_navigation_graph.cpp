#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// Class to represent the campus graph
class CampusGraph {
private:
    unordered_map<int, vector<int>> adjList; // Adjacency list to represent the graph

public:
    // Add a path (edge) between two buildings (nodes)
    void addPath(int building1, int building2) {
        adjList[building1].push_back(building2);
        adjList[building2].push_back(building1);
    }

    // Perform DFS to visit all connected buildings
    void dfs(int building, unordered_set<int>& visited) {
        visited.insert(building); // Mark the current building as visited
        for (int neighbor : adjList[building]) {
            if (visited.find(neighbor) == visited.end()) {
                dfs(neighbor, visited); // Visit unvisited neighbors recursively
            }
        }
    }

    // Check if all buildings on the campus are connected
    bool areAllBuildingsConnected() {
        if (adjList.empty()) return true; // If there are no buildings, they are trivially connected

        unordered_set<int> visited; // To track visited buildings

        // Start DFS from any building (e.g., the first key in adjList)
        int startBuilding = adjList.begin()->first;
        dfs(startBuilding, visited);

        // Check if all buildings have been visited
        for (const auto& entry : adjList) {
            if (visited.find(entry.first) == visited.end()) {
                return false; // If any building is not visited, they are not all connected
            }
        }
        return true; // All buildings are connected
    }
};

int main() {
    CampusGraph campus;

    // Add paths between buildings
    campus.addPath(1, 2);
    campus.addPath(2, 3);
    campus.addPath(3, 4);
    campus.addPath(4, 5);
    campus.addPath(6, 7); // A disconnected building group

    // Check if all buildings are connected
    if (campus.areAllBuildingsConnected()) {
        cout << "All buildings on the campus are connected." << endl;
    } else {
        cout << "Not all buildings on the campus are connected." << endl;
    }

    return 0;
}
