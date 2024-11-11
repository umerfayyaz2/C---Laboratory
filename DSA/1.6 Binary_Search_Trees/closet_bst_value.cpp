#include <iostream>
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
    int closestValue(TreeNode *root, double target)
    {
        int closest = root->val;

        while (root != nullptr)
        {
            // Update closest if the current node is closer to the target
            if (std::abs(root->val - target) < std::abs(closest - target))
            {
                closest = root->val;
            }

            // Move left or right depending on the target value
            if (target < root->val)
            {
                root = root->left;
            }
            else
            {
                root = root->right;
            }
        }
        return closest;
    }
};
