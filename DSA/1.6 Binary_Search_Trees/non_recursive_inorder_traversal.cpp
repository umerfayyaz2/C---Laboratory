#include <iostream>
#include <stack>
using namespace std;

template <typename T>
struct TreeNode
{
    T data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(T value) : data(value), left(nullptr), right(nullptr) {}
};

template <typename T>
class BinaryTree
{
public:
    TreeNode<T> *root;
    BinaryTree() : root(nullptr) {}

    void nonRecursiveInorderTraversal()
    {
        stack<TreeNode<T> *> stack;
        TreeNode<T> *current = root;

        while (current != nullptr || !stack.empty())
        {
            if (current != nullptr)
            {
                stack.push(current); // Push node and move to its left child
                current = current->left;
            }
            else
            {
                current = stack.top();
                stack.pop(); // Pop and visit the node
                cout << current->data << " ";
                current = current->right; // Move to right child
            }
        }
        cout << endl;
    }
};
