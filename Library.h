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
    std::vector<Book> bookList_ = {};
    std::vector<std::reference_wrapper<Book>> favorites_ = {};
public:
    Library() {};

    bool ListOut(bool (*cmp)(const Book &, const Book &), std::pair<bool, Genre> genreFiltr,
                 std::pair<bool, bool> wasReadFiltr) const;
    void ListOutWihtChoice() const;
    void AddBook();
    void RemoveBook();
    void AddBookToFavorites();
    void MarkAsRead();
    std::vector<std::reference_wrapper<Book>> GetFavorites();
    std::vector<Book> Search(const std::string& substr) const;
    void PrintSearch();
    void UpdateFavorites();
    void UpdateRecPoints() const;
    std::vector<Book> Recomends() const;
    void PrintRecomends() const;
    bool Action();
    void UpdateId();

    void Save() const;
    int Load();
};

#endif //T_BANK_LIBRARY_LIBRARY_H