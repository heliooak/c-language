#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int LerIdade(short int *a,short int *b,int x,int y);
int VerIdade(short int *a,int x, char *t);


int main(void){
    setlocale(LC_ALL,"portuguese");

    short int *h,*m;
    int nh,nm;

    printf("Informe a quantidade de homens e mulheres na sala, respectivamente: ");
    scanf("%d %d",&nh,&nm);
    fflush(stdin);

    h=(short int*)malloc(nh*sizeof(short int));

    m=(short int*)malloc(nm*sizeof(short int));

    LerIdade(h,m,nh,nm);
    VerIdade(h,nh,"Conjunto das idades informadas dos homens");
    VerIdade(m,nm,"Conjunto das idades informadas das mulheres");
}


int LerIdade(short int *a,short int *b,int x, int y){
  printf("\nCadastro de idade e gênero das pessoas");
  printf("\nh = homem \nm = mulher\n");

  int idade;
  char genero;
  int i=0;
  int ih=0, im=0;

  while(ih<x || im<y){
    printf("\nInforme a idade e gênero da %d pessoa: ",(i+1));
    scanf("%d %c",&idade,&genero);
    if(genero=='h') {
        if(ih<x){
            a[ih]=idade;
            ih++;
            i++;
        } else {
          printf("\n Total de H já atingido");
        }
    } else {
       if(im<y){
           b[im]=idade;
           im++;
           i++;
       } else {
          printf("\n Total de M já atingido");
      }
    }
  }
}


int VerIdade(short int *a,int x, char *t){
  printf("\n%s:\n",t);
  int k=0;
  while(k<x){
    if(x==1){
      printf("(%d)",a[k]);
    } else {
        if(k==0){
          printf("(%d, ",a[k]);
        }else if(k>0 && k<(x-1)){
          printf("%d, ",a[k]);
        }else{
          printf("%d)",a[k]);
        }
    }
    k++;
  }
}


