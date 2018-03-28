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
} TpArvore;

void menu(TpArvore *arvore){
    int opc;

    printf("1-inserir um elemento\n2-listar os elementos inseridos\n0-sair\n");
    scanf("%d",&opc);
    switch(opc){
    case 1:
        //inserir(arvore);
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
    arvore = (TpArvore*)malloc(sizeof(TpArvore));
    arvore->raiz = (TpNodo*)malloc(sizeof(TpNodo));
    arvore->raiz->altura = 0;
    arvore->raiz->nivel = 0;
    arvore->raiz->altesquerda = 0;
    arvore->raiz->altdireita = 0;
}

int main(){
    TpArvore *arvore;

    inicia(arvore);
    menu(arvore);
}
