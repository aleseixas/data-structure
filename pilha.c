#include "fila.h"
#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


p_pilha criar_pilha(){
  p_pilha valor = malloc(sizeof(struct pilha));
  valor->topo = NULL;
  return valor;
}

void remove_pilha(p_pilha pilha,int tamanho) {
  p_no topo = pilha ->topo;
  int t = strlen(topo->palavra);
  for(int k = t ; k >=(t - tamanho) ; k--){
    topo->palavra[k] = 0;
  }
}

void insere_pilha(p_pilha pilha , p_fila fila, int tamanho){
  p_no novo = malloc(sizeof(struct no));
  for (int k = 0 ; k < tamanho ; k++){
    novo->palavra[k] = fila->v[k];
  }
  novo ->proximo = pilha ->topo;
  pilha->topo = novo;
}

void imprime_pilha(p_pilha pilha){
  p_no valor = malloc(sizeof(struct no));
  int tamanho = 0;
  printf("\nPILHA ATUAL: ");
  valor = pilha->topo;
  while(valor){
    valor = valor->proximo;
    tamanho++;
  }
  valor = pilha->topo;
  if(valor != NULL){
    for (int k = 0 ; k < tamanho ; k++){
      valor = pilha->topo;
      for (int j = k ; j < tamanho ; j++){
        if (j == tamanho - 1)
          printf("%s",valor->palavra);
        valor = valor->proximo;
      }
    }
  }
  printf("\n####\n");
}

void destruir_lista(p_no lista) {
 if (lista != NULL) {
    destruir_lista(lista->proximo);
    free(lista);
}
}
