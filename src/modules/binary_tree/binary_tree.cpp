#include "../../../include/utils.h"
#include "binary_tree.h"

// Constructor: Initialize an empty binary tree
BinaryTree::BinaryTree() : root(nullptr) {}

// Destructor: Clean up all nodes when the tree is destroyed
BinaryTree::~BinaryTree() {
    clear();
}

// Insert a new node with value x into the tree
// Maintains BST property
void BinaryTree::insert(int x) {
    root = insertRecursive(root, x);
    std::cout << "Inserted: " << x << std::endl;
}

// Recursive helper for insert operation
// Returns the new root of the subtree
TreeNode* BinaryTree::insertRecursive(TreeNode* node, int x) {
    if (!node) return new TreeNode(x);
    if (x < node->data) node->left = insertRecursive(node->left, x);
    else if (x > node->data) node->right = insertRecursive(node->right, x);
    return node;
}

// Remove the node with value x from the tree
// Maintains BST property
void BinaryTree::remove(int x) {
    root = removeRecursive(root, x);
    std::cout << "Removed: " << x << std::endl;
}

// Recursive helper for remove operation
// Returns the new root of the subtree
TreeNode* BinaryTree::removeRecursive(TreeNode* node, int x) {
    if (!node) return nullptr;

    if (x < node->data) node->left = removeRecursive(node->left, x);
    else if (x > node->data) node->right = removeRecursive(node->right, x);
    else {
        // Node found
        if (!node->left && !node->right) {
            delete node;
            return nullptr;
        }
        if (!node->left) {
            TreeNode* temp = node->right;
            delete node;
            return temp;
        }
        if (!node->right) {
            TreeNode* temp = node->left;
            delete node;
            return temp;
        }

        TreeNode* successor = findMin(node->right);
        node->data = successor->data;
        node->right = removeRecursive(node->right, successor->data);
    }
    return node;
}

// Search for a node with value x in the tree
bool BinaryTree::search(int x) {
    return searchRecursive(root, x);
}

// Recursive helper for search operation
bool BinaryTree::searchRecursive(TreeNode* node, int x) {
    if (!node) return false;
    if (x == node->data) return true;
    return x < node->data ? searchRecursive(node->left, x) : searchRecursive(node->right, x);
}

// Perform in-order traversal (Left-Root-Right)
void BinaryTree::inOrderTraversal() {
    std::cout << "In-Order: ";
    inOrder(root);
    std::cout << std::endl;
}

// Recursive helper for in-order traversal
void BinaryTree::inOrder(TreeNode* node) {
    if (!node) return;
    inOrder(node->left);
    std::cout << node->data << " ";
    inOrder(node->right);
}

// Perform pre-order traversal (Root-Left-Right)
void BinaryTree::preOrderTraversal() {
    std::cout << "Pre-Order: ";
    preOrder(root);
    std::cout << std::endl;
}

// Recursive helper for pre-order traversal
void BinaryTree::preOrder(TreeNode* node) {
    if (!node) return;
    std::cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}

// Perform post-order traversal (Left-Right-Root)
void BinaryTree::postOrderTraversal() {
    std::cout << "Post-Order: ";
    postOrder(root);
    std::cout << std::endl;
}

// Recursive helper for post-order traversal
void BinaryTree::postOrder(TreeNode* node) {
    if (!node) return;
    postOrder(node->left);
    postOrder(node->right);
    std::cout << node->data << " ";
}

// Get the height of the tree, returns -1 for empty tree, 0 for single node
int BinaryTree::height() {
    return heightRecursive(root);
}

// Recursive helper to calculate tree height
int BinaryTree::heightRecursive(TreeNode* node) {
    if (!node) return 0;
    int left = heightRecursive(node->left);
    int right = heightRecursive(node->right);
    return 1 + std::max(left, right);
}

// Check if the tree is empty, returns true if tree has no nodes, false otherwise
bool BinaryTree::isEmpty() {
    return root == nullptr;
}

// Remove all nodes from the tree
void BinaryTree::clear() {
    clearRecursive(root);
    root = nullptr;
    std::cout << "Binary tree cleared" << std::endl;
}

// Recursive helper to clear all nodes
void BinaryTree::clearRecursive(TreeNode* node) {
    if (!node) return;
    clearRecursive(node->left);
    clearRecursive(node->right);
    delete node;
}

// Find the minimum value in the tree, throws runtime_error if tree is empty
int BinaryTree::min() {
    if (!root) throw std::runtime_error("Tree is empty");
    return findMin(root)->data;
}

// Find the maximum value in the tree, throws runtime_error if tree is empty
int BinaryTree::max() {
    if (!root) throw std::runtime_error("Tree is empty");
    return findMax(root)->data;
}

// Find the node with minimum value in a subtree, returns nullptr if node is null
TreeNode* BinaryTree::findMin(TreeNode* node) {
    while (node && node->left) node = node->left;
    return node;
}

// Find the node with maximum value in a subtree, returns nullptr if node is null
TreeNode* BinaryTree::findMax(TreeNode* node) {
    while (node && node->right) node = node->right;
    return node;
}

// Display the menu of available operations
void BinaryTree::displayMenu() {
    std::cout << CYAN << "BINARY TREE OPERATIONS" << RESET << std::endl;
    std::cout << "1. Insert" << std::endl;
    std::cout << "2. Delete" << std::endl;
    std::cout << "3. Search" << std::endl;
    std::cout << "4. In-order Traversal" << std::endl;
    std::cout << "5. Pre-order Traversal" << std::endl;
    std::cout << "6. Post-order Traversal" << std::endl;
    std::cout << "7. Height" << std::endl;
    std::cout << "8. Is empty?" << std::endl;
    std::cout << "9. Clear" << std::endl;
    std::cout << "10. Min" << std::endl;
    std::cout << "11. Max" << std::endl;
    std::cout << "0. Back to main menu" << std::endl;
    std::cout << "Select operation: ";
}

// Handle user interaction for binary tree operations
void BinaryTree::handleBinaryTreeOperations() {
    int choice, value;
    cls();

    do {
        displayMenu();
        std::cin >> choice;
        cls();
        std::cout << CYAN << "Selected option: " << choice << RESET << std::endl;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << RED << "Invalid input." << RESET << std::endl;
            continue;
        }

        try {
            switch (choice) {
                case 1:
                    std::cout << "Enter value to insert: "; std::cin >> value;
                    insert(value);
                    break;
                case 2:
                    std::cout << "Enter value to delete: "; std::cin >> value;
                    remove(value);
                    break;
                case 3:
                    std::cout << "Enter value to search: "; std::cin >> value;
                    std::cout << (search(value) ? "Found" : "Not found") << std::endl;
                    break;
                case 4:
                    inOrderTraversal();
                    break;
                case 5:
                    preOrderTraversal();
                    break;
                case 6:
                    postOrderTraversal();
                    break;
                case 7:
                    std::cout << "Tree height: " << height() << std::endl;
                    break;
                case 8:
                    std::cout << (isEmpty() ? "Tree is empty" : "Tree is not empty") << std::endl;
                    break;
                case 9:
                    clear();
                    break;
                case 10:
                    std::cout << "Minimum value: " << min() << std::endl;
                    break;
                case 11:
                    std::cout << "Maximum value: " << max() << std::endl;
                    break;
                case 0:
                    std::cout << "Returning to main menu..." << std::endl;
                    break;
                default:
                    cls();
                    std::cout << RED << "Invalid option." << RESET << std::endl;
            }
        } catch (const std::exception& e) {
            cls();
            std::cout << RED << "Error: " << e.what() << RESET << std::endl;
        }

    } while (choice != 0);
}
