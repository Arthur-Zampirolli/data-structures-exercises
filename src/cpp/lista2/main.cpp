
#include "deck/deck.hpp"
#include <iostream>
#include "stdlib.h"

int main(){
    auto d = new Deque();
    d->insereInicio('a');
    d->insereFim('b');
    d->insereInicio('d');
    d->imprime();
    d->removeFim();
    d->imprime();
    std::printf("Pilha deque section ... \n");
    auto pd = new PilhaDeque();

    pd->push('n');
    pd->imprime();
    pd->push('a');
    pd->push('t');
    pd->imprime();
    pd->pop();
    pd->imprime();
    return 0;
}