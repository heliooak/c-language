#include<stdio.h>
#include<string.h>// necess�rio para strncpy
#include<locale.h>

void main(){
    char str1[4] = "abch";
    char str2[4] = "abd";
    int retorno;

    retorno = strcmp(str1, str2);
    printf("retorno = %d\n", retorno);
    // mostra o retorno da fun��o strcmp
}
