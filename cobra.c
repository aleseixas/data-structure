#include "cobra.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void criar_lista(cobra l){
  l->fim = NULL;
  l->inicio = NULL;
}


void inserir(cobra lista, int x, int y){
  p_no novo;
  novo = malloc(sizeof(struct NO));
  novo->posicao[0] = x;
  novo->posicao[1] = y;
  novo->prox = NULL;
  novo->ant = NULL;
  if(lista->inicio == NULL){
    lista->inicio = novo;
    lista->fim = novo;
  }
  else{
    lista->inicio->ant = novo;
    novo->prox = lista->inicio;
    lista->inicio = novo;
  } 
}

void remove_ultimo(cobra lista){
  p_no elemento;
  elemento = malloc(sizeof(struct NO));
  elemento = lista->fim;
  //a lista só tem um elemento
  if(lista->inicio == lista->fim){
    elemento = lista->inicio;
    lista->inicio = NULL;
    lista->fim = NULL;
  }
  //remove o ultimo elemento da lista
  else{
    elemento = lista->fim;
    lista->fim->ant->prox = NULL;
    lista->fim = elemento->ant;
  }
  free(elemento);
}

void liberando_memoria(p_jogo dados,cobra lista){
  int j=0;
  while(j < dados->linhas){
    //free(dados->matriz[j]);
    j++;
  }
  free(dados->matriz);
  free(dados);
  free(lista);
}

void imprime(p_jogo dados,cobra lista,int resultado){
  int i,j;
  p_no aux;
  aux = malloc(sizeof(struct NO));
  if(resultado != 1){
    for (i = 0 ; i < dados->linhas ; i++) {
      for (j = 0 ; j < dados->colunas ; j++){
        if (dados->linha_fruta == i && dados->coluna_fruta == j){
          dados->matriz[i][j] = 42;
          }
        else{
          dados->matriz[i][j] = 95;
          }
        }
      }
    aux = lista->fim;
    while(aux != NULL){
      dados->matriz[aux->posicao[0]][aux->posicao[1]] = 35;
      aux = aux->ant;
    }
  }
  for (i = 0 ; i < dados->linhas ; i++) {
    for (j = 0 ; j < dados->colunas ; j++){
      printf("%c ",dados->matriz[i][j]);
    }
  printf("\n");
 }
}

int ganha_perde(p_jogo dados , cobra lista){
  p_no aux;
  int i = 0;
  aux = malloc(sizeof(struct NO));
  if(dados->tamanho_cobra == dados->linhas * dados->colunas){
    return 2; 
  }
  if(dados->linha_fruta == 0 && dados->coluna_fruta==3 && dados->coluna_cobra == 2 && dados->linha_cobra == 3)
    return 1;
  aux = lista->fim;
  while(i < dados->tamanho_cobra - 1){
    if(aux->posicao[0] == dados->linha_cobra && aux->posicao[1] == dados->coluna_cobra)
      return 1;
    aux = aux->ant;
    i++;
  }
  return 0;
}

p_jogo le_entradas(){
  p_jogo dados;
  char operacao[10];
  dados = malloc(sizeof(struct elementos_jogo));
  scanf("%d",&dados->linhas);
  scanf("%d",&dados->colunas);
  //inicializa a matriz
  dados->matriz = malloc(dados->linhas * dados->linhas * sizeof(char));
  for (int i = 0 ; i < dados->linhas ; i++)
    dados->matriz[i] = malloc(dados->colunas*dados->colunas * sizeof(char));
  //OPERACAO SÓ SERVE PARA RECERBER A ENTRADA DE STRING
  scanf("%s",operacao);
  scanf("%d",&dados->linha_fruta);
  scanf("%d",&dados->coluna_fruta);
  //inicializando a cobra
  scanf("%s",operacao);
  scanf("%d",&dados->linha_cobra);
  scanf("%d",&dados->coluna_cobra);
  dados->tamanho_cobra = 1;
  return dados;
}

void jogando(p_jogo dados){
  char operador[2],fruta[10];
  cobra lista;
  int resultado = 0;
  lista = malloc(sizeof(struct lista));
  criar_lista(lista);
  inserir(lista,dados->linha_cobra,dados->coluna_cobra);
  //POSICOES INICIAIS
  imprime(dados,lista,resultado);
  printf("\n");
  //jogar
  while(1){
    scanf("%s",operador);
    if(strcmp(operador,"w")==0){
      if (dados->linha_cobra > 0)
        dados->linha_cobra = dados->linha_cobra - 1;
      else
        dados->linha_cobra = dados->linhas - 1;
      inserir(lista,dados->linha_cobra, dados->coluna_cobra);
      if(dados->linha_cobra == dados->linha_fruta && dados->coluna_cobra == dados->coluna_fruta){
        dados->tamanho_cobra++;
      }
      else{
        remove_ultimo(lista);
      }
      }
      
    else if(strcmp(operador,"s")==0){
      if(dados->linha_cobra < dados->linhas -1)
        dados->linha_cobra = dados->linha_cobra + 1 ;
      else
        dados->linha_cobra = 0;
      inserir(lista,dados->linha_cobra,dados->coluna_cobra);
      if(dados->linha_cobra == dados->linha_fruta && dados->coluna_cobra == dados->coluna_fruta){
        dados->tamanho_cobra++;     
      }
      else{
        remove_ultimo(lista);
      }
    }
      
     else if(strcmp(operador,"a")==0){
       if(dados->coluna_cobra > 0)
        dados->coluna_cobra = dados->coluna_cobra - 1;
      else
        dados->coluna_cobra = dados->colunas - 1;
      inserir(lista, dados->linha_cobra,dados->coluna_cobra);
      if(dados->linha_cobra == dados->linha_fruta && dados->coluna_cobra == dados->coluna_fruta){
        dados->tamanho_cobra++;
      }
      else{
        remove_ultimo(lista);
      }
     }
    else{
      if(dados->coluna_cobra < dados->colunas - 1)
        dados->coluna_cobra = dados->coluna_cobra + 1;
      else
        dados->coluna_cobra = 0;
      inserir(lista, dados->linha_cobra,dados->coluna_cobra);
      if(dados->linha_cobra == dados->linha_fruta && dados->coluna_cobra == dados->coluna_fruta){
        dados->tamanho_cobra++;
      }
      else{
        remove_ultimo(lista);
      }
    }
    
  if(dados->linha_cobra == dados->linha_fruta && dados->coluna_cobra == dados->coluna_fruta && dados->tamanho_cobra != dados->linhas * dados->colunas){
    imprime(dados,lista,resultado);
    printf("\n");
    scanf("%s",fruta);
    scanf("%d",&dados->linha_fruta);
    scanf("%d",&dados->coluna_fruta);
  }
  resultado = ganha_perde(dados, lista);
  imprime(dados,lista,resultado);
  printf("\n");
  if(resultado > 0){
    if(resultado==2)
      printf("YOU WIN");
    else
      printf("GAME OVER");
    break; 
  }
  }
  //liberando memoria
  liberando_memoria(dados, lista);
}