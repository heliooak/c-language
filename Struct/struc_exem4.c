#include<stdio.h>
#include<string.h>
#include<locale.h>


typedef struct{
    float Peso, Altura;
    int Idade;
    char Nome[20];
}Pessoa;

void ImprimePessoa(Pessoa P);
Pessoa SetPessoa();

void main(){
    Pessoa P1;

    P1=SetPessoa();
    ImprimePessoa(P1);
}

Pessoa SetPessoa(){
    Pessoa P;
    P.Idade=15;
    P.Peso=60.5;
    P.Altura=1.75;
    strcpy(P.Nome,"Luiza");
    return P;
}

void ImprimePessoa(Pessoa P){
    printf("Nome: %s   Idade: %d   Peso: %.2f   Altura: %.2f",P.Nome,P.Idade,P.Peso,P.Altura);
}








