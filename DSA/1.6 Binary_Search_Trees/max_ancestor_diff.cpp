#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>

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
    int maxAncestorDiff(TreeNode *root)
    {
        return dfs(root, root->val, root->val);
    }

private:
    int dfs(TreeNode *node, int curr_min, int curr_max)
    {
        if (node == nullptr)
        {
            return curr_max - curr_min;
        }

        // Update current min and max based on the current node value
        curr_min = std::min(curr_min, node->val);
        curr_max = std::max(curr_max, node->val);

        // Recursively calculate the difference for left and right subtrees
        int left_diff = dfs(node->left, curr_min, curr_max);
        int right_diff = dfs(node->right, curr_min, curr_max);

        // Return the maximum difference found in both subtrees
        return std::max(left_diff, right_diff);
    }
};
