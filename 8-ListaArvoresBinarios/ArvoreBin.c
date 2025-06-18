#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBin.h"

ArvBin* cria_ArvBin(){
    ArvBin* raiz = (ArvBin*) malloc(sizeof(ArvBin));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}

void libera_NO(struct NO* no){
    if(no == NULL)
        return;
    libera_NO(no->esq);
    libera_NO(no->dir);
    free(no);
    no = NULL;
}

void libera_ArvBin(ArvBin* raiz){
    if(raiz == NULL)
        return;
    libera_NO(*raiz);//libera cada n�
    free(raiz);//libera a raiz
}

int insere_ArvBin(ArvBin* raiz, int valor){
    if(raiz == NULL)
        return 0;
    struct NO* novo;
    novo = (struct NO*) malloc(sizeof(struct NO));
    if(novo == NULL)
        return 0;
    novo->info = valor;
    novo->dir = NULL;
    novo->esq = NULL;

    if(*raiz == NULL)
        *raiz = novo;
    else{
        struct NO* atual = *raiz;
        struct NO* ant = NULL;
        while(atual != NULL){
            ant = atual;
            if(valor == atual->info){
                free(novo);
                return 0;//elemento j� existe
            }

            if(valor > atual->info)
                atual = atual->dir;
            else
                atual = atual->esq;
        }
        if(valor > ant->info)
            ant->dir = novo;
        else
            ant->esq = novo;
    }
    return 1;
}

// http://www.ime.usp.br/~pf/algoritmos/aulas/binst.html
int remove_ArvBin(ArvBin *raiz, int valor){
    if(raiz == NULL)
        return 0;
    struct NO* ant = NULL;
    struct NO* atual = *raiz;
    while(atual != NULL){
        if(valor == atual->info){
            if(atual == *raiz)
                *raiz = remove_atual(atual);
            else{
                if(ant->dir == atual)
                    ant->dir = remove_atual(atual);
                else
                    ant->esq = remove_atual(atual);
            }
            return 1;
        }
        ant = atual;
        if(valor > atual->info)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
}

int estaVazia_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return 1;
    if(*raiz == NULL)
        return 1;
    return 0;
}

struct NO* remove_atual(struct NO* atual) {
    struct NO *no1, *no2;
    if(atual->esq == NULL){
        no2 = atual->dir;
        free(atual);
        return no2;
    }
    no1 = atual;
    no2 = atual->esq;
    while(no2->dir != NULL){
        no1 = no2;
        no2 = no2->dir;
    }
    // no2 � o n� anterior a r na ordem e-r-d
    // no1 � o pai de no2
    if(no1 != atual){
        no1->dir = no2->esq;
        no2->esq = atual->esq;
    }
    no2->dir = atual->dir;
    free(atual);
    return no2;
}

int altura_ArvBin(ArvBin *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = altura_ArvBin(&((*raiz)->esq));
    int alt_dir = altura_ArvBin(&((*raiz)->dir));
    if (alt_esq > alt_dir)
        return (alt_esq + 1);
    else
        return(alt_dir + 1);
}


void preOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        printf("%d\n",(*raiz)->info);
        preOrdem_ArvBin(&((*raiz)->esq));
        preOrdem_ArvBin(&((*raiz)->dir));
    }
}
// Exercício 1 - Contar Folhas na arvoré
/* A arvore é percorrida por recursão, indo para esquerda e direita, até que encontre as folhas, nós que 
não possuem filhos. Casos bases são, quando o ponteiro da raiz for nulo ou a raiz for nula, retornando zero e 
quando os ponteiros dos nós a direita e esquerda de raiz foram ambos nulos, retornando um. E o caso geral é a 
soma do número de folhas na subárvore esquerda com o número de folhas na subárvore direita.
*/
int contaFolhas(ArvBin *raiz){
    if(raiz == NULL || *raiz == NULL)
        return 0;
    if((*raiz)->esq == NULL && (*raiz)->dir == NULL)
        return 1;    
    return contaFolhas(&((*raiz)->esq)) + contaFolhas(&((*raiz)->dir));
}

// Exercício 2 - Imprimir Arvore em detalhes
/* Para resolução desse exercício, foram utilizadas duas funções, uma auxiliar para imprimir cada nó,
e uma para chamar a auxiliar. A função auxiliar opera de modo recursivo, onde ela recebe o no e o seu pai
e a partir disso, ela imprimi o no, o pai, no esquerdo e o no direito. Depois ela é chamada de novo, só que 
para o nó à esquerda e para o nó à direita
*/
void imprimeNo(struct NO* no, struct NO* pai) {
    if (no == NULL) {
        printf("NULL ");
        return;
    }
    printf("No: %d, pai:  ", no->info);
    if (pai != NULL) printf("%d", pai->info);
    else printf("NULL");

    printf(" Esquerdo:");
    if (no->esq != NULL) printf("%d", no->esq->info);
    else printf("NULL");

    printf(" Direito:");
    if (no->dir != NULL) printf("%d", no->dir->info);
    else printf("NULL");

    if (no->dir == NULL && no->esq == NULL) printf("[FOLHA]");

    imprimeNo(no->esq, no);
    imprimeNo(no->dir, no);
}

// Função de Imprimir arvore
void imprimeArvore(ArvBin *raiz){
    if (raiz == NULL || *raiz == NULL){
        printf("Arvore vazia ou nula");
        return;
    }

    imprimeNo(*raiz, NULL);
}

// Exercício 3 - Conta repetições
/*

*/
int consultaNoRepetido(ArvBin *raiz, int valor){
    if(raiz == NULL) return 0;
    
    int count = ((*raiz)->info == valor) ? 1 : 0;

    count += consultaNoRepetido(&(*raiz)->esq, valor);
    count += consultaNoRepetido(&(*raiz)->dir, valor);
    return count;
}

// Exercício 4 - 