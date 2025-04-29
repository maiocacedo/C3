/*

* 4- Lista - Algoritmos e Estruturas de Dados III 
* Autores: | > Caio Macedo Lima da Cruz.....RA: 2651378
*          | > José Carlos Seben............RA: 2651130

*/

#include <stdio.h>
#include <stdlib.h>

struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};

typedef struct elemento* Pilha; // Pilha de Aluno
typedef struct fila Fila;


typedef struct elementoFiPi ElemFiPi;
typedef struct filaFiPi* filaFiPi;

typedef struct elementoFiFi ElemFiFi;
typedef struct filaFiFi* FilaFiFi;

typedef struct elementoInt ElemInt;
typedef struct FilaInt FilaInt;

typedef struct elementoPi ElemPi;
typedef struct elementoPi* PilhaPi;


Fila* cria_Fila();
void libera_Fila(Fila* fi);
int consulta_Fila(Fila* fi, struct aluno *al);
int insere_Fila(Fila* fi, struct aluno al);
int remove_Fila(Fila* fi);
int tamanho_Fila(Fila* fi);
int Fila_vazia(Fila* fi);
int Fila_cheia(Fila* fi);
void imprime_Fila(Fila* fi);
int separa_fila(Fila* f1, Fila* f2, int n);
FilaInt* ordem_crescente(FilaInt* fi);
int nova_fila_ordem_crescente(FilaInt* f1, FilaInt* f2, FilaInt* f3);
int reverso(Fila* f1);