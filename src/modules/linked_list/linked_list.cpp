#include "linked_list.h"

// Constructor
LinkedList::LinkedList() : head(nullptr), listSize(0) {}

// Destructor
LinkedList::~LinkedList() {
    clear();
}

// Insert at the beginning of the list
void LinkedList::insertFirst(int x) {
    ListNode* newNode = new ListNode(x);
    newNode->next = head;
    head = newNode;
    listSize++;
    std::cout << "Inserted " << x << " at the beginning" << std::endl;
}

// Insert at the end of the list
void LinkedList::insertLast(int x) {
    ListNode* newNode = new ListNode(x);

    if (head == nullptr) {
        head = newNode;
    } else {
        ListNode* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    listSize++;
    std::cout << "Inserted " << x << " at the end" << std::endl;
}

// Delete the first node
void LinkedList::deleteFirst() {
    if (head == nullptr) {
        throw std::runtime_error("List is empty: Cannot delete from empty list");
    }

    ListNode* temp = head;
    int deletedValue = head->data;
    head = head->next;
    delete temp;
    listSize--;

    std::cout << "Deleted first element: " << deletedValue << std::endl;
}

// Delete the last node
void LinkedList::deleteLast() {
    if (head == nullptr) {
        throw std::runtime_error("List is empty: Cannot delete from empty list");
    }

    if (head->next == nullptr) {
        // Only one element
        int deletedValue = head->data;
        delete head;
        head = nullptr;
        listSize--;
        std::cout << "Deleted last element: " << deletedValue << std::endl;
        return;
    }

    // Find the second-to-last node
    ListNode* current = head;
    while (current->next->next != nullptr) {
        current = current->next;
    }

    int deletedValue = current->next->data;
    delete current->next;
    current->next = nullptr;
    listSize--;

    std::cout << "Deleted last element: " << deletedValue << std::endl;
}

// Insert at specific index
void LinkedList::insertAt(int x, int index) {
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

    ListNode* newNode = new ListNode(x);
    ListNode* current = head;

    // Navigate to position index-1
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
    listSize++;

    std::cout << "Inserted " << x << " at index " << index << std::endl;
}

// Delete at specific index
void LinkedList::deleteAt(int index) {
    if (!isValidIndex(index)) {
        throw std::runtime_error("Invalid index: Index out of bounds");
    }

    if (index == 0) {
        deleteFirst();
        return;
    }

    ListNode* current = head;

    // Navigate to position index-1
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }

    ListNode* nodeToDelete = current->next;
    int deletedValue = nodeToDelete->data;
    current->next = nodeToDelete->next;
    delete nodeToDelete;
    listSize--;

    std::cout << "Deleted element " << deletedValue << " at index " << index << std::endl;
}

// Find element in the list (returns index, -1 if not found)
int LinkedList::find(int x) {
    ListNode* current = head;
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
int LinkedList::size() {
    return listSize;
}

// Clear all elements
void LinkedList::clear() {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
    listSize = 0;
    std::cout << "List cleared" << std::endl;
}

// Display list contents
void LinkedList::display() {
    if (head == nullptr) {
        std::cout << "List is empty" << std::endl;
        return;
    }

    std::cout << "List contents: ";
    ListNode* current = head;
    int index = 0;

    while (current != nullptr) {
        std::cout << "[" << index << ":" << current->data << "]";
        if (current->next != nullptr) {
            std::cout << " -> ";
        }
        current = current->next;
        index++;
    }
    std::cout << std::endl;
}

// Helper function to get node at specific index
ListNode* LinkedList::getNodeAt(int index) {
    if (!isValidIndex(index)) {
        return nullptr;
    }

    ListNode* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }

    return current;
}

// Helper function to validate index
bool LinkedList::isValidIndex(int index) {
    return index >= 0 && index < listSize;
}

// Display linked list operations menu
void LinkedList::displayMenu() {
    std::cout << "\n--- LINKED LIST OPERATIONS ---" << std::endl;
    std::cout << "1. Insert at beginning" << std::endl;
    std::cout << "2. Insert at end" << std::endl;
    std::cout << "3. Insert at index" << std::endl;
    std::cout << "4. Delete first" << std::endl;
    std::cout << "5. Delete last" << std::endl;
    std::cout << "6. Delete at index" << std::endl;
    std::cout << "7. Find element" << std::endl;
    std::cout << "8. Get size" << std::endl;
    std::cout << "9. Display list" << std::endl;
    std::cout << "10. Clear list" << std::endl;
    std::cout << "0. Back to main menu" << std::endl;
    std::cout << "Select operation: ";
}

// Handle linked list operations with user interaction
void LinkedList::handleLinkedListOperations() {
    int choice;
    int value, index;

    do {
        displayMenu();
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input. Please enter a number." << std::endl;
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
                        std::cout << "Invalid value." << std::endl;
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
                        std::cout << "Invalid value." << std::endl;
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
                        std::cout << "Invalid input." << std::endl;
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
                        std::cout << "Invalid input." << std::endl;
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
                        std::cout << "Invalid value." << std::endl;
                    } else {
                        index = find(value);
                        if (index != -1) {
                            std::cout << "Element " << value << " found at index " << index << std::endl;
                        } else {
                            std::cout << "Element " << value << " not found in list" << std::endl;
                        }
                    }
                    break;

                case 8: // Get size
                    std::cout << "List size: " << size() << std::endl;
                    break;

                case 9: // Display
                    display();
                    break;

                case 10: // Clear
                    clear();
                    break;

                case 0: // Back
                    std::cout << "Returning to main menu..." << std::endl;
                    break;

                default:
                    std::cout << "Invalid option. Please try again." << std::endl;
                    break;
            }
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }

    } while (choice != 0);
}