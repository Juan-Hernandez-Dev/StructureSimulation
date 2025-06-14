#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <stdexcept>

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class Stack {
private:
    Node* topNode;
    int stackSize;

public:
    // Constructor
    Stack();

    // Destructor
    ~Stack();

    // Core stack operations
    void push(int x);
    int pop();
    int peek();
    int top();
    bool isEmpty();
    int size();
    void clear();

    // Utility functions
    void display();
    void displayMenu();
    void handleStackOperations();
};

#endif // STACK_H