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
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        if (root == nullptr)
            return 0;

        int sum = 0;

        // If the node's value is within range, include it in the sum
        if (root->val >= low && root->val <= high)
        {
            sum += root->val;
        }

        // If the node's value is greater than low, explore the left subtree
        if (root->val > low)
        {
            sum += rangeSumBST(root->left, low, high);
        }

        // If the node's value is less than high, explore the right subtree
        if (root->val < high)
        {
            sum += rangeSumBST(root->right, low, high);
        }

        return sum;
    }
};
