#include<stdio.h>
#include<string.h>// necess�rio para strncpy
#include<locale.h>

void main(){
    setlocale(LC_ALL, "portuguese");
   int val1, val2;
   int *ponteiro1;

   ponteiro1=&val1;

   printf("\n Digite dois valores: ");
   scanf("%d %d", ponteiro1, &val2);

   printf("\n O valor da vari�vel val1 � %d", val1); // conte�do de val1
   printf("\n O valor da vari�vel v2 � %d", val2);// conte�do de val2
   printf("\n O valor da vari�vel val1 � %d", *ponteiro1); // conte�do de val1
}
