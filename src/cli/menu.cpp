#include "menu.h"
#include <iostream>
#include <conio.h>
#include <windows.h>

// ANSI color codes
#define RESET "\033[0m"
#define CYAN "\033[36m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#define RED "\033[31m"

void Menu::clearScreen() {
    system("cls");
}

void Menu::waitForEnter() {
    std::cout << "\n" << YELLOW << "Press Enter to continue..." << RESET << std::endl;
    std::cin.ignore();
    std::cin.get();
}

Menu::Menu(const std::string& title) : title(title) {}

void Menu::addItem(const std::string& text, std::function<void()> action) {
    items.push_back({text, action});
}

void Menu::display() {
    clearScreen();
    std::cout << GREEN << title << RESET << std::endl;
    
    for (int i = 0; i < items.size(); ++i) {
        if (i == selected)
            std::cout << CYAN << " > " << items[i].text << RESET << std::endl;
        else
            std::cout << "   " << items[i].text << std::endl;
    }
}

void Menu::run() {
    int key;
    while (true) {
        display();
        key = _getch();

        if (key == 224) {  // Arrow key
            key = _getch();
            if (key == 72)  // Up
                selected = (selected - 1 + items.size()) % items.size();
            else if (key == 80)  // Down
                selected = (selected + 1) % items.size();
        } 
        else if (key == 13) {  // Enter
            clearScreen();
            items[selected].action();
            if (selected == items.size() - 1) break; // Exit if last item was selected
        }
    }
}
