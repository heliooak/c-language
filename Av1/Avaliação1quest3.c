#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int Armazena(int *a, int b);
int Escreve(int *a, int b);
int Impares(int *a, int b);
int Positivos(int *a, int b);
int Multiplos(int *a, int b);

void main(void){
    setlocale(LC_ALL,"Portuguese");

    int n;
    int *x;

    printf("Informe o tamanho do vetor: ");
    scanf("%d",&n);
    fflush(stdin);

    x=(int *)malloc(n*sizeof(int));
    if(!x){
        printf("memory fail");
        exit(1);
    }

    Armazena(x,n);
    Escreve(x,n);
    Impares(x,n);
    Positivos(x,n);
    Multiplos(x,n);
}

int Armazena(int *a, int b){
    printf("-----Armazenamento-----");
    int i=0;
    while(i<b){
        printf("\n%d� n�mero: ",(i+1));
        scanf("%d",&a[i]);
        fflush(stdin);
        i++;
    }
}

int Escreve(int *a, int b){
    printf("\n-----Foram armazenados-----\n");
    int i;
    for(i=0;i<b;i++){
        printf(" %d",a[i]);
    }
}

int Impares(int *a, int b){
    printf("\n-----S�o �mpares-----\n");
    int i, d;
    for(i=0;i<b;i++){
        d=a[i];
        if(d%2!=0){
            printf(" %d",d);
        }
    }
}

int Positivos(int *a, int b){
    printf("\n-----S�o positivos------\n");
    int i, d;
    for(i=0;i<b;i++){
        d=a[i];
        if(d>0){
            printf(" %d",d);
        }
    }
}

int Multiplos(int *a, int b){
    printf("\n-----S�o m�ltiplos de 7 ou de 9-----\n");
    int i, d;
    for(i=0;i<b;i++){
        d=a[i];
        if((d%7==0) || (d%9==0)){
                printf(" %d",d);
        }
    }
}
