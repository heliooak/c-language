#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>

int main(void){
    setlocale(LC_ALL,"portuguese");

    char *p;

    p=malloc(17);
    if(!p){
        printf("Alocation Error\n");
        exit(1);
    }

    strcpy(p,"This is 16 chars");

    p=realloc(p,18);
    if(!p){
        printf("Allocation Error\n");
        exit(1);
    }

    strcat(p,".");

    printf(p);

    free(p);

    return 0;

}
