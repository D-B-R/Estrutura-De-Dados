#include"Arvore.h"

void define(tree *t)
{
    *t = NULL;
}

void cria_raiz(tree *t, tipo_elem item) 
{
    pno no = malloc(sizeof(no));
    no->esq = NULL;
    no->dir = NULL;
    no->info = item;
    *t = no;
}

int altura(tree r) 
{
    if (r == NULL) 
    {
        return 0;
    }
    int altE = altura(r->esq); 
    int altD = altura(r->dir); 
    if (altE > altD) 
    {
        return altE + 1;
    }
    return altD + 1;
}

int numeroNos(tree r)
{
    if (r == NULL) 
    {
        return 0;
    }
    int nE = numeroNos(r->esq); 
    int nR = numeroNos(r->dir); 
    return nE + nR + 1; 
}

int inserirNo(tree *r, tipo_elem item, int direc) 
{
    pno no = malloc(sizeof(no)); 
    no->esq = NULL;
    no->dir = NULL;
    no->info = item;
    pno aux = *r;
    if (direc == 0) 
    {
        if (aux->esq == NULL)
        {
            aux->esq = no;
        }
        else
        {
            return -1;
        }
    }
    else 
    {
        if (aux->dir == NULL)
        {
            aux->dir = no;
        }
        else
        {
            return -1;
        }
    }
    return 0;
}

void exibirArvore(tree r) 
{
    if (r != NULL)
    {
        printf(" %c\n", r->info);
        exibirArvore(r->esq);
        exibirArvore(r->dir);
    }
}
