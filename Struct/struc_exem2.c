#include<stdio.h>
#include<string.h>
#include<locale.h>

typedef struct{
    float Peso, Altura;
    int Idade;
    char Nome[20];
}Pessoa;

void ImprimePessoa(Pessoa P);

void main(){
    setlocale(LC_ALL,"Portuguese");
    Pessoa P1, P2, VetorPessoas[10];

    P1.Idade=15;
    P1.Peso=60.5;
    P1.Altura=1.75;
    strcpy(P1.Nome,"Luiza");

    VetorPessoas[4].Idade=23;
    VetorPessoas[4].Peso=75.3;
    VetorPessoas[4].Altura=1.89;
    strcpy(VetorPessoas[4].Nome,"Márcia");

    P2=VetorPessoas[4];

    ImprimePessoa(P2);
}

void ImprimePessoa(Pessoa P){
    printf("\nNome: %s    Idade: %d   Peso: %.2f   Altura: %.2f\n",P.Nome,P.Idade,P.Peso,P.Altura);
}
