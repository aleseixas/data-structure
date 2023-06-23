#include <stdio.h>
#include <string.h>
#define MAX 99

void imprime_matriz_quadrada(int M[][MAX], int n) {
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++)
      printf("%d ", M[i][j]);
  printf("\n");
 }
}

void criando_matriz(int A[][MAX], int n){
  int i, j, valor;
  for (i = 0 ; i < n ; i++){
    valor = 0;
    for (j = 0 ; j < n ; j++){ 
      valor++;
      if ( valor <= 3)
        A[i][j] = 1;
      if ( valor == 6)
        valor = 0;
  }
}
}

void copia_matriz(int A[][MAX],int novos_valores[][MAX], int n){
  int i,j;
  for (i = 0; i < n; i++) 
    for (j = 0; j < n; j++){
      A[i][j] = novos_valores[i][j];
    }
}

void transposta(int A[][MAX], int B[][MAX], int n){
  int i,j;
  char valor[1],matriz[1];
  scanf("%s", valor);
  scanf("%s", matriz);
  for (i = 0 ; i < n ; i++)
    for (j = 0 ; j < n ; j++){
      if (strcmp(matriz,"B") == 0)
        B[i][j] = A[j][i];
      else if(strcmp(matriz,"A") == 0)
        A[i][j] = B[j][i];    
    }
  if (strcmp(matriz,"B") == 0)
    imprime_matriz_quadrada(B, n);
  else
    imprime_matriz_quadrada(A, n);
}

void soma(int A[][MAX], int B[][MAX], int n){
  int i,j;
  char soma_1[3],soma_2[3],matriz[3];
  scanf("%s", soma_1);
  scanf("%s", soma_2);
  scanf("%s", matriz);
  for (i = 0 ; i < n ; i++)
    for (j = 0 ; j < n ; j++){
      if (strcmp(matriz,"B") == 0){
        if(strcmp(soma_1,soma_2) == 0){
          copia_matriz(B, A , n);
        }
        else{
          if (A[i][j] + B[i][j] >= 2)
            B[i][j] = 1;
          else
            B[i][j] = A[i][j] + B[i][j];
          }}
      else if (strcmp(matriz,"A") == 0){
        if(strcmp(soma_1,soma_2) == 0){
          A[i][j] = A[i][j];
        }
        else{
          if (A[i][j] + B[i][j] >= 2)
            copia_matriz(A,B,n);
          else
            A[i][j] = A[i][j] + B[i][j];
        }}
    }
  if (strcmp(matriz,"B") == 0)
    imprime_matriz_quadrada(B, n);
  else if(strcmp(matriz,"A") == 0)
    imprime_matriz_quadrada(A, n);
}

void multi_ele(int A[][MAX], int B[][MAX], int n){
  int i,j;
  char mult_1[3],mult_2[3],matriz[3];
  scanf("%s", mult_1);
  scanf("%s", mult_2);
  scanf("%s", matriz);
  for (i = 0 ; i < n ; i++)
    for (j = 0 ; j < n ; j++){
      if (strcmp(mult_1,mult_2) == 1){
        if (strcmp(matriz,"B") == 0)
          B[i][j] = A[i][j] * B[i][j];
        else
          A[i][j] = A[i][j] * B[i][j];
      }
      else{
        if (strcmp(mult_1,"B") == 0)
          B[i][j] = B[i][j] * B[i][j];
        else
          A[i][j] = A[i][j] * A[i][j];
      } 

    }
  if (strcmp(matriz,"B") == 0)
    imprime_matriz_quadrada(B, n);
  else
    imprime_matriz_quadrada(A, n);
}

void bordas(int A[][MAX], int B[][MAX], int n){
  int i,j,C[MAX][MAX];
  char valor[3],matriz[3];
  scanf("%s", matriz);
  scanf("%s", valor);
  if (strcmp(valor,matriz) == 0){
    if(strcmp("B",matriz) == 0)
      copia_matriz(C, B, n);
    else
      copia_matriz(C, A, n);
  }  
  for (i = 0 ; i < n ; i++)
    for (j = 0 ; j < n ; j++){
      if (strcmp(valor,"B") == 0){
        if(strcmp("B",matriz) == 0){
          if (C[i][j]==1 && C[i-1][j-1]==1 && C[i-1][j]==1 && C[i-1][j+1]==1 && C[i][j-1]==1 && C[i][j+1]==1 && C[i+1][j-1]==1 && C[i+1][j]==1 && C[i+1][j+1]==1)
            B[i][j] = 0;
          }
        else{
          if (A[i][j]==1 && A[i-1][j-1]==1 && A[i-1][j]==1 && A[i-1][j+1]==1 && A[i][j-1]==1 && A[i][j+1]==1 && A[i+1][j-1]==1 && A[i+1][j]==1 && A[i+1][j+1]==1)
            B[i][j] = 0;    
          }
        }
      else if(strcmp("A",valor) == 0){
        if(strcmp("A",matriz) == 0){
          if (C[i][j]==1 && C[i-1][j-1]==1 && C[i-1][j]==1 && C[i-1][j+1]==1 && C[i][j-1]==1 && C[i][j+1]==1 && C[i+1][j-1]==1 && C[i+1][j]==1 && C[i+1][j+1]==1)
            A[i][j] = 0; 
        }
        else{
          if (B[i][j]==1 && B[i-1][j-1]==1 && B[i-1][j]==1 && B[i-1][j+1]==1 && B[i][j-1]==1 && B[i][j+1]==1 && B[i+1][j-1]==1 && B[i+1][j]==1 && B[i+1][j+1]==1)
            A[i][j] = 0;
      }
        }
    }
  if (strcmp(valor,"B") == 0)
    imprime_matriz_quadrada(B, n);
  else
    imprime_matriz_quadrada(A, n);
}

void multi_m(int A[][MAX],int B[][MAX],int C[][MAX],int n){
  int i, j, k;
  char mult_1[1],mult_2[1],matriz[1];
  scanf("%s", mult_1);
  scanf("%s", mult_2);
  scanf("%s", matriz);
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++) {
      C[i][j] = 0;
      for (k = 0; k < n; k++)
        C[i][j] += A[i][k] * B[k][j];
  } 
  for(i = 0 ; i < n ; i++)
    for (j = 0 ; j < n ; j++){
      if (strcmp(matriz,"B") == 0)
        if (C[i][j] >= 2)
          B[i][j] = 1;
        else
          B[i][j] = C[i][j];
      else
        if (C[i][j] >= 2)
          A[i][j] = 1;
        else
          A[i][j] = C[i][j];
        
    }
  
  if (strcmp(matriz,"B") == 0)
    imprime_matriz_quadrada(B, n);
  else
    imprime_matriz_quadrada(A, n);  
}

  
int main(void) {
  int dimensao,A[MAX][MAX],B[MAX][MAX],C[MAX][MAX],n_operacao;
  char operador[10];
  scanf("%d", &dimensao);
  criando_matriz(A, dimensao);
  criando_matriz(B, dimensao);
  scanf("%d", &n_operacao);
  for (int i = 0 ; i < n_operacao ; i++){
    printf("\n");
    scanf("%s", operador);
    if ( strcmp(operador,"TRANSPOSTA") == 0)
      transposta(A, B, dimensao);
    else if( strcmp(operador,"SOMA") == 0)
      soma(A,B,dimensao);
    else if( strcmp(operador,"MULTI_ELEM") == 0)
      multi_ele(A, B, dimensao);
    else if( strcmp(operador,"MULTI_MAT") == 0)
      multi_m(A, B, C, dimensao);
    else if( strcmp(operador,"BORDAS") == 0)
      bordas(A,B,dimensao);   
  }
  return 0;
}