#include <stack>
#include <vector>
using namespace std;

//  Given the root of a binary tree, return the preorder traversal of its nodes' values.
// Time and space complexity: 0(n)

class Node{
public:
    int val;
    Node *left; 
    Node *right;

    // Default Constructor
    Node(): val{0}, left{nullptr}, right{nullptr}{};

    // initialize val
    Node(int x): val{x}, left{nullptr}, right{nullptr}{}; 

    // initialize val and pointers
    Node(int x, Node *lNode, Node *rNode): val{x}, left{lNode}, right{rNode}{}; 
};

class Solution {
public:
    vector<int> preorderTraversal(Node* root) {
        // Create the vector to store value
        vector<int> result;

        // Create a stack to store the Node
        stack<Node*> stack;

        // Push the root node to stack
        if (root != nullptr) stack.push(root);
        while (!stack.empty()) {
            Node* currentNode = stack.top();
            stack.pop();
            result.push_back(currentNode->val);
            if (currentNode->right != nullptr) stack.push(currentNode->right);
            if (currentNode->left != nullptr) stack.push(currentNode->left);
        }
        return result;
    }
};