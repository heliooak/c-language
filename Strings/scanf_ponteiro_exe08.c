#include<stdio.h>
#include<string.h>// necessário para strncpy
#include<locale.h>

void main(){
    setlocale(LC_ALL, "portuguese");
   int val1, val2;
   int *ponteiro1;

   ponteiro1=&val1;

   printf("\n Digite dois valores: ");
   scanf("%d %d", ponteiro1, &val2);

   printf("\n O valor da variável val1 é %d", val1); // conteúdo de val1
   printf("\n O valor da variável v2 é %d", val2);// conteúdo de val2
   printf("\n O valor da variável val1 é %d", *ponteiro1); // conteúdo de val1
}
