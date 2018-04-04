#include <stdio.h>
#include <stdlib.h>

typedef struct _nodo{
    int chave;
    int altura, nivel;
    int altdireita,altesquerda;
    struct _nodo *esq;
    struct _nodo *dir;
    struct _nodo *pai;
} TpNodo;
typedef struct _arvore{
    TpNodo *raiz;
    TpNodo *nodo;
} TpArvore;

void inserir(TpArvore *arvore){
    int valor;

    system("clear");
    printf("valor: ");
    scanf("%d",&valor);
    if(arvore->nodo->chave == -1){
        arvore->nodo->chave = valor;
    }else{
        while(arvore->nodo->chave != -1){
            if(valor > arvore->nodo->chave){
                arvore->nodo = arvore->nodo->dir;
            }
            else if(valor < arvore->nodo->chave){
                arvore->nodo = arvore->nodo->esq;
            }
        }
        arvore->nodo->chave = valor;
        if(arvore->nodo->esq == NULL && arvore->nodo->dir == NULL){
            //--------------------------- inicia o nodo esquerdo
            arvore->nodo->esq = (TpNodo*)malloc(sizeof(TpNodo));
            arvore->nodo->esq->pai = arvore->nodo;
            arvore->nodo->esq->altdireita = 0;
            arvore->nodo->esq->altesquerda = 0;
            arvore->nodo->esq->altura = 0;  //arrumar as de cima
            arvore->nodo->esq->nivel = arvore->nodo->nivel++;
            arvore->nodo->esq->esq = NULL;
            arvore->nodo->esq->dir = NULL;
            arvore->nodo->esq->chave = -1;
            //--------------------------- inicia o nodo direito
            arvore->nodo->dir = (TpNodo*)malloc(sizeof(TpNodo));
            arvore->nodo->dir->pai = arvore->nodo;
            arvore->nodo->dir->altdireita = 0;
            arvore->nodo->dir->altesquerda = 0;
            arvore->nodo->dir->altura = 0;  //arrumar as de cima
            arvore->nodo->dir->nivel = arvore->nodo->nivel++;
            arvore->nodo->dir->esq = NULL;
            arvore->nodo->dir->dir = NULL;
            arvore->nodo->dir->chave = -1;
        }
    }
    arvore->nodo = arvore->raiz;
    menu(arvore);
}
void menu(TpArvore *arvore){
    int opc;

    system("clear");
    printf("1-inserir um elemento\n2-listar os elementos inseridos\n0-sair\n");
    scanf("%d",&opc);
    switch(opc){
    case 1:
        inserir(arvore);
        break;
    case 2:
        //listar(arvore);
        break;
    case 0:
        printf("\nAte logo!");
        break;
    default:
        system("clear");
        printf("Opcao invalida!\n\n");
        aux(arvore);
    }
}
void aux(TpArvore *arvore){
    menu(arvore);
}
void inicia(TpArvore *arvore){
    //--------------------------- inicia a raiz
    arvore->raiz = (TpNodo*)malloc(sizeof(TpNodo));
    arvore->raiz->altura = 1;
    arvore->raiz->nivel = 0;
    arvore->raiz->altesquerda = 1;
    arvore->raiz->altdireita = 1;
    arvore->raiz->pai = NULL;
    arvore->raiz->chave = -1;
    //--------------------------- inicia o nodo esquerdo
    arvore->raiz->esq = (TpNodo*)malloc(sizeof(TpNodo));
    arvore->raiz->esq->pai = arvore->raiz;
    arvore->raiz->esq->altdireita = 0;
    arvore->raiz->esq->altesquerda = 0;
    arvore->raiz->esq->altura = 0;
    arvore->raiz->esq->nivel = 1;
    arvore->raiz->esq->esq = NULL;
    arvore->raiz->esq->dir = NULL;
    arvore->raiz->esq->chave = -1;
    //--------------------------- inicia o nodo direito
    arvore->raiz->dir = (TpNodo*)malloc(sizeof(TpNodo));
    arvore->raiz->dir->pai = arvore->raiz;
    arvore->raiz->dir->altdireita = 0;
    arvore->raiz->dir->altesquerda = 0;
    arvore->raiz->dir->altura = 0;
    arvore->raiz->dir->nivel = 1;
    arvore->raiz->dir->esq = NULL;
    arvore->raiz->dir->dir = NULL;
    arvore->raiz->dir->chave = -1;
    //---------------------------
    arvore->nodo = arvore->raiz;
}

int main(){
    TpArvore *arvore;

    arvore = (TpArvore*)malloc(sizeof(TpArvore));
    inicia(arvore);
    menu(arvore);
}
