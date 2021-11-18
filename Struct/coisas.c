#include<stdio.h>
#include<string.h>
#include<locale.h>

typedef struct{
    char Nome[10];
    int Idade;
    float Valor;
}Coisa;

void Cadastra(Coisa *C,int *a, int *b);
void Mostra(Coisa *C, int b);
void Sair();

void main(){
    setlocale(LC_ALL,"Portuguese");

    int n, pos;
    printf("Quantidade de coisas a serem cadastradas: ");
    scanf("%d",&n);
    fflush(stdin);
    pos=0;
    Coisa Vetor[n];

    int option;
    while(1){
        printf("\n\n0 - Sair do sistema\n1 - Cadastrar uma coisa nova\n2 - Mostrar as coisas já cadastradas\n");
        scanf("%d",&option);
        fflush(stdin);
        switch(option){
            case 0:
                Sair();
            case 1:
                Cadastra(Vetor,&n,&pos);
                continue;
            case 2:
                Mostra(Vetor,pos);
                continue;
        }
    }

}

void Cadastra(Coisa *C, int *a, int *b){
    printf("\nCadastro\n---------------------");
    int i=*b;
    int j=*a;
    while(i<j){
        if(i==0 || i<j){
            printf("\n%dº : Nome, Idade, Valor: ",(i+1));
            scanf("%s %d %f",C[i].Nome,&C[i].Idade,&C[i].Valor);
            fflush(stdin);
            if(!strcmp(C[i].Nome,"0") || C[i].Idade==0 || C[i].Valor==0){
                *b=i;
                break;
            }else{
                i++;
                *b=i;
            }
        }
    }
    if(i==j){
        printf("\nLimite de cadastro atingido.\n");
    }
}

void Mostra(Coisa *C, int j){
    printf("\nItens Cadastrados\n-------------------");
    int i;
    for(i=0;i<j;i++){
        printf("\n(%s, %d anos, R$ %.2f)",C[i].Nome,C[i].Idade,C[i].Valor);
    }
}

void Sair(){
    exit(1);
}

