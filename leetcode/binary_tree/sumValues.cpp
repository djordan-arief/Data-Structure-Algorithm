#include <stack>

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
    int sumValues(Node *root){
        int total = 0;
        std::stack <Node *> node_stack; 
        if (root != nullptr) node_stack.push(root);
        while (!node_stack.empty()){
            Node *currentNode = node_stack.top();
            node_stack.pop();
            total += currentNode->val; 
            if(currentNode->right != nullptr) node_stack.push(currentNode->right);
            if(currentNode->left != nullptr) node_stack.push(currentNode->left);
        }
        return total; 
    }
};