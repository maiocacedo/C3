/*

* 4- Lista - Algoritmos e Estruturas de Dados III 
* Autores: | > Caio Macedo Lima da Cruz.....RA: 2651378
*          | > José Carlos Seben............RA: 2651130

*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>    

struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};

// Fila de alunos
typedef struct elemento* Pilha; // Pilha de Aluno
typedef struct fila Fila;

// Estruras do exercício 2
typedef struct elementoFiPi ElemFiPi; // Elemento fila de pilha
typedef struct filaFiPi filaFiPi; // Fila de pilha

typedef struct elementoFiFi ElemFiFi; // Elemento fila de filas
typedef struct filaFiFi FilaFiFi;  // Fila de filas

typedef struct elementoPi ElemPi;
typedef struct elementoPi* PilhaPi;

// Fila de inteiros
typedef struct elementoInt ElemInt; // Elemento fila de inteiros
typedef struct filaint FilaInt; // Fila de inteiros

// funções para fila de alunos
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

// funções para fila de inteiros
FilaInt* cria_Fila_int();
void libera_Fila_int(FilaInt* fi);
int consulta_Fila_int(FilaInt* fi, int *al);
int insere_Fila_int(FilaInt* fi, int al);
int remove_Fila_int(FilaInt* fi);
int tamanho_Fila_int(FilaInt* fi);
int Fila_vazia_int(FilaInt* fi);
void imprime_Fila_int(FilaInt* fi);
int FuraFilaInt(FilaInt* fi, int al);
int ordem_crescente(FilaInt* fi);
int nova_fila_ordem_crescente(FilaInt* f1, FilaInt* f2, FilaInt* f3);

int reverso(FilaInt* f1);

//atividade 3:
typedef struct elementoPilha {
    int dados;
    struct elementoPilha *prox;
} ElemPilha;

typedef struct {
    ElemPilha *topo;
    int qtd;
} PilhaAux;

// Funções de pilhas utilizadas para inverter os elementos da fila
PilhaAux* cria_Pilha();
void libera_Pilha(PilhaAux* pi);
int empilha(PilhaAux* pi, int dados);
int desempilha(PilhaAux* pi, int *dados);
int Pilha_vazia(PilhaAux* pi);

// Função para inverter a fila com a pilha
int FilaInt_vazia(FilaInt* fi);
void inverte_FilaInt(FilaInt* fi);
int remove_Fila_int2(FilaInt* fi, int *elemento);

void menu();

