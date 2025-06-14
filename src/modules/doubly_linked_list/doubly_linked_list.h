#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>
#include <stdexcept>

struct DoublyListNode {
    int data;
    DoublyListNode* next;
    DoublyListNode* prev;

    DoublyListNode(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
private:
    DoublyListNode* head;
    DoublyListNode* tail;
    int listSize;

public:
    // Constructor
    DoublyLinkedList();

    // Destructor
    ~DoublyLinkedList();

    // Core doubly linked list operations
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
    void displayReverse();
    void displayMenu();
    void handleDoublyLinkedListOperations();

private:
    // Helper functions
    DoublyListNode* getNodeAt(int index);
    bool isValidIndex(int index);
};

#endif // DOUBLYLINKEDLIST_H