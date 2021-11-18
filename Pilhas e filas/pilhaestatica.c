#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

#define N 3

typedef struct{
    int dados[N];
    int topo;
}PILHA;

void inicializaPilha(PILHA *p){
    int i;
    for(i=0;i<N;i++);{
        p->dados[i]=0;
    }
    p->topo=0;
}

void empilhaPilha(int dado, PILHA *p){
    if(p->topo==N){
        printf("ERRO: Pilha cheia.\n");
    }else{
        p->dados[p->topo]=dado;
        p->topo++;
        return;
    }
}

int desempilhaPilha(PILHA *p){
    if(p->topo==0){
        printf("ERRO: Pilha vazia.\n");
        return;
    }else{
        p->topo--;
        return p->dados[p->topo];
    }
}

void imprimePilha(PILHA *p){
    printf("Imprimindo a pilha:\n");
    int i;
    for(i=0;i<(p->topo);i++){
        printf(" %d",p->dados[i]);
    }
    printf("\n");
}

int main(){
    setlocale(LC_ALL,"portuguese");

    PILHA p1;

    inicializaPilha(&p1);

    empilhaPilha(10,&p1);
    empilhaPilha(20,&p1);
    empilhaPilha(30,&p1);
    empilhaPilha(40,&p1);

    imprimePilha(&p1);


    printf("\n");
    system("pause");
    system("cls");

    printf("Desempilhando: %d\n",desempilhaPilha(&p1));
    printf("Desempilhando: %d\n",desempilhaPilha(&p1));
    printf("Desempilhando: %d\n",desempilhaPilha(&p1));
    desempilhaPilha(&p1);
}
