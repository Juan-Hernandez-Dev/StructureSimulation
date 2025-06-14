#include "../../../include/utils.h"
#include "doubly_linked_list.h"

// Constructor
DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr), listSize(0) {}

// Destructor
DoublyLinkedList::~DoublyLinkedList() {
    clear();
}

// Insert at the beginning of the list
void DoublyLinkedList::insertFirst(int x) {
    DoublyListNode* newNode = new DoublyListNode(x);

    if (head == nullptr) {
        // Empty list
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    listSize++;
    std::cout << "Inserted " << x << " at the beginning" << std::endl;
}

// Insert at the end of the list
void DoublyLinkedList::insertLast(int x) {
    DoublyListNode* newNode = new DoublyListNode(x);

    if (tail == nullptr) {
        // Empty list
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    listSize++;
    std::cout << "Inserted " << x << " at the end" << std::endl;
}

// Delete the first node
void DoublyLinkedList::deleteFirst() {
    if (head == nullptr) {
        throw std::runtime_error("List is empty: Cannot delete from empty list");
    }

    int deletedValue = head->data;

    if (head == tail) {
        // Only one element
        delete head;
        head = tail = nullptr;
    } else {
        DoublyListNode* temp = head;
        head = head->next;
        head->prev = nullptr;
        delete temp;
    }

    listSize--;
    std::cout << "Deleted first element: " << deletedValue << std::endl;
}

// Delete the last node
void DoublyLinkedList::deleteLast() {
    if (tail == nullptr) {
        throw std::runtime_error("List is empty: Cannot delete from empty list");
    }

    int deletedValue = tail->data;

    if (head == tail) {
        // Only one element
        delete tail;
        head = tail = nullptr;
    } else {
        DoublyListNode* temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
    }

    listSize--;
    std::cout << "Deleted last element: " << deletedValue << std::endl;
}

// Insert at specific index
void DoublyLinkedList::insertAt(int x, int index) {
    if (index < 0 || index > listSize) {
        throw std::runtime_error("Invalid index: Index out of bounds");
    }

    if (index == 0) {
        insertFirst(x);
        return;
    }

    if (index == listSize) {
        insertLast(x);
        return;
    }

    DoublyListNode* newNode = new DoublyListNode(x);
    DoublyListNode* current;

    // Optimize: traverse from head or tail depending on index
    if (index <= listSize / 2) {
        // Traverse from head
        current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
    } else {
        // Traverse from tail
        current = tail;
        for (int i = listSize - 1; i > index; i--) {
            current = current->prev;
        }
    }

    // Insert before current node
    newNode->next = current;
    newNode->prev = current->prev;
    current->prev->next = newNode;
    current->prev = newNode;

    listSize++;
    std::cout << "Inserted " << x << " at index " << index << std::endl;
}

// Delete at specific index
void DoublyLinkedList::deleteAt(int index) {
    if (!isValidIndex(index)) {
        throw std::runtime_error("Invalid index: Index out of bounds");
    }

    if (index == 0) {
        deleteFirst();
        return;
    }

    if (index == listSize - 1) {
        deleteLast();
        return;
    }

    DoublyListNode* nodeToDelete = getNodeAt(index);
    int deletedValue = nodeToDelete->data;

    // Update links
    nodeToDelete->prev->next = nodeToDelete->next;
    nodeToDelete->next->prev = nodeToDelete->prev;

    delete nodeToDelete;
    listSize--;

    std::cout << "Deleted element " << deletedValue << " at index " << index << std::endl;
}

// Find element in the list (returns index, -1 if not found)
int DoublyLinkedList::find(int x) {
    DoublyListNode* current = head;
    int index = 0;

    while (current != nullptr) {
        if (current->data == x) {
            return index;
        }
        current = current->next;
        index++;
    }

    return -1; // Not found
}

// Get list size
int DoublyLinkedList::size() {
    return listSize;
}

// Clear all elements
void DoublyLinkedList::clear() {
    while (head != nullptr) {
        DoublyListNode* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
    listSize = 0;
    std::cout << "Doubly linked list cleared" << std::endl;
}

// Display list contents from head to tail
void DoublyLinkedList::display() {
    if (head == nullptr) {
        std::cout << "Doubly linked list is empty" << std::endl;
        return;
    }

    std::cout << "List contents (head to tail): ";
    DoublyListNode* current = head;
    int index = 0;

    while (current != nullptr) {
        std::cout << "[" << index << ":" << current->data << "]";
        if (current->next != nullptr) {
            std::cout << " <-> ";
        }
        current = current->next;
        index++;
    }
    std::cout << std::endl;
}

// Display list contents from tail to head
void DoublyLinkedList::displayReverse() {
    if (tail == nullptr) {
        std::cout << "Doubly linked list is empty" << std::endl;
        return;
    }

    std::cout << "List contents (tail to head): ";
    DoublyListNode* current = tail;
    int index = listSize - 1;

    while (current != nullptr) {
        std::cout << "[" << index << ":" << current->data << "]";
        if (current->prev != nullptr) {
            std::cout << " <-> ";
        }
        current = current->prev;
        index--;
    }
    std::cout << std::endl;
}

// Helper function to get node at specific index
DoublyListNode* DoublyLinkedList::getNodeAt(int index) {
    if (!isValidIndex(index)) {
        return nullptr;
    }

    DoublyListNode* current;

    // Optimize: traverse from head or tail depending on index
    if (index <= listSize / 2) {
        // Traverse from head
        current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
    } else {
        // Traverse from tail
        current = tail;
        for (int i = listSize - 1; i > index; i--) {
            current = current->prev;
        }
    }

    return current;
}

// Helper function to validate index
bool DoublyLinkedList::isValidIndex(int index) {
    return index >= 0 && index < listSize;
}

// Display doubly linked list operations menu
void DoublyLinkedList::displayMenu() {
    std::cout << CYAN << "DOUBLY LINKED LIST OPERATIONS" << RESET << std::endl;
    std::cout << "1. Insert at beginning" << std::endl;
    std::cout << "2. Insert at end" << std::endl;
    std::cout << "3. Insert at index" << std::endl;
    std::cout << "4. Delete first" << std::endl;
    std::cout << "5. Delete last" << std::endl;
    std::cout << "6. Delete at index" << std::endl;
    std::cout << "7. Find element" << std::endl;
    std::cout << "8. Get size" << std::endl;
    std::cout << "9. Display list (forward)" << std::endl;
    std::cout << "10. Display list (reverse)" << std::endl;
    std::cout << "11. Clear list" << std::endl;
    std::cout << "0. Back to main menu" << std::endl;
    std::cout << "Select operation: ";
}

// Handle doubly linked list operations with user interaction
void DoublyLinkedList::handleDoublyLinkedListOperations() {
    int choice;
    int value, index;
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
                case 1: // Insert at beginning
                    std::cout << "Enter value to insert: ";
                    std::cin >> value;
                    if (std::cin.fail()) {
                        std::cin.clear();
                        std::cin.ignore(10000, '\n');
                        std::cout << RED << "Invalid value." << RESET << std::endl;
                    } else {
                        insertFirst(value);
                    }
                    break;

                case 2: // Insert at end
                    std::cout << "Enter value to insert: ";
                    std::cin >> value;
                    if (std::cin.fail()) {
                        std::cin.clear();
                        std::cin.ignore(10000, '\n');
                        std::cout << RED << "Invalid value." << RESET << std::endl;
                    } else {
                        insertLast(value);
                    }
                    break;

                case 3: // Insert at index
                    std::cout << "Enter value to insert: ";
                    std::cin >> value;
                    std::cout << "Enter index (0 to " << listSize << "): ";
                    std::cin >> index;
                    if (std::cin.fail()) {
                        std::cin.clear();
                        std::cin.ignore(10000, '\n');
                        std::cout << RED << "Invalid input." << RESET << std::endl;
                    } else {
                        insertAt(value, index);
                    }
                    break;

                case 4: // Delete first
                    deleteFirst();
                    break;

                case 5: // Delete last
                    deleteLast();
                    break;

                case 6: // Delete at index
                    std::cout << "Enter index to delete (0 to " << (listSize-1) << "): ";
                    std::cin >> index;
                    if (std::cin.fail()) {
                        std::cin.clear();
                        std::cin.ignore(10000, '\n');
                        std::cout << RED << "Invalid input." << RESET << std::endl;
                    } else {
                        deleteAt(index);
                    }
                    break;

                case 7: // Find element
                    std::cout << "Enter value to find: ";
                    std::cin >> value;
                    if (std::cin.fail()) {
                        std::cin.clear();
                        std::cin.ignore(10000, '\n');
                        std::cout << RED << "Invalid value." << RESET << std::endl;
                    } else {
                        index = find(value);
                        if (index != -1) {
                            std::cout << RED << "Element " << value << " found at index " << index << RESET << std::endl;
                        } else {
                            std::cout << RED << "Element " << value << " not found in list" << RESET << std::endl;
                        }
                    }
                    break;

                case 8: // Get size
                    std::cout << "Doubly linked list size: " << size() << std::endl;
                    break;

                case 9: // Display forward
                    display();
                    break;

                case 10: // Display reverse
                    displayReverse();
                    break;

                case 11: // Clear
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