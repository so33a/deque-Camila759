#ifndef FILA_H
#define FILA_H

typedef struct node * link;
struct node {
  int item;
  link next;
};

typedef struct {
  link esquerda;
  link direita;
} * FILA;

link novoNo(int item, link next);
FILA novaFila();
void inserir(FILA f, int e);
int remover(FILA f);
void imprimirFila(FILA f);
void destroiFila(FILA f);
int filaVazia(FILA f); 

#endif 
