#include<stdio.h>
#include<string.h>// necessário para strncpy
#include<locale.h>

void main(){
    setlocale(LC_ALL, "portuguese");
    char str1[8] = "Curso C";
    char str2[5];

    strncpy(str2, str1, 5);

    str2[5] = '\0';
    printf("str2= %s\n", str2);
}
