#include<stdio.h>
#include<string.h>
#include<locale.h>

typedef struct{
    char Nome[20];
    int Idade;
    float Altura;
}Pessoa;

void Armazena(Pessoa *P);
void ImprimePessoa(Pessoa *P);
void MaisNova(Pessoa *P);
void MaisAlta(Pessoa *P);
void MaioresIdade(Pessoa *P);

void main(){
    setlocale(LC_ALL,"portugueses");

    Pessoa Galera[5];
    Armazena(Galera);
    ImprimePessoa(Galera);
    MaisNova(Galera);
    MaisAlta(Galera);
    MaioresIdade(Galera);
}

void Armazena(Pessoa *P){
    printf("\n-----Coleta-----\n");
    int i=0;
    while(i<5){
        printf("\nNome, Idade e Altura: ");
        scanf("%s %d %f",P[i].Nome,&P[i].Idade,&P[i].Altura);
        fflush(stdin);
        i++;
    }
}

void ImprimePessoa(Pessoa *P){
    printf("\n-----Dados Cadastrados-----\n");
    int i;
    for(i=0;i<5;i++){
        printf("\n(%s, %d anos, %.2f m)",P[i].Nome,P[i].Idade,P[i].Altura);
    }
}

void MaisNova(Pessoa *P){
    printf("\n-----Pessoa mais nova------\n");
    char a[20];
    float b;
    int i,j,k;
    for(i=0;i<5;i++){
        for(j=(i+1);j<5;j++){
            if(P[i].Idade>=P[j].Idade){
                k=P[i].Idade;
                P[i].Idade=P[j].Idade;
                P[j].Idade=k;
                strcpy(a,P[i].Nome);
                strcpy(P[i].Nome,P[j].Nome);
                strcpy(P[j].Nome,a);
                b=P[i].Altura;
                P[i].Altura=P[j].Altura;
                P[j].Altura=b;
            }
        }
    }
    printf("\n(%s, %d anos, %.2f m)",P[0].Nome,P[0].Idade,P[0].Altura);
}

void MaisAlta(Pessoa *P){
    printf("\n-----Pessoa mais alta------\n");
    char a[20];
    float b;
    int i,j,k;
    for(i=0;i<5;i++){
        for(j=(i+1);j<5;j++){
            if(P[i].Altura>=P[j].Altura){
                k=P[i].Altura;
                P[i].Altura=P[j].Altura;
                P[j].Altura=k;
                k=P[i].Idade;
                P[i].Idade=P[j].Idade;
                P[j].Idade=k;
                strcpy(a,P[i].Nome);
                strcpy(P[i].Nome,P[j].Nome);
                strcpy(P[j].Nome,a);
            }
        }
    }
    printf("\n(%s, %d anos, %.2f m)",P[4].Nome,P[4].Idade,P[4].Altura);
}

void MaioresIdade(Pessoa *P){
    printf("\n-----Maiores de Idade------\n");
    int i;
    for(i=0;i<5;i++){
        if(P[i].Idade>=18){
            printf("\n(%s, %d, %.2f)",P[i].Nome,P[i].Idade,P[i].Altura);
        }
    }
}






















