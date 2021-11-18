#include<stdio.h>
#include<locale.h>

int VerConjunto(int *a);
void MenosMemoria(int *a,int b);
void MaisMemoria(int *a,int *b);

void main(void){
    setlocale(LC_ALL,"portuguese");

    int tam;

    int x[15];

    int *y;
    y=(int*)malloc(15*sizeof(int));
    if(!y){
        printf("Memory request failed.\n");
        exit(1);
    }


    printf("Armazenados 10 elementos em um vetor de tamanho 15:\n");
    int i=0;
    while(1){
        x[i]=i;
        y[i]=i;
        if(x[i]==10){
            printf(" %d",x[i]);
            break;
        }else{
            printf(" %d",x[i]);
            i++;
        }
    }
    tam=(i+1);

    VerConjunto(y);
    MaisMemoria(y,tam);


    printf("\n\nQuantidade de valores armazenados no vetor diferente de 0:\n%d elementos do tipo (int)\n",i);/* pegamos o valor do contador i no while como referência para detectar o tamanho efetivo do vetor que é ajustado o tão grande até se for desejado o valor alocado em malloc previamente*/

}

int VerConjunto(int *a){
    printf("\n\nOs números são:\n");
    int i=0;
    while(1){
        if(i!=0 && a[i]==0){
            break;
        }else{
            printf(" %d",a[i]);
            i++;
        }
    }
}

void MenosMemoria(int *a, int b){
    a=(int*)realloc(a,b*sizeof(int));
}

void MaisMemoria(int *a, int *b){
    printf("Aumentar a capacidade de armazenamento para quantos elementos:\n");
    scanf("%d",&b);
    fflush(stdin);
    int c=b;
    a=(int*)realloc(a,c*sizeof(int));
}
