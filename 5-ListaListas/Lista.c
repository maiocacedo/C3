#include <stdio.h>
#include <stdlib.h>
#include "Lista.h" //inclui os Prot�tipos

//Defini��o do tipo lista
struct elemento{
    struct aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elemento;

Lista* cria_lista(){
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL)
        *li = NULL;
    return li;
}

void libera_lista(Lista* li){
    if(li != NULL){
        Elemento* no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

int insere_lista_final(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    Elemento *no;
    no = (Elemento*) malloc(sizeof(Elemento));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = NULL;
    if((*li) == NULL){//lista vazia: insere inicio
        *li = no;
    }else{
        Elemento *aux;
        aux = *li;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
    }
    return 1;
}

int insere_lista_inicio(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    Elemento* no;
    no = (Elemento*) malloc(sizeof(Elemento));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = (*li);
    *li = no;
    return 1;
}

int insere_lista_ordenada(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    Elemento *no = (Elemento*) malloc(sizeof(Elemento));
    if(no == NULL)
        return 0;
    no->dados = al;
    if((*li) == NULL){//lista vazia: insere inicio
        no->prox = NULL;
        *li = no;
        return 1;
    }
    else{
        Elemento *ant, *atual = *li;
        while(atual != NULL && atual->dados.matricula < al.matricula){
            ant = atual;
            atual = atual->prox;
        }
        if(atual == *li){//insere in�cio
            no->prox = (*li);
            *li = no;
        }else{
            no->prox = atual;
            ant->prox = no;
        }
        return 1;
    }
}

int remove_lista(Lista* li, int mat){
    if(li == NULL)
        return 0;
    if((*li) == NULL)//lista vazia
        return 0;
    Elemento *ant, *no = *li;
    while(no != NULL && no->dados.matricula != mat){
        ant = no;
        no = no->prox;
    }
    if(no == NULL)//n�o encontrado
        return 0;

    if(no == *li)//remover o primeiro?
        *li = no->prox;
    else
        ant->prox = no->prox;
    free(no);
    return 1;
}

int remove_lista_inicio(Lista* li){
    if(li == NULL)
        return 0;
    if((*li) == NULL)//lista vazia
        return 0;

    Elemento *no = *li;
    *li = no->prox;
    free(no);
    return 1;
}

int remove_lista_final(Lista* li){
    if(li == NULL)
        return 0;
    if((*li) == NULL)//lista vazia
        return 0;

    Elemento *ant, *no = *li;
    while(no->prox != NULL){
        ant = no;
        no = no->prox;
    }

    if(no == (*li))//remover o primeiro?
        *li = no->prox;
    else
        ant->prox = no->prox;
    free(no);
    return 1;
}

int tamanho_lista(Lista* li){
    if(li == NULL)
        return 0;
    int cont = 0;
    Elemento* no = *li;
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
    Elemento* no = *li;
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

// Exercicio 2

// Remove elemento da lista recursivamente
int remove_lista_rec(Lista* li, int mat){
    if(li == NULL) return 0;

    if(*li == NULL) return 0; // lista vazia

    Elemento *no = *li;

    if(no->dados.matricula == mat){
        *li = no->prox;
        free(no);
        return 1;
    }
    
    return remove_lista_rec(&((*li)->prox), mat);
}

// Lista para comparar duas listas recursivamente
int lista_ingual_rec(Lista* li1, Lista* li2){
    if(li1 == NULL || li2 == NULL) return 0;
    if(*li1 == NULL && *li2 == NULL) return 1;
    if(*li1 == NULL || *li2 == NULL) return 0;

    if ((*li1)->dados.matricula == (*li2)->dados.matricula){
        return lista_ingual_rec(&((*li1)->prox), &((*li2)->prox));
    }

    return 0;
}

// Exercicio 3
int insere_lista_pos(Lista* li, struct aluno al, int pos){
    if(li == NULL || tamanho_lista(li)+1 < pos) return 0;

    else if(pos == 1 || (*li) == NULL) return insere_lista_inicio(li, al);
    
    Elemento *no;
    no = (Elemento*) malloc(sizeof(Elemento));
    if(no == NULL) return 0;
    no->dados = al;

    Elemento *aux = *li;
    for(int i = 1; i<pos-1; i++){
        aux = aux->prox;
    }
        
    no->prox = aux->prox;
    aux->prox = no;

    return 1;   
}

// Exercicio 5
// Remove elementos com certa matricula da lista recursivamente
int remove_toda_lista_rec(Lista* li, int mat){
    if(li == NULL) return 0;

    if(*li == NULL) return 1; // lista vazia

    Elemento *no = *li;

    if(no->dados.matricula == mat){
        *li = no->prox;
        free(no);
        return remove_toda_lista_rec(li, mat);
    }
    
    return remove_toda_lista_rec(&((*li)->prox), mat);
}

// Remove elementos com certa matricula da lista 
int remove_toda_lista(Lista* li, int mat){
    if(li == NULL) return 0;

    if(*li == NULL) return 0; // lista vazia

    while(*li != NULL && (*li)->dados.matricula == mat){
        Elemento *no = *li;
        *li = (*li) -> prox;
        free(no);
    }

    if(*li == NULL) return 1; // lista vazia

    Elemento *ant = *li;
    Elemento *no = ant->prox;

    while(no != NULL){

        if(no->dados.matricula == mat){
            ant->prox = no->prox;
            free(no);
            no = ant->prox;
        }

        else{
            ant = no;
            no = no->prox;
        }
}
    return 1;
    
}

// Exercício 7

