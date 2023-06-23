#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

int posicao(int id){
  int n = 0 ;
  n = id % 2000;
  return n;
}

void insere_hash(char nome[],int tempo,int id, hash h){
  int n;
  n = posicao(id);
  while(h.vetor[n].id != 0)
    n = n + 1;
  strcpy(h.vetor[n].nome_proc,nome);
  h.vetor[n].tempo = tempo;
  h.vetor[n].id = id;
}

void remove_hash(int id_procurado, hash h){
  int n,tamanho;
  n = posicao(id_procurado);
  while(h.vetor[n].id != id_procurado){
    n = n+1;
  }
  h.vetor[n].id = 0;
  tamanho = strlen(h.vetor[n].nome_proc);
  for (int k = 0 ; k < tamanho ; k++)
    h.vetor[n].nome_proc[k] = 0;
  h.vetor[n].tempo = 0;
}

void consulta_nome(int id_procurado, hash h){
  int n;
  n = posicao(id_procurado);
  if(h.vetor[n].id == id_procurado)
    printf("PROCESSO %d: %s\n",id_procurado,h.vetor[n].nome_proc);
  while(h.vetor[n].id != id_procurado){
    n = n+1;
    if(n == 2000){
      printf("PROCESSO %d NAO ENCONTRADO!\n",id_procurado);
      break;
    }
    else if(h.vetor[n].id == id_procurado)
      printf("PROCESSO %d: %s\n",id_procurado,h.vetor[n].nome_proc);
  }
}

void consulta_tempo(int id_procurado, hash h){
  int n;
  n = posicao(id_procurado);
  while(h.vetor[n].id != id_procurado){
    n = n+1;
  }
  printf("TEMPO DO PROCESSO %d: %d DIAS.\n",id_procurado,h.vetor[n].tempo);
}

void entradas(){
  int qnt_operacao;
  Processo p;
  hash h;
  h.vetor = malloc(2000*sizeof(Processo));
  char operacao[1];
  scanf("%d",&qnt_operacao);
  for(int k = 0 ;  k < qnt_operacao ; k++){
    scanf("%s",operacao);
    if(strcmp("I",operacao)==0){
      scanf("%d",&p.id);
      scanf("%s",p.nome_proc);
      scanf("%d",&p.tempo);
      insere_hash(p.nome_proc,p.tempo,p.id,h);
      printf("PROCESSO %d INSERIDO!\n",p.id);
    }
    else if(strcmp("R",operacao)==0){
      scanf("%d",&p.id);
      remove_hash(p.id,h);
      printf("PROCESSO %d REMOVIDO!\n",p.id);
    }
    else if(strcmp("C",operacao)==0){
      scanf("%d",&p.id);
      consulta_nome(p.id,h);
    }
    else{
      scanf("%d",&p.id);
      consulta_tempo(p.id,h);
    }
  }
  printf("FINALIZADO!");
  free(h.vetor);
}