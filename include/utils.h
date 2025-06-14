#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <limits>

// Definiciones de colores
#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

// Función para limpiar la pantalla
inline void cls() {
    system("cls");
}

// Función para limpiar el buffer de entrada
inline void clearBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

#endif // UTILS_H
