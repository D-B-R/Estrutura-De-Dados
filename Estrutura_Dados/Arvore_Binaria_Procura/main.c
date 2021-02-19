#include"Arvore.h"

int main()
{
    pno Raiz = NULL;
    int nums[] = {30, 10, 15, 5, 40, 13, 12, 210, 20, 25, 16};
    int i;
    for (i = 0; i < sizeof(nums) / sizeof(int);i ++)
    {
        inserir(&Raiz, nums[i]);
    }
    imprime_em_ordem(&Raiz);
    printf("\n");
    excluir(&Raiz->esq->esq);
    imprime_em_ordem(&Raiz);
    return 0;
}
