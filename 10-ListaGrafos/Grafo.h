#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct grafo Grafo;

Grafo* cria_Grafo(int nro_vertices, int grau_max, int eh_ponderado);
void libera_Grafo(Grafo* gr);
int insereAresta(Grafo* gr, int orig, int dest, int eh_digrafo, float peso);
int removeAresta(Grafo* gr, int orig, int dest, int eh_digrafo);
void imprime_Grafo(Grafo *gr);

GrafoLista* cria_GrafoLista(int n_nos);
int insere_aresta_lista(GrafoLista* grafol, char *nome_v, int peso, int no);
int remove_aresta_lista(GrafoLista* grafol, int no, char *nome_v);


void Prim(Grafo* gr, int origem);

int encontra_no(Grafo* gr, int no);
int encontra_aresta_menor(Grafo* gr, int no);