typedef struct mapa *p_mapa;
typedef struct visita *p_visita;


struct mapa{
  char cidade[50];
  int qnt_visita;
  p_mapa esq, direita; 
};

struct visita{
  char cidade[50];
  int encontrou,dia;
  p_visita esq, direita;
};

void ler_entradas();
//*possui as entradas que o usuario irá fazer e as manipulações que serão feitas ao decorrer do codigo