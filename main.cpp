//
// Created by nikit on 19.03.2026.
//
#include <iostream>
#include "Book.h"
#include "Library.h"

int main() {
    Library library;
    std::cout << "Welcome to yout personal library!" << std::endl;
    try {
        int a = library.Load();
        std::cout << "Library loaded successfully (code " << a << "): " << std::endl;
    }
    catch (...) {
        std::cout << "Failed to load the library from the file." << std::endl
        << "Your library will be created from scratch." << std::endl;
    }

    bool workContinue = true;
    while (workContinue) {
        workContinue = library.Action();
    }
    return 0;
}