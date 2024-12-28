#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
using namespace std;

// Class to represent the family tree graph
class FamilyTree
{
private:
    unordered_map<string, vector<string> > adjList; // Adjacency list to represent the family tree

public:
    // Add a relationship between two family members
    void addRelationship(const string &person1, const string &person2)
    {
        adjList[person1].push_back(person2);
        adjList[person2].push_back(person1);
    }

    // Perform DFS to determine if two people are directly or indirectly related
    bool dfs(const string &current, const string &target, unordered_set<string> &visited)
    {
        if (current == target)
        {
            return true; // Found the target person
        }

        visited.insert(current); // Mark the current person as visited

        for (const string &neighbor : adjList[current])
        {
            if (visited.find(neighbor) == visited.end())
            { // If neighbor is not visited
                if (dfs(neighbor, target, visited))
                {
                    return true; // Found the target person in the subtree
                }
            }
        }

        return false; // Target person not found
    }

    // Check if two people are directly or indirectly related
    bool areRelated(const string &person1, const string &person2)
    {
        if (adjList.find(person1) == adjList.end() || adjList.find(person2) == adjList.end())
        {
            return false; // Either person is not in the family tree
        }

        unordered_set<string> visited;         // To keep track of visited family members
        return dfs(person1, person2, visited); // Perform DFS to check connectivity
    }
};

int main()
{
    FamilyTree family;

    // Add relationships between family members
    family.addRelationship("Alice", "Bob");
    family.addRelationship("Bob", "Charlie");
    family.addRelationship("Charlie", "David");
    family.addRelationship("Eve", "Frank");
    family.addRelationship("Frank", "Grace");

    // Check if two people are related
    string person1 = "Alice";
    string person2 = "David";

    if (family.areRelated(person1, person2))
    {
        cout << person1 << " and " << person2 << " are related in the family tree." << endl;
    }
    else
    {
        cout << person1 << " and " << person2 << " are NOT related in the family tree." << endl;
    }

    // Check another relationship
    person1 = "Alice";
    person2 = "Grace";

    if (family.areRelated(person1, person2))
    {
        cout << person1 << " and " << person2 << " are related in the family tree." << endl;
    }
    else
    {
        cout << person1 << " and " << person2 << " are NOT related in the family tree." << endl;
    }

    return 0;
}
