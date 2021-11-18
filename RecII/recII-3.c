#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

typedef struct{
    char Nome[20];
    int Idade;
}PESSOA;

void cadastraPessoas(PESSOA *x,int y);
void arruma(char *x);
void arrumaNomes(PESSOA *x,int y);
void ordemAlfa(PESSOA *x,int y);
void ordemIdade(PESSOA *x,int y);
void ordemMaiorIdade(PESSOA *x,int y);
void mostraPessoas(PESSOA *x,int y);
void sair();



int main(){
    setlocale(LC_ALL,"portuguese");

    int n;
    printf("\nQuantidade de pessoas a serem cadastradas: ");
    scanf("%d",&n);
    fflush(stdin);

    PESSOA *Array;

    Array=(PESSOA*)malloc(n*sizeof(PESSOA));
    if(!Array){
        printf("\nMemory request failed.\n");
        exit(1);
    }

    int option=1;
    while(option!=0){
        printf("\n\n0 - Sair do sistema\n1 - Cadastrar Pessoas\n2 - Cadastrados em ordem alfabética\n3 - Cadastrados em ordem crescente de idade\n4 - Cadastrados maiores de Idade\n");
        scanf("%d",&option);
        fflush(stdin);
        switch(option){
            case 0:
                sair();
            case 1:
                cadastraPessoas(Array,n);
                continue;
            case 2:
                ordemAlfa(Array,n);
                continue;
            case 3:
                ordemIdade(Array,n);
                continue;
            case 4:
                ordemMaiorIdade(Array,n);
                continue;
        }
    }
    return 0;
}

void cadastraPessoas(PESSOA *x, int y){
    printf("\n------Cadastro de Pessoas-----\n");
    int i=0;
    while(i<y){
        printf("%d Pessoa (Nome, Idade): ",(i+1));
        scanf("%s %d",x[i].Nome,&x[i].Idade);
        i++;
    }
}


void mostraPessoas(PESSOA *x,int y){
    printf("\nPessoas Cadastradas\n-------------------");
    int i;
    for(i=0;i<y;i++){
        printf("\n(%s, %d)",x[i].Nome,x[i].Idade);
    }
}


void arruma(char *x){
    int y,n;
    n=strlen(x);

    for(y=0;y<n;y++){

        if(x[y]<90 && x[y]!=32){
            x[y]=x[y]+32;
        }
        if((y==0 || x[y-1]==32) && (x[y]!=32)){
            x[y]=x[y]-32;
        }
        if(x[y]==32 && (x[y-2]=='D')){
            x[y-2]=x[y-2]+32;
        }
        if(x[y]==32 && x[y-3]=='D' && x[y-1]=='s'){
            x[y-3]=x[y-3]+32;
        }
    }
}


void arrumaNomes(PESSOA *x,int y){
    char a[20];
    int i;
    for(i=0;i<y;i++){
        strcpy(a,x[i].Nome);
        int n=strlen(a);
        arruma(a);
        strcpy(x[i].Nome,a);
    }
    int j =0;
    int retorno=strcmp(x[j].Nome,x[j+1].Nome);
        printf("\nRetorno = %d\n",retorno);
}

void ordemAlfa(PESSOA *x,int y){
 int a,b,c;
 char k[20];
    for(a=0;a<y;a++){
        for(b=(a+1);b<y;b++){
            int retorno=strcmp(x[a].Nome,x[b].Nome);
            if(retorno>0){
                strcpy(k,x[a].Nome);
                strcpy(x[a].Nome,x[b].Nome);
                strcpy(x[b].Nome,k);
                c=x[a].Idade;
                x[a].Idade=x[b].Idade;
                x[b].Idade=c;
            }
        }
    }
    mostraPessoas(x,y);
}

void ordemIdade(PESSOA *x,int y){
    int a,b,c;
    char k[20];
    for(a=0;a<y;a++){
        for(b=(a+1);b<y;b++){
            if(x[a].Idade>=x[b].Idade){
                c=x[a].Idade;
                x[a].Idade=x[b].Idade;
                x[b].Idade=c;
                strcpy(k,x[a].Nome);
                strcpy(x[a].Nome,x[b].Nome);
                strcpy(x[b].Nome,k);
            }
        }
    }
    mostraPessoas(x,y);
}

void ordemMaiorIdade(PESSOA *x,int y){
    int i;
    for(i=0;i<y;i++){
        if(x[i].Idade>=18){
            printf("\n(%s, %d)",x[i].Nome,x[i].Idade);
        }
    }
}

void sair(){
    exit(1);
}







