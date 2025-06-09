#include <iostream>
#include "cli/menu.h"
#include "backend/sum/sum.h"

void showSum() {
    int a, b;
    std::cout << "Enter first number: ";
    std::cin >> a;
    std::cout << "Enter second number: ";
    std::cin >> b;
    
    int result = sum(a, b);
    std::cout << "\n" << "Result: " << a << " + " << b << " = " << result << std::endl;
    
    std::cout << "\nPress Enter to continue...";
    std::cin.ignore();
    std::cin.get();
}

void exitProgram() {
    std::cout << "Exiting..." << std::endl;
}

int main() {
    Menu menu("Structure Simulation");
    
    // Add menu items with their corresponding actions
    menu.addItem("Sum Two Numbers", showSum);
    menu.addItem("Exit", exitProgram);
    
    // Start the menu
    menu.run();
    
    return 0;
}
