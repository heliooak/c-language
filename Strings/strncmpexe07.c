#include<stdio.h>
#include<string.h>// necess�rio para strncpy
#include<locale.h>

void main(){
    setlocale(LC_ALL, "portuguese");
    int v1;
    int *v2; // ponteiro para inteiro

    v1=10;

    v2=&v1; // v2 recebe endere�o de v1

    printf("\n O valor da vari�vel v1 � %d ", v1);
    // conte�do de v1
    printf("\n O endere�o da vari�vel v1 � %X", &v1);
    // endere�o de v1
    printf("\n O valor da vari�vel v2 � %X", v2);
    // conte�do  de v2, que � o endere�o de v1
    printf("\n O endere�o da vari�vel v2 � %X", &v2);
    // endere�o de v2
    printf("\n O valor para onde o endere�o guardado em v2 aponta � %d", *v2);
    // valor para onde o endere�o em v2 aponta
}
