//
// Created by nikit on 19.03.2026.
//

#ifndef T_BANK_LIBRARY_LIBRARY_H
#define T_BANK_LIBRARY_LIBRARY_H
#include <vector>
#include <string>
#include <iostream>
#include "Book.h"

class Library {
private:
    std::vector<Book> books = {};
public:
    Library();

    void AddBook();
    void RemoveBook();
    void BookList();


};


#endif //T_BANK_LIBRARY_LIBRARY_H