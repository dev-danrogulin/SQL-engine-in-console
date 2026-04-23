cmake_minimum_required(VERSION 3.10)
project(MiniSQL)

set(CMAKE_CXX_STANDART 17)
set(CMAKE_CXX_STANDART_REQUIRED ON)

add_executable(MiniSQL
    main.cpp
    Table.cpp
    Database.cpp
    Printer.cpp
)