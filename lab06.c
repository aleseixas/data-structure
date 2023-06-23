#include <stdio.h>
#include "cobra.h"

int main(void) {
  p_jogo elementos;
  elementos = le_entradas();
  //ACOES DO JOGADOR
  jogando(elementos);
  return 0;
}