#include <queue>

/*
Given the root of a binary tree, return the sum of values of its deepest leaves.

*/

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution{
public:
    int deepestLeavesSum(TreeNode *root){
        std::queue<TreeNode *> q;
        q.push(root);
        int total = 0;

        while (!q.empty())
        {
            total = 0;
            int q_size = q.size();
            for (int i = 0; i < q_size; i++)
            {
                TreeNode *currentNode = q.front();
                q.pop();
                total += currentNode->val;

                if (currentNode->right != NULL)
                    q.push(currentNode->right);
                if (currentNode->left != NULL)
                    q.push(currentNode->left);
            }
        }

        return total;
    }
};