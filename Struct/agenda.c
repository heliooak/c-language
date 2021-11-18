#include<stdio.h>
#include<string.h>
#include<locale.h>

typedef struct{
    char Nome[20];
    int Telefone;
}Agenda;

void Sair();
void Cadastra(Agenda *C,int *a, int *b);
void Mostra(Agenda *C, int b);
void Procura(Agenda *C, int b);
void Apaga(Agenda *C, int b);


void main(){
    setlocale(LC_ALL,"Portuguese");

    int n, pos;
    printf("Quantidade de pessoas a serem cadastradas: ");
    scanf("%d",&n);
    fflush(stdin);
    pos=0;
    Agenda Vetor[n];

    int option;
    while(1){
        printf("\n\n0 - Sair do sistema\n1 - Cadastrar uma pessoa\n2 - Mostrar as coisas já cadastradas\n3 - Procurar e mostrar uma pessoa pelo nome\n4 - Apagar uma pessoa do cadastro pelo nome\n");
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
            case 3:
                Procura(Vetor,pos);
                continue;
            case 4:
                Apaga(Vetor,pos);
                continue;
        }
    }

}

void Cadastra(Agenda *C, int *a, int *b){
    printf("\nCadastro\n---------------------");
    int i=*b;
    int j=*a;
    while(i<j){
        if(i==0 || i<j){
            printf("\n%dº : Nome e Telefone: ",(i+1));
            scanf("%s %d",C[i].Nome,&C[i].Telefone);
            fflush(stdin);
            if(!strcmp(C[i].Nome,"0") || C[i].Telefone==0){
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

void Mostra(Agenda *C, int b){
    printf("\nPessoas Cadastradas\n-------------------");
    int i;
    for(i=0;i<b;i++){
        printf("\n(%s, %d )",C[i].Nome,C[i].Telefone);
    }
}

void Procura(Agenda *C, int b){
    char a[20];
    printf("\n\n-------------------\nProcurar pelo nome: ");
    scanf("%s",a);
    int i,x;
    for(i=0;i<=b;i++){
        x=strcmp(C[i].Nome,a);
        if(x==0){
            printf("Localizado:\nnome: %s telefone: %d",C[i].Nome,C[i].Telefone);
            break;
        }else if(x!=0 && i!=b){
            continue;
        }else{
            printf("Nome não localizado.");
        }
    }
}

void Apaga(Agenda *C, int b){
    char a[20];
    int i,x;
    printf("\n------------------------\nApagar pelo nome: \n");
    scanf("%s", a);
    for(i=0;i<=b;i++){
        x=strcmp(C[i].Nome,a);
        if(x==0){
            printf("\nREMOVIDO:\n(nome: %s, telefone: %d)",C[i].Nome,C[i].Telefone);
            for(i;i<b;i++){
                if(i<(b-1)){
                    strcpy(C[i].Nome,C[i+1].Nome);
                    C[i].Telefone=C[i+1].Telefone;
                }else if(i==(b-1)){
                    break;
                }
            }
            break;
        }else if(x!=0 && i!=b){
            continue;
        }else{
            printf("Nome não localizado.");
        }
    }

}

void Sair(){
    exit(1);
}

