#include "arvoreBusca.hpp"
#include <cctype>

NoBin *aloca(char c)
{
    NoBin *no = new NoBin;
    no->chave = c;
    no->dir = no->esq = nullptr;
    return no;
}

auto maior(NoBin *no) -> char
{
    NoBin *temp = no;
    char maior = '\0';
    if(no){
        if(isupper(no->chave)) maior = no->chave;
    }
    while(temp){
        ::printf("iterando...\n");
        if(isupper(temp->chave)){
            ::printf("maior %c\n", maior);
            maior = temp->chave;
            temp = temp->dir;
        }else{
            temp = temp->esq;
        }
    }
    return maior;
}
auto menor(NoBin *no) -> char
{
    NoBin *temp = no;
    char menor = '\0';
    if(no){
        if(isupper(no->chave)) menor = no->chave;
    }
    while(temp){
        ::printf("iterando...\n");
        if(isupper(temp->chave)){
            ::printf("menor %c\n", menor);
            menor = temp->chave;
            temp = temp->esq;
        }else{
            temp = temp->esq;
        }
    }
    return menor;
}

auto insere(char chave, NoBin *raiz) -> void
{

    ::printf("Inserindo chave=%c na árvore...\n", chave);
    if (!raiz)
    {
        raiz = aloca(chave);
    }
    else
    {
        if (chave > raiz->chave)
        {
            if (raiz->dir == nullptr)
            {
                raiz->dir = aloca(chave);
            }
            else
            {
                insere(chave, raiz->dir);
            }
        }
        if (chave <= raiz->chave)
        {
            if (raiz->esq == nullptr)
            {
                raiz->esq = aloca(chave);
            }
            else
            {
                insere(chave, raiz->esq);
            }
        }
    }
}
auto remove(NoBin *raiz, char dado) -> void
{
    return;
}
auto imprime(NoBin *raiz) -> void
{
    if (!raiz)
        return;
    imprime(raiz->dir);
    ::printf("%c ", raiz->chave);
    imprime(raiz->esq);
}
auto estritaBin(NoBin *no) -> bool
{
    return false;
}
auto emNiveis(NoBin *no) -> void
{
}
auto ehPerfeita(NoBin *no) -> bool
{
    return false;
}
auto ehCompleta(NoBin *no) -> bool
{
    return false;
}

auto bstreeRequirements(NoBin*no) -> bool{
    //filhos n podem ser iguais
    //filhos de um lado devem ser > que os de outro
    if(no){
        if(no->dir && no->esq){
            if(no->esq->chave == no->dir->chave ) return false;
            if((no->esq->chave < no->chave && no->dir->chave < no->chave) || (no->esq->chave > no->chave && no->dir->chave > no->chave)) return false;
        }
    }
    return true;
}

auto ehBinariaBusca(NoBin* no) -> bool{
    if(!no) return true;
    return bstreeRequirements(no);
    ehBinariaBusca(no->dir);
    ehBinariaBusca(no->esq);
}


auto altura(NoBin *no)
{
    if (!no)
        return 0;
    return altura(no->dir) + 1;
    return altura(no->esq) + 1;
}
