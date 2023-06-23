typedef struct{
  int id,tempo;
  char nome_proc[50];
}Processo;

typedef struct{
  Processo *vetor;
}hash;


void entradas();
//*lê as entradas do programa, fazendo as manipulações necessarias no heap