#include <stdio.h>
#include <stdlib.h>

typedef struct _produto{
    int codigo;
    char nome[20];
    float preco;
}TpProduto;

void menu(){
    int opc;

    printf("1-inserir um produto\n2-listar os produtos cadastrados\n0-sair\n");
    scanf("%d",&opc);
    switch(opc){
    case 1:
        inserir();
        break;
    case 2:
        listar();
        break;
    case 0:
        printf("\nAte logo!");
        break;
    default:
        system("clear");
        printf("Opcao invalida!\n\n");
        aux();
    }
}
void aux(){
    menu();
}
int main()
{
    menu();
}
