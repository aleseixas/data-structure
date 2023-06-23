typedef struct{
  char nome[101];
  float M;
  int N;
  int medida[1001];
}represa;

represa le_represa();
//*Uma função que lê dados de uma represa, inseridos na entrada do programa na forma e retorna uma dado do tipo Represa;

int media_represa(represa a);
//*Uma função que calcula a media de KM^3  do nivel da represa;

int capacidade_max(represa M);
//*Uma função que recebe o valor de M e retorna 1 caso alguma das medidas desta Represa tem valor maior ou igual do que 90% de sua capacidade máxima, ou retorne 0 caso contrário;

void imprime_dados(represa nome);
//*imprime todas as informaçõs manipuladas sobre a represa

void manipula_string(int tamanho_string , char nome[101]);
//* manipula o nome da empressa e seus dados

int tamanho_string(char nome[101]);
//* descobre o tamanho da string

void letra_minuscula(char nome[101]);
//* deixa as letras da string minuscula

void espacos(char nome[101]);
//* substitui os valores "_" por espaços

void somente_nome(char nome[101],int tamanho);
//*pega apenas o nome da represa

void remove_numeros(char nome[101]);
//* retira os numeros do final da string 
