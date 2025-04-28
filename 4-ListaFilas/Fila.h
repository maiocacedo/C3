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

typedef struct fila Fila;

Fila* cria_Fila();
void libera_Fila(Fila* fi);
int consulta_Fila(Fila* fi, struct aluno *al);
int insere_Fila(Fila* fi, struct aluno al);
int remove_Fila(Fila* fi);
int tamanho_Fila(Fila* fi);
int Fila_vazia(Fila* fi);
int Fila_cheia(Fila* fi);
void imprime_Fila(Fila* fi);
