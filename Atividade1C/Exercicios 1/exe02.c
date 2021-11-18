#include<stdio.h>
#include<locale.h>

void main() {
    setlocale(LC_ALL,"portuguese");

    float a, b, c, med;
    printf("Digite o primeiro valor: ");
    scanf("%f", &a);
    fflush(stdin);
    printf("Digite o segundo valor: ");
    scanf("%f", &b);
    fflush(stdin);
    printf("Digite o terceiro valor: ");
    scanf("%f", &c);
    med=(a+b+c)/3;
    printf("A média das nota dos 3 alunos é: %.2f", med);
}
