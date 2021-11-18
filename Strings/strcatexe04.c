#include<stdio.h>
#include<string.h>// necessário para strncpy
#include<locale.h>

void main(){
    setlocale(LC_ALL, "portuguese");
    char str1[20] = "Curso";
    char str2[17] = " de programaçãok C";

    strncat(str1, str2, 15);
    // Concatena a string1 com 15 posições da string2

    printf("str = %s\n", str1);
    // Será exibido Curso de Programação
}
