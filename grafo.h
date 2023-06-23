typedef struct no *p_no;

struct no{
  int valor;
  int c_p;
  p_no prox;
};

struct grafo{
  p_no *adjacencia;
  int n;
};

typedef struct grafo *p_grafo;

void entradas();
//*lê as entradas do programa, fazendo as manipulações necessarias no heap