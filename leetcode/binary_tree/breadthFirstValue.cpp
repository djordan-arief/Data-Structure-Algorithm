#include <queue>
#include <vector>

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
public:
    std::vector<int> breadthFirstValue(Node *root){
        std::vector<int> result;
        std::queue<Node *> node_queue; 
        node_queue.push(root); 

        while(!node_queue.empty()){
            Node *currentNode = node_queue.front();
            node_queue.pop();
            result.push_back(currentNode->val);

            if (currentNode->right != nullptr) node_queue.push(currentNode->right); 
            if (currentNode->left != nullptr) node_queue.push(currentNode->left);
        }

        return result;
    }
};