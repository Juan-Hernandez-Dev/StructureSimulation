# Data Structures Simulator

A C++ console application that demonstrates various data structures and their operations through an interactive menu-driven interface.

## Features

- **Stack**: Implementation of stack data structure with push, pop, peek, and other operations
- **Queue**: Implementation of queue data structure with enqueue, dequeue, and other operations
- **Linked List**: Implementation of singly linked list with various operations
- **Doubly Linked List**: Implementation of doubly linked list with bidirectional traversal
- **Circular Linked List**: Implementation of circular linked list
- **Binary Tree**: Implementation of binary tree with insert, delete, and traversal operations

## Prerequisites

- Windows operating system
- MinGW-w64 (GCC for Windows) installed and added to system PATH
- Basic knowledge of C++ programming

## Getting Started

### Compilation

1. Make sure you have MinGW-w64 installed and added to your system PATH
2. Open a command prompt in the project directory
3. Run the following command to compile the project:
   ```
   run.bat
   ```
   This will create a `build` directory and compile all source files into `build/program.exe`

### Running the Program

Once compiled, you can run the program without building executing:
```
.\build\program.exe
```

## Usage

1. The program will display a main menu with options for different data structures
2. Select a data structure by entering the corresponding number
3. Follow the on-screen instructions to perform various operations on the selected data structure
4. Use option 0 to return to the main menu or exit the program

## Project Structure

```
StructureSimulation/
├── include/               # Header files
│   └── utils.h            # Utility functions and color definitions
├── src/                   # Source files
│   ├── main.cpp           # Main program entry point
│   └── modules/           # Data structure implementations
│       ├── stack/
│       ├── queue/
│       ├── linked_list/
│       ├── doubly_linked_list/
│       ├── circular_linked_list/
│       └── binary_tree/
└── run.bat                # Build script
```

## Color Coding

The console interface uses color coding for better user experience:

- **Cyan**: Menu headers and titles
- **Red**: Error messages and warnings
- **Green**: Success messages and operation results
- **Yellow**: User prompts and information messages