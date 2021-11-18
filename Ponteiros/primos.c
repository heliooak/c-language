#include<stdio.h>
#include<locale.h>

void LerVetor(int *a);
void VerVetor(int *a);
void TestaPrimo(int *a);
void VerPrimos(int *a, int b);

int valores[10];
int primos[10];

int main(void){
  setlocale(LC_ALL,"portuguese");

  LerVetor(valores);
  VerVetor(valores);
  TestaPrimo(valores);
}

void LerVetor(int *a){
    printf("Digite dez valores de sua escolha\n----------------------------------\n");
    int i;
    for(i=0;i<10;i++){
        printf("Digite o %dº valor: ",(i+1));
        scanf("%d",&a[i]);
        fflush(stdin);
    }
}

void VerVetor(int*a){
    int j=0;
    printf("\n\nValores digitados:\n");
    while (j<10){
        if(j==0){
            printf("(%d, ",a[j]);
        }else if(j==9){
            printf("%d)",a[j]);
        }else{
        printf("%d, ", a[j]);
        }
        j++;
    }
}

void TestaPrimo(int*a){
  int i=0;
  int tam=0;
  while(i<10){
    int y=0;
    int z=1;
    while(z<=(a[i]/2)){
      if((a[i]%z)==0){
        y++;
      }
      z++;
    }
    if(y==1){
      printf("\nO número %d é primo", a[i]);
      primos[i]=a[i];
      tam++;
    }else{
      printf("\nO número %d não é primo",a[i]);
    }
    i++;
  }
  printf("\n\nExistem %d números primos:\n", tam);
  VerPrimos(primos,tam);
}

void VerPrimos(int *a, int b){
  int j=0;
  while(j<b){
    if(j==0){
      printf("(%d, ",a[j]);
    }else if(j==(b-1)){
      printf("%d)",a[j]);
    }else{
      printf("%d, ", a[j]);
    }
    j++;
  }
}

