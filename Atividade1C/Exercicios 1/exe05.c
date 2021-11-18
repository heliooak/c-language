#include<stdio.h>
#include<locale.h>

void main() {
    setlocale(LC_ALL,"portuguese");

    /* m = montande para saque; nx = notas de 100, notas de 50 ...
    */

    int valor, m, n100, n50, n20, n10, n5, n2, n1;

    printf("Digite o valor desejado: ");
    scanf("%i", &m);
    fflush(stdin);
    valor = m;
    printf("\nValor solicitado: R$ %i,00\n", valor);

    if (m>=100) {
        n100 = m/100;
        m = m%100;
        printf("\nNúmero de notas de R$100,00: %i", n100);
    }if (m>=50)   {
        n50 = m/50;
        m = m%50;
        printf("\nNúmero de notas de R$50,00: %i", n50);
    } if (m>=20)   {
        n20 = m/20;
        m = m%20;
        printf("\nNúmero de notas de R$20,00: %i", n20);
    } if(m>=10)    {
        n10 = m/10;
        m = m%10;
        printf("\nNúmero de notas de R$10,00: %i", n10);
    } if(m>=5)     {
        n5 = m/5;
        m = m%5;
        printf("\nNúmero de notas de R$5,00: %i", n5);
    } if(m>=2)    {
        n2 = m/2;
        m = m%2;
        printf("\nNúmero de notas de R$2,00: %i", n2);
    } if(m>=1)      {
        n1 = m;
        m = 0;
        printf("\nNúmero de notas de R$1,00: %i", n1);
    }

}
