/*
Leetcode 450: Delete Node in a BST (Binary Search Tree)

Given a root node reference of a BST and a key,
delete the node with the given key in the BST.
Return the root node reference (possibly updated)
of the BST.

Basically, the deletion can be divided into two
stages:

Search for a node to remove.
If the node is found, delete the node.


*/
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        // base case
        if (root == nullptr) return root; 
        if (key > root->val) root->right=deleteNode(root->right, key); 
        if (key < root->val) root->left=deleteNode(root->left, key);
        if (key == root->val){
            if (root->left == nullptr) return root->right; 
            if (root->right == nullptr) return root->left;
            TreeNode *currentNode = root->right; 
            while (currentNode->left){
                currentNode = currentNode->left; 
            }
            root->val = currentNode->val; 
            root->right = deleteNode(root->right, root->val); 
        }
        return root; 
    }
};