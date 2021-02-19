#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct no_arvore
{
    int info;
    struct no_arvore *esq;
    struct no_arvore *dir;
} NO, *pno;

//prototipação

void inserir(pno*, int);
void imprime_em_ordem(pno*);
void imprime_pre_ordem(pno*);
void imprime_pos_ordem(pno*);

#endif // ARVORE_H_INCLUDED
