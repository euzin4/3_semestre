#include <stdio.h>
#include <stdlib.h>

typedef struct _nodo{
    int chave;
    int nivel;
    int cor;    // 0=vermelho, 1=preto
    struct _nodo *pai;
    struct _nodo *esq;
    struct _nodo *dir;
}TpNodo;
typedef struct _arvore{
    TpNodo *raiz;
    TpNodo *nodo;
}TpArvore;

void balancear(TpArvore *arvore){
    arvore->nodo->cor = 0;
    while(arvore->nodo->pai != NULL && arvore->nodo->pai->cor == 0 && arvore->nodo->cor == 0){
        if(arvore->nodo->pai->pai->esq->cor == 0 && arvore->nodo->pai->pai->dir->cor == 0){   //caso 1
            arvore->nodo->pai->pai->cor = 0;
            arvore->nodo->pai->pai->esq->cor = 1;
            arvore->nodo->pai->pai->dir->cor = 1;
            arvore->nodo = arvore->nodo->pai->pai;
        }else if(arvore->nodo->pai->pai != NULL){
            //---caso 2
            if(arvore->nodo->pai->pai->dir->cor == 1 && arvore->nodo->pai->esq->chave == -1 || arvore->nodo->cor == 0 && arvore->nodo->pai->cor == 0 && arvore->nodo->pai->pai->dir->cor == 1 && arvore->nodo->pai->dir == arvore->nodo){   //esq-dir
                arvore->nodo->pai->pai->esq = arvore->nodo;
                arvore->nodo->pai->dir = arvore->nodo->esq;
                arvore->nodo->esq->pai = arvore->nodo->pai;
                arvore->nodo->pai = arvore->nodo->pai->pai;
                arvore->nodo->esq->pai->pai = arvore->nodo;
                arvore->nodo->esq = arvore->nodo->esq->pai;
                arvore->nodo = arvore->nodo->esq;
            }else if(arvore->nodo->pai->pai->esq->cor == 1 && arvore->nodo->pai->dir->chave == -1 || arvore->nodo->cor == 0 && arvore->nodo->pai->cor == 0 && arvore->nodo->pai->pai->esq->cor == 1 && arvore->nodo->pai->esq == arvore->nodo){ //dir-esq
                arvore->nodo->pai->pai->dir = arvore->nodo;
                arvore->nodo->pai->esq = arvore->nodo->dir;
                arvore->nodo->dir->pai = arvore->nodo->pai;
                arvore->nodo->pai = arvore->nodo->pai->pai;
                arvore->nodo->dir->pai->pai = arvore->nodo;
                arvore->nodo->dir = arvore->nodo->dir->pai;
                arvore->nodo = arvore->nodo->dir;
            }
            //---caso 3
            if(arvore->nodo->pai->pai->dir->cor == 1 && arvore->nodo->pai->dir->chave == -1 || arvore->nodo->pai->pai->dir->cor == 1 && arvore->nodo->pai->cor == 0 && arvore->nodo->cor == 0){   //esq-esq
                if(arvore->nodo->pai->pai->pai != NULL){
                    if(arvore->nodo->pai->pai->pai->esq == arvore->nodo->pai->pai){
                        arvore->nodo->pai->pai->pai->esq = arvore->nodo->pai;
                    }else if(arvore->nodo->pai->pai->pai->dir == arvore->nodo->pai->pai){
                        arvore->nodo->pai->pai->pai->dir = arvore->nodo->pai;
                    }
                }
                arvore->nodo->pai->dir->pai = arvore->nodo->pai->pai;
                arvore->nodo->pai->pai->esq = arvore->nodo->pai->dir;
                arvore->nodo->pai->pai = arvore->nodo->pai->pai->pai;
                arvore->nodo->pai->dir->pai->pai = arvore->nodo->pai;
                arvore->nodo->pai->dir = arvore->nodo->pai->dir->pai;
                arvore->nodo = arvore->nodo->pai;
                arvore->nodo->cor = 1;
                arvore->nodo->dir->cor = 0;
                if(arvore->nodo->pai == NULL){
                    arvore->raiz = arvore->nodo;
                }
            }else if(arvore->nodo->pai->pai->esq->cor == 1 && arvore->nodo->pai->esq->chave == -1 || arvore->nodo->pai->pai->esq->cor == 1 && arvore->nodo->pai->cor == 0 && arvore->nodo->cor == 0){ //dir-dir
                if(arvore->nodo->pai->pai->pai != NULL){
                    if(arvore->nodo->pai->pai->pai->esq == arvore->nodo->pai->pai){
                        arvore->nodo->pai->pai->pai->esq = arvore->nodo->pai;
                    }else if(arvore->nodo->pai->pai->pai->dir == arvore->nodo->pai->pai){
                        arvore->nodo->pai->pai->pai->dir = arvore->nodo->pai;
                    }
                }
                arvore->nodo->pai->esq->pai = arvore->nodo->pai->pai;
                arvore->nodo->pai->pai->dir = arvore->nodo->pai->esq;
                arvore->nodo->pai->pai = arvore->nodo->pai->pai->pai;
                arvore->nodo->pai->esq->pai->pai = arvore->nodo->pai;
                arvore->nodo->pai->esq = arvore->nodo->pai->esq->pai;
                arvore->nodo = arvore->nodo->pai;
                arvore->nodo->cor = 1;
                arvore->nodo->esq->cor = 0;
                if(arvore->nodo->pai == NULL){
                    arvore->raiz = arvore->nodo;
                }
            }
            nivel(arvore);
        }
    }
    arvore->nodo = arvore->raiz;
    arvore->raiz->cor = 1;

}
void nivel(TpArvore *arvore){
    TpNodo *aux1;

    aux1 = arvore->raiz;
    ajustenvl(arvore, aux1);
}
void ajustenvl(TpArvore *arvore, TpNodo *aux1){
    if(arvore->raiz->chave == -1){
        printf("Arvore vazia!");
        return;
    }else if(aux1 != NULL){
        if(aux1->pai == NULL){
            aux1->nivel = 0;
        }else{
            aux1->nivel = aux1->pai->nivel +1;
        }
        ajustenvl(arvore, aux1->esq);
        ajustenvl(arvore, aux1->dir);
    }
}
void listar(TpArvore *arvore){
    TpNodo *aux;

    aux = arvore->raiz;
    exibir_pre(arvore, aux);
    printf("\n\n");
    menu(arvore);
}
void exibir_pre(TpArvore *arvore, TpNodo *aux){
    if(arvore->raiz->chave == -1){
        printf("Arvore vazia!");
        return;
    }
    if(aux->chave != -1){
        printf("chave:%d nivel:%d cor:%d ", aux->chave, aux->nivel, aux->cor);
        if(aux->pai != NULL){
            printf("pai:%d;; ",aux->pai->chave);
        }else{
            printf("pai:NULL;;");
        }
        printf("\n");
        exibir_pre(arvore, aux->esq);
        exibir_pre(arvore, aux->dir);
    }
}
void inserir(TpArvore *arvore){
    int valor = -1;

    system("cls");
    while(valor < 0){
        printf("valor: ");
        scanf("%d",&valor);
        if(valor < 0){
            system("cls");
            printf("digite um valor maior que zero!\n\n");
        }
    }
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
            arvore->nodo->pai->esq->nivel = arvore->nodo->pai->nivel + 1;
            arvore->nodo->pai->dir->nivel = arvore->nodo->pai->nivel + 1;
            //--------------------------- inicia o nodo sentinela esquerdo
            arvore->nodo->esq = (TpNodo*)malloc(sizeof(TpNodo));
            arvore->nodo->esq->pai = arvore->nodo;
            arvore->nodo->esq->esq = NULL;
            arvore->nodo->esq->dir = NULL;
            arvore->nodo->esq->nivel = arvore->nodo->nivel + 1;
            arvore->nodo->esq->cor = 1;
            arvore->nodo->esq->chave = -1;
            //--------------------------- inicia o nodo sentinela direito
            arvore->nodo->dir = (TpNodo*)malloc(sizeof(TpNodo));
            arvore->nodo->dir->pai = arvore->nodo;
            arvore->nodo->dir->esq = NULL;
            arvore->nodo->dir->dir = NULL;
            arvore->nodo->dir->nivel = arvore->nodo->nivel + 1;
            arvore->nodo->dir->cor = 1;
            arvore->nodo->dir->chave = -1;
            balancear(arvore);
        }
    }
    arvore->nodo = arvore->raiz;
    menu(arvore);
}
void inicia(TpArvore *arvore){
    arvore->raiz = (TpNodo*)malloc(sizeof(TpNodo));
    arvore->raiz->chave = -1;
    arvore->raiz->nivel = 0;
    arvore->raiz->cor = 1;
    arvore->raiz->pai = NULL;
    //-----nodo esquerdo
    arvore->raiz->esq = (TpNodo*)malloc(sizeof(TpNodo));
    arvore->raiz->esq->chave = -1;
    arvore->raiz->esq->nivel = 1;
    arvore->raiz->esq->cor = 1;
    arvore->raiz->esq->pai = arvore->raiz;
    arvore->raiz->esq->esq = NULL;
    arvore->raiz->esq->dir = NULL;
    //-----nodo direito
    arvore->raiz->dir = (TpNodo*)malloc(sizeof(TpNodo));
    arvore->raiz->dir->chave = -1;
    arvore->raiz->dir->nivel = 1;
    arvore->raiz->dir->cor = 1;
    arvore->raiz->dir->pai = arvore->raiz;
    arvore->raiz->dir->esq = NULL;
    arvore->raiz->dir->dir = NULL;
}
void menu(TpArvore *arvore){
    int opc;

    printf("1-inserir um elemento\n2-listar os elementos inseridos\n0-sair\n");
    scanf("%d",&opc);
    switch(opc){
    case 1:
        inserir(arvore);
        break;
    case 2:
        system("cls");
        listar(arvore);
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

int main(){
    TpArvore *arvore;

    arvore = (TpArvore*)malloc(sizeof(TpArvore));
    inicia(arvore);
    arvore->nodo = arvore->raiz;
    menu(arvore);

    return 0;
}
