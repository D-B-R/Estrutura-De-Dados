#include"Arvore.h"

void inserir(pno *t, int dado)
{
    pno aux;
    if (*t == NULL)
    {
        aux = (pno) malloc(sizeof(NO));
        aux->info = dado;
        aux->esq = NULL;
        aux->dir = NULL;
        *t = aux;
    }
    else if ((*t)->info < dado)
    {
        inserir(&(*t)->dir, dado);
    }
    else
    {
        inserir(&(*t)->esq, dado);
    }
}

void imprime_em_ordem(pno *t)
{
    if ((*t) == NULL)
    {
        return;
    }
    imprime_em_ordem(&(*t)->esq);
    printf("\t%d", (*t)->info);
    imprime_em_ordem(&(*t)->dir);
}

void imprime_pre_ordem(pno *t)
{
    if ((*t) == NULL)
    {
        return;
    }
    printf("\t%d", (*t)->info);
    imprime_pre_ordem(&(*t)->esq);
    imprime_pre_ordem(&(*t)->dir);
}

void imprime_pos_ordem(pno *t)
{
    if ((*t) == NULL)
    {
        return;
    }
    imprime_pos_ordem(&(*t)->esq);
    imprime_pos_ordem(&(*t)->dir);
    printf("\t%d", (*t)->info);
}

pno* menor_direita(pno *t)
{
    if ((*t) == NULL)
    {
        return NULL;
    }
    if ((*t)->esq == NULL)
    {
        return t;
    }
    return menor_direita(&(*t)->esq);
}

void excluir(pno *t)
{
    if ((*t) == NULL)
    {
        return;
    }
    pno *sub = menor_direita(&(*t)->dir);
    if ((*sub) == NULL)
    {
        (*sub) = (*t);
        (*t) = (*t)->esq;
        free(*sub);
        *sub = NULL;
        return;
    }
    (*t)->info = (*sub)->info;
    if ((*sub)->esq == NULL && (*sub)->dir == NULL)
    {
        free(*sub);
        *sub = NULL;
        return;
    }
    excluir(sub);
}
