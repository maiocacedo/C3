#include <stdio.h>
#include <stdlib.h>
#include "ListasDupla.h"
#define ERR 0
#define OK 1

// Fila
struct fila{
    int info;
    struct fila *prox;
    struct fila *ant;
}; typedef struct fila Fila;

// No Descritor
struct nodesc{
    struct fila *ini;
    struct fila *fim;
}; 

//Defini��o do tipo lista
struct elemento{
    struct elemento *ant;
    struct aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elem;



Lista* cria_lista(){
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL)
        *li = NULL;
    return li;
}

void libera_lista(Lista* li){
    if(li != NULL){
        Elem* no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

int consulta_lista_pos(Lista* li, int pos, struct aluno *al){
    if(li == NULL || pos <= 0)
        return 0;
    Elem *no = *li;
    int i = 1;
    while(no != NULL && i < pos){
        no = no->prox;
        i++;
    }
    if(no == NULL)
        return 0;
    else{
        *al = no->dados;
        return 1;
    }
}

int consulta_lista_mat(Lista* li, int mat, struct aluno *al){
    if(li == NULL)
        return 0;
    Elem *no = *li;
    while(no != NULL && no->dados.matricula != mat){
        no = no->prox;
    }
    if(no == NULL)
        return 0;
    else{
        *al = no->dados;
        return 1;
    }
}

int insere_lista_final(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    Elem *no;
    no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = NULL;
    if((*li) == NULL){//lista vazia: insere in�cio
        no->ant = NULL;
        *li = no;
    }else{
        Elem *aux;
        aux = *li;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
        no->ant = aux;
    }
    return 1;
}

int insere_lista_inicio(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    Elem* no;
    no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = (*li);
    no->ant = NULL;
    if(*li != NULL)//lista n�o vazia: apontar para o anterior!
        (*li)->ant = no;
    *li = no;
    return 1;
}

int remove_lista_inicio(Lista* li){
    if(li == NULL)
        return 0;
    if((*li) == NULL)//lista vazia
        return 0;

    Elem *no = *li;
    *li = no->prox;
    if(no->prox != NULL)
        no->prox->ant = NULL;

    free(no);
    return 1;
}

int remove_lista_final(Lista* li){
    if(li == NULL)
        return 0;
    if((*li) == NULL)//lista vazia
        return 0;

    Elem *no = *li;
    while(no->prox != NULL)
        no = no->prox;

    if(no->ant == NULL)//remover o primeiro e �nico
        *li = no->prox;
    else
        no->ant->prox = NULL;

    free(no);
    return 1;
}

int tamanho_lista(Lista* li){
    if(li == NULL)
        return 0;
    int cont = 0;
    Elem* no = *li;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int lista_cheia(Lista* li){
    return 0;
}

int lista_vazia(Lista* li){
    if(li == NULL)
        return 1;
    if(*li == NULL)
        return 1;
    return 0;
}

void imprime_lista(Lista* li){
    if(li == NULL)
        return;
    Elem* no = *li;
    while(no != NULL){
        printf("Matricula: %d\n",no->dados.matricula);
        printf("Nome: %s\n",no->dados.nome);
        printf("Notas: %f %f %f\n",no->dados.n1,
                                   no->dados.n2,
                                   no->dados.n3);
        printf("-------------------------------\n");

        no = no->prox;
    }
}

//Exercicio 2.:
int insere_lista_ordenada(Lista *li, struct aluno al)
{
    if (li == NULL) return 0;

    Elem *no = malloc(sizeof *no);
    if (no == NULL) return 0;

    no->dados = al;
    no->prox = NULL;
    no->ant = NULL;
    if((*li) == NULL){
        *li = no;
        return 1;
    }
    
    Elem *atual = *li;
        while (atual != NULL && atual->dados.matricula < al.matricula)
        {
            atual = atual->prox;
        }
        if (atual == *li)
        { // insere in�cio
            no->prox = *li;
            no->ant = NULL;
            (*li)->ant = no;
            *li = no;
        }
        else
        {
            Elem *anterior = atual ? atual -> ant: NULL;
            no->prox = atual;
            no->ant = anterior;

            if(anterior != NULL) anterior ->prox = no;

            if(atual != NULL) atual->ant = no;
        }
        return 1;
}

// EXERCICIO 4:

// Função para inserção de elemento no inicio da lista circular
int insere_lista_circular_inicio(Lista* li, struct aluno al){
    if(li == NULL) return ERR;

    Elem *no = malloc(sizeof *no);
    if (no == NULL) return ERR;

    no->dados = al;
    
    if(*li == NULL){
        
        no->prox = no;
        no->ant = no;
        *li = no;
        
        return OK;
    } else{
        
        no->prox = *li;
        no->ant = (*li)->ant;
        (*li)->ant->prox = no;
        (*li)->ant = no;
        *li = no;
        
        return OK;
    }

}

// Função para inserção de elemento no final de lista circular
int insere_lista_circular_final(Lista* li, struct aluno al){
    if(li == NULL) return ERR;

    Elem *no = malloc(sizeof *no);
    if (no == NULL) return ERR;
    
    no->dados = al;

    if((*li) == NULL){
        no->prox = no;
        no->ant = no;
        *li = no;
        return OK;
    } else{
        no->prox = *li;
        no->ant = (*li)->ant;
        (*li)->ant->prox = no;
        (*li)->ant = no;
        return OK;
    }
}

// Função para remvoer primeiro elemento de lista circular
int remove_lista_circular_inicio(Lista* li){
    if(li == NULL) return ERR;
    if(*li == NULL) return ERR;

    Elem *no = *li;

    if(no->prox == no){
        free(no);
        *li = NULL;
        return OK;
    } else{
        no->ant->prox = no->prox; // prox do ultimo aponta para o novo primeiro
        no->prox->ant = no->ant; // ant do prox aponta para o novo ultimo
        *li = no->prox; // novo primeiro
        free(no); // libera o antigo primeiro
        return OK;
    }
}

// Função para remover ultimo elemento de lista circular
int remove_lista_circular_final(Lista* li){
    if(li == NULL) return ERR;
    if(*li == NULL) return ERR;

    Elem *no = (*li)->ant;
    if(no->prox == no){
        free(no);
        *li = NULL;
        return OK;
    } else{
        no->prox->ant = no->ant; 
        no->ant->prox = no->prox; 
        (*li)->ant = no->ant; // novo ultimo
        free(no); // libera o antigo primeiro

        return OK;
    }
}

// Função para percorrer lista circular
int percorre_lista_circular(Lista* li){
    if(li == NULL) return ERR;
    if(*li == NULL) return ERR;

    Elem *no = *li;
    do{
        
        printf("Matricula: %d\n",no->dados.matricula);
        printf("Nome: %s\n",no->dados.nome);
        printf("Notas: %f %f %f\n",no->dados.n1,
                                   no->dados.n2,
                                   no->dados.n3);
        printf("-------------------------------\n");

        no = no->prox;
    }while(no != *li);
    
    return OK;
}

// EXERCICIO 5:

// Função para inicializar no decritor.
int inicializa_noDesc(noDesc *no){
    if(no == NULL) return ERR; 

    *no = malloc(sizeof*(*no));

    if(*no == NULL) return ERR; 
    
    (*no)->ini = NULL;
    (*no)->fim = NULL;

    return OK;
}

// Função para enfileiramento em filas, utilizando no descritor
int enfileirar(noDesc *desc, int elem){

}

// Função para desenfileiramento em filas, utilizando no descritor
int desenfileirar(noDesc *desc, int *elem){
    
}