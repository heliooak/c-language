#include<stdio.h>
#include<string.h>
#include<locale.h>

void main(){
    setlocale(LC_ALL, "portuguese");
    char nome[15];

    strcpy(nome, "Fulano de Tal");
    //strcpy(string_destino, string_origem);
    //note que a string de destino � nome
    //a string de origem � "Fulano de Tal"

    printf("Nome= %s", nome);
}
