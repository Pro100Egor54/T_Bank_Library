cmake_minimum_required(VERSION 4.1)
project(T_Bank_Library)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(.idea)

add_executable(T_Bank_Library
        .idea/.gitignore
        .idea/workspace.xml
        main.cpp
        Book.cpp
        Book.h
        Library.cpp
        Library.h
        Genre.h
        Welcome.h
)
