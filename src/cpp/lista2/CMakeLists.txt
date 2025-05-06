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

add_library(deck STATIC     deck/deck.cpp deck/deck.hpp)
target_sources(deck  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/deck)

add_library(exercicios STATIC     exercicios/exercicios.cpp exercicios/exercicios.hpp)
target_sources(exercicios  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/exercicios)

add_library(pilha2Filas STATIC     pilha2Filas/pilha2Filas.cpp pilha2Filas/pilha2Filas.hpp)
target_sources(pilha2Filas  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/pilha2Filas)

add_library(fila2P STATIC     fila2P/fila2P.cpp fila2P/fila2P.hpp)
target_sources(fila2P  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/fila2P)

add_library(fila STATIC     fila/fila.cpp fila/fila.hpp)
target_sources(fila  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/fila)

add_library(pilha STATIC     pilha/pilha.cpp pilha/pilha.hpp)
target_sources(pilha  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/pilha)

add_executable(main main.cpp)
target_link_libraries(main PRIVATE deck)
target_link_libraries(main PRIVATE exercicios)
target_link_libraries(main PRIVATE fila)
target_link_libraries(main PRIVATE pilha2Filas)
target_link_libraries(main PRIVATE fila2P)
target_link_libraries(main PRIVATE pilha)

set_property(TARGET main PROPERTY CXX_STANDARD 23)
set_property(TARGET main PROPERTY CXX_STANDARD_REQUIRED ON)