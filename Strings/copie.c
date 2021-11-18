#include<stdio.h>
#include<string.h>
#include<locale.h>

void main(){
    setlocale(LC_ALL, "portuguese");

    int x;
    char nome[90];
    char sobre[90];
    char city[90];

    char nome1[30], nome2[30], nome3[30];
    char sobre1[30], sobre2[30], sobre3[30];
    int age1, age2, age3;
    char city1[30], city2[30], city3[30];

    for(x=0;x<3;x++){
        char nome[nome1,nome2,nome3];
        char sobre[sobre1,sobre2,sobre3];
        int age[];
        char city[city1,city2,city3];

        printf("Digite seu nome, sobrenome, idade e cidade");
        scanf("%s %s %d %s",nome[x],sobre[x],age[x],city[x]);

        printf("%s %s %d %s",nome[x],sobre[x], age[x]);

    }
}
