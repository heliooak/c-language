#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

typedef struct{
    int Idade;
    float Peso, Altura;
}ALUNO;

int cadastraAluno(ALUNO *x,int y);
void maisNova(ALUNO *x,int y);
void maisBaixa(ALUNO *x,int y);
void maisPesada(ALUNO *x,int y);

int main(){
    setlocale(LC_ALL,"portuguese");

    ALUNO *Array;
    int n,pos;
    n=10;

    Array=(ALUNO*)malloc(n*sizeof(ALUNO));

    cadastraAluno(Array,n);
    maisNova(Array,n);
    maisBaixa(Array,n);
    maisPesada(Array,n);
}

int cadastraAluno(ALUNO *x,int y){
    printf("\nCadastro\n------------------\n");
    int i=0;
    while(i<y){
        printf("\n%d Aluno: Idade, Peso, Altura: ",(i+1));
        scanf("%d %f %f",&x[i].Idade,&x[i].Peso,&x[i].Altura);
        fflush(stdin);
        i++;
    }
}

void maisNova(ALUNO *x,int y){
    int a,b,c,k;
    for(a=0;a<y;a++){
        for(b=(a+1);b<y;b++){
            if(x[a].Idade>=x[b].Idade){
                k=x[a].Idade;
                x[a].Idade=x[b].Idade;
                x[b].Idade=k;
                k=x[a].Peso;
                x[a].Peso=x[b].Peso;
                x[b].Peso=k;
                k=x[a].Altura;
                x[a].Altura=x[b].Altura;
                x[b].Altura=k;
            }
        }
    }
    printf("\nPessoa mais nova:(Idade, Peso, Altura): (%d, %.2f, %.2f)",x[0].Idade,x[0].Peso,x[0].Altura);
}

void maisBaixa(ALUNO *x,int y){
    int a,b,c,k;
    for(a=0;a<y;a++){
        for(b=(a+1);b<y;b++){
            if(x[a].Altura>=x[b].Altura){
                k=x[a].Altura;
                x[a].Altura=x[b].Altura;
                x[b].Altura=k;
                k=x[a].Peso;
                x[a].Peso=x[b].Peso;
                x[b].Peso=k;
                k=x[a].Idade;
                x[a].Idade=x[b].Idade;
                x[b].Idade=k;
            }
        }
    }
    printf("\nPessoa mais baixa:(Idade, Peso, Altura): (%d, %.2f, %.2f)",x[0].Idade,x[0].Peso,x[0].Altura);
}

void maisPesada(ALUNO *x,int y){
    int a,b,c,k;
    for(a=0;a<y;a++){
        for(b=(a+1);b<y;b++){
            if(x[a].Peso>=x[b].Peso){
                k=x[a].Peso;
                x[a].Peso=x[b].Peso;
                x[b].Peso=k;
                k=x[a].Idade;
                x[a].Idade=x[b].Idade;
                x[b].Idade=k;
                k=x[a].Altura;
                x[a].Altura=x[b].Altura;
                x[b].Altura=k;
            }
        }
    }
    printf("\nPessoa mais pesada:(Idade, Peso, Altura): (%d, %.2f, %.2f)",x[y-1].Idade,x[y-1].Peso,x[y-1].Altura);
}
