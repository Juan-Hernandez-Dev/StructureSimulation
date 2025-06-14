#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <stdexcept>

struct QueueNode {
    int data;
    QueueNode* next;

    QueueNode(int value) : data(value), next(nullptr) {}
};

class Queue {
private:
    QueueNode* frontNode;
    QueueNode* rearNode;
    int queueSize;

public:
    // Constructor
    Queue();

    // Destructor
    ~Queue();

    // Core queue operations
    void enqueue(int x);
    int dequeue();
    int front();
    bool isEmpty();
    int size();
    void clear();

    // Utility functions
    void display();
    void displayMenu();
    void handleQueueOperations();
};

#endif // QUEUE_H