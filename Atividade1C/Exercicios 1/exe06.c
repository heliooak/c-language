#include<stdio.h>
#include<locale.h>

void main() {
    setlocale(LC_ALL,"portuguese");

    float a, h, m, s;
    printf("Conversor de segundos para hh:mm:ss\nDigite a quantidade de segundos: ");
    scanf("%f", &a);
    fflush(stdin);

    printf("\nQuantidade de segundos informados: %.0fs\n", a);

    if (a>59)   {
        m=a/60;
        s=(int)a%60;
        if (m>59)   {
            h=m/60;
            m=(int)m%60;
        } else  {
            h=0;
        }
        printf("A quantidade de tempo informada é: %2.fh:%2.fm:%2.fs", h, m, s);
    } else{
        printf("A quantidade de tempo informada é: 00:00:%f", a);
    }
}
