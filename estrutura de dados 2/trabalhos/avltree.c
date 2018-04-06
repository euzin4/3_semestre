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
    TpNodo *naux;
} TpArvore;

void inserir(TpArvore *arvore){
    int valor;

    system("cls");
    printf("valor: ");
    scanf("%d",&valor);
    if(arvore->nodo->chave == -1){
        system("cls");
        arvore->nodo->chave = valor;
    }else{
        while(arvore->nodo->chave != -1){
            if(valor > arvore->nodo->chave){
                system("cls");
                arvore->nodo = arvore->nodo->dir;
            }
            else if(valor < arvore->nodo->chave){
                system("cls");
                arvore->nodo = arvore->nodo->esq;
            }
            else if(valor == arvore->nodo->chave){
                system("cls");
                printf("Numero ja inserido!\n\n");
                break;
            }
        }
        arvore->nodo->chave = valor;
        if(arvore->nodo->esq == NULL && arvore->nodo->dir == NULL){
            //--------------------------- inicia o nodo sentinela esquerdo
            arvore->nodo->esq = (TpNodo*)malloc(sizeof(TpNodo));
            arvore->nodo->esq->pai = arvore->nodo;
            arvore->nodo->esq->altdireita = 0;
            arvore->nodo->esq->altesquerda = 0;
            arvore->nodo->esq->altura = 0;
            arvore->nodo->esq->nivel = arvore->nodo->nivel+1;
            arvore->nodo->esq->esq = NULL;
            arvore->nodo->esq->dir = NULL;
            arvore->nodo->esq->chave = -1;
            //--------------------------- inicia o nodo sentinela direito
            arvore->nodo->dir = (TpNodo*)malloc(sizeof(TpNodo));
            arvore->nodo->dir->pai = arvore->nodo;
            arvore->nodo->dir->altdireita = 0;
            arvore->nodo->dir->altesquerda = 0;
            arvore->nodo->dir->altura = 0;
            arvore->nodo->dir->nivel = arvore->nodo->nivel+1;
            arvore->nodo->dir->esq = NULL;
            arvore->nodo->dir->dir = NULL;
            arvore->nodo->dir->chave = -1;
            arvore->naux = arvore->nodo;
            altura(arvore); //arruma a altura da arvore
            balancear(arvore);
        }
    }
    arvore->nodo = arvore->raiz;
    menu(arvore);
}
void altura(TpArvore *arvore){
    while(arvore->nodo->pai != NULL){
        if(arvore->nodo->esq->altura >= arvore->nodo->dir->altura){
            arvore->nodo->altura = arvore->nodo->esq->altura+1;
        }else if(arvore->nodo->esq->altura < arvore->nodo->dir->altura){
            arvore->nodo->altura = arvore->nodo->dir->altura+1;
        }
        arvore->nodo->altesquerda = arvore->nodo->esq->altura;
        arvore->nodo->altdireita = arvore->nodo->dir->altura;
        arvore->nodo = arvore->nodo->pai;
        if(arvore->nodo == arvore->raiz){
            if(arvore->nodo->esq->altura >= arvore->nodo->dir->altura){
                arvore->nodo->altura = arvore->nodo->esq->altura+1;
            }else if(arvore->nodo->esq->altura < arvore->nodo->dir->altura){
                arvore->nodo->altura = arvore->nodo->dir->altura+1;
            }
        }
    }
}
void balancear(TpArvore *arvore){
    while(arvore->naux->pai != NULL){
        //left right
        if(arvore->naux->pai != NULL && arvore->naux->pai->esq->chave == -1 && arvore->naux->pai->pai != NULL && arvore->naux->pai->pai->dir->chave == -1){
            arvore->naux->pai->dir = arvore->naux->esq;
            arvore->naux->esq->pai = arvore->naux->pai;
            arvore->naux->esq = arvore->naux->pai;
            arvore->naux->pai->pai->esq = arvore->naux;
            arvore->naux->pai = arvore->naux->pai->pai;
            arvore->naux->esq->pai = arvore->naux;
            //left left
            if(arvore->naux->pai != NULL && arvore->naux->pai->pai != NULL && arvore->naux->pai->pai->esq->chave == arvore->naux->pai->chave){
                arvore->naux->pai->pai->esq = arvore->naux;
            }else if(arvore->naux->pai != NULL && arvore->naux->pai->pai != NULL && arvore->naux->pai->pai->dir->chave == arvore->naux->pai->chave){
                arvore->naux->pai->pai->dir = arvore->naux;
            }
            arvore->naux->dir->pai = arvore->naux->pai;
            arvore->naux->pai->esq = arvore->naux->dir;
            arvore->naux->dir = arvore->naux->pai;
            if(arvore->naux->pai == arvore->raiz){
                arvore->raiz = arvore->naux;
            }
            if(arvore->naux->pai->pai == NULL){
                arvore->naux->pai = NULL;
            }else{
                arvore->naux->pai = arvore->naux->pai->pai;
            }
            arvore->naux->dir->pai = arvore->naux;
            arvore->naux->esq->altura = arvore->naux->esq->esq->altura+1;
            arvore->naux->altura = arvore->naux->esq->altura+1;
            arvore->naux->dir->altura = arvore->naux->dir->dir->altura+1;
        }
        //left left
        if( arvore->naux->pai != NULL && arvore->naux->pai->dir->chave == -1 && arvore->naux->pai->pai != NULL && arvore->naux->pai->pai->dir->chave == -1){
            arvore->naux = arvore->naux->pai;
            if(arvore->naux->pai != NULL && arvore->naux->pai->pai != NULL && arvore->naux->pai->pai->esq->chave == arvore->naux->pai->chave){
                arvore->naux->pai->pai->esq = arvore->naux;
            }else if(arvore->naux->pai != NULL && arvore->naux->pai->pai != NULL && arvore->naux->pai->pai->dir->chave == arvore->naux->pai->chave){
                arvore->naux->pai->pai->dir = arvore->naux;
            }
            arvore->naux->dir->pai = arvore->naux->pai;
            arvore->naux->pai->esq = arvore->naux->dir;
            arvore->naux->dir = arvore->naux->pai;
            if(arvore->naux->pai == arvore->raiz){
                arvore->raiz = arvore->naux;
            }
            if(arvore->naux->pai->pai == NULL){
                arvore->naux->pai = NULL;
            }else{
                arvore->naux->pai = arvore->naux->pai->pai;
            }
            arvore->naux->dir->pai = arvore->naux;
            arvore->naux->esq->altura = arvore->naux->esq->esq->altura+1;
            arvore->naux->altura = arvore->naux->esq->altura+1;
            arvore->naux->dir->altura = arvore->naux->dir->dir->altura+1;
        }//----
        //right left
        if(arvore->naux->pai != NULL && arvore->naux->pai->dir->chave == -1 && arvore->naux->pai->pai != NULL && arvore->naux->pai->pai->esq->chave == -1){
            arvore->naux->pai->esq = arvore->naux->dir;
            arvore->naux->dir->pai = arvore->naux->pai;
            arvore->naux->dir = arvore->naux->pai;
            arvore->naux->pai->pai->dir = arvore->naux;
            arvore->naux->pai = arvore->naux->pai->pai;
            arvore->naux->dir->pai = arvore->naux;
            //right right
            if(arvore->naux->pai != NULL && arvore->naux->pai->pai != NULL && arvore->naux->pai->pai->esq->chave == arvore->naux->pai->chave){
                arvore->naux->pai->pai->esq = arvore->naux;
            }else if(arvore->naux->pai != NULL && arvore->naux->pai->pai != NULL && arvore->naux->pai->pai->dir->chave == arvore->naux->pai->chave){
                arvore->naux->pai->pai->dir = arvore->naux;
            }
            arvore->naux->esq->pai = arvore->naux->pai;
            arvore->naux->pai->dir = arvore->naux->esq;
            arvore->naux->esq = arvore->naux->pai;
            if(arvore->naux->pai == arvore->raiz){
                arvore->raiz = arvore->naux;
            }
            if(arvore->naux->pai->pai == NULL){
                arvore->naux->pai = NULL;
            }else{
                arvore->naux->pai = arvore->naux->pai->pai;
            }
            arvore->naux->esq->pai = arvore->naux;
            arvore->naux->esq->altura = arvore->naux->esq->esq->altura+1;
            arvore->naux->altura = arvore->naux->esq->altura+1;
            arvore->naux->dir->altura = arvore->naux->dir->dir->altura+1;
        }
        //right right
        if(arvore->naux->pai != NULL && arvore->naux->pai->esq->chave == -1 && arvore->naux->pai->pai != NULL && arvore->naux->pai->pai->esq->chave == -1){
            arvore->naux = arvore->naux->pai;
            if(arvore->naux->pai->pai != NULL && arvore->naux->pai->pai->esq->chave == arvore->naux->pai->chave){
                arvore->naux->pai->pai->esq = arvore->naux;
            }else if(arvore->naux->pai->pai != NULL && arvore->naux->pai->pai->dir->chave == arvore->naux->pai->chave){
                arvore->naux->pai->pai->dir = arvore->naux;
            }
            arvore->naux->esq->pai = arvore->naux->pai;
            arvore->naux->pai->dir = arvore->naux->esq;
            arvore->naux->esq = arvore->naux->pai;
            if(arvore->naux->pai == arvore->raiz){
                arvore->raiz = arvore->naux;
            }
            if(arvore->naux->pai->pai == NULL){
                arvore->naux->pai = NULL;
            }else{
                arvore->naux->pai = arvore->naux->pai->pai;
            }
            arvore->naux->esq->pai = arvore->naux;
            arvore->naux->esq->altura = arvore->naux->esq->esq->altura+1;
            arvore->naux->altura = arvore->naux->esq->altura+1;
            arvore->naux->dir->altura = arvore->naux->dir->dir->altura+1;
        }//----
        if(arvore->naux->pai != NULL){
            arvore->naux = arvore->naux->pai;
        }
    }
}
void menu(TpArvore *arvore){
    int opc;

    printf("1-inserir um elemento\n2-listar os elementos inseridos(nao funciona)\n0-sair\n");
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
        system("cls");
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
