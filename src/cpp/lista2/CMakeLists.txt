cmake_minimum_required(VERSION 4.0.0)
project(lista2 LANGUAGES CXX)

set(CMAKE_CXX_COMPILER "clang++-20")
#set(CMAKE_C_COMPILER "clang")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "a9e1cf81-9932-4810-974b-6eccaf14e457")
set(CMAKE_CXX_MODULE_STD 1)

#target_sources(deck  PUBLIC  FILE_SET CXX_MODULES FILES   deck/deck.cppm)

add_library(deck STATIC     deck/deck.cpp deck/deck.h)
target_sources(deck  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/deck)

add_executable(main main.cpp)
target_link_libraries(main PRIVATE deck)

set_property(TARGET main PROPERTY CXX_STANDARD 23)
set_property(TARGET main PROPERTY CXX_STANDARD_REQUIRED ON)