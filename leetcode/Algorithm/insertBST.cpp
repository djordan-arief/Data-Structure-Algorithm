/*
Leetcode: 701. Insert into a binary search tree

You are given the root node of a binary search tree (BST)
and a value to insert into the tree. Return the root node of
the BST after the insertion. It is guaranteed that the new value
does not exist in the original BST.

Notice that there may exist multiple valid ways for the insertion,
as long as the tree remains a BST after insertion. You can return any
of them.

Time and space complexity: O(h) where h is equal to the height of the tree

*/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // base case
        if (root == nullptr){
            // create a new node and initialize the value to val
            TreeNode *new_node = new TreeNode{val};
            return new_node;
        }

        // if value is bigger, we go to right side of BST
        if (val > root->val) {
            root->right = insertIntoBST(root->right, val);
        }

        // if value is smaller, we go to left side of BST
        if (val < root->val) {
            root->left = insertIntoBST(root->left, val);
        }
        return root; 
    }
};
