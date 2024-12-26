#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <vector>
#include <string>
using namespace std;

// Class to represent the Social Network
class SocialNetwork {
private:
    unordered_map<string, unordered_set<string>> adjList; // Adjacency list for graph representation

public:
    // Add a person to the network
    void addPerson(const string& person) {
        if (adjList.find(person) == adjList.end()) {
            adjList[person] = unordered_set<string>();
            cout << person << " added to the network.\n";
        } else {
            cout << person << " already exists in the network.\n";
        }
    }

    // Add a friendship (undirected edge) between two people
    void addFriendship(const string& person1, const string& person2) {
        if (adjList.find(person1) == adjList.end() || adjList.find(person2) == adjList.end()) {
            cout << "Both people must exist in the network before adding a friendship.\n";
            return;
        }
        adjList[person1].insert(person2);
        adjList[person2].insert(person1);
        cout << "Friendship added between " << person1 << " and " << person2 << ".\n";
    }

    // Find mutual friends between two people
    vector<string> findMutualFriends(const string& person1, const string& person2) {
        vector<string> mutualFriends;
        if (adjList.find(person1) == adjList.end() || adjList.find(person2) == adjList.end()) {
            cout << "Both people must exist in the network to find mutual friends.\n";
            return mutualFriends;
        }
        for (const string& friend1 : adjList[person1]) {
            if (adjList[person2].find(friend1) != adjList[person2].end()) {
                mutualFriends.push_back(friend1);
            }
        }
        return mutualFriends;
    }

    // Suggest friends for a person based on friends-of-friends
    vector<string> suggestFriends(const string& person) {
        vector<string> suggestions;
        if (adjList.find(person) == adjList.end()) {
            cout << person << " does not exist in the network.\n";
            return suggestions;
        }

        unordered_set<string> visited; // To avoid duplicate suggestions
        for (const string& friend1 : adjList[person]) {
            for (const string& friendOfFriend : adjList[friend1]) {
                // Suggest if it's not the person themselves and not already a direct friend
                if (friendOfFriend != person && adjList[person].find(friendOfFriend) == adjList[person].end()) {
                    visited.insert(friendOfFriend);
                }
            }
        }
        suggestions.assign(visited.begin(), visited.end());
        return suggestions;
    }

    // Check if two people are connected (directly or indirectly) using BFS
    bool areConnected(const string& person1, const string& person2) {
        if (adjList.find(person1) == adjList.end() || adjList.find(person2) == adjList.end()) {
            return false;
        }

        unordered_set<string> visited;
        queue<string> q;

        q.push(person1);
        visited.insert(person1);

        while (!q.empty()) {
            string current = q.front();
            q.pop();

            if (current == person2) {
                return true;
            }

            for (const string& neighbor : adjList[current]) {
                if (visited.find(neighbor) == visited.end()) {
                    q.push(neighbor);
                    visited.insert(neighbor);
                }
            }
        }
        return false;
    }

    // Display all people and their connections
    void displayNetwork() const {
        for (const auto& person : adjList) {
            cout << person.first << ": ";
            for (const string& friend1 : person.second) {
                cout << friend1 << " ";
            }
            cout << endl;
        }
    }
};

// Main function to demonstrate the Social Network
int main() {
    SocialNetwork network;

    // Adding people to the network
    network.addPerson("Alice");
    network.addPerson("Bob");
    network.addPerson("Charlie");
    network.addPerson("David");
    network.addPerson("Eve");

    // Adding friendships
    network.addFriendship("Alice", "Bob");
    network.addFriendship("Alice", "Charlie");
    network.addFriendship("Bob", "David");
    network.addFriendship("Charlie", "Eve");

    // Displaying the network
    cout << "\nSocial Network:\n";
    network.displayNetwork();

    // Finding mutual friends
    cout << "\nMutual friends between Alice and Bob:\n";
    vector<string> mutualFriends = network.findMutualFriends("Alice", "Bob");
    for (const string& mutual : mutualFriends) {
        cout << mutual << endl;
    }

    // Suggesting friends
    cout << "\nFriend suggestions for Alice:\n";
    vector<string> suggestions = network.suggestFriends("Alice");
    for (const string& suggestion : suggestions) {
        cout << suggestion << endl;
    }

    // Checking connectivity
    cout << "\nAre Alice and David connected? ";
    cout << (network.areConnected("Alice", "David") ? "Yes" : "No") << endl;

    cout << "\nAre Alice and Eve connected? ";
    cout << (network.areConnected("Alice", "Eve") ? "Yes" : "No") << endl;

    return 0;
}
