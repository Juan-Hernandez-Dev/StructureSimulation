#include "../../../include/utils.h"
#include "stack.h"

// Constructor
Stack::Stack() : topNode(nullptr), stackSize(0) {}

// Destructor
Stack::~Stack() {
    clear();
}

// Push: Add element to top of stack
void Stack::push(int x) {
    Node* newNode = new Node(x);
    newNode->next = topNode;
    topNode = newNode;
    stackSize++;
    std::cout << "Pushed " << x << " to stack" << std::endl;
}

// Pop: Remove and return top element
int Stack::pop() {
    if (isEmpty()) {
        throw std::runtime_error("Stack underflow: Cannot pop from empty stack");
    }

    Node* temp = topNode;
    int poppedValue = topNode->data;
    topNode = topNode->next;
    delete temp;
    stackSize--;

    return poppedValue;
}

// Peek/Top: Return top element without removing it
int Stack::peek() {
    if (isEmpty()) {
        throw std::runtime_error("Stack is empty: Cannot peek");
    }
    return topNode->data;
}

int Stack::top() {
    return peek(); // Same functionality as peek
}

// Check if stack is empty
bool Stack::isEmpty() {
    return topNode == nullptr;
}

// Get stack size
int Stack::size() {
    return stackSize;
}

// Clear all elements from stack
void Stack::clear() {
    while (!isEmpty()) {
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
    }
    stackSize = 0;
    std::cout << "Stack cleared" << std::endl;
}

// Display stack contents
void Stack::display() {
    if (isEmpty()) {
        std::cout << "Stack is empty" << std::endl;
        return;
    }

    std::cout << "Stack contents (top to bottom): ";
    Node* current = topNode;
    while (current != nullptr) {
        std::cout << current->data;
        if (current->next != nullptr) {
            std::cout << " -> ";
        }
        current = current->next;
    }
    std::cout << std::endl;
}

// Display stack operations menu
void Stack::displayMenu() {
    std::cout << CYAN << "STACK OPERATIONS" << RESET << std::endl;
    std::cout << "1. Push element" << std::endl;
    std::cout << "2. Pop element" << std::endl;
    std::cout << "3. Peek/Top element" << std::endl;
    std::cout << "4. Check if empty" << std::endl;
    std::cout << "5. Get size" << std::endl;
    std::cout << "6. Display stack" << std::endl;
    std::cout << "7. Clear stack" << std::endl;
    std::cout << "0. Back to main menu" << std::endl;
    std::cout << "Select operation: ";
}

// Handle stack operations with user interaction
void Stack::handleStackOperations() {
    int choice;
    int value;
    cls();

    do {
        displayMenu();
        std::cin >> choice;
        cls();
        std::cout << CYAN << "Selected option: " << choice << RESET << std::endl;
        
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << RED << "Invalid input. Please enter a number." << RESET << std::endl;
            continue;
        }

        try {
            switch (choice) {
                case 1: // Push
                    std::cout << "Enter value to push: ";
                    std::cin >> value;
                    if (std::cin.fail()) {
                        std::cin.clear();
                        std::cin.ignore(10000, '\n');
                        std::cout << RED << "Invalid value." << RESET << std::endl;
                    } else {
                        push(value);
                    }
                    break;

                case 2: // Pop
                    value = pop();
                    std::cout << "Popped value: " << value << std::endl;
                    break;

                case 3: // Peek/Top
                    value = peek();
                    std::cout << "Top element: " << value << std::endl;
                    break;

                case 4: // Is Empty
                    if (isEmpty()) {
                        std::cout << RED << "Stack is empty" << RESET << std::endl;
                    } else {
                        std::cout << RED << "Stack is not empty" << RESET << std::endl;
                    }
                    break;

                case 5: // Size
                    std::cout << "Stack size: " << size() << std::endl;
                    break;

                case 6: // Display
                    display();
                    break;

                case 7: // Clear
                    clear();
                    break;

                case 0: // Back
                    std::cout << "Returning to main menu..." << std::endl;
                    break;

                default:
                    cls();
                    std::cout << RED << "Invalid option. Please try again." << RESET << std::endl;
                    break;
            }
        } catch (const std::exception& e) {
            cls();
            std::cout << RED << "Error: " << e.what() << RESET << std::endl;
        }

    } while (choice != 0);
}