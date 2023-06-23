#include <stdio.h>
#include "represa.h"

represa le_represa(){
  represa a;
  scanf("%s",a.nome);
  scanf("%f", & a.M);
  scanf("%d",&a.N);
  for (int k = 0 ; k < a.N ; k++)
    scanf("%d", &a.medida[k]);   
  return a;
}

int tamanho_string(char nome[101]){
  int tamanho = 0,k = 0;
  while (nome[k] != '\0'){
    tamanho++;
    k++;
  }
  return tamanho;
}

int capacidade_max(represa a){
  int verdade = 0;
  for (int k = 0 ; k < a.N ;k++){
    if ((a.medida[k] / a.M) >= 0.9)
      verdade = 1;
  }
  if (verdade == 1)
    return  1;
  else
    return 0;
}

int media_represa(represa a){
  int soma = 0,media;
  for (int k = 0 ; k < a.N ;k++)
    soma += a.medida[k];
  media = soma / a.N ;
  return media;
}

void letra_minuscula(char nome[101]){
  int k = 0;
  while (nome[k] != '\0'){
    if (65 <= nome[k] && nome[k] <= 90)
      nome[k] = nome[k] + 32;
    k++;
  }
}

void espaco(char nome[101]){
  int k = 0;
  while(nome[k] != '\0'){
    if (nome[k] == 95)
      nome[k] = nome[k] - 63;
    k++;
  }
}

void remove_numeros(char nome[101]){
  int k = 0;
  while(nome[k] != '\0'){
   if (48 <= nome[k] && nome[k]<= 57)
      nome[k] = 00;
    k++;
  }
}

void somente_nome(char nome[101], int tamanho){
  int k,palavra = 0;
  char prefixo[11] = "represa_de_";
  for (k = 0 ; k < 11 ; k++)
    if (prefixo[k] == nome[k])
      palavra++;
  if (palavra == 11){
    for (k = 0 ; k < tamanho-11 ; k++)
      nome[k] = nome[k+11];
    
    for(k = 0; k < 12 ; k++)
      nome[tamanho - k] = 00;
  }
}

void manipula_string(int tamanho_string , char nome[101]){
  somente_nome(nome, tamanho_string);
  letra_minuscula(nome);
  espaco(nome);
  remove_numeros(nome);
}

void imprime_dados(represa a){
  manipula_string(tamanho_string(a.nome), a.nome);
  printf("NOME: %s\n", a.nome);
  printf("QTD NIVEIS: %d\n", a.N);
  printf("MEDIA: %d\n", media_represa(a) );
  if (capacidade_max(a) == 1)
    printf("CAPACIDADE ACIMA DE 90%% DA MAXIMA!\n");
  printf("#####\n");
}



