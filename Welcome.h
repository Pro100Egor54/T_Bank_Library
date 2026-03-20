//
// Created by nikit on 21.03.2026.
//

#ifndef T_BANK_LIBRARY_WELCOME_H
#define T_BANK_LIBRARY_WELCOME_H
#include <fstream>
#include <string>

inline void Welcome() {
    std::string line;

    std::ifstream in("img.txt"); // окрываем файл для чтения
    if (in.is_open())
    {
        while (std::getline(in, line))
        {
            std::cout << line << std::endl;
        }
    }
    in.close();     // закрываем файл
}

#endif //T_BANK_LIBRARY_WELCOME_H