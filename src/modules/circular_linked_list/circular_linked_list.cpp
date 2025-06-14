#include "../../../include/utils.h"
#include "circular_linked_list.h"

// Constructor
CircularLinkedList::CircularLinkedList() : head(nullptr), listSize(0) {}

// Destructor
CircularLinkedList::~CircularLinkedList() {
    clear();
}

// Insert a new node with value x at the beginning of the list
void CircularLinkedList::insertFirst(int x) {
    CircularListNode* newNode = new CircularListNode(x);
    if (!head) {
        newNode->next = newNode;
        head = newNode;
    } else {
        CircularListNode* tail = head;
        while (tail->next != head) tail = tail->next;
        newNode->next = head;
        head = newNode;
        tail->next = head;
    }
    listSize++;
    std::cout << "Inserted " << x << " at the beginning" << std::endl;
}

// Insert a new node with value x at the end of the list
void CircularLinkedList::insertLast(int x) {
    CircularListNode* newNode = new CircularListNode(x);
    if (!head) {
        newNode->next = newNode;
        head = newNode;
    } else {
        CircularListNode* tail = head;
        while (tail->next != head) tail = tail->next;
        tail->next = newNode;
        newNode->next = head;
    }
    listSize++;
    std::cout << "Inserted " << x << " at the end" << std::endl;
}

// Remove and return the first node in the list, throws runtime_error if list is empty
void CircularLinkedList::deleteFirst() {
    if (!head) throw std::runtime_error("List is empty");

    int deletedValue = head->data;
    if (head->next == head) {
        delete head;
        head = nullptr;
    } else {
        CircularListNode* tail = head;
        while (tail->next != head) tail = tail->next;
        CircularListNode* temp = head;
        head = head->next;
        tail->next = head;
        delete temp;
    }
    listSize--;
    std::cout << "Deleted first element: " << deletedValue << std::endl;
}

// Remove and return the last node in the list, throws runtime_error if list is empty
void CircularLinkedList::deleteLast() {
    if (!head) throw std::runtime_error("List is empty");

    int deletedValue;
    if (head->next == head) {
        deletedValue = head->data;
        delete head;
        head = nullptr;
    } else {
        CircularListNode* prev = nullptr;
        CircularListNode* current = head;
        while (current->next != head) {
            prev = current;
            current = current->next;
        }
        deletedValue = current->data;
        prev->next = head;
        delete current;
    }
    listSize--;
    std::cout << "Deleted last element: " << deletedValue << std::endl;
}

// Insert a new node with value x at the specified index, throws out_of_range if index is invalid
void CircularLinkedList::insertAt(int x, int index) {
    if (index < 0 || index > listSize) throw std::runtime_error("Invalid index");
    if (index == 0) {
        insertFirst(x);
    } else if (index == listSize) {
        insertLast(x);
    } else {
        CircularListNode* newNode = new CircularListNode(x);
        CircularListNode* prev = getNodeAt(index - 1);
        newNode->next = prev->next;
        prev->next = newNode;
        listSize++;
        std::cout << "Inserted " << x << " at index " << index << std::endl;
    }
}

// Remove and return the node at the specified index, throws out_of_range if index is invalid
void CircularLinkedList::deleteAt(int index) {
    if (!isValidIndex(index)) throw std::runtime_error("Invalid index");
    if (index == 0) {
        deleteFirst();
    } else {
        CircularListNode* prev = getNodeAt(index - 1);
        CircularListNode* toDelete = prev->next;
        int deletedValue = toDelete->data;
        prev->next = toDelete->next;
        delete toDelete;
        listSize--;
        std::cout << "Deleted element " << deletedValue << " at index " << index << std::endl;
    }
}

// Find the first occurrence of x in the list, returns index of x if found, -1 otherwise
int CircularLinkedList::find(int x) {
    if (!head) return -1;
    CircularListNode* current = head;
    int index = 0;
    do {
        if (current->data == x) return index;
        current = current->next;
        index++;
    } while (current != head);
    return -1;
}

// Get the number of nodes in the list
int CircularLinkedList::size() {
    return listSize;
}

// Remove all nodes from the list
void CircularLinkedList::clear() {
    while (listSize > 0) deleteFirst();
    std::cout << "Circular linked list cleared" << std::endl;
}

// Check if the list is properly circular, returns true if the list is circular, false otherwise
bool CircularLinkedList::isCircular() {
    if (!head) return false;
    CircularListNode* current = head->next;
    while (current && current != head) current = current->next;
    return current == head;
}

// Display the contents of the list
void CircularLinkedList::display() {
    if (!head) {
        std::cout << "Circular linked list is empty" << std::endl;
        return;
    }
    std::cout << "List contents: ";
    CircularListNode* current = head;
    int index = 0;
    do {
        std::cout << "[" << index++ << ":" << current->data << "] ";
        current = current->next;
    } while (current != head);
    std::cout << std::endl;
}

// Get the node at the specified index, throws out_of_range if index is invalid
CircularListNode* CircularLinkedList::getNodeAt(int index) {
    if (!isValidIndex(index)) return nullptr;
    CircularListNode* current = head;
    for (int i = 0; i < index; i++) current = current->next;
    return current;
}

// Check if the given index is valid, returns true if index is within bounds, false otherwise
bool CircularLinkedList::isValidIndex(int index) {
    return index >= 0 && index < listSize;
}

// Display the menu of available operations
void CircularLinkedList::displayMenu() {
    std::cout << CYAN << "CIRCULAR LINKED LIST OPERATIONS" << RESET << std::endl;
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
    std::cout << "11. Check if circular" << std::endl;
    std::cout << "0. Back to main menu" << std::endl;
    std::cout << "Select operation: ";
}

// Handle user interaction for circular linked list operations
void CircularLinkedList::handleCircularLinkedListOperations() {
    int choice, value, index;
    cls();

    do {
        displayMenu();
        std::cin >> choice;
        cls();
        std::cout << CYAN << "Selected option: " << choice << RESET << std::endl;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << RED << "Invalid input. Try again." << RESET << std::endl;
            continue;
        }

        try {
            switch (choice) {
                case 1:
                    std::cout << "Enter value to insert: "; std::cin >> value;
                    insertFirst(value);
                    break;
                case 2:
                    std::cout << "Enter value to insert: "; std::cin >> value;
                    insertLast(value);
                    break;
                case 3:
                    std::cout << "Enter value to insert: "; std::cin >> value;
                    std::cout << "Enter index (0 to " << listSize << "): "; std::cin >> index;
                    insertAt(value, index);
                    break;
                case 4:
                    deleteFirst();
                    break;
                case 5:
                    deleteLast();
                    break;
                case 6:
                    std::cout << "Enter index to delete (0 to " << (listSize-1) << "): "; std::cin >> index;
                    deleteAt(index);
                    break;
                case 7:
                    std::cout << "Enter value to find: "; std::cin >> value;
                    index = find(value);
                    if (index != -1) std::cout << "Found at index " << index << std::endl;
                    else std::cout << "Not found." << std::endl;
                    break;
                case 8:
                    std::cout << "List size: " << size() << std::endl;
                    break;
                case 9:
                    display();
                    break;
                case 10:
                    clear();
                    break;
                case 11:
                    std::cout << (isCircular() ? "List is circular." : "List is not circular.") << std::endl;
                    break;
                case 0:
                    std::cout << "Returning to main menu..." << std::endl;
                    break;
                default:
                    cls();
                    std::cout << RED << "Invalid choice." << RESET << std::endl;
                    break;
            }
        } catch (const std::exception& e) {
            cls();
            std::cout << RED << "Error: " << e.what() << RESET << std::endl;
        }

    } while (choice != 0);
}
