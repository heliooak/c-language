#include<stdio.h>
#include<string.h>
#include<locale.h>

void Arruma(char *x);

void main(void){
    setlocale(LC_ALL,"portuguese");

    char nome[30];
    printf("Digite seu nome completo:\n");
    scanf("%[^\n]s",nome);
    scanf("%*c");
    fflush(stdin);

    printf("O nome digitado é: %s",nome);

    Arruma(nome);

}

void Arruma(char *x){
    int y,n;
    n=strlen(x);

    for(y=0;y<n;y++){

        if(x[y]==32){
          x[y]=95;
        }
        if(x[y]<90 && x[y]!=32){
            x[y]=x[y]+32;
        }
        if((y==0 || x[y-1]==32) && (x[y]!=32)){
            x[y]=x[y]-32;
        }
        if(x[y]==32 && (x[y-2]=='D')){
            x[y-2]=x[y-2]+32;
        }
        if(x[y]==32 && x[y-3]=='D' && x[y-1]=='s'){
            x[y-3]=x[y-3]+32;
        }
    }
    printf("\n%s",x);
}
