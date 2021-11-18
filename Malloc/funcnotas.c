#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>

int MedTurma(short int *a, int b);
int MedBaixa(short int *a, int b, int c);

int main(void){
    setlocale(LC_ALL,"portuguese");

    short int *notas;
    int n;

    printf("Informe a quantidade de alunos: ");
    scanf("%d",&n);
    fflush(stdin);

    notas = (short int*)malloc(n*sizeof(short int));
    if(!notas){
        printf("Memory request failed.\n");
        exit(1);
    }

    for(int i=0;i<n;i++){
        printf("Digite a nota do %dº aluno: \n",(i+1));
        scanf("%d",&notas[i]);
    }

    printf("\nConjunto das notas:\n");
    for(int i=0;i<n;i++){
        printf(" %d",notas[i]);
    }

    MedTurma(notas,n);

    free(notas);
}

int MedTurma(short int *a, int b){
    int i;
    int med=a[0];
    for(i=1;i<b;i++){
        if(i==(b-1)){
            med=((med+a[i])/b);
        }else{
            med=med+a[i];
        }
    }
    printf("\nA média da turma é: %d\n",med);
    MedBaixa(a, b, med);
}

int MedBaixa(short int *a, int b, int c){
    int i;
    printf("Notas abaixo da média: \n");
    for(i=0;i<b;i++){
        if(a[i]<c){
            printf(" %d",a[i]);
        }
    }
}
