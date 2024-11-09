#include <iostream>

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    int goodNodes(TreeNode *root)
    {
        return dfs(root, root->val);
    }

private:
    int dfs(TreeNode *node, int max_so_far)
    {
        if (node == nullptr)
            return 0;

        int good = 0;
        // Check if the current node is a "good" node
        if (node->val >= max_so_far)
        {
            good = 1; // This node is good
        }

        // Update max_so_far to the maximum of current max_so_far and node's value
        max_so_far = std::max(max_so_far, node->val);

        // Recurse for left and right subtrees and add their results
        good += dfs(node->left, max_so_far);
        good += dfs(node->right, max_so_far);

        return good;
    }
};