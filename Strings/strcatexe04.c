#include<stdio.h>
#include<string.h>// necess�rio para strncpy
#include<locale.h>

void main(){
    setlocale(LC_ALL, "portuguese");
    char str1[20] = "Curso";
    char str2[17] = " de programa��ok C";

    strncat(str1, str2, 15);
    // Concatena a string1 com 15 posi��es da string2

    printf("str = %s\n", str1);
    // Ser� exibido Curso de Programa��o
}
