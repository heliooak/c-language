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

void cadastraAluno(ALUNOS *x,int *y);
void mostraAlunos(ALUNOS *x,int z);
int  procuraAluno(ALUNOS *x, int z);
void alteraAluno1(ALUNOS *x,int z);
void alteraAluno2(ALUNOS *x,int z);
void alteraAluno3(ALUNOS *x,int z);
void sair(int t, ALUNOS *v);
float medAluno(ALUNOS *x, int z);
void salvar(ALUNOS *vp, int t);
void gravarReg(int t);
int carregarReg();
void carregar(ALUNOS *vp, int t);


void main(){
    setlocale(LC_ALL,"portuguese");

    int n,pos;
    pos= carregarReg();
    printf("Informe a quantidade de alunos a serem cadastrados: ");
    scanf("%d",&n);
    fflush(stdin);

    ALUNOS *Array;

    Array = malloc((n+pos)*sizeof(ALUNOS));

    carregar(Array,pos);

    int option=1;
    while(option!=0){
        medAluno(Array,pos);
        printf("\n\n0 - Sair do sistema\n1 - Cadastrar Alunos\n2 - Mostrar Alunos já cadastrados\n3 - Procurar e mostrar um aluno pela matrícula\n4 - Altera a nota 1 do aluno\n5 - Altera a nota 2 do aluno\n6 - Altera a nota 3 do aluno\n");
        scanf("%d",&option);
        fflush(stdin);
        switch(option){
            case 0:
                sair(pos,Array);
                continue;
            case 1:
                cadastraAluno(Array,&pos);
                continue;
            case 2:
                mostraAlunos(Array,pos);
                continue;
            case 3:
                procuraAluno(Array,pos);
                continue;
            case 4:
                alteraAluno1(Array,pos);
                continue;
            case 5:
                alteraAluno2(Array,pos);
                continue;
            case 6:
                alteraAluno3(Array,pos);
                continue;
        }
    }
}

void sair(int tot, ALUNOS *v){
    gravarReg(tot);
    salvar(v,tot);

}

void salvar(ALUNOS *vp, int t){
 FILE *fp;

 if ((fp=fopen ("aluno.txt","w")) != NULL) {
  for(int posi=0; posi<t; posi++){
     fprintf(fp,"\n %s %d %f %f %f %f\n", vp[posi].Nome, vp[posi].Matricula, vp[posi].Nota1, vp[posi].Nota2, vp[posi].Nota3, vp[posi].Media);
  }
  fclose(fp);
 } else {
    printf("Problema na abertura do arquivo");
 }
}

void gravarReg(int t){
 FILE *fp;

 if ((fp=fopen ("nalunos.txt","w")) != NULL) {
    fprintf(fp,"%d",t);
    fclose(fp);
 } else {
    printf("Problema na abertura do arquivo");
 }
}

int carregarReg(){
 FILE *fp;

 int t;
 if ((fp=fopen ("nalunos.txt","r")) != NULL) {
    fscanf(fp,"%d",&t);
    fclose(fp);
 } else {
    printf("Problema na abertura do arquivo");
    t=0;
 }

 return t;
}

void carregar(ALUNOS *vp, int t){
 FILE *fp;

 if ((fp=fopen ("aluno.txt","r")) != NULL) {
  for(int posi=0; posi<t; posi++){
     fscanf(fp,"%s %d %f %f %f %f", vp[posi].Nome, &vp[posi].Matricula, &vp[posi].Nota1, &vp[posi].Nota2, &vp[posi].Nota3, &vp[posi].Media);
  }
  fclose(fp);
 } else {
    printf("Problema na abertura do arquivo");
 }
}


void cadastraAluno(ALUNOS *x,int *y){
    printf("\nCadastro\n---------------------");
    printf("\n%dº Aluno : Nome, Matrícula: ",((*y)+1));
            scanf("%s %d",x[*y].Nome,&x[*y].Matricula);
            fflush(stdin);
            x[*y].Nota1=0;
            x[*y].Nota2=0;
            x[*y].Nota3=0;
            x[*y].Media=0;

    (*y)++;
}

int  procuraAluno(ALUNOS *x, int z){
    int a;
    printf("\n\n-------------------\nProcurar pela matrícula: ");
    scanf("%d",&a);
    int i=0;
    while(i<z && a!=x[i].Matricula){
      i++;
    }

    if(a==x[i].Matricula){
            printf("Localizado:\nNome: %s, Matrícula: %d, Nota1: %.2f, Nota2: %.2f, Nota3: %.2f, Média: %.2f",x[i].Nome,x[i].Matricula,x[i].Nota1,x[i].Nota2,x[i].Nota3,x[i].Media);
    }else{
            printf("Matrícula não localizada.");
    }
    return i;
}

void alteraAluno1(ALUNOS *x,int z){
    int a;
    a=procuraAluno(x,z);
    printf("\nAlterar a Nota 1 atual para: ");
    scanf("%f",&x[a].Nota1);
    fflush(stdin);
    printf("Nota alterada com sucesso!");
}

void alteraAluno2(ALUNOS *x,int z){
    int a;
    a=procuraAluno(x,z);
    printf("\nAlterar a Nota 2 atual para: ");
    scanf("%f",&x[a].Nota2);
    fflush(stdin);
    printf("Nota alterada com sucesso!");
}

void alteraAluno3(ALUNOS *x,int z){
    int a;
    a=procuraAluno(x,z);
    printf("\nAlterar a Nota 3 atual para: ");
    scanf("%f",&x[a].Nota3);
    fflush(stdin);
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
