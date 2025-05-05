#include "stdio.h"
#include "stdlib.h"
#include <string.h>

typedef struct node{
    struct node * next;
    int data;
}Node;

typedef struct deck{
    struct node * first;
    struct node * last;
    int N;
}Deck;

typedef struct pessoa {
    char nome[20];
    unsigned int idade;
    char *cpf;
}Pessoa; 

int main(){
    printf("tamanho de double %lu bytes\n", sizeof(double));
    printf("tamanho de float %lu bytes\n", sizeof(float));
    printf("tamanho de char %lu bytes\n", sizeof(short));
    // int    x1 = 5;        // => 5
    // int    x2 = x1 + 10;  // => 15
    // int    x3 = x2 / 2;   // => 7
    // float  x4 = x2 / 2;   // => 7.0
    // float  x5 = x2 / 2.0;
    // printf("%d %d %d\n", x1, x2, x3);
    // printf("%f %f\n", x4, x5);
    //agregado homogeneo
    char matriz[2][2]={{'a','b'},{'c','d'}};
    //agregado heterogeneo
    Pessoa *p = malloc(sizeof(Pessoa));//alocação da estrutura
    char nome[20];
    char *n = "Arthur";
    int size = strlen(n);
    strcpy(p->nome, n);
    p->idade = 27;
    p->cpf = "12345678613";
    
    for(int i = 0; i<size; i++)
        printf("%c", p->nome[i]);
    printf("\n");
    for(int i = 0; i < 11; i++)
        printf("%c", p->cpf[i]);
    return 0;
}