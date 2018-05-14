#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *p;
    char c[20];

    p = fopen("arquivo.txt", "a");  //o "a" escreve no arquivo sem apagar o que ja estava la
    printf("escreva algo: ");
    fgets(c, 19, stdin);
    fprintf(p, "%s", c);    //"p" é o ponteiro do arquivo, "c" é a variavel da qual vao ser copiados os dados para o arquivo
}
