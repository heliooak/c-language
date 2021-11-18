#include<stdio.h>
#include<string.h>// necessário para strncpy
#include<locale.h>

void main(){
   char str[5] = "Curso";
   int tamanho;

   tamanho = strlen(str);

   printf("O tamanho da string %s vale %d\n", str, tamanho);
}
