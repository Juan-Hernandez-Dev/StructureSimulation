#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <stdexcept>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    TreeNode* root;

public:
    // Constructor y destructor
    BinaryTree();
    ~BinaryTree();

    // Operaciones principales
    void insert(int x);
    void remove(int x);
    bool search(int x);
    void inOrderTraversal();
    void preOrderTraversal();
    void postOrderTraversal();
    int height();
    bool isEmpty();
    void clear();
    int min();
    int max();

    // Interfaz de usuario
    void displayMenu();
    void handleBinaryTreeOperations();

private:
    // Funciones auxiliares recursivas
    TreeNode* insertRecursive(TreeNode* node, int x);
    TreeNode* removeRecursive(TreeNode* node, int x);
    TreeNode* findMin(TreeNode* node);
    TreeNode* findMax(TreeNode* node);
    bool searchRecursive(TreeNode* node, int x);
    void inOrder(TreeNode* node);
    void preOrder(TreeNode* node);
    void postOrder(TreeNode* node);
    int heightRecursive(TreeNode* node);
    void clearRecursive(TreeNode* node);
};

#endif // BINARYTREE_H
