typedef struct pilha *p_pilha;
typedef struct no *p_no;
typedef struct fila *p_fila;

struct no{
  char palavra[500];
  p_no proximo;
};

struct pilha {
  p_no topo;
};

p_pilha criar_pilha();
//cria a pilha

void destruir_lista(p_no lista);
//destroi a lista

void insere_pilha(p_pilha pilha , p_fila fila,int tamanho);
//*insere o valore na pilha , sempre no topo

void remove_pilha(p_pilha pilha,int tamanho);
//*retira o valore na pilha , sempre no topo

void imprime_pilha(p_pilha pilha);
//*imprime a pilha inteira