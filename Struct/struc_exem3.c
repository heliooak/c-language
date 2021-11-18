#include<stdio.h>
#include<string.h>
#include<locale.h>

typedef struct{
    float Peso, Altura;
    int Idade;
    char Nome[20];
}Pessoa;

void ImprimePessoa(Pessoa P);
void Atribui1(Pessoa *P);
void Atribui2(Pessoa *P);

void main(){
    setlocale(LC_ALL,"Portuguese");
    Pessoa P1, P2;

    Atribui1(&P1);
    ImprimePessoa(P1);
    Atribui2(&P2);
    ImprimePessoa(P2);

}

void Atribui1(Pessoa *P){
    (*P).Idade=15;
    (*P).Peso=60.5;
    (*P).Altura=1.75;
    strcpy((*P).Nome,"Luiza");
}

void Atribui2(Pessoa *P){
    P->Idade=25;
    P->Peso=63.5;
    P->Altura=1.67;
    strcpy(P->Nome,"Flávia");
}

void ImprimePessoa(Pessoa P){
    printf("\nNome: %s   Idade: %d   Peso: %.2f   Altura: %.2f\n",P.Nome,P.Idade,P.Peso,P.Altura);
}





































