#include <stack>
/*
Given two binary trees original and cloned and given a 
reference to a node target in the original tree.

The cloned tree is a copy of the original tree.

Return a reference to the same node in the cloned tree.

Note that you are not allowed to change any of the two 
trees or the target node and the answer must be a reference to a 
node in the cloned tree.


*/

class Node{
public:
    int val; 
    Node *left; 
    Node *right; 

    Node(): val{0}, left{nullptr}, right{nullptr}{};
    Node(int x): val{x}, left{nullptr}, right{nullptr}{}; 
    Node(int x, Node *lNode, Node *rNode): val{x}, left{lNode}, right{rNode}{}; 
};

class Solution{
    Node* getTargetCopy(Node* original, Node* cloned, Node* target) {
        // Check if root of cloned is the target node
        if (cloned->val == target->val) return cloned; 

        // Create a stack for node pointer
        std::stack <Node *> node_stack;

        // push the root cloned tree to stack
        node_stack.push(cloned); 

        // create pointer to store the current node that is equal to the target node
        Node *targetNode; 
        while (!node_stack.empty()){
            Node *currentNode = node_stack.top(); 
            node_stack.pop(); 

            // check if current node is the target node
            if (currentNode->val == target->val) targetNode = currentNode;

            // check if node right is not null
            if (currentNode->right != nullptr) node_stack.push(currentNode->right);

            // check if node left is not null
            if (currentNode->left != nullptr) node_stack.push(currentNode->left);
        }
        return targetNode;
    }
};