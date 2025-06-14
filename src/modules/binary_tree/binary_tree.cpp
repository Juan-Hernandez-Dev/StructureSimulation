#include "../../../include/utils.h"
#include "binary_tree.h"

BinaryTree::BinaryTree() : root(nullptr) {}

BinaryTree::~BinaryTree() {
    clear();
}

void BinaryTree::insert(int x) {
    root = insertRecursive(root, x);
    std::cout << "Inserted: " << x << std::endl;
}

TreeNode* BinaryTree::insertRecursive(TreeNode* node, int x) {
    if (!node) return new TreeNode(x);
    if (x < node->data) node->left = insertRecursive(node->left, x);
    else if (x > node->data) node->right = insertRecursive(node->right, x);
    return node;
}

void BinaryTree::remove(int x) {
    root = removeRecursive(root, x);
    std::cout << "Removed: " << x << std::endl;
}

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

bool BinaryTree::search(int x) {
    return searchRecursive(root, x);
}

bool BinaryTree::searchRecursive(TreeNode* node, int x) {
    if (!node) return false;
    if (x == node->data) return true;
    return x < node->data ? searchRecursive(node->left, x) : searchRecursive(node->right, x);
}

void BinaryTree::inOrderTraversal() {
    std::cout << "In-Order: ";
    inOrder(root);
    std::cout << std::endl;
}

void BinaryTree::inOrder(TreeNode* node) {
    if (!node) return;
    inOrder(node->left);
    std::cout << node->data << " ";
    inOrder(node->right);
}

void BinaryTree::preOrderTraversal() {
    std::cout << "Pre-Order: ";
    preOrder(root);
    std::cout << std::endl;
}

void BinaryTree::preOrder(TreeNode* node) {
    if (!node) return;
    std::cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}

void BinaryTree::postOrderTraversal() {
    std::cout << "Post-Order: ";
    postOrder(root);
    std::cout << std::endl;
}

void BinaryTree::postOrder(TreeNode* node) {
    if (!node) return;
    postOrder(node->left);
    postOrder(node->right);
    std::cout << node->data << " ";
}

int BinaryTree::height() {
    return heightRecursive(root);
}

int BinaryTree::heightRecursive(TreeNode* node) {
    if (!node) return 0;
    int left = heightRecursive(node->left);
    int right = heightRecursive(node->right);
    return 1 + std::max(left, right);
}

bool BinaryTree::isEmpty() {
    return root == nullptr;
}

void BinaryTree::clear() {
    clearRecursive(root);
    root = nullptr;
    std::cout << "Binary tree cleared" << std::endl;
}

void BinaryTree::clearRecursive(TreeNode* node) {
    if (!node) return;
    clearRecursive(node->left);
    clearRecursive(node->right);
    delete node;
}

int BinaryTree::min() {
    if (!root) throw std::runtime_error("Tree is empty");
    return findMin(root)->data;
}

int BinaryTree::max() {
    if (!root) throw std::runtime_error("Tree is empty");
    return findMax(root)->data;
}

TreeNode* BinaryTree::findMin(TreeNode* node) {
    while (node && node->left) node = node->left;
    return node;
}

TreeNode* BinaryTree::findMax(TreeNode* node) {
    while (node && node->right) node = node->right;
    return node;
}

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
