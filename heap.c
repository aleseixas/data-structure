#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heap.h"
#define PAI(i) ((i-1)/2)
#define F_ESQ(i) (2*i+1) /*Filho esquerdo de i*/
#define F_DIR(i) (2*i+2) /*Filho direito de i*/

void troca(Item *a, Item *b) {
 Item t = *a;
 *a = *b;
 *b = t;
}

void sobe_no_heap(p_fp fprio, int k) {
if (k > 0 && fprio->v[PAI(k)].chave > fprio->v[k].chave) {
  troca(&fprio->v[k], &fprio->v[PAI(k)]);
  sobe_no_heap(fprio, PAI(k));
  }
}


void desce_no_heap(p_fp fprio, int k) {
int maior_filho;
if (F_ESQ(k) < fprio->n ) {
  maior_filho = F_ESQ(k);
  if (F_DIR(k) < fprio->n && fprio->v[F_ESQ(k)].chave > fprio->v[F_DIR(k)].chave)
    maior_filho = F_DIR(k);
  if (fprio->v[k].chave > fprio->v[maior_filho].chave) {
    troca(&fprio->v[k], &fprio->v[maior_filho]);
    desce_no_heap(fprio, maior_filho);
    }
  }
if(fprio->n == 2)
  troca(&fprio->v[0],&fprio->v[1]);
}

void insere(p_fp fprio, Item item) {
  fprio->v[fprio->n] = item;
  fprio->n++;
  sobe_no_heap(fprio, fprio->n - 1);
}

p_fp cria_fila(int tam){
  p_fp fprio = malloc(sizeof(FP));
  fprio->v = malloc((tam) * sizeof(Item));
  fprio->n = 0;
  fprio->tamanho = tam;
  fprio->v[tam-1].chave = 10000;
  return fprio;
}

int encontra_posicao(int j ,p_fp valor){
  for(int k = 0 ; k < valor->n ; k++){
    if(j == valor->v[k].arquivo)
      return k;
  }
  return 0;
}

void muda_prioridade(p_fp fprio, int k, int valor) {
if (fprio->v[k].chave < valor) {
  fprio->v[k].chave = valor;
  if(fprio->n == 3){
    troca(&fprio->v[1],&fprio->v[2]);
  }
  else
    desce_no_heap(fprio, k);
} 
else {
  fprio->v[k].chave = valor;
  if(fprio->n == 3){
    troca(&fprio->v[2],&fprio->v[1]);
  }
  else
    sobe_no_heap(fprio, k);
  }
}

void tira_lixo(p_fp fprio,int *vetor,int *vetor2){
  int n = 0;
  int k = 0;
  while(n != fprio->n){
    for (int l = 0 ; l < fprio->tamanho ; l++){
      if(fprio->v[k].arquivo == vetor[l]){
        fprio->v[n].arquivo = vetor[l];
        fprio->v[n].chave = vetor2[l];
        n++;
      }
    }
    k++;
  }
}

void remove_h(p_fp fprio,int qnt,int *vetor,int *vetor2){
  printf("PROCESSOS REMOVIDOS:");
  for (int k = 0 ; k < qnt ; k++){
    tira_lixo(fprio, vetor,vetor2);
    printf(" %d",fprio->v[0].arquivo);
    fprio->v[0] = fprio->v[fprio->n];
    fprio->n--;
    desce_no_heap(fprio,0);
  }
  printf("\n");
}

void entradas(){
  int qnt,operacoes,*vetor,*vetor2;
  char operador[1];
  p_fp f;
  Item valor;
  scanf("%d",&qnt);
  f = cria_fila(qnt);
  vetor = malloc(qnt*sizeof(int));
  vetor2 = malloc(qnt*sizeof(int));
  for(int k = 0 ; k < qnt  ; k++){
    scanf("%d",&valor.arquivo);
    scanf("%d",&valor.chave);
    vetor[k] = valor.arquivo;
    vetor2[k] = valor.chave;
    insere(f,valor);
  }
  
  scanf("%d",&operacoes);
  for(int j = 0 ; j < operacoes ; j++){
    scanf("%s",operador);
    if(strcmp(operador,"R")==0){
      scanf("%d",&qnt);
      remove_h(f,qnt,vetor,vetor2);
    }
    else if(strcmp(operador,"M")==0){
      scanf("%d",&valor.arquivo);
      scanf("%d",&valor.chave);
      muda_prioridade(f,encontra_posicao(valor.arquivo,f),valor.chave);
    }
  }
  printf("FINALIZADO!");
}