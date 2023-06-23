#include "mapa.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


p_visita exclui_visita(p_visita v,int data,char cidade_excluida[]){
  if(v == NULL){
    return NULL;
  }
  else{
    strcpy(cidade_excluida,v->cidade);
    if(v->dia == data){
      if(v->esq == NULL && v->direita == NULL){
        free(v);
        return NULL;
      }
    else{
      if(v->esq == NULL || v->direita == NULL){
        p_visita novo;
        if(v->direita != NULL){
          novo = v->direita;
          }
        else{
          novo = v->esq;
          }
        free(v);
        return novo;
      }
      else{
        p_visita novo = v->esq;
        while(novo->direita != NULL){
          novo = novo->direita;
        }
        v->dia = novo->dia;
        v->encontrou = novo->encontrou;
        strcpy(v->cidade,novo->cidade);
        novo->dia = data;
        v->esq = exclui_visita(v, data,cidade_excluida);
        return v;
      }
    } 
    }
    else{
      if(data < v->dia)
        v->esq = exclui_visita(v->esq, data,cidade_excluida);
      else
        v->direita = exclui_visita(v->direita,data,cidade_excluida);
      return v;
    }
  }
}


p_mapa exclui_mapa(p_mapa m , char nome[], int visitas){
  if(m == NULL){
    return NULL;
  }
  else{
    if(strcmp(m->cidade,nome)==0){
      if(m->esq == NULL && m->direita == NULL){
        free(m);
        return NULL;
      }
    else{
      if(m->esq == NULL || m->direita == NULL){
        p_mapa novo;
        if(m->direita != NULL)
          novo = m->direita;
        else
          novo = m->esq;
        free(m);
        return novo;
      }
      else{
        p_mapa novo = m->esq;
        while(novo->direita != NULL){
          novo = novo->direita;
        }
        m->qnt_visita = novo->qnt_visita;
        strcpy(m->cidade,novo->cidade);
        strcpy(novo->cidade,nome);
        m->esq = exclui_mapa(m,nome,visitas);
        return m;
      }
    }
    }
    else{
      if(strcmp(nome,m->cidade)==0 && visitas < m->qnt_visita)
        m->esq = exclui_mapa(m->esq, nome,visitas);
      else if(strcmp(nome,m->cidade) && visitas > m->qnt_visita)
        m->direita = exclui_mapa(m->direita,nome,visitas);
      return m;
    }
  }
}


p_mapa inserir_m(p_mapa raiz, char city[] ,int n_visitas){
  if(n_visitas==0){
    p_mapa novo;
    if (raiz == NULL){
      novo = malloc(sizeof(struct mapa));
      novo->esq = novo->direita = NULL;
      strcpy(novo->cidade,city);
      novo->qnt_visita = n_visitas;
      printf("ARVORE: MAPA\n");
      printf("CIDADE: %s\n",city);
      printf("INSERIDO COM SUCESSO!\n");
      printf("####\n");
      return novo;
    }
    if (n_visitas < raiz->qnt_visita){
      raiz->esq = inserir_m(raiz->esq,city,n_visitas);
    }
    else{
      raiz->direita = inserir_m(raiz->direita,city,n_visitas);
      }
  }
  else{
    if(raiz != NULL){
      if(strcmp(raiz->cidade,city)==0)
        raiz->qnt_visita = n_visitas + 1;
      inserir_m(raiz->direita,city,n_visitas);
      inserir_m(raiz->esq,city,n_visitas);
    }
  }
  return raiz;
}

p_mapa alterando_m(p_mapa m , char nome[], int visitas){
  if(m != NULL){
    if(strcmp(m->cidade,nome)==0){
      m->qnt_visita = visitas - 1;
      printf("CIDADE: %s\n",m->cidade);
      printf("QUANTIDADE DE VISITAS RESTANTES: %d\n",visitas);
      printf("####\n");
      if(m->qnt_visita == 0 ){
        exclui_mapa(m, nome, visitas);
      }
    }
    alterando_m(m->direita,nome,visitas);
    alterando_m(m->esq,nome,visitas);
  }
  return m;
}

p_visita inserir_v(p_visita raiz, int data ,int encontra , char city[]) {
  p_visita novo;
  if (raiz == NULL) {
    novo = malloc(sizeof(struct visita));
    novo->esq = novo->direita = NULL;
    novo->dia = data;
    novo->encontrou = encontra;
    strcpy(novo->cidade,city);
    printf("ARVORE: VISITA\n");
    printf("DATA: %d\n",data);
    printf("CIDADE: %s\n",city);
    printf("INSERIDO COM SUCESSO!\n");
    printf("####\n");
    return novo;
  }
  if (data < raiz->dia){
    raiz->esq = inserir_v(raiz->esq,data,encontra,city);
    }
  else{
    raiz->direita =  inserir_v(raiz->direita,data,encontra,city);
    }
  return raiz;
}

int numero_visita(p_visita v , char nome[],int valor[]){
  if (v != NULL){
    if(strcmp(nome,v->cidade)==0){
      valor[0] = valor[0] + 1;
    }
    numero_visita(v->esq,nome,valor);
    numero_visita(v->direita,nome,valor);
  }
  return valor[0];
}

void relatorio_d(int data1,int data2, p_visita v){
  if(v != NULL){
    if((v->dia >= data1 && v->dia != 0) && (v->dia <= data2 && v->dia != 0)){
      printf("DATA: %d\n",v->dia);
      printf("CIDADE: %s\n",v->cidade);
      printf("####\n");
    }
    relatorio_d(data1,data2,v->esq);
    relatorio_d(data1,data2,v->direita);
  }
}

void relatorio_p(int data1, int data2 , p_visita v){
  if(v != NULL){
    relatorio_p(data1,data2,v->esq);
    relatorio_p(data1,data2,v->direita);
    if((v->encontrou == 1 && v->dia >= data1) && (v->dia <= data2 && v->encontrou==1)){
      printf("DATA: %d\n",v->dia);
      printf("CIDADE: %s\n",v->cidade);
      printf("####\n");
    }
  }
}

void ler_entradas(){
  int qnt_operacao,data,achou,n_visitas,valor[1],data2;
  valor[0] = 0;
  char operacao[18],city[50],cidade_excluida[50];
  p_mapa m = malloc(sizeof(struct mapa));
  p_visita v = malloc(sizeof(struct visita));
  scanf("%d",&qnt_operacao);
  for (int k = 0 ; k < qnt_operacao ; k++){
    scanf("%s",operacao);
    if(strcmp(operacao,"insere_visita")==0){
      valor[0] = 0;
      scanf("%s",city);
      scanf("%d",&data);
      scanf("%d",&achou);
      n_visitas = numero_visita(v,city,valor);
      inserir_m(m,city,n_visitas);
      inserir_v(v,data,achou,city);
    }
    else if(strcmp(operacao,"exclui_visita")==0){
      valor[0] = 0 ;
      scanf("%d",&data);
      exclui_visita(v,data,cidade_excluida);
      n_visitas = numero_visita(v,cidade_excluida,valor);
      alterando_m(m,cidade_excluida,n_visitas);
    }
    else if(strcmp(operacao,"relatorio_data")==0){
      exclui_visita(v,0,cidade_excluida);
      scanf("%d",&data);
      scanf("%d",&data2);
      printf("--VISITAS--\n");
      relatorio_d(data,data2,v);
    }
    else if(strcmp(operacao,"relatorio_pista")==0){
      scanf("%d",&data);
      scanf("%d",&data2);
      printf("--PISTAS--\n");
      relatorio_p(data,data2,v);
    }
  }
}

