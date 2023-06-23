#include <stdio.h>
//funções para manipular os vetores
void imprime_vetor(int T, int lista[]){
    int i;
    for (i = 0; i < T; i++){
        printf("%d ", lista[i]);
    }
    printf("\n");
}

void le_vetor(int lista[], int n){
    int i;
    for (i = 0; i < n; i++)
    scanf("%d", &lista[i]);
}

//função que multiplica os valores impares por M
void multiplicao(int lista[], int T){
    int M;
    scanf("%d", &M);
    for(int i=1; i<=T; i+=2){
        lista[i] = lista[i] * M;
    }
    imprime_vetor(T , lista);
} 

//função que checa se o vetor tem os valores do conjunto, caso não, torna o valor = 0
void conjunto(int lista[],int T){
    int tamanho_conjunto,valor,nova_lista[T];
  //fazendo vetor só de 0
  for (int k=0; k < T ; k++){
    nova_lista[k] = 0;
  }
    scanf("%d", &tamanho_conjunto);
    for (int j=0; j < tamanho_conjunto; j++){
        scanf("%d", &valor);
        for (int k=0; k < T; k++){
            if(valor == lista[k] )
            nova_lista[k] = valor;
        }
    }
  //igualando vetores 
  for (int i=0 ; i < T ; i++){
    lista[i] = nova_lista [i];
  }
    imprime_vetor(T,lista);
}

//inverte a ordem do vetor
void inverso(int lista[],int T){
    int fim,aux;
    fim = T - 1;
    for (int inicio = 0 ; inicio < T/2 ; inicio++){
        aux = lista[inicio];
        lista[inicio] = lista[fim];
        lista[fim] = aux;
        fim--;
    }
    imprime_vetor(T,lista);
}

//muda as posições dos valores por um determinado passo
void ciclico(int lista[],int T){
  int P;
  scanf("%d", &P);
  int outro_vetor[T-P];
  //adicionando valores no outro_vetor
  for ( int k=0; k < T-P ; k++){
    outro_vetor[k] = lista[k];
  }
  //substituindo alguns valores
  for (int i=0 ; i < P ; i++){
    lista[i] = lista[(T-P)+i];
  }
  //substituindo o resto dos valores
  for (int j=0 ; j < T-P ; j++){
    lista[j+P] = outro_vetor[j];
  }
  imprime_vetor(T, lista);
    }
  
//entradas e saidas do codigo
int main(){
    int T,n_operacoes,operacao;
    scanf("%d", &T);
    int u[T];
    le_vetor(u,T);
    scanf("%d", &n_operacoes);
    for (int j=0; j < n_operacoes ;j++){
        scanf("%d",&operacao);
        if(operacao==1){ 
            conjunto(u,T);
        }
        else if(operacao==2){
            multiplicao(u,T);
        }
        else if(operacao==3){
            ciclico(u,T);
        }
        else if(operacao==4){
            inverso(u,T);
        }
    }
    return 0;
}