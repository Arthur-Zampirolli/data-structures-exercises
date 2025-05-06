#ifndef PILHA_2_FILAS
#define PILHA_2_FILAS
#include "../fila/fila.hpp"

struct Pilha2F{
    FilaDeque aux;
    FilaDeque p;
    auto push(char dado){
        aux.insere(dado);
    }
    //complexidade O(N)
    auto pop(){
        //tem que circular ela pra baixo
        int i = aux.N - 1;
        while(i >= 1){
            char c = aux.remove();
            aux.insere(c);
            i--;
        }
        aux.remove();
    }
    auto topo(){
        return aux.fim();
    }
    void imprime(){
        aux.imprimeFim();
    }
    auto tamanho(){
        return aux.N;
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