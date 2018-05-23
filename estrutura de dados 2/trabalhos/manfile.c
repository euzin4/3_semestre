#include <stdio.h>
#include <stdlib.h>

typedef struct _produto{
    int codigo;
    char nome[20];
    float preco;
}TpProduto;

void inserir(FILE *file){
    TpProduto produto;

    system("clear");
    printf("Codigo: ");
    scanf("%d", &produto.codigo);
    getchar();
    printf("Nome: ");
    fgets(produto.nome, 19, stdin);
    printf("Preco: ");
    scanf("%f", &produto.preco);
    file = fopen("arquivo.txt", "a");
    fprintf(file, "codigo:%d\n", produto.codigo);
    fprintf(file, "nome:%s", produto.nome);
    fprintf(file, "preco:%.2f\n\n", produto.preco);
    fclose(file);
    system("clear");
    printf("Dados inseridos!\n\n");
    menu(file);
}
void listar(FILE *file){
    char texto[100];

    file = fopen("arquivo.txt", "r");
    if(file != NULL){
        system("clear");
        while(fgets(texto, 99, file) != NULL){
            printf("%s", texto);
        }
        //printf("\n");
    }else{
        printf("Ocorreu um erro na abertura do arquivo\n\n");
    }
    menu(file);
}
void menu(FILE *file){
    int opc;

    printf("1-inserir um produto\n2-listar os produtos cadastrados\n0-sair\n");
    scanf("%d",&opc);
    switch(opc){
    case 1:
        inserir(file);
        break;
    case 2:
        listar(file);
        break;
    case 0:
        printf("\nAte logo!");
        break;
    default:
        system("clear");
        printf("Opcao invalida!\n\n");
        aux(file);
    }
}
void aux(FILE *file){
    menu(file);
}
int main()
{
    FILE *file;

    file = fopen("arquivo.txt", "a");
    fclose(file);
    menu(file);
    return 0;
}
