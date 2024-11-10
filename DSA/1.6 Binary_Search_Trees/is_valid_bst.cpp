#include <iostream>
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
    bool isValidBST(TreeNode *root)
    {
        return validate(root, LONG_MIN, LONG_MAX);
    }

private:
    bool validate(TreeNode *node, long min_val, long max_val)
    {
        // Base case: if the node is null, it is valid
        if (!node)
            return true;

        // Check if the current node's value is within the valid range
        if (node->val <= min_val || node->val >= max_val)
            return false;

        // Recursively validate the left and right subtrees
        return validate(node->left, min_val, node->val) &&
               validate(node->right, node->val, max_val);
    }
};
