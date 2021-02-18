#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef char tipo_elem;

typedef struct no *pno;

typedef struct no
{
    tipo_elem info;
    pno esq;
    pno dir;
} NO;

typedef pno tree;

// prototipação

void define(tree*);
void cria_raiz(tree*, tipo_elem);
int altura(tree);
int numeroNos(tree);
int inserirNo(tree*, tipo_elem, int);
void exibirArvore(tree);

#endif // ARVORE_H_INCLUDED
