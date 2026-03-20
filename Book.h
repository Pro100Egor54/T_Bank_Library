//
// Created by nikit on 19.03.2026.
//

#ifndef T_BANK_LIBRARY_BOOK_H
#define T_BANK_LIBRARY_BOOK_H
#include <string>
#include "Genre.h"


class Book {
private:
    int id_ = 0;
    std::string title_;
    std::string author_;
    Genre genre_;
    unsigned publicationYear_{};
    std::string description_;
    int recPoints_ = 0;

    bool inFavorites_=false;
    bool wasRead_=false;

public:
    Book(std::string title, std::string author, Genre genre, unsigned publicationYear, std::string description, int id,
        bool wasRead, bool inFavorites, int recPoints);
    Book(int id);

    void AddToFavorites();
    void Read();
    void SetRecPoints(int recPoints);
    void SetId(int id);

    std::string GetTitle() const;
    std::string GetAuthor() const;
    Genre GetGenre() const;
    unsigned GetPubYear() const;
    std::string GetDescription() const;
    bool IsInFavorites_() const;
    bool WasRead() const;
    int GetId() const;
    int GetRecPoints() const;
    std::ostream& PrintBookInfo (std::ostream& out);
};

int CalculateSimilarity(const Book& book1, const Book& book2);

bool TitleCmp(const Book& book1, const Book& book2);
bool AuthorCmp(const Book& book1, const Book& book2);
bool PubYearCmp(const Book& book1, const Book& book2);
bool RecomendationCmp(const Book& book1, const Book& book2);

std::ostream& operator << (std::ostream& out, Book& book);

#endif //T_BANK_LIBRARY_BOOK_H