#include <iostream>
#include "../include/utils.h"
#include "modules/stack/stack.h"
#include "modules/queue/queue.h"
#include "modules/linked_list/linked_list.h"
#include "modules/doubly_linked_list/doubly_linked_list.h"
#include "modules/circular_linked_list/circular_linked_list.h"
#include "modules/binary_tree/binary_tree.h"

void showMenu() {
    std::cout << BOLD << CYAN << "MENU" << RESET << std::endl;
    std::cout << "1. Stack" << std::endl;
    std::cout << "2. Queue" << std::endl;
    std::cout << "3. linked list" << std::endl;
    std::cout << "4. Doubly linked lists" << std::endl;
    std::cout << "5. Circular linked lists" << std::endl;
    std::cout << "6. Binary tree" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "Select an option: ";
}

int main() {
    int option;
    cls();

    do {
        showMenu();
        std::cin >> option;

        if (std::cin.fail()) {
            clearBuffer();
            std::cout << BOLD << RED << "Error: Please enter a valid number." << RESET << std::endl;
            continue;
        } else {
            cls();
            std::cout << BOLD << CYAN << "Selected option: " << option << RESET << std::endl;
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
                std::cout << BOLD << CYAN << "Goodbye!" << RESET << std::endl;
                break;
            default:
                cls();
                std::cout << BOLD << RED << "Invalid option. Please try again." << RESET << std::endl;
                break;
        }

    } while (option != 0);

    return 0;
}