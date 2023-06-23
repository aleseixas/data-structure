#include "ultron.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

p_matriz le_matriz(){
  p_matriz dados;
  dados = malloc(sizeof(struct matriz));
  scanf("%d",&dados->linhas);
  scanf("%d",&dados->colunas);
  dados->l_alocado = dados->linhas*2;
  dados->c_alocado = dados->colunas*2;
  //alocando matriz
  dados->matriz = malloc((dados->l_alocado) * sizeof(int*));
  for (int i = 0 ; i < dados->l_alocado ; i++){
    dados->matriz[i] = malloc((dados->c_alocado) * sizeof(int));
    }
  //entrada matriz
  for (int i= 0 ; i < dados->linhas ; i++){
    for (int j = 0 ; j < dados->colunas ; j++){
      scanf("%d",&dados->matriz[i][j]);
    }
  }
  return dados;
}

void imprime_matriz(p_matriz M) {
  int i, j;
  for (i = 0; i < M->linhas ; i++) {
    for (j = 0; j < M->colunas ; j++)
      printf("%d ", M->matriz[i][j]);
  printf("\n");
 }
}

void insere_linhas(p_matriz M, int *vetor){
  for (int k = 0 ; k < M->colunas ; k++){
    M->matriz[M->linhas][k] = vetor[k];
  }
  M->linhas = M->linhas + 1;
  imprime_matriz(M);
}

void orderna_linha(int *coluna , int tamanho){
  int j,i,aux;
  for(i = 1 ; i < tamanho ; i++){
    aux = coluna[i];
    for (j = i ; (j>0) && (aux < coluna[j-1]) ; j-- )
      coluna[j] = coluna[j-1];
    coluna[j] = aux;
  }  
}

void insere_colunas(p_matriz M , int *vetor){
  for (int k = 0 ; k < M->linhas ; k++){
    for (int j = M->colunas ; j >= 0 ; j--){
      M->matriz[k][j+1] = M->matriz[k][j]; 
      if (j==0)
        M->matriz[k][j] = vetor[k];
    }
  }
  //ordenando as linhas com o vetor
  M->colunas = M->colunas + 1;
  for(int k = 0 ; k < M->linhas ; k++)
    orderna_linha(M->matriz[k], M->colunas);
  imprime_matriz(M);  
}


void out_linhas(int posicao , p_matriz M){
  for(int i = posicao  ; i < M->linhas ; i++){
   for (int j = 0 ; j < M->colunas ; j++){
      M->matriz[i][j] = M->matriz[i+1][j];
    }
  }
  M->linhas = M->linhas-1;
  imprime_matriz(M);
}

void out_colunas(int posicao , p_matriz M){
  for(int i= 0 ; i < M->linhas ; i++){
    for (int j = posicao ; j < M->colunas ; j++ ){
      M->matriz[i][j] = M->matriz[i][j+1];
    }
  }
  M->colunas = M->colunas - 1;
  imprime_matriz(M);
}

void check_alocacao(p_matriz dados){
  if (dados->linhas == dados->l_alocado){
    dados->matriz = realloc(dados->matriz,(2*dados->l_alocado)*sizeof(int));
    dados->l_alocado = dados->l_alocado * 2;
    }
  if (dados->colunas == dados->c_alocado){
    for (int i = 0 ; i < dados->l_alocado ; i++)
      dados->matriz[i] = realloc(dados->matriz[i],2*(dados->c_alocado)*sizeof(int));
    dados->c_alocado = dados->c_alocado * 2;
  }
  
  if(dados->linhas == dados->l_alocado / 4){
    dados->matriz = realloc(dados->matriz, (dados->l_alocado / 2 )*sizeof(int));
    dados->l_alocado = dados->l_alocado / 2;
    }
  if (dados->colunas == dados->c_alocado / 4){
    for (int i = 0 ; i < dados->l_alocado ; i++)
      dados->matriz[i] = realloc(dados->matriz[i],(dados->c_alocado/2)*sizeof(int));
    dados->c_alocado = dados->c_alocado / 2;
  }
  
}

void liberando_memoria(p_matriz dados){
  for (int i = 0 ; i < dados->l_alocado ; i++){
    free(dados->matriz[i]);
  }
  free(dados->matriz);
}

void operacao(p_matriz dados){
  int *vetor,total,posicao;
  char operador[10],tipo_operador[5];
  scanf("%d",&total);
  for (int k = 0 ; k < total ; k++){
    scanf("%s",operador);
    if (strcmp(operador,"IN")==0){
      scanf("%s",tipo_operador);
      if (strcmp(tipo_operador,"C")==0){
        vetor = malloc(dados->linhas * sizeof(int));
        for (int v = 0 ; v < dados->linhas ; v++)
          scanf("%d",&vetor[v]);
        insere_colunas(dados,vetor);
      }
      else{
        vetor = malloc(dados->colunas * sizeof(int));
        for (int v = 0 ; v < dados->colunas ; v++)
          scanf("%d",&vetor[v]);
        insere_linhas(dados,vetor);
      }
    }
    else if(strcmp(operador,"OUT")==0){
      scanf("%s",tipo_operador);
      if (strcmp(tipo_operador,"C")==0){
        scanf("%d",&posicao);
        out_colunas(posicao, dados);
      }
      else{
        scanf("%d",&posicao);
        out_linhas(posicao,dados);
      }
    }
    check_alocacao(dados);
    printf("###\n");
  }
  free(vetor);
  liberando_memoria(dados);
  free(dados);
  printf("COMBINACAO MATRICIAL FINALIZADA!");
}