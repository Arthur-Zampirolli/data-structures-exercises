#ifndef ARVORE_BUSCA
#define ARVORE_BUSCA
#include <stdio.h>



struct NoBin {
    char chave;
    NoBin * esq;
    NoBin * dir;
};

auto insere(char chave, NoBin * no) -> void;
auto remove(NoBin * raiz, char dado) -> void;
auto imprime(NoBin * raiz) -> void;
auto estritaBin(NoBin * no) -> bool; //exercicio 1a
auto emNiveis(NoBin* no) -> void; //exercicio 1b
auto ehPerfeita(NoBin* no) -> bool; //exercicio 1c
auto ehCompleta(NoBin* no) -> bool;
auto altura(NoBin* no); //exercicio 1e
auto buscaNo(NoBin* no);//auxiliar exercicio 1e
auto aloca(char c) -> NoBin*;
auto maior(NoBin* no) -> char;
auto menor(NoBin* no) -> char;
auto ehBinariaBusca(NoBin* no) -> bool;
#endif