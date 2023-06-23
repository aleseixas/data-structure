typedef struct{
   int arquivo,chave;
}Item;

typedef struct{
  Item *v;
  int n,tamanho;
}FP;

typedef FP *p_fp;

void entradas();
//*lê as entradas do programa, fazendo as manipulações necessarias no heap