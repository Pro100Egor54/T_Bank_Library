//
// Created by nikit on 19.03.2026.
//

#include "Library.h"
#include "algorithm"
#include "Book.h"
#include "Genre.h"
#include <limits>
#include <fstream>

bool Library::ListOut(bool (*cmp)(const Book &, const Book &), std::pair<bool, Genre> genreFiltr,
    std::pair<bool, bool> wasReadFiltr) const {
    bool typedAnthg = false;
    std::vector<Book> SortedBookList = bookList_;
    std::sort(SortedBookList.begin(), SortedBookList.end(), cmp);

    if (genreFiltr.first) {
        for (int i = 0; i < SortedBookList.size(); i++) {
            if (SortedBookList[i].GetGenre() != genreFiltr.second)
                SortedBookList.erase(SortedBookList.begin() + i);
        }
    }
    if (wasReadFiltr.first) {
        for (int i = 0; i < SortedBookList.size(); i++) {
            if (SortedBookList[i].WasRead() != wasReadFiltr.second)
                SortedBookList.erase(SortedBookList.begin() + i);
        }
    }

    for (int i = 0; i < SortedBookList.size(); i++) {
        Book book = SortedBookList[i];
        std::cout << book;
        typedAnthg = true;
    }

    return typedAnthg;
}

void Library::ListOutWihtChoice() const {
    int sortChoice;
    bool(*cmp)(const Book&, const Book&);
    std::cout << "Choice type of sorting list: " << std::endl;
    std::cout << "1. By the title: " << std::endl;
    std::cout << "2. By the author: " << std::endl;
    std::cout << "3. By the year of publication: " << std::endl;
    std::cin >> sortChoice;

    switch (sortChoice) {
        case 1:
            cmp = TitleCmp;
            break;
        case 2:
            cmp = AuthorCmp;
            break;
        case 3:
            cmp = PubYearCmp;
        default:
            std::cout << "Not a valid choice, used defualt sorting by title." << std::endl;
            cmp = TitleCmp;
            break;
    }

    int filtrChoice = 4;
    std::pair <bool, bool> wasReadFiltr = {false, false};
    std::pair <bool, Genre> genreFiltr = {false, Any};
    std::cout << "Add any filter from the following list or continue: " << std::endl;
    std::cout << "1. By the status of reading;" << std::endl;
    std::cout << "2. By the genre;" << std::endl;
    std::cout << "3. Continue;" << std::endl;
    std::cin >> filtrChoice;

    int readChoice = 0;
    switch (filtrChoice) {

        case 1:
            std::cout << "0. Print all books" << std::endl;
            std::cout << "1. Print read book" << std::endl;
            std::cout << "2. Print not read bool" << std::endl;
            std::cin >> readChoice;
            switch (readChoice) {
                case 1:
                    wasReadFiltr.first = true;
                    wasReadFiltr.second = true;
                    break;
                case 2:
                    wasReadFiltr.first = true;
                    wasReadFiltr.second = false;
                    break;
                case 0:
                    wasReadFiltr.first = false;
                    break;
                default:
                    std::cout << "Not a valid choice, filters not setted." << std::endl;
                    break;
            }
            break;

        case 2:
            genreFiltr.first = true;
            genreFiltr.second = ChooseGenre();
            break;

        case 3:
            ListOut(cmp, genreFiltr, wasReadFiltr);
            break;

        default:
            std::cout << "Invalid choice, filters not setted" << std::endl;
            bool typedAnthg = ListOut(cmp, genreFiltr, wasReadFiltr);
            if (!typedAnthg) std::cout << "Not found any book matching the filter." << std::endl;
            break;
    }
}

std::vector<Book> Library::GetFavorites() {
    return favorites_;
}

void Library::AddBook() {
    std::cout << "Adding book;" << std::endl;
    Book book = Book(int(bookList_.size()));
    bookList_.push_back(book);
    std::cout << "Book added successfully." << std::endl;
}

void Library::RemoveBook() {
    int bookId;
    std::cout << "Input ID of book, what you want to remove: " << std::endl;
    std::cin >> bookId;
    if (bookId < bookList_.size()) {
        bookList_.erase(bookList_.begin() + bookId);
        std::cout << "Book removed successfully." << std::endl;
    } else {
        std::cout << "Invalid book ID." << std::endl;
    }
}

void Library::AddBookToFavorites() {
    int bookId;
    std::cout << "Input ID of book, what you want to add in favorites: " << std::endl;
    std::cin >> bookId;
    try {
        Book& book = bookList_[bookId];
        if (!book.IsInFavorites_()) {
            book.AddToFavorites();
            favorites_.emplace_back(book);
            std::cout << "Book added in favorite successfully." << std::endl;
        } else {
            std::cout << "Book already is in favorites." << std::endl;
        }
    } catch (...) {
        std::cout << "Invalid book ID." << std::endl;
    }
}

void Library::MarkAsRead() {
    int bookId;
    int wasRead;
    std::cout << "Input ID of book, what you want to mark as read/not read: " << std::endl;
    std::cin >> bookId;
    std::cout << "1. Mark as READ;" << std::endl;
    std::cout << "0. Mark as NOTREAD;" << std::endl;
    std::cin >> wasRead;
    try {
        Book& book = bookList_[bookId];
        if (wasRead == 0 || wasRead == 1) {
            book.SetStatus(wasRead);
            std::cout << "Status setted successfully" << std::endl;
        } else std::cout << "Invalid input, status no changed!" << std::endl;
    } catch (...) {
        std::cout << "Invalid book ID." << std::endl;
    }
}

std::vector<Book> Library::Search(const std::string& substr) const{
    std::vector<Book> bookList = bookList_;
    for (int i = 0; i < bookList.size(); i++) {
        Book book = bookList[i];
        bool substrInTitle = book.GetTitle().find(substr) != -1;
        bool substrInAuthor = book.GetAuthor().find(substr) != -1;
        bool substrInDescription = book.GetDescription().find(substr) != -1;
        if (!(substrInTitle || substrInAuthor || substrInDescription)) {
            bookList.erase(bookList.begin() + i);
        }
    }
    return bookList;
}

void Library::PrintSearch() {
    std::string substr;
    std::cout << "Input substring,by what you want to search: " << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, substr);
    std::vector<Book> bookList = Search(substr);
    for (Book book : bookList) {
        std::cout << book;
    }
}

void Library::UpdateFavorites() {
    favorites_ = {};
    for (Book book : bookList_) {
        if (book.IsInFavorites_()) {
            favorites_.emplace_back(book);
        }
    }
}

void Library::UpdateRecPoints() {
    UpdateFavorites();
    for (Book& updatingBook : bookList_) {
        int recPoints = 0;
        for (Book& favoriteBook : favorites_) {
            recPoints += CalculateSimilarity(updatingBook, favoriteBook);
        }
        updatingBook.SetRecPoints(recPoints);
    }
}

std::vector<Book> Library::Recomends()  {
    std::vector<Book> recomends = bookList_;
    UpdateRecPoints();
    sort(recomends.begin(), recomends.end(), RecomendationCmp);
    return recomends;
}

void Library::PrintRecomends() {
    UpdateRecPoints();
    std::vector<Book> recomends = Recomends();
    bool typedAnthg = false;
    for (Book book : recomends) {
        if (book.GetRecPoints() != 0)
            std::cout << book;
            typedAnthg = true;
    }
    if (!typedAnthg) {std::cout << "We can't recommend anything, add more books and mark more books as favorites" << std::endl;}
}

bool Library::Action() {
    UpdateId();
    UpdateFavorites();
    int choice;
    std::cout << "Choose action from following list: " << std::endl;
    std::cout << "1. Add book;" << std::endl;
    std::cout << "2. Remove book;" << std::endl;
    std::cout << "3. Search book;" << std::endl;
    std::cout << "4. Add book to favorite;" << std::endl;
    std::cout << "5. Mark book as read/not read;" << std::endl;
    std::cout << "6. Print favorites list;" << std::endl;
    std::cout << "7. Print all books;" << std::endl;
    std::cout << "8. Print recomendation list;" << std::endl;
    std::cout << "9. Exit;" << std::endl;
    std::cout << " -> " << std::endl;

    //Tmp variables
    std::cin >> choice;
    std::string substr;
    std::vector<Book> bookList = Search(substr);
    bool typedAnthg = false;

    switch (choice) {
        case 1://"1. Add book;"
            AddBook();
            break;
        case 2://"2. Remove book;"
            RemoveBook();
            break;
        case 3://"3. Search book;"
            PrintSearch();
            break;
        case 4://"4. Add book to favorite;"
            AddBookToFavorites();
            break;
        case 5:
            MarkAsRead();
            break;
        case 6://"6. Print favorites list;"
            typedAnthg = false;
            for (Book book : favorites_) {
                std::cout << book;
                typedAnthg = true;
            }
            if (!typedAnthg) std::cout << "You have not got any book in favorites.";
            typedAnthg = false;
            break;
        case 7://"7. Print all books;"
            ListOutWihtChoice();
            break;
        case 8:
            PrintRecomends();
            break;
        case 9://"9. Exit;"
            Save();
            return false;
            break;
        default:
            std::cout << "Not a valid choice." << std::endl;
            break;
    }
    UpdateId();
    UpdateFavorites();
    return true;
}

void Library::UpdateId() {
    for (int i = 0; i < bookList_.size(); i++) {
        bookList_[i].SetId(i);
    }
}

void Library::Save() const{
    std::ofstream out;
    out.open("LibrarySave.txt");
    if (out.is_open())
    {
        for (Book book : bookList_) {
            if (out.is_open())
                book.PrintBookInfo(out);
            std::cout << "Book id(" << book.GetId() << ") has been written" << std::endl;
        }
    }
    if (out.is_open()) {
        out.close();
    }
    std::cout << "Library has been written" << std::endl;
}

int Library::Load() {
    std::ifstream in;
    in.open("LibrarySave.txt");
    if (in.is_open()) {
        std::string line;
        int id;
        while (in >> id) {
            in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            if (!(std::getline(in, line))) return -1;
            std::string title = line;

            if (!(std::getline(in, line))) return -2;
            std::string author = line;

            int n;
            if (!(in >> n)) return -3;
            Genre genre = static_cast<Genre>(n);
            in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            int publicationYear;
            if (!(in >> publicationYear)) return -4;
            in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            if (!(std::getline(in, line))) return -5;
            std::string description = line;

            int recPoints;
            if (!(in >> recPoints)) return -6;
            in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            bool inFavorites;
            if (!(in >> inFavorites)) return -7;
            in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            bool wasRead;
            if (!(in >> wasRead)) return -8;
            in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            Book book(title, author, genre,
                publicationYear, description, id,
                wasRead, inFavorites, recPoints);
            bookList_.push_back(book);
            if (inFavorites) {
                favorites_.push_back(book);
            }
        }
    }
    in.close();
    return 0;
}