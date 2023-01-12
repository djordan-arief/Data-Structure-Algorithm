#include <iostream>
#include <vector>
class Node{
public: 
    int data; 
    Node *next {nullptr}; 

    Node (int x): data {x}{}
};

void linkedList(Node &node1, Node &node2){
    node1.next = &node2; 
}

void printLinkedList(Node &head){
    Node *currentNode = &head; 
    while (currentNode != NULL){
        std::cout <<"Node data: " << currentNode->data << std::endl; 
        currentNode = currentNode->next; 
    }
}

void pushDataNode(Node &head, std::vector <int> &r){
    Node *currentNode = &head; 
    while (currentNode != NULL){
        r.emplace_back(currentNode->data); 
        currentNode = currentNode->next; 
    }
}

void sumValNode (Node &head, int &sum){
    Node *currentNode = &head; 
    while (currentNode != NULL){
        sum += currentNode->data; 
        currentNode = currentNode->next; 
    }
}

bool findValNode(Node &head, int target){
    Node *currentNode = &head; 
    while (currentNode != NULL){
        if (currentNode->data == target) return true; 
        currentNode = currentNode->next; 
    }

    return false; 
}

int returnIndexNode(Node &head, int index){
    Node *currentNode = &head; 
    int currentIndex {0}; 
    while (currentNode != NULL){
        if (currentIndex == index)return currentNode->data; 
        currentNode = currentNode->next; 
        currentIndex++; 
    }

    return 0; 
}

Node *reverseList(Node &head){
    Node *prevNode = nullptr; 
    Node *currentNode = &head; 

    while (currentNode != NULL){
        Node *nextNode = currentNode->next; 
        currentNode->next = prevNode; 
        prevNode = currentNode; 
        currentNode = nextNode; 
    }
    return currentNode; 
}

void mergeList(Node &head){
    
}



int main (){
    std::cout << std::boolalpha; 
    Node node1 {32}; 
    Node node2 {14}; 
    Node node3 {99};
    Node node4 {102};
    Node node5 {33}; 

    linkedList(node1, node2); 
    linkedList(node2, node3); 
    linkedList(node3, node4); 
    linkedList(node4, node5); 

    // printLinkedList(node1);
    // std::vector <int> result; 
    // pushDataNode(node1, result); 

    // int total {0}; 
    // sumValNode(node1, total); 
    // std::cout << total << std::endl;

    // std::cout << findValNode(node1, 200) << std::endl;

    // std::cout << returnIndexNode(node1, 13) << std::endl; 

    reverseList(node1); 

    return 0; 
}



