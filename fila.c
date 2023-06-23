#include "fila.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


p_fila criar_fila(int N) {
  p_fila f;
  f = malloc(sizeof(struct fila));
  f->v = malloc(N*sizeof(char));
  f->N = N;
  f->tamanho = 0;
  return f;
};

int saiu_fila(p_fila f,int t){
  for (int k = 0 ; k < f->tamanho - t ; k++){
    f->v[k] = f->v[k+t];
  }
  for(int k = f->tamanho; k >= f->tamanho - t ; k--){
    f->v[k] = 0;
  }
  f->tamanho = f->tamanho - t;
  return 1;
}

void entrou_fila(p_fila f, char palavra[50]){
  int valor = 0;
  for (int k = f->tamanho ; k < f->tamanho + strlen(palavra) ; k++){ 
    f->v[k] = palavra[valor];
    valor++;
  }
  f->tamanho = f->tamanho + strlen(palavra);
}

void imprime_fila(p_fila fila){
  printf("FILA ATUAL: ");
  printf("%s",fila->v);
}

void capta_numeros(char x[]){
  char valor[10];
  int soma=0;
  for (int k = 0 ; k < strlen(x) ; k++){
    if(48 <= x[k] && 57>=x[k]){
      valor[soma] = x[k];
      soma++;
    }
  }
  for(int k = 0 ; k < strlen(valor) ; k++)
    x[k] = valor[k];
}


