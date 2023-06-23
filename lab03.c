#include <stdio.h>
#include "represa.h"
int main(void) {
  int T,i;
  represa r;
  scanf("%d", &T);
  for (i = 0 ; i < T ; i++) {
      r = le_represa();
      imprime_dados(r);
    }  
  return 0;
}