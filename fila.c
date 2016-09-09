#include <stdio.h>
#include <stdlib.h>
#include "fila.h"


link novoNo(int item, link next) {
  link t = malloc(sizeof *t);
  if (t == NULL) {
    printf ("Erro no malloc \n");
    exit(-1);
  }
  t->item = item;
  t->next = next;
  return t;
}

FILA novaFila() {
  FILA f = malloc(sizeof *f);
  f->direita = f->esquerda = NULL;
  return f;
}

void inserir(FILA f, int e) {
  if(f->esquerda == NULL) {
    f->esquerda = f->direita = novoNo(e, NULL);
  } else {
    f->direita->next = novoNo(e, NULL);
    f->direita = f->direita->next;
  }
}

int remover(FILA f){
  int x;
  link t;
  if(filaVazia(f)){
    printf ("Erro, a fila esta vazia\n");
    return 0;
  }
  
  x = f->esquerda->item;
  t = f->esquerda;
  f->esquerda = f->esquerda->next;
 
  if(f->esquerda == NULL)
    f->direita = NULL;

  free(t);
  return x;
}
int filaVazia(FILA f) {
  return ((f->direita == NULL) || (f->esquerda == NULL));
}
void imprimirFila(FILA f) {
  link t;
  for(t = f->esquerda; t != NULL; t = t->next) 
    printf ("%d ", t->item);
  printf ("\n");
}
void destroiFila(FILA f) {
  while (!filaVazia(f))
    remover(f);
  free(f);
}

