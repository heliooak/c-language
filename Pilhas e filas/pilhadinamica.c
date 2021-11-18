#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

typedef struct{
    int dado;
    struct NO *prox;
}NO;

typedef struct{
    NO *topo;
}PILHA;

void inicializaPilha(PILHA *p){
    p->topo=NULL;
}

void empilha(int dado,PILHA *p){
    NO *ptr=(NO*)malloc(sizeof(NO));
    if(ptr==NULL){
        printf("ERRO: aloca��o de n�.\n");
        return;
    }else{
        ptr->dado=dado;
        ptr->prox=p->topo;
        p->topo=ptr;
    }
}

int desempilha(PILHA *p){
    NO *ptr=p->topo;
    int dado;
    if(ptr==NULL){
        printf("ERRO: Pilha vazia.\n");
        return;
    }else{
        p->topo=ptr->prox;
        ptr->prox=NULL;
        dado=ptr->dado;
        free(ptr);
        return dado;
        printf("Dado excluido: %d\n",dado);
    }
}

void imprimePilha(PILHA *p){
    NO *ptr=p->topo;
    if(ptr==NULL){
        printf("ERRO: Pilha vazia\n");
    }else{
        while(ptr!=NULL){
            printf("%d ",ptr->dado);
            ptr=ptr->prox;
        }
        printf("\n");
    }
}

int main(){
    PILHA *p1 = (PILHA*)malloc(sizeof(PILHA));
    if(p1==NULL){
        printf("ERRO: Aloca��o da pilha.\n");
    }else{
        inicializaPilha(p1);

        empilha(10,p1);
        empilha(20,p1);
        empilha(30,p1);

        imprimePilha(p1);

        printf("Tentando desempilhar - resultado: %d.\n", desempilha(p1));
        printf("Tentando desempilhar - resultado: %d.\n", desempilha(p1));
        printf("Tentando desempilhar - resultado: %d.\n", desempilha(p1));
    }
}
