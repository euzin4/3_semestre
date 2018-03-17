#include <stdio.h>
#include <stdlib.h>

int main(){
    float val,res,pdec,auxm;
    int cexp=0,mant[23],cont=0,sinal,pint,auxexp;
    char exp[8];

    printf("digite um numero fracionario (use ponto): ");
    scanf("%f",&val);
    if(val < 0){
        res = val * -1;
        sinal=1;    //sinal caso seja numero negativo
    }else{
        res=val;
        sinal=0;    //sinal caso seja numero positivo
    }   // se o valor digitado for maior ou igual a 1 e menor que 2 "res" fica com o mesmo valor
    while(res >= 2){    //se o valor digitado for maior ou igual a 2
        res = res/2;
        cexp++;
    }
    while(res>0 && res<1){  //se o valor digitado for maior que zero e menor que 1
        res = res*2;
        cexp--;
    }
    pint=floor(res);  //parte inteira
    pdec=res-pint;  //parte decimal
    //-----------------------calculo da mantissa
    while(pdec != 0){
        if(cont == 23)
            break;
        auxm = pdec*2;
        mant[cont] = floor(auxm);
        pdec = auxm - mant[cont];
        cont++;
    }
    while(cont < 23){   //completa os 23 digitos da mantissa com zero caso o cálculo acabar antes deles serem preenchidos
        mant[cont] = 0;
        cont++;
    }
    //-----------------------cálculo do exp
    auxexp = cexp+127;
    if(auxexp >= 128){
        exp[0] = 1;
        auxexp -= 128;
    }else{
        exp[0] = 0;
    }
    if(auxexp < 128 && auxexp >= 64){
        exp[1] = 1;
        auxexp -= 64;
    }else{
        exp[1] = 0;
    }
    if(auxexp < 64 && auxexp >= 32){
        exp[2] = 1;
        auxexp -= 32;
    }else{
        exp[2] = 0;
    }
    if(auxexp < 32 && auxexp >= 16){
        exp[3] = 1;
        auxexp -= 16;
    }else{
        exp[3] = 0;
    }
    if(auxexp < 16 && auxexp >= 8){
        exp[4] = 1;
        auxexp -= 8;
    }else{
        exp[4] = 0;
    }
    if(auxexp < 8 && auxexp >= 4){
        exp[5] = 1;
        auxexp -= 4;
    }else{
        exp[5] = 0;
    }
    if(auxexp < 4 && auxexp >= 2){
        exp[6] = 1;
        auxexp -= 2;
    }else{
        exp[6] = 0;
    }
    if(auxexp == 1){
        exp[7] = 1;
        auxexp -= 1;
    }else{
        exp[7] = 0;
    }
    //-----------------------apresentação dos valores
    printf("|%d|",sinal);
    for(cont=0; cont < 8; cont++){
        printf("%d",exp[cont]);
    }
    printf("|");
    for(cont=0; cont != 23; cont++){
        printf("%d",mant[cont]);
    }
    printf("|\n");

    return 0;
}
