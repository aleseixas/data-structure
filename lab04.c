#include <stdio.h>
#include <stdlib.h>

int media(int *vetor, int tamanho) {
  int soma = 0;
  for (int k = 0; k < tamanho; k++)
    soma += vetor[k];
  return soma / tamanho;
}

void normaliza(int media, int *vetor, int tamanho) {
  for (int k = 0; k < tamanho; k++)
    vetor[k] = vetor[k] - media;
}

int vetor_negativo(int vetor[], int tamanho) {
  for (int k = 0; k < tamanho; k++) {
    if (vetor[k] > 0)
      return 0;
  }
  return 1;
}

int subtropas(int tamanho, int tropa[], int valor, int tipo, int tamanho_elite,int *elite) {
  int soma = 0, max = 0, fim = 0, inicio = 0;
  if (vetor_negativo(tropa, tamanho) == 0) {
    for (int k = 0; k < tamanho; k++) {
      soma += tropa[k];
      if (soma < 0) {
        soma = 0;
        inicio = k + 1;
      }
      if (max < soma) {
        max = soma;
        fim = k;
        }
    }
  } 
  else {
    max = tropa[0];
    for (int k = 0; k < tamanho; k++) {
      if (max < tropa[k])
        max = tropa[k];
    }
  }
  if (fim == 0 && tipo == 0)
    inicio = 0;
  // IMPRIME OS TIPOS DE SUBSTROPAS,TIPO = 0 = SUBTROPA FORTE E TIPO = 1 =
  // SUBRTROPA DE ELITE, ALÉM DISSO CRIA O VETOR SUBTROPA ELITE

  if (tipo == 0) {
    if (vetor_negativo(tropa, tamanho) == 0) {
      int total = 0;
      printf("Sub-tropa Forte %d: ", valor);
      for (int k = inicio; k <= fim; k++) {
        printf("%d ", tropa[k]);
        if (valor == 1)
          elite[total] = tropa[k];
        else
          elite[(tamanho_elite) + total] = tropa[k];
        total++;
      }
      printf("\n");
      return total;
  } 
    else {
      printf("Sub-tropa Forte %d: %d \n", valor, max);
      if (valor == 1)
        elite[0] = max;
      else
        elite[tamanho_elite] = max;
      return 1;
    }
  } 
  else {
    if (vetor_negativo(tropa, tamanho) == 0) {
      printf("Sub-tropa Elite: ");
      for (int k = inicio; k <= fim; k++)
        printf("%d ", tropa[k] + valor);
      printf("\n");
      return 0;
    }

    else {
      printf("Sub-tropa Elite: %d \n", max + valor);
      return 0;
    }
  }
}

int main(void) {
  int Q, tamanho_tropa = 0, *tropa, valor, tamanho_elite = 0, *elite;
  elite = (int*)malloc(100 * sizeof(int));
  // quantidade de tropas
  scanf("%d", &Q);
  for (int k = 0; k < Q; k++) {
    valor = k + 1;
    // tamanho da tropa
    scanf("%d", &tamanho_tropa);
    tropa = malloc(tamanho_tropa * sizeof(int));
    // valores das tropas
    for (int k = 0; k < tamanho_tropa; k++) 
      scanf("%d", &tropa[k]);
    tamanho_elite += subtropas(tamanho_tropa, tropa, valor, 0,tamanho_elite, elite);
    free(tropa);
    if (k == Q - 1) {
      int m = 0;
      m = media(elite, tamanho_elite);
      normaliza(m, elite, tamanho_elite);
      subtropas(tamanho_elite, elite, m, 1, tamanho_elite, elite);
      free(elite);
    }
  }
  return 0;
}
