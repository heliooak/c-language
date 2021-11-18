#include<stdio.h>
#include<string.h>
#include<locale.h>

void main(){

    char a[20];
    int x, y;

    scanf("%[^\n]s", a); /* scanf que permite ler
                                        ler espaços em branco*/
    scanf("%*c"); // limpa o buffer do teclado do scanf %[^\n]s //

    printf("Digitou %s", a);

    x=strlen(a);
    printf("\n Tamanho %d", x);

    for(y=0;y<=x;y++){
        printf("\n %c %d", a[y], a[y]);
    }
}
