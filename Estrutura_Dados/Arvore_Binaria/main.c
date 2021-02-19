#include"Arvore.h"

int main()
{
    tree raiz;
    define(&raiz);
    cria_raiz(&raiz, 'a');
    inserirNo(&raiz, 'b', 0);
    inserirNo(&raiz, 'c', 1);
    inserirNo(&raiz->dir, 'e', 0);
    inserirNo(&raiz->dir->esq, 'g', 1);
    exibirArvore(raiz);
    return 0;
}
