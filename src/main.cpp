#include <iostream>
#include <limits>
#include "modules/stack/stack.h"
#include "modules/queue/queue.h"
#include "modules/linked_list/linked_list.h"
#include "modules/doubly_linked_list/doubly_linked_list.h"
#include "modules/circular_linked_list/circular_linked_list.h"
#include "modules/binary_tree/binary_tree.h"
using namespace std;

#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

void cls() {
    system("cls");
}

void showMenu() {
    cout << BOLD << CYAN << "Menu:" << RESET << endl;
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
    cls();

    do {
        showMenu();
        cin >> option;

        if (cin.fail()) {
            clearBuffer();
            cout << BOLD << RED << "Error: Please enter a valid number." << RESET << endl;
            continue;
        } else {
            cls();
            cout << BOLD << CYAN << "Selected option: " << option << RESET << endl;
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
                cout << BOLD << CYAN << "Goodbye!" << RESET << endl;
                break;
            default:
                cls();
                cout << BOLD << RED << "Invalid option. Please try again." << RESET << endl;
                break;
        }

    } while (option != 0);

    return 0;
}