#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<locale.h>

void main(){
    setlocale(LC_ALL, "portuguese");
    char nome[12];

    printf("Digite um nome: ");
    scanf("%s", &nome);

    nome[12] = tolower(nome);

    printf("Nome com todas as letras minúsculas: %s", nome);
}
