typedef struct matriz *p_matriz;

struct matriz{
  int linhas;
  int colunas;
  int **matriz;
  int c_alocado;
  int l_alocado;
};

p_matriz le_matriz();
//*le a matriz a ser manipulada

void operacao(p_matriz dados);
//* le a quantidade de operacao e as operacoes executadas,além disso manipular a matriz e imprime o reultado de cada operacao

void imprime_matriz(p_matriz M);
//* imprime a matriz

void insere_linhas(p_matriz M, int *vetor);
//* retorna a nova quantidade de linhas, insere nova linha na ultima posicao e imprime a matriz

void out_linha(int posicao, p_matriz M);
//* retira a linha presente de uma determina posicao

void out_colunas(int posicao, p_matriz M);
//*retira a coluna presente de uma determinada posicao

void check_alocacao(p_matriz dados);
//*ele aloca dinamicamente as matrizes ao decorrer do codigo

void insere_colunas(p_matriz M , int *vetor);
//*insere uma coluna na matriz em ordem crescente
