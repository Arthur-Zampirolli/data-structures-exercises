#include "exercicios.hpp"

void exercicio1a(){
    auto d = new Deque();
    d->insereInicio('a');
    d->insereFim('b');
    d->insereInicio('d');
    d->imprime();
    d->removeFim();
    d->imprime();
}

void exercicio1b(){
    auto pd = new PilhaDeque();
    pd->push('n');
    pd->imprime();
    pd->push('a');
    pd->push('t');
    pd->imprime();
    pd->pop();
    pd->imprime();
}

void exercicio2(){
    auto p2f = new Pilha2Filas();
    p2f->push('n');
    p2f->push('a');
    p2f->push('t');
    std::printf("Topo da p2f %c\n", p2f->topo()->dado);
    //p2f->pop();
    p2f->imprime();
}