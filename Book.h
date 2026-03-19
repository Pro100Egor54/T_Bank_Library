//
// Created by nikit on 19.03.2026.
//

#ifndef T_BANK_LIBRARY_BOOK_H
#define T_BANK_LIBRARY_BOOK_H
#include <string>
#include "Genre.h"


class Book {
private:
    std::string title_;
    std::string author_;
    Genre genre_;
    unsigned publicationYear_;
    std::string description_;

    bool inFavorites_;
    bool wasRead_;

public:
    Book(std::string title, std::string author, Genre genre, unsigned publicationYear, std::string description);
    Book();

    void AddToFavorites();
    void ReadBook();

    std::string GetTitle() const;
    std::string GetAuthor() const;
    Genre GetGenre() const;
    unsigned GetPubYear() const;
    std::string GetDescription() const;
    bool IsInFavorites_() const;
    bool WasRead() const;
    void SaveBook();
};

bool TitleCmp(Book book1, Book book2);
bool AuthorCmp(Book book1, Book book2);
bool GenreCmp(Book book1, Book book2);

#endif //T_BANK_LIBRARY_BOOK_H