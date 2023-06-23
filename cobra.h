#include <stdio.h>
#include <stdlib.h>

typedef struct elementos_jogo *p_jogo;
typedef struct NO *p_no;
typedef struct lista *cobra;

struct elementos_jogo{
  int linhas,colunas;
  int linha_fruta,coluna_fruta;
  int linha_cobra,coluna_cobra,tamanho_cobra;
  char **matriz;
};

struct NO{
  int posicao[2];
  p_no prox;
  p_no ant;
};

struct lista{
  p_no inicio;
  p_no fim;
};

p_jogo le_entradas();
//*ele ler as entradas iniciais do código e inicializa a matriz

void jogando(p_jogo dados);
//*imprime as acoes do jogador e recebe as novas acoes
