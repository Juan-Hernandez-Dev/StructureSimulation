#include <iostream>
#include <limits>
#include "modules/stack/stack.h"
#include "modules/queue/queue.h"
#include "modules/linked_list/linked_list.h"
#include "modules/doubly_linked_list/doubly_linked_list.h"
#include "modules/circular_linked_list/circular_linked_list.h"
#include "modules/binary_tree/binary_tree.h"

using namespace std;

void showMenu() {
    cout << "\nMenu:" << endl;
    cout << "1. Stack" << endl;
    cout << "2. Queue" << endl;
    cout << "3. linked list" << endl;
    cout << "4. Doubly linked lists" << endl;
    cout << "5. Circular linked lists" << endl;
    cout << "6. Binary tree" << endl;
    cout << "0. Exit" << endl;
    cout << "Select an option: ";
}

void clearBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    int option;

    do {
        showMenu();
        cin >> option;

        if (cin.fail()) {
            clearBuffer();
            cout << "Error: Please enter a valid number." << endl;
            continue;
        }

        switch (option) {
            case 1: {
                Stack myStack;
                myStack.handleStackOperations();
                break;
            }
            case 2: {
                Queue myQueue;
                myQueue.handleQueueOperations();
                break;
            }
            case 3: {
                LinkedList myList;
                myList.handleLinkedListOperations();
                break;
            }
            case 4: {
                DoublyLinkedList myDList;
                myDList.handleDoublyLinkedListOperations();
                break;
            }
            case 5: {
                CircularLinkedList myCList;
                myCList.handleCircularLinkedListOperations();
                break;
            }
            case 6: {
                BinaryTree myBinaryTree;
                myBinaryTree.handleBinaryTreeOperations();
                break;
            }

            case 0:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
                break;
        }

    } while (option != 0);

    return 0;
}