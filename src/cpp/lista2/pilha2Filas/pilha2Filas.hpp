#ifndef PILHA_2_FILAS
#define PILHA_2_FILAS
#include "../fila/fila.hpp"

struct Pilha2Filas{
    FilaDeque aux;
    FilaDeque p;
    auto push(char dado){
        aux.insere(dado);
    }
    auto pop(){
        transfere(-1);
        p.remove();
        transfere(1);      
    }
    auto topo(){
        return aux.fim();
    }
    void imprime(){
        aux.imprime();
    }
    private: 
        void transfere(int d){
            while(aux.N > 0 && d < 0){
                char c = aux.remove();
                std:: printf("Transferindo %c de aux pra p...\n", c);
                p.insere(c);
            }
            while(aux.N > 0 && d > 0){
                char c = p.remove();
                std:: printf("Transferindo %c de p pra aux...\n", c);
                aux.insere(c);
            }
        }
};

#endif