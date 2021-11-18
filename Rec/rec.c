#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

typedef struct{
    int Matricula;
    char Nome[20];
    float Nota1,Nota2,Nota3;
    float Media;
}ALUNOS;

void cadastraAluno(ALUNOS *x,int *y,int z);
void mostraAlunos(ALUNOS *x,int z);
void procuraAluno(ALUNOS *x,int z);
void alteraAluno(ALUNOS *x,int z);
void sair();
float medAluno(ALUNOS *x, int z);


void main(){
    setlocale(LC_ALL,"portuguese");

    int n,pos;
    pos=0;
    printf("Informe a quantidade de alunos a serem cadastrados: ");
    scanf("%d",&n);
    fflush(stdin);

    ALUNOS Array[n];

    int option;
    while(1){
        medAluno(Array,n);
        printf("\n\n0 - Sair do sistema\n1 - Cadastrar Alunos\n2 - Mostrar Alunos já cadastrados\n3 - Procurar e mostrar um aluno pela matrícula\n4 - Altera as notas de um aluno\n");
        scanf("%d",&option);
        fflush(stdin);
        switch(option){
            case 0:
                sair();
            case 1:
                cadastraAluno(Array,&pos,n);
                continue;
            case 2:
                mostraAlunos(Array,n);
                continue;
            case 3:
                procuraAluno(Array,n);
                continue;
            case 4:
                alteraAluno(Array,n);
                continue;
        }
    }
}

void sair(){
    exit(1);
}

void cadastraAluno(ALUNOS *x,int *y,int z){
    printf("\nCadastro\n---------------------");
    int i=*y;
    int j=z;
    while(i<j){
        if(!strcmp(x[i].Nome,"0") || x[i].Matricula==0){
            *y=i;
            break;
        }else{
            printf("\n%dº Aluno : Nome, Matrícula e Nota1 Nota2 e Nota3: ",(i+1));
            scanf("%s %d %f %f %f",x[i].Nome,&x[i].Matricula,&x[i].Nota1,&x[i].Nota2,&x[i].Nota3);
            fflush(stdin);
            i++;
            *y=i;
            if(i==j){
                printf("\nLimite de cadastro atingido.\n");
            }
        }
    }
}

void procuraAluno(ALUNOS *x, int z){
    int a;
    printf("\n\n-------------------\nProcurar pela matrícula: ");
    scanf("%d",&a);
    int i;
    for(i=0;i<=z;i++){
        if(a==x[i].Matricula){
            printf("Localizado:\nNome: %s, Matrícula: %d, Nota1: %.2f, Nota2: %.2f, Nota3: %.2f, Média: %.2f",x[i].Nome,x[i].Matricula,x[i].Nota1,x[i].Nota2,x[i].Nota3,x[i].Media);
            break;
        }else if((a!=x[i].Matricula) && (i<z)){
            continue;
        }else{
            printf("Matrícula não localizada.");
        }
    }
}

void alteraAluno(ALUNOS *x,int z){
    int a;
    printf("\n\n-------------------\nProcurar pela matrícula: ");
    scanf("%d",&a);
    int i;
    for(i=0;i<=z;i++){
        if(a==x[i].Matricula){
            printf("Localizado:\nNome: %s, Matrícula: %d, Nota1: %.2f, Nota2: %.2f, Nota3: %.2f, Média: %.2f",x[i].Nome,x[i].Matricula,x[i].Nota1,x[i].Nota2,x[i].Nota3,x[i].Media);
            printf("\nAlterar a Nota 1 atual para: ");
            scanf("%f",&x[i].Nota1);
            fflush(stdin);
            printf("\nAlterar a Nota 2 atual para: ");
            scanf("%f",&x[i].Nota2);
            fflush(stdin);
            printf("\nAlterar a Nota 3 atual para: ");
            scanf("%f",&x[i].Nota3);
            fflush(stdin);
            break;
        }else if((a!=x[i].Matricula) && (i<z)){
            continue;
        }else{
            printf("Matrícula não localizada.");
        }
    }
    printf("Nota alterada com sucesso!");
}

void mostraAlunos(ALUNOS *x,int z){
    printf("\nPessoas Cadastradas\n-------------------");
    int i;
    for(i=0;i<z;i++){
        printf("\n(%s, %d, N1: %.2f, N2: %.2f, N3: %.2f, Média: %.2f )",x[i].Nome,x[i].Matricula,x[i].Nota1,x[i].Nota2,x[i].Nota3,x[i].Media);
    }
}

float medAluno(ALUNOS *x, int z){
    float a,b,c,med;
    int i;
    for(i=0;i<z;i++){
        a=x[i].Nota1;
        b=x[i].Nota2;
        c=x[i].Nota3;
        med=((a+b+c)/3);
        x[i].Media=med;
    }
}
