#include<stdio.h>
#include<string.h>// necessário para strncpy
#include<locale.h>

void main(){
    setlocale(LC_ALL, "portuguese");
    int v1;
    int *v2; // ponteiro para inteiro

    v1=10;

    v2=&v1; // v2 recebe endereço de v1

    printf("\n O valor da variável v1 é %d ", v1);
    // conteúdo de v1
    printf("\n O endereço da variável v1 é %X", &v1);
    // endereço de v1
    printf("\n O valor da variável v2 é %X", v2);
    // conteúdo  de v2, que é o endereço de v1
    printf("\n O endereço da variável v2 é %X", &v2);
    // endereço de v2
    printf("\n O valor para onde o endereço guardado em v2 aponta é %d", *v2);
    // valor para onde o endereço em v2 aponta
}
