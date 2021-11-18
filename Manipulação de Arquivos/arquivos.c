#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
 char nomePessoa[10];
 int idade;
} pessoa;

void gravart(int t){
   FILE *fp;

 if ((fp=fopen ("fileT.txt","w")) != NULL) {
   fprintf(fp,"%d",t);
   fclose(fp);
} else{
     printf("Problema na abertura do arquivo");
 }
}

int carregarT(){
 FILE *fp;
 int t;
 if ((fp=fopen ("fileT.txt","r")) != NULL) {
    fscanf(fp,"%d",&t);
    fclose(fp);
 } else {
    printf("Problema na abertura do arquivo");
    t=0;
 }
 return t;
}


int ordenanome(const void *a, const void *b){
  pessoa *p1, *p2;
  p1=(pessoa*)a;
  p2=(pessoa*)b;

  return strcmp (p1->nomePessoa,p2->nomePessoa);
}
int ordenaidade(const void *a, const void *b){
  pessoa *p1, *p2;
  p1=(pessoa*)a;
  p2=(pessoa*)b;

  return (p1->idade - p2->idade);
}

void ler (pessoa *v, int x){
    printf("Digite seu nome e idade ");
    scanf("%s%i",v[x].nomePessoa,&v[x].idade);

}
void Escrever(pessoa *v, int x){
  for(int posi=0; posi<x; posi++){
    printf("%i - nome %s , idade %i \n", posi, v[posi].nomePessoa,v[posi].idade);

  }
}
void Gravar(pessoa *v, int x) {
 FILE *fp;

 if ((fp=fopen ("file.txt","w")) != NULL) {
   for(int posi=0; posi<x; posi++){
     fprintf(fp,"%s %i\n",v[posi].nomePessoa, v[posi].idade);
   }
    fclose(fp);
 } else {
    printf("Problema na abertura do arquivo");
 }

}
void Carregar(pessoa *v, int x) {
 FILE *fp;

 if ((fp=fopen ("file.txt","r")) != NULL) {
   for(int posi=0; posi<x; posi++){
     fscanf(fp,"%s %i",v[posi].nomePessoa, &v[posi].idade);
   }
    fclose(fp);
 } else {
    printf("Problema na abertura do arquivo");
 }

}
int menu(){
  int op;
  printf("\n-------------------------------------");
  printf("\n 0- SAIR ");
  printf("\n 1- LER ");
  printf("\n 2- MOSTRAR TODOS ");
  printf("\n 3- GRAVAR ");;
  printf("\n 4- ORDENAR POR NOME");
  printf("\n 5- ORDENAR POR IDADE ");
  printf("\n-------------------------------------");

  scanf ("%d",&op);
  return op;
}


void main() {
 pessoa *v;
 int op=1;
 int t=carregarT();
 int n;
 int c=0;

 printf("\n Ja existe %d registros",t);
 printf("\n Alocar para mais quantos");
 scanf("%d",&n);
 n=n+t;
 v=malloc(n*sizeof(pessoa));
 Carregar(v,t);

    while(op>0){
        op=menu();
        if(op==1 && t<n){
         ler(v,t);
         t++;
        }
        if(op==2){
         Escrever(v,t);
        }
        if(op==3){
          Gravar(v,t);
          gravart(t);
        }
        if(op==4){
          qsort(v,t,sizeof(pessoa),ordenanome);
        }
        if(op==5){
          qsort(v,t,sizeof(pessoa),ordenaidade);
        }
      }
}




