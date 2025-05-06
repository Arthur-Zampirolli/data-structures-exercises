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
    auto p2f = new Pilha2F();
    p2f->push('n');
    p2f->push('a');
    p2f->push('t');
    p2f->push('a');
    p2f->push('l');
    p2f->push('i');
    p2f->push('a');
    p2f->imprime();
    std::printf("Topo da p2f %c\n", p2f->topo()->dado);
    p2f->pop();
    p2f->imprime();
    std::printf("Topo da p2f %c\n", p2f->topo()->dado);
    p2f->pop();
    p2f->imprime();
}

void exercicio3(){
    auto f2p = new Fila2P();
    f2p->enfileira('n');
    f2p->enfileira('a');
    f2p->enfileira('t');
    f2p->enfileira('a');
    f2p->enfileira('l');
    f2p->enfileira('i');
    f2p->enfileira('a');
    std::printf("frente da f2p %c\n", f2p->frente());
    f2p->imprime();
    f2p->desenfileira();
    std::printf("frente da f2p %c\n", f2p->frente());
    f2p->imprime();
    f2p->enfileira('a');
    f2p->enfileira('b');
    f2p->enfileira('c');
    f2p->imprime();
    f2p->desenfileira();
    f2p->imprime();
}