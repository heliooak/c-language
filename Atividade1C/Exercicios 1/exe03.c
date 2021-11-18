#include<stdio.h>
#include<locale.h>

void main() {
    setlocale(LC_ALL, "portuguese");

    float a, b, area;
    printf("Digite o comprimento da base do triângulo: ");
    scanf("%f", &a);
    fflush(stdin);
    printf("Digite o comprimento da altura do triângulo: ");
    scanf("%f", &b);
    fflush(stdin);
    area=(a*b)/2;
    printf("A area do triangulo eh: %.2f", med);
}
