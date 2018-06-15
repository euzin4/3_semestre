#include <stdio.h>
#include <stdlib.h>

typedef struct _nodo{
    int chave;
    struct _nodo *filho;
}TpNodo;
typedef struct _arvore{
    int t;
    int maxc, maxf;
    int minc, minf;
    TpNodo *raiz;
    TpNodo *nodo;
}TpArvore;

void menu(){
    int opc;

    printf("1-inserir um produto\n2-listar os produtos cadastrados\n0-sair\n");
    scanf("%d",&opc);
    switch(opc){
    case 1:
        //inserir();
        break;
    case 2:
        //listar();
        break;
    case 0:
        printf("\nAte logo!");
        break;
    default:
        system("cls");
        printf("Opcao invalida!\n\n");
        aux();
    }
}
void aux(){
    menu();
}
int main()
{
    TpArvore *arvore;

    arvore = (TpArvore*)malloc(sizeof(TpArvore));
    printf("Digite o valor de 't':");
    scanf("%d", &arvore->t);
}
