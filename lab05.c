#include <stdio.h>
#include "ultron.h"

int main(void) {
  p_matriz m;
  //entradas do código
  m = le_matriz();
  //operacoes
  operacao(m);
  return 0;
}