#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <stdexcept>

struct ListNode {
    int data;
    ListNode* next;

    ListNode(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    ListNode* head;
    int listSize;

public:
    // Constructor
    LinkedList();

    // Destructor
    ~LinkedList();

    // Core linked list operations
    void insertFirst(int x);
    void insertLast(int x);
    void deleteFirst();
    void deleteLast();
    void insertAt(int x, int index);
    void deleteAt(int index);
    int find(int x);
    int size();
    void clear();

    // Utility functions
    void display();
    void displayMenu();
    void handleLinkedListOperations();

private:
    // Helper functions
    ListNode* getNodeAt(int index);
    bool isValidIndex(int index);
};

#endif // LINKEDLIST_H