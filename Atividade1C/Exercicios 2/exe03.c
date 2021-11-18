#include<stdio.h>
#include<locale.h>

void main() {
    setlocale(LC_ALL, "portuguese");

    float a, b, c, d, m, x;
    printf("Digite as notas 1, 2, 3 e 4 do aluno: ");
    scanf("%f %f %f %f", &a, &b, &c, &d);

    if(a>=b){
        x=a;
        a=b;
        b=x;
    }
    if(a>=c){
        x=a;
        a=c;
        c=x;
    }
    if(a>=d){
        x=a;
        a=d;
        d=x;
    }
    if(b>=c){
        x=b;
        b=c;
        c=x;
    }
    if(b>=d){
        x=b;
        b=d;
        d=x;
    }
    if(c>=d){
        x=c;
        c=d;
        d=x;
    }

    m=(b+c+d)/3;
    printf("As 3 melhores notas organizadas de forma crescente são: (%.1f , %.1f, %.1f)", b, c, d);
    printf("A média das nota é: %.1f", m);
}
