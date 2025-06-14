#include "queue.h"

// Constructor
Queue::Queue() : frontNode(nullptr), rearNode(nullptr), queueSize(0) {}

// Destructor
Queue::~Queue() {
    clear();
}

// Enqueue: Add element to rear of queue
void Queue::enqueue(int x) {
    QueueNode* newNode = new QueueNode(x);

    if (isEmpty()) {
        frontNode = rearNode = newNode;
    } else {
        rearNode->next = newNode;
        rearNode = newNode;
    }

    queueSize++;
    std::cout << "Enqueued " << x << " to queue" << std::endl;
}

// Dequeue: Remove and return front element
int Queue::dequeue() {
    if (isEmpty()) {
        throw std::runtime_error("Queue underflow: Cannot dequeue from empty queue");
    }

    QueueNode* temp = frontNode;
    int dequeuedValue = frontNode->data;
    frontNode = frontNode->next;

    // If queue becomes empty after dequeue
    if (frontNode == nullptr) {
        rearNode = nullptr;
    }

    delete temp;
    queueSize--;

    return dequeuedValue;
}

// Front: Return front element without removing it
int Queue::front() {
    if (isEmpty()) {
        throw std::runtime_error("Queue is empty: Cannot get front element");
    }
    return frontNode->data;
}

// Check if queue is empty
bool Queue::isEmpty() {
    return frontNode == nullptr;
}

// Get queue size
int Queue::size() {
    return queueSize;
}

// Clear all elements from queue
void Queue::clear() {
    while (!isEmpty()) {
        QueueNode* temp = frontNode;
        frontNode = frontNode->next;
        delete temp;
    }
    rearNode = nullptr;
    queueSize = 0;
    std::cout << "Queue cleared" << std::endl;
}

// Display queue contents
void Queue::display() {
    if (isEmpty()) {
        std::cout << "Queue is empty" << std::endl;
        return;
    }

    std::cout << "Queue contents (front to rear): ";
    QueueNode* current = frontNode;
    while (current != nullptr) {
        std::cout << current->data;
        if (current->next != nullptr) {
            std::cout << " -> ";
        }
        current = current->next;
    }
    std::cout << std::endl;
}

// Display queue operations menu
void Queue::displayMenu() {
    std::cout << "\n--- QUEUE OPERATIONS ---" << std::endl;
    std::cout << "1. Enqueue element" << std::endl;
    std::cout << "2. Dequeue element" << std::endl;
    std::cout << "3. Front element" << std::endl;
    std::cout << "4. Check if empty" << std::endl;
    std::cout << "5. Get size" << std::endl;
    std::cout << "6. Display queue" << std::endl;
    std::cout << "7. Clear queue" << std::endl;
    std::cout << "0. Back to main menu" << std::endl;
    std::cout << "Select operation: ";
}

// Handle queue operations with user interaction
void Queue::handleQueueOperations() {
    int choice;
    int value;

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
                case 1: // Enqueue
                    std::cout << "Enter value to enqueue: ";
                    std::cin >> value;
                    if (std::cin.fail()) {
                        std::cin.clear();
                        std::cin.ignore(10000, '\n');
                        std::cout << "Invalid value." << std::endl;
                    } else {
                        enqueue(value);
                    }
                    break;

                case 2: // Dequeue
                    value = dequeue();
                    std::cout << "Dequeued value: " << value << std::endl;
                    break;

                case 3: // Front
                    value = front();
                    std::cout << "Front element: " << value << std::endl;
                    break;

                case 4: // Is Empty
                    if (isEmpty()) {
                        std::cout << "Queue is empty" << std::endl;
                    } else {
                        std::cout << "Queue is not empty" << std::endl;
                    }
                    break;

                case 5: // Size
                    std::cout << "Queue size: " << size() << std::endl;
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
                    std::cout << "Invalid option. Please try again." << std::endl;
                    break;
            }
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }

    } while (choice != 0);
}