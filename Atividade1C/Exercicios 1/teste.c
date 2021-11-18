#include<stdio.h>
#include<locale.h>

void main() {
    setlocale(LC_"portuguese");
    int m, n100, r100;
    printf("Digite o valor desejado: ");
    scanf("%d", &m);
    fflush(stdin);
    printf("Valor solicitado R$ %d", m);


    if (m>=100) {
        n100 = m/100;
        r100 = m%100;
    }
    printf("\nNumero de notas de 100: %i", n100);
    printf("\nResto dos valores da divisão: %i", r100);

}
