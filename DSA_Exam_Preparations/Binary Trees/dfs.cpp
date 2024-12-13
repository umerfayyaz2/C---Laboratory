#include <iostream>
#include <stack>
using namespace std;

struct Node
{
    int data;
    Node *right;
    Node *left;
}

void
dfs()
{
    if (root == nullptr)
    {
        return;
    }

    stack<Node *> s;
    s.push(root);

    while (!s.empty())
    {
        Node *node = s.top();
        cout << node->data << " ";
        s.pop();

        if (node->right != nullptr)
        {
            s.push(node->right);
        }

        if (node->left != nullptr)
        {
            s.push(node->left);
        }
    }

    cout << endl;
}