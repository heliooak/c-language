#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int GeraVetor(int **a,int *b);
int VerVetor(int *a,int b);

int main(void){
    setlocale(LC_ALL,"Portuguese");

    int tam;

    int *x;
    x = (int*)malloc(5*sizeof(int));
    if(!x){
      printf("Memory request failed.\n");
      exit(1);
    }

    GeraVetor(&x,&tam);
    VerVetor(x,tam);

}

int GeraVetor(int **a,int *b){

  printf("Digite 00 para sair\n");
  int i=0;
  while(1){
    printf("Entre com o %dº valor: ",(i+1));
    scanf("%d",&(*a)[i]);
    fflush(stdin);
    if((*a)[i]==00){
      break;
    }else{
        i++;
    }if(i==4){
        *a = (int *)realloc(*a,20*sizeof(int));
    }
  }
  *b=i;
}

int VerVetor(int *a,int b){
    printf("\nVetor informado:\n");
    int i;
    for(i=0;i<b;i++){
        printf(" %d",a[i]);
    }
}
