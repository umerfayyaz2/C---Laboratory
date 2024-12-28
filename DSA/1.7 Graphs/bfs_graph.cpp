#include <iostream>
#include <queue>
using namespace std;

vector<int> bfs_graph(int V, vector<int> adj_list[])
{
    queue<int> q;
    q.push(0);
    vector<int> visited(V, 0);

    vector<int> result;
    int node;
    while (!q.empty())
    {
        node = q.front();
        q.pop();
        result.push_back(node);
        visited[node] = 1; // set node to visited

        for (int i = 0; i < adj_list[node].size; i++)
        {
            if (!visited[node][i] == 1)
            {
                visited[node][i] = 1;
                q.push(adj_list[node][i]); // enqueue adjacent unvisited node
            }
        }
    }
    return result;
}