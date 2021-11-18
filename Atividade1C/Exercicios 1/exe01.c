#include<stdio.h>
#import<locale.h>

int main() {
    int a, b, s;
    printf("Digite o primeiro valor: ");
    scanf("%i", &a);
    fflush(stdin);
    printf("Digite o segundo valor: ");
    scanf("%i", &b);
    fflush(stdin);
    s=(a+b);
    printf("A soma dos valores %i + %i = %i", a, b, s);
}
