#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int GuardarDados(int *a, float *b, float *c, int d);
int MostrarDados(int *a, float *b, float *c, int d, int e);
int MediaIdades(int *a, int b, int *c);
int MaisBaixa(int *c, float *d, float *x, int qtde);


void main(){
    setlocale(LC_ALL,"portuguese");

    int qtde, *media, *idade;
    float *peso, *altura;


    printf("Informe a quantidade de pessoas a serem cadastradas: ");
    scanf("%d",&qtde);
    fflush(stdin);
    idade=(int*)malloc(qtde*sizeof(int));
    if(!idade){
        printf("Memory request failed.\n");
        exit(1);
    }

    peso=(float*)malloc(qtde*sizeof(float));
    if(!peso){
        printf("Memory request failed.\n");
        exit(1);
    }

    altura=(float*)malloc(qtde*sizeof(float));
    if(!altura){
        printf("Memory request failed.\n");
        exit(1);
    }


    GuardarDados(idade,peso,altura,qtde);
    MediaIdades(idade,qtde,&media);
    MostrarDados(idade,peso,altura,qtde,media);
    MaisBaixa(idade,peso,altura,qtde);

}

int GuardarDados(int *a, float *b, float *c, int d){
    int n=0;
    while(n<d){
        printf("Digite os seguintes dados da %dª Pessoa:  Idade, Peso, Altura: ",(n+1));
        scanf("%d %f %f",&a[n],&b[n],&c[n]);
        fflush(stdin);
        n++;
    }
}

int MediaIdades(int *a, int b, int *c){
    int m=a[0];
    int i;
    for(i=1;i<b;i++){
        if(i==(b-1)){
            m=(m+a[i])/b;
        }else{
            m=(m+a[i]);
        }
    }
    *c=m;
}

int MostrarDados(int *a, float *b, float *c, int d, int e){
    printf("\n-----------------------------\nDados gerais cadastrados: ");
    int i=0;
    while(i<d){
        printf("\n(%d anos, %.2f kg, %.2f m)",a[i],b[i],c[i]);
        i++;
    }
    printf("\n-----------------------------\nMédia das idades: %d",e);

    printf("\n------------------------------\nPessoas maiores de idade:");
    int j,k,l;
    for(j=0;j<d;j++){
        if(a[j]>=18){
            printf("\n(%d anos, %.2f kg, %.2f m)",a[j],b[j],c[j]);
        }
    }

    printf("\n------------------------------\nPessoas com idade acima da media:");
    for(k=0;k<d;k++){
        if(a[k]>e){
            printf("\n(%d anos, %.2f kg, %.2f m)",a[k],b[k],c[k]);
        }
    }
}

int MaisBaixa(int *c, float *d, float *x, int qtde){
    int a,b;
    float y;
    for(a=0;a<qtde;a++){
        for(b=(a+1);b<qtde;b++){
            if(x[a]>=x[b]){
                y=x[a];
                x[a]=x[b];
                x[b]=y;
                c[a]=c[b];
                d[a]=d[b];
            }
        }
    }
    printf("\n-----------------------------\nOrdem das alturas: ");
    int i=0;
    while(i<qtde){
        if(i==0){
            printf("(%.2f m, ",x[i]);
        }
        if(i==(qtde-1)){
            printf("%.2f m)",x[i]);
        }else if(i!=0){
            printf("%.2f m, ",x[i]);
        }
        i++;
    }
    printf("\n-----------------------------\nDados da pessoa mais baixa:\n(%d anos, %.2f kg, %.2f m)",c[0],d[0],x[0]);
}



