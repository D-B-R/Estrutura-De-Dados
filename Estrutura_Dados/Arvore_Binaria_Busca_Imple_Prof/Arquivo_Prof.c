#include <stdio.h>
#include <stdlib.h>

typedef struct no_arvore{
  struct no_arvore *esq;
  struct no_arvore *dir;
  int           info;
}NO, *pno;



void inserir(pno *t, int dado){
  
  pno novo=NULL;
  if (*t == NULL) {
    novo = (pno) malloc(sizeof(NO));
    if (novo == NULL){ printf("Meleca"); return;}
    novo->esq = NULL;
    novo->dir = NULL;
    novo->info = dado;
    *t=novo;
  }
 
  else if (dado < (*t)->info) {
     inserir(&((*t)->esq), dado);
  }
  else{
    
    if (dado > (*t)->info) {
       inserir(&((*t)->dir), dado);
    }
  }
}

void imprime_pre_ordem(pno *t){
    if((*t)==NULL) return;
    printf("\t%d", (*t)->info);
    imprime_pre_ordem(&(*t)->esq);
    imprime_pre_ordem(&(*t)->dir);
}


void imprime_em_ordem(pno *t){
    if((*t)==NULL) return;
    imprime_em_ordem(&(*t)->esq);
    printf("\t%d", (*t)->info);
    imprime_em_ordem(&(*t)->dir);
}


void imprime_pos_ordem(pno *t){
    if((*t)==NULL) return;
    imprime_pos_ordem(&(*t)->esq);
    imprime_pos_ordem(&(*t)->dir);
    printf("\t%d", (*t)->info);
}



void inicializa(pno *t){
   *t=NULL;
}


pno *minimo(pno *T){
    if(*T==NULL) return NULL;
    if((*T)->esq ==NULL ) return *T;
    return minimo(&(*T)->esq);
}

void remover(pno *raiz, int valor){
    pno aux;
    pno pai_aux=NULL;
    if(*raiz==NULL) return;
    
    if(valor < (*raiz)->info){
      remover(&((*raiz)->esq), valor);
    }else if(valor > (*raiz)->info){ 
      remover(&((*raiz)->dir), valor);
    }else{ // encontrou
     
      if( ((*raiz)->esq)!=NULL && ((*raiz)->dir)!=NULL ){
        
        aux = minimo(&(*raiz)->dir);
        (*raiz)->info = (aux->info);
        remover(&(*raiz)->dir, aux->info);
      }else{
         
         aux = *raiz;
        
         if(((*raiz)->esq)==NULL){
            
            *raiz = (*raiz)->dir;
          }
          else {
            
            *raiz = (*raiz)->esq;
          }
          free(aux);
       }
    }
}


int main()
{
    pno Raiz;

    inicializa(&Raiz);
    inserir(&Raiz, 30);
    inserir(&Raiz, 10);
    inserir(&Raiz, 15);
    inserir(&Raiz,  5);
    inserir(&Raiz, 40);
    inserir(&Raiz, 13);
    inserir(&Raiz, 12);
    inserir(&Raiz, 210);
    inserir(&Raiz, 20);
    inserir(&Raiz, 25);
    inserir(&Raiz, 16);




    
    printf("\n\n------em------\n\n");
    imprime_em_ordem(&Raiz);

    printf("\n\n-----pre-------\n\n");
    imprime_pre_ordem(&Raiz);

    printf("\n\n------pos------\n\n");
    imprime_pos_ordem(&Raiz);



    return 0;
}