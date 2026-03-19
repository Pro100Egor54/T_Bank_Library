//
// Created by nikit on 19.03.2026.
//

#ifndef T_BANK_LIBRARY_GENRE_H
#define T_BANK_LIBRARY_GENRE_H
#include <map>

enum Genre {
    Action_and_adventure=1,
    Detective=2,
    Sci_fi=3,
    Historical_fiction=4,
    Dystopia=5,
    Fantasy=6,
    Romance_novel=7,
    Short_stories=8,
    Western=9,
    Horror=10,
    Classic=11,
    Fairy_tale=12,
    Fan_fiction=13,
    True_crime=14,
    How_to_books=15,
    Science_writing=16,
    Travel_writing=17,
    Creative_non_fiction=18,
    Essay=19,
    Biography_и_Autobiography=20,
    Memoir=21,
};

const std::map<Genre, std::string> GenreNames = {
    {Action_and_adventure, "Action_and_adventure"},
    {Detective, "Detective"},
    {Sci_fi, "Sci_fi"},
    {Historical_fiction, "Historical_fiction"},
    {Dystopia, "Dystopia"},
    {Fantasy, "Fantasy"},
    {Romance_novel, "Romance_novel"},
    {Short_stories, "Short_stories"},
    {Western, "Western"},
    {Horror, "Horror"},
    {Classic, "Classic"},
    {Fairy_tale, "Fairy_tale"},
    {Fan_fiction, "Fan_fiction"},
    {True_crime, "True_crime"},
    {How_to_books, "How_to_books"},
    {Science_writing, "Science_writing"},
    {Travel_writing, "Travel_writing"},
    {Creative_non_fiction, "Creative_non_fiction"},
    {Essay, "Essay"},
    {Biography_и_Autobiography, "Biography_и_Autobiography"},
    {Memoir, "Memoir"},
};

#endif //T_BANK_LIBRARY_GENRE_H