#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafo.h"

p_grafo cria_grafo(int n){
  int i;
  p_grafo g = malloc(sizeof(struct grafo));
  g->n = n;
  g->adjacencia = malloc(n * sizeof(p_no));
  for (i = 0; i < n; i++)
    g->adjacencia[i] = NULL;
  return g;
}
void libera_lista(p_no lista) {
  if (lista != NULL) {
   libera_lista(lista->prox);
   free(lista);
  }
}

void destroi_grafo(p_grafo g) {
  int i;
  for (i = 0; i < g->n; i++)
    libera_lista(g->adjacencia[i]);
  free(g->adjacencia);
  free(g);
}

p_no insere_na_lista(p_no lista, int v) {
  p_no novo = malloc(sizeof(struct no));
  novo->valor = v;
  novo->prox = lista;
  return novo;
}


void insere_aresta(p_grafo g, int u, int v) {
  g->adjacencia[v] = insere_na_lista(g->adjacencia[v], u);
  g->adjacencia[u] = insere_na_lista(g->adjacencia[u], v);
}


void imprime_arestas(p_grafo g) {
  int u;
  p_no t;
  for (u = 0; u < g->n; u++)
    for (t = g->adjacencia[u]; t != NULL; t = t->prox)
      printf("{%d , %d}\n", u, t->valor);
}

void distancia(int c , int p , int x , p_grafo g){
  p_no t = g->adjacencia[c];
  int **vetor,contador = 0,max[10];
  vetor = malloc(sizeof(int)*g->n);
  for (int k = 0 ; k < g->n ;k++)
    vetor[k] = malloc(sizeof(int)*g->n);
  for (t = g->adjacencia[c]; t != NULL; t = t->prox){
    printf("boaaaa %d\n",contador);
    contador = 0;
    while(contador < g->n*g->n && t!= NULL){
      printf("oiiii %d\n",t->valor);
      t = t->prox;
      g->adjacencia[t->valor];
      contador++;
    }
  }
}


void entradas(){
  p_grafo g;
  int n_p,n_c,qnt_arestas,v1,v2;
  scanf("%d",&n_c);
  scanf("%d",&n_p);
  scanf("%d",&qnt_arestas);
  g = cria_grafo(n_p+n_c);
  for(int k = 0 ; k < qnt_arestas ; k++){
    scanf("%d",&v1);
    scanf("%d",&v2);
    insere_aresta(g,v1,v2);
  }
  imprime_arestas(g);
  int qnt_operacoes,c,p,x;
  char operador[2];
  scanf("%d",&qnt_operacoes);
  for(int i = 0 ; i < qnt_operacoes ; i++){
    scanf("%s",operador);
    if(strcmp(operador,"D")==0){
      scanf("%d",&c);
      scanf("%d",&p);
      scanf("%d",&x);
      distancia(c, p, x, g);
    }
    else{
      scanf("%d",&c);
      scanf("%d",&p);
    }
  }
}