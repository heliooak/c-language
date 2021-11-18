#include<stdio.h>
#include<locale.h>

int main(void){
    setlocale(LC_ALL,"portuguese");
    int t, i, num[4][3];

    for(t=1;t<3;++t){
        for(i=0;i<3;++i){
            printf("Entre com valor na posição [%d][%d]: ",(t-1),i);
            scanf("%d",&num[t][i]);
            fflush(stdin);
            /* num[t][i]=(t*4)+i+1; */
        }
    }

    for(t=0;t<3;++t){
        for(i=0;i<3;++i){
            if(){

            }
            printf("%3d ",num[t][i]);
        }
        printf("\n");
    }
    return 0;
}
