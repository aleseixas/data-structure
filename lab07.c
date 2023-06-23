#include <stdio.h>
#include "pilha.h"
#include "fila.h"
#include <string.h>
#include <stdlib.h>

int main(void) {
  char comando[50];
  p_fila f;
  p_pilha p;
  f = criar_fila(500);
  p = criar_pilha();
  //looping
  while(1){
    fgets(comando,50,stdin);
    comando[strlen(comando) - 1] = '\0';
    if(strncmp(comando,"EXI",3)==0){
        break;
    }
    else if(strncmp(comando,"EXEC",4) == 0){
      capta_numeros(comando);
      int valor = atoi(comando);
      insere_pilha(p,f, valor);
      saiu_fila(f, valor);
      imprime_fila(f);
      imprime_pilha(p);
    }
    else if(strncmp(comando,"DEL",3) == 0){
      capta_numeros(comando);
      int valor = atoi(comando);
      remove_pilha(p,valor);
      imprime_fila(f);
      imprime_pilha(p);
    }
    else {
      entrou_fila(f,comando);
      imprime_fila(f);
      imprime_pilha(p);
    }
  }
  //liberando memoria
  free(f->v);
  free(f);
  destruir_lista(p->topo);
  free(p);
}