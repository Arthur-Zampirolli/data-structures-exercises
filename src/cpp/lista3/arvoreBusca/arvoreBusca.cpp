#include "arvoreBusca.hpp"
#include <cctype>
#include <queue>
#include <cmath>
NoBin *aloca(char c)
{
    NoBin *no = new NoBin;
    no->chave = c;
    no->dir = no->esq = nullptr;
    return no;
}

auto preordem(NoBin* no) -> void{
    if(!no) return;
    ::printf(" %c ", no->chave);
    preordem(no->esq);
    preordem(no->dir);
}
auto posordem(NoBin* no) -> void{
    if(!no) return;
    preordem(no->esq);
    preordem(no->dir);
    ::printf(" %c ", no->chave);

}
auto inorder(NoBin* no) -> void{
    if(!no) return;
    preordem(no->esq);
    ::printf(" %c ", no->chave);
    preordem(no->dir);
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

    imprime(raiz->esq);
    imprime(raiz->dir);
    ::printf("%c ", raiz->chave);


}
auto estritaBin(NoBin *no) -> bool
{
    return false;
}
auto emNiveis(NoBin *no) -> void
{
    std::queue<NoBin*> fila;
    fila.push(no);
    int nivel = 0;
    int i = 0;
    while(!fila.empty()){
        NoBin* temp = fila.front();
        fila.pop();
        if(!temp){
            ::printf(" * ");
        }
        else{
            ::printf(" %c", temp->chave);
            fila.push(temp->esq);
            fila.push(temp->dir);
        }
    }
    ::printf("\n");
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

auto busca(char chave, NoBin *no) -> char {
    //return '\0';
    if(!no) return '\0';
    else if(no->chave == chave) return chave;
    else if(chave > no->chave){
        return busca(chave, no->dir);
    }
    else if(chave < no->chave){
        return busca(chave, no->esq);
    }
}

auto altura(NoBin *no) -> int
{
    if (!no)
        return 0;
    int dir = altura(no->dir);
    int esq = altura(no->esq);
    if(dir > esq){
        return dir + 1;
    }else{
        return esq + 1;
    }
}
auto anterior(char chave, NoBin* no) -> char{
    
    if(!no) return '\0';
    if(no->dir){
        if(no->dir->chave == chave) return no->chave;
    }
    if(no->esq){
        if(no->esq->chave == chave) return no->chave;
    }
    if(chave < no->chave){
        return anterior(chave, no->esq);
    }
    else{
        return anterior(chave, no->dir);
    }
    return '\0';
}
auto posterior(char chave, NoBin* no) -> char{
    if(!no) return '\0';
    if(!no->dir) return '\0';
    if(no->chave == chave) return no->dir->chave;
    if(chave < no->chave){
        return posterior(chave, no->esq);
    }
    else{
        return posterior(chave, no->dir);
    }
    return '\0';
}