#include<stdio.h>
#include<locale.h>

void main() {
    setlocale(LC_ALL, "portuguese");
    float x1, y1, x2, y2, x3, y3;
    float mab, mbc, mac;

    printf("Entre com as coordenadas do ponto A: ");
    scanf("%f %f", &x1, &y1);
    fflush(stdin);

    printf("Entre com as coordenadas do ponto B: ");
    scanf("%f %f", &x2, &y2);
    fflush(stdin);

    printf("Entre com as coordenadas do ponto C: ");
    scanf("%f %f", &x3, &y3);
    fflush(stdin);

    mab=(y2-y1)/(x2-x1);
    mbc=(y3-y2)/(x3-x2);
    mac=(y3-y1)/(x3-x1);

    printf("Coeficiente angular da reta AB = %.2f\n",mab);
    printf("Coeficiente angular da reta BC = %.2f\n", mbc);
    printf("Coeficiente angular da reta AC = %.2f", mac);

}
