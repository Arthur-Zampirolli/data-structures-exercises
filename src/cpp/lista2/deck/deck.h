#ifndef DECK
#define DECK
#include <iostream>
#include "stdlib.h"
using namespace std;


template <typename Agregado, typename Tipo>
concept DequeTAD = requires(Agregado a, Tipo t){ 
    // requer operação de consulta ao elemento 'inicio' 
    { a.inicio() }; 
    // requer operação de consulta ao elemento 'fim' 
    { a.fim() }; 
    // requer operação 'insereInicio' sobre tipo 't' 
    { a.insereInicio(t) }; 
    // requer operação 'insereFim' sobre tipo 't' 
    { a.insereFim(t) }; 
    // requer operação 'removeInicio' e retorna tipo 't' 
    { a.removeInicio() }; 
    // requer operação 'removeFim' e retorna tipo 't' 
    { a.removeFim() }; 
};

struct Deque{
    struct No {
        char dado;
        No* prox;
        No* ant;
        No(char d) : dado(d), prox(nullptr), ant(nullptr) {}
    };

    No* no_inicio;
    No* no_fim;
    int N;
    auto initDeque(){
        this->no_fim = this->no_inicio = nullptr;
        this->N = 0;
    }
    //complexidade O(1)
    auto inicio(){
        return this->no_inicio;
    }
    //complexidade O(1)
    auto fim(){
        return this->no_fim;
    }
    //complexidade O(1)
    auto insereInicio(char dado){
        std::printf("inserindo %c no inicio do deck...\n", dado);
        No *n = new No(dado);
        if(this->N == 0){
            this->no_inicio = this->no_fim = n;
            this->N++;
            return;
        }
        No *temp = this->no_inicio;
        temp->ant = n;
        n->prox = temp;
        this->no_inicio = n;
        this->N++;
        return;
    }
    //complexidade O(1)
    auto insereFim(char dado){
        std::printf("inserindo %c no fim do deck...\n", dado);
        No *n = new No(dado);
        if(this->N == 0){
            this->no_inicio = this->no_fim = n;
            this->N++;
            return;
        }
        No *temp = this->no_fim;
        n->ant = temp;
        temp->prox = n;
        this->no_fim = n;
        this->N++;
        return;
    }
    //complexidade O(1)
    auto removeFim(){
        std::printf("removendo %c do fim do deck...\n", this->no_fim->dado);
        No *dado = this->no_fim;
        this->N--;
        if(this->N == 0){
            this->no_fim = this->no_inicio = nullptr;
            free(dado);
            return;
        }
        this->no_fim = dado->ant;
        dado->ant->prox = nullptr;
        free(dado);
    }
    //complexidade O(1)
    auto removeInicio(){
        std::printf("removendo %c do inicio do deck...\n", this->no_inicio->dado);
        No *dado = this->no_inicio;
        this->N--;
        if(this->N == 0){
            this->no_fim = this->no_inicio = nullptr;
            free(dado);
            return;
        }
        this->no_inicio = dado->prox;
        dado->prox->ant = nullptr;
        free(dado);
    }
    //complexidade O(N)
    auto imprime(){
        No *i = this->no_inicio;
        std::printf("Imprimindo valores do deck...\n");
        while(i){
            std::printf("%c ",i->dado);
            i = i->prox;
        }
        std::printf("\n");
    }
};

//mesma complexidade do deque
struct PilhaDeque{
    Deque d;
    PilhaDeque(){
        //d = new Deque();
        d.initDeque();
    }
    auto top(){
        d.inicio();
    }
    auto push(char dado){
        d.insereInicio(dado);
    }
    auto pop(){
        d.removeInicio();
    }
    auto imprime(){
        d.imprime();
    }
};
//mesma complexidade do deque
struct FilaDeque{
    Deque d;
    FilaDeque(){
        d.initDeque();
    }
    auto insere(char dado){
        d.insereFim(dado);
    }
    auto remove(){
        d.removeInicio();
    }
    auto imprime(){
        d.imprime();
    }
};

#endif