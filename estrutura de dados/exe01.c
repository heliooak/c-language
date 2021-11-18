#include<stdio.h>
#include<locale.h>
#define alturaMaxima 225

typedef struct{
    int peso;
    int altura;
}PesoAltura;

int main(){
    setlocale(LC_ALL,"portuguese");
    PesoAltura* pessoa1=(PesoAltura*)malloc(sizeof(PesoAltura));
    pessoa1->peso=80;
    pessoa1->altura=185;
    printf("Peso: %i, Altura: %i. ",pessoa1->peso,pessoa1->altura);
    if((pessoa1->altura)>alturaMaxima){
        printf("\nAltura acima da máxima.\n");
    }else{
        printf("\nAltura abaixo da máxima.\n");
    }
}
