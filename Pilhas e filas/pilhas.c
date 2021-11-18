#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 int desempilha(char *pilha, int *topo, char caracter);
 int empilha(char *pilha, int *topo, char caracter);

  void main(){
        char palavra[20];

       printf("Digite a palavra ");
       scanf("%s",palavra);

       analisa(palavra);
}

void analisa(char *vetor){
          int t,x;
          char letra;
          char pilha[20];
          int topo=-1;
          int status=0;

          t=strlen(vetor);
          x=0;

  while(x<t && status==0){
              letra=vetor[x];
              if(letra== '(' ){
                  status=empilha(pilha,&topo,')');
             }
             if(letra== '[' ){
                  status=empilha(pilha,&topo,']');
             }
             if(letra== '{' ){
                  status=empilha(pilha,&topo,'}');
             }

             if(letra== ')' || letra== ']' || letra== '}' ){
                  status=desempilha(pilha,&topo,letra);
             }

           x++;

}

       if(status==0 && topo==-1){
            printf("\n Reconheceu OK");
      } else {
          printf("\n Nao reconheceu ");
      }

}


 int empilha(char *pilha, int *topo, char caracter){
                  if((*topo)<19) {
	                  (*topo)++;
                	   pilha[*topo]=caracter;
                                   return 0;
	} else {
	          return 1;
               }
}

 int desempilha(char *pilha, int *topo, char caracter){
	if(pilha[(*topo)]==caracter){

  (*topo)--;
                    return 0;
	} else {
	    return 1;
               }
}
