//
// Created by nikit on 19.03.2026.
//

#include "Book.h"

#include <iostream>
#include <ostream>
#include <limits>


Book::Book(std::string title, std::string author, Genre genre,
    unsigned publicationYear, std::string description, int id,
    bool wasRead, bool inFavorites, int recPoints) {
    title_ = title;
    author_ = author;
    genre_ = genre;
    publicationYear_ = publicationYear;
    description_ = description;
    id_ = id;
    wasRead_ = wasRead;
    recPoints_ = recPoints;
    inFavorites_ = inFavorites;
}

void Book::AddToFavorites() {
    inFavorites_ = true;
}

void Book::Read() {
    wasRead_ = true;
}

void Book::SetRecPoints(int recPoints) {
    recPoints_ = recPoints;
}

void Book::SetId(int id) {
    id_ = id;
}

std::string Book::GetTitle() const {
    return title_;
}

std::string Book::GetAuthor() const {
    return author_;
}

Genre Book::GetGenre() const {
    return genre_;
}

unsigned Book::GetPubYear() const {
    return publicationYear_;
}

std::string Book::GetDescription() const {
    return description_;
}

bool Book::IsInFavorites_() const {
    return inFavorites_;
}

bool Book::WasRead() const {
    return wasRead_;
}

int Book::GetId() const {
    return id_;
}

int Book::GetRecPoints() const {
    return recPoints_;
}

Book::Book(int id) {
    id_ = id;
    std::cout << "Input book's title: " << std::endl;
    std::cin.ignore();
    std::getline(std::cin, title_);

    std::cout << "Input book's author: " << std::endl;
    std::getline(std::cin, author_);

    std::cout << "Choose book's genre: " << std::endl;
    genre_ = ChooseGenre();

    std::cout << "Input year of publication: " << std::endl;
    std::cin >> publicationYear_;

    std::cout << "Input short description: " << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, description_);
}

//Сходство книг вычисляется по количеству совпадающих характеристик;
int CalculateSimilarity(const Book& book1, const Book& book2) {
    int similarity = 0;
    if (book1.GetGenre() == book2.GetGenre()) similarity += 1;
    if (book1.GetAuthor() == book2.GetAuthor()) similarity += 1;
    if (abs(book1.GetPubYear() - book2.GetPubYear()) < 30 ) similarity += 1;
    // Сходство книги самой себе = 0, чтобы уже избранные не предлагались;
    if (book1.GetId() == book2.GetId()) similarity = 0;
    if (book1.IsInFavorites_() == book2.IsInFavorites_()) similarity = 0;
    if (book1.WasRead()) similarity = 0;
    return similarity;
}

bool TitleCmp(const Book& book1, const Book& book2) {
    return book1.GetTitle() > book2.GetTitle();
}
bool AuthorCmp(const Book& book1, const Book& book2) {
    return book1.GetAuthor() > book2.GetAuthor();
}
bool PubYearCmp(const Book& book1, const Book& book2) {
    return book1.GetPubYear() > book2.GetPubYear();
}

bool RecomendationCmp(const Book& book1, const Book& book2) {
    return book1.GetRecPoints() > book2.GetRecPoints();
}

std::ostream& operator << (std::ostream& out, Book& book) {
    return out << book.GetId() << "-id| "
        << book.GetTitle()
        << " by " << book.GetAuthor()
        << ", " << book.GetPubYear() << " year of publication"
        << std::endl;
}

std::ostream& Book::PrintBookInfo (std::ostream& out) {
    return out << id_ << std::endl
    << title_ << std::endl
    << author_ << std::endl
    << genre_ << std::endl
    << publicationYear_ << std::endl
    << description_ << std::endl
    << recPoints_ << std::endl
    << inFavorites_ << std::endl
    << wasRead_ << std::endl;
}