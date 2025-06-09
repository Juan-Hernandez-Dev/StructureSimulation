#pragma once
#include <string>
#include <vector>
#include <functional>

class Menu {
private:
    struct MenuItem {
        std::string text;
        std::function<void()> action;
    };
    
    std::vector<MenuItem> items;
    std::string title;
    int selected = 0;
    
    void clearScreen();
    void waitForEnter();
    
public:
    Menu(const std::string& title);
    
    void addItem(const std::string& text, std::function<void()> action);
    void display();
    void run();
};
