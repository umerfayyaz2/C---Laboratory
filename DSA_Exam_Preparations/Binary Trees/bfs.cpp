#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node *right;
    Node *left;
}

void
bfs()
{
    if (node == null ptr)
    {
        cout << "tree is empty" << endl;
        return;
    }

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *node = q.front();
        cout << node->data << " ";
        q.pop();

        if (node->left != nulptr)
        {
            q.push(node->left);
        }

        if (node->right != nulptr)
        {
            q.push(node->right);
        }
    }
    cout << endl;
}