/*
This program implements an AVL tree with operations to insert, delete, and traverse nodes.
It includes functions for left and right rotations, calculating balance factors, updating node heights, and performing
in-order, pre-order, and post-order traversals. Input commands are read from the user to perform tree operations and
print traversal results based on the specified order.
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

// Node structure for AVL tree
class nodeTree {
public:
    int kVal;           // Node value
    nodeTree* childR;   // Right child
    nodeTree* childL;   // Left child
    int nodeH;          // Height of the node

    // Constructor
    nodeTree(int valueK) {
        this->kVal = valueK;
        this->childR = nullptr;
        this->childL = nullptr;
        this->nodeH = 1;
    }
};

// Function to find maximum of two integers
int max(int a, int b) {
    return std::max(a, b);
}

// Function to get height of a node
int heightNode(nodeTree* node) {
    return (node == nullptr) ? 0 : node->nodeH;
}

// Function to create a new node
nodeTree* createNodeN(int valueK) {
    return new nodeTree(valueK);
}

// Update height of a node based on its children's heights
void updateHeight(nodeTree* node) {
    if (node != nullptr) {
        node->nodeH = max(heightNode(node->childL), heightNode(node->childR)) + 1;
    }
}

// Right rotation
nodeTree* rotateR(nodeTree* a) {
    nodeTree* b = a->childL;
    nodeTree* tSubTree = b->childR;
    b->childR = a;
    a->childL = tSubTree;
    updateHeight(a);
    updateHeight(b);
    return b;
}

// Left rotation
nodeTree* rotateL(nodeTree* b) {
    nodeTree* a = b->childR;
    nodeTree* tSubTree = a->childL;
    a->childL = b;
    b->childR = tSubTree;
    updateHeight(b);
    updateHeight(a);
    return a;
}

// Calculate balance factor of a node
int balanceCal(nodeTree* node) {
    return (node == nullptr) ? 0 : heightNode(node->childL) - heightNode(node->childR);
}

// Insert a node into the AVL tree
nodeTree* nodeInsertion(nodeTree* node, int valueK) {
    if (node == nullptr)
        return createNodeN(valueK);

    if (valueK < node->kVal) {
        node->childL = nodeInsertion(node->childL, valueK);
        node->nodeH = max(heightNode(node->childL), heightNode(node->childR)) + 1;
    } else if (valueK > node->kVal) {
        node->childR = nodeInsertion(node->childR, valueK);
        node->nodeH = max(heightNode(node->childL), heightNode(node->childR)) + 1;
    }

    int balFac = balanceCal(node);

    // Rebalance tree if needed
    if (balFac > 1 && valueK < node->childL->kVal)
        return rotateR(node);
    if (balFac < -1 && valueK > node->childR->kVal)
        return rotateL(node);
    if (balFac > 1 && valueK > node->childL->kVal) {
        node->childL = rotateL(node->childL);
        return rotateR(node);
    }
    if (balFac < -1 && valueK < node->childR->kVal) {
        node->childR = rotateR(node->childR);
        return rotateL(node);
    }
    return node;
}

// Find maximum node in a subtree
nodeTree* findMaxNode(nodeTree* node) {
    if (node == nullptr || node->childR == nullptr)
        return node;
    return findMaxNode(node->childR);
}

// Delete a node from AVL tree
nodeTree* deleteNode(nodeTree* rNode, int valueK) {
    if (rNode == nullptr)
        return rNode;
    if (valueK < rNode->kVal)
        rNode->childL = deleteNode(rNode->childL, valueK);
    else if (valueK > rNode->kVal)
        rNode->childR = deleteNode(rNode->childR, valueK);
    else {
        if (rNode->childL == nullptr || rNode->childR == nullptr) {
            nodeTree* replacementNode = (rNode->childL != nullptr) ? rNode->childL : rNode->childR;
            delete rNode;
            rNode = replacementNode;
        } else {
            nodeTree* replacementNode = findMaxNode(rNode->childL);
            rNode->kVal = replacementNode->kVal;
            rNode->childL = deleteNode(rNode->childL, replacementNode->kVal);
        }
    }
    if (rNode == nullptr)
        return rNode;

    rNode->nodeH = max(heightNode(rNode->childL), heightNode(rNode->childR)) + 1;

    int balFac = balanceCal(rNode);

    // Rebalance the tree if needed
    if (balFac > 1) {
        if (balanceCal(rNode->childL) < 0)
            rNode->childL = rotateL(rNode->childL);
        return rotateR(rNode);
    }

    if (balFac < -1) {
        if (balanceCal(rNode->childR) > 0)
            rNode->childR = rotateR(rNode->childR);
        return rotateL(rNode);
    }
    return rNode;
}

// In-order traversal
void inOrderTraversal(nodeTree* rNode) {
    if (rNode != nullptr) {
        inOrderTraversal(rNode->childL);
        std::cout << rNode->kVal << " ";
        inOrderTraversal(rNode->childR);
    }
}

// Pre-order traversal
void preOrderTraversal(nodeTree* rNode) {
    if (rNode != nullptr) {
        std::cout << rNode->kVal << " ";
        preOrderTraversal(rNode->childL);
        preOrderTraversal(rNode->childR);
    }
}

// Post-order traversal
void postOrderTraversal(nodeTree* rNode) {
    if (rNode != nullptr) {
        postOrderTraversal(rNode->childL);
        postOrderTraversal(rNode->childR);
        std::cout << rNode->kVal << " ";
    }
}

// Print tree based on traversal order
void printTree(nodeTree* rNode, std::string order) {
    if (order == "PRE") {
        preOrderTraversal(rNode);
    } else if (order == "IN") {
        inOrderTraversal(rNode);
    } else if (order == "POST") {
        postOrderTraversal(rNode);
    }
}

int main() {
    nodeTree* rNode = nullptr;

    std::string input;
    // Get input from user as a whole line with spaces
    std::getline(std::cin, input);

    std::string inputUser;

    for (size_t i = 0; i <= input.size(); ++i) {
        if (i == input.size() || input[i] == ' ') {
            // Perform operation using user input
            if (!inputUser.empty()) {
                if (inputUser == "PRE" || inputUser == "POST" || inputUser == "IN") {
                    if (rNode == nullptr)
                        std::cout << "EMPTY" << std::endl;
                    else
                        printTree(rNode, inputUser);
                } else if (inputUser[0] == 'A') {
                    int value = std::stoi(inputUser.substr(1));
                    rNode = nodeInsertion(rNode, value);
                } else if (inputUser[0] == 'D') {
                    int value = std::stoi(inputUser.substr(1));
                    rNode = deleteNode(rNode, value);
                }
            }
            inputUser.clear();
        } else {
            inputUser += input[i];
        }
    }
    return 0;
}