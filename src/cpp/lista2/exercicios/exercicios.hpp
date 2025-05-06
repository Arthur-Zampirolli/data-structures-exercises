#ifndef EXERCICIOS
#define EXERCICIOS
#include "../deck/deck.hpp"
#include "../pilha2Filas/pilha2Filas.hpp"
#include "../fila2P/fila2P.hpp"
#include <stack>
#include <queue>

void exercicio1a();
void exercicio1b();
void exercicio2();
void exercicio3();
void exercicio4a();
void exercicio4b();
void exercicio4c();
void exercicio5();
void exercicio6();
void exercicio7();


/*funcoes auxiliares dos exercicios 4 pra frente*/
void imprimeStack(stack<char> p);
void inverte4a(stack<char>*s);
void inverte4b(stack<char>*s);
void inverte4c(stack<char>*s);
void fillQueue(stack<char>*s, stack<char> *p);
#endif