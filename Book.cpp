//
// Created by nikit on 19.03.2026.
//

#include "Book.h"

#include <iostream>
#include <ostream>


Book::Book(std::string title, std::string author, Genre genre, unsigned publicationYear, std::string description) {
    title_ = title;
    author_ = author;
    genre_ = genre;
    inFavorites_ = false;
    wasRead_ = false;
    publicationYear_ = publicationYear;
    description_ = description;
}

void Book::AddToFavorites() {
    inFavorites_ = true;
}

void Book::ReadBook() {
    wasRead_ = true;
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

Book::Book() {
    std::cout << "Input book's title: " << std::endl;
    std::getline(std::cin, title_);

    std::cout << "Input book's author: " << std::endl;
    std::getline(std::cin, author_);

    std::cout << "Choose book's genre: " << std::endl;
    for (auto genreName : GenreNames) {
        Genre genre = genreName.first;
        std::string name = genreName.second;
        std::cout << genre << ") " << name << std::endl;
    }
    int n;
    std::cin >> n;
    genre_ = static_cast<Genre>(n);

    std::cout << "Input year of publication: " << std::endl;
    std::cin >> publicationYear_;

    std::cout << "Input short description: " << std::endl;
    std::getline(std::cin, description_);
}

bool TitleCmp(Book book1, Book book2) {
    return book1.GetTitle() > book2.GetTitle();
}
bool AuthorCmp(Book book1, Book book2) {
    return book1.GetAuthor() > book2.GetAuthor();
}
bool PubYearCmp(Book book1, Book book2) {
    return book1.GetPubYear() > book2.GetPubYear();
}