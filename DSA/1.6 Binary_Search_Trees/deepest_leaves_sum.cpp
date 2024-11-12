#include <iostream>
#include <queue>
using namespace std;

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
    int deepestLeavesSum(TreeNode *root)
    {
        if (!root)
            return 0;

        queue<TreeNode *> q;
        q.push(root);
        int sum = 0;

        while (!q.empty())
        {
            int level_size = q.size();
            sum = 0; // Reset sum for the current level

            for (int i = 0; i < level_size; ++i)
            {
                TreeNode *node = q.front();
                q.pop();

                // Add current node's value to sum for the current level
                sum += node->val;

                // Add children to the queue for next level processing
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
        }

        return sum;
    }
};
