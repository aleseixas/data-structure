typedef struct fila *p_fila;

struct fila {
 char *v;
 int N, tamanho;
};

p_fila criar_fila(int N);
//*declara o ponteiro *p_fila 

int saiu_fila(p_fila f,int t);
//*tira a primeira palavra da fila

void entrou_fila(p_fila f, char palavra[50]);
//*inseriu palavra na fila

void imprime_fila(p_fila fila);
//*imprime a fila inteira

void capta_numeros(char x[]);
//*capta as strings em forma de numeros


