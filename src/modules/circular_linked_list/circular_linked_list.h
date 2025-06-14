#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H

#include <iostream>
#include <stdexcept>

struct CircularListNode {
    int data;
    CircularListNode* next;

    CircularListNode(int value) : data(value), next(nullptr) {}
};

class CircularLinkedList {
private:
    CircularListNode* head;
    int listSize;

public:
    // Constructor y destructor
    CircularLinkedList();
    ~CircularLinkedList();

    // Operaciones principales
    void insertFirst(int x);
    void insertLast(int x);
    void deleteFirst();
    void deleteLast();
    void insertAt(int x, int index);
    void deleteAt(int index);
    int find(int x);
    int size();
    void clear();
    bool isCircular();

    // Visualización y menú
    void display();
    void displayMenu();
    void handleCircularLinkedListOperations();

private:
    // Funciones auxiliares
    CircularListNode* getNodeAt(int index);
    bool isValidIndex(int index);
};

#endif // CIRCULARLINKEDLIST_H
