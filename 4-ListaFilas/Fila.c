/*

* 4- Lista - Algoritmos e Estruturas de Dados III 
* Autores: | > Caio Macedo Lima da Cruz.....RA: 2651378
*          | > José Carlos Seben............RA: 2651130

*/

#include "Fila.h";

struct elemento{
    struct aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elem;

struct elementoFiPi{
    Pilha* pi;
    struct elementoFiPi *prox;
};typedef struct elementoFiPi ElemFiPi;

struct elementoFiFi {
    Fila* fi;
    struct elementoFiFi *prox;
};typedef struct elementoFiFi ElemFiFi;

struct elementoPi
{
    Fila* fi;
    struct elementoPi *prox;
};typedef struct elementoPi ElemPi;

  
//Defini��o do N� Descritor da Fila
struct fila{
    struct elemento *inicio;
    struct elemento *final;
    int qtd;
};

Fila* cria_Fila(){
    Fila* fi = (Fila*) malloc(sizeof(Fila));
    if(fi != NULL){
        fi->final = NULL;
        fi->inicio = NULL;
        fi->qtd = 0;
    }
    return fi;
}

void libera_Fila(Fila* fi){
    if(fi != NULL){
        Elem* no;
        while(fi->inicio != NULL){
            no = fi->inicio;
            fi->inicio = fi->inicio->prox;
            free(no);
        }
        free(fi);
    }
}

int consulta_Fila(Fila* fi, struct aluno *al){
    if(fi == NULL)
        return 0;
    if(fi->inicio == NULL)//fila vazia
        return 0;
    *al = fi->inicio->dados;
    return 1;
}

int insere_Fila(Fila* fi, struct aluno al){
    if(fi == NULL)
        return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = NULL;
    if(fi->final == NULL)//fila vazia
        fi->inicio = no;
    else
        fi->final->prox = no;
    fi->final = no;
    fi->qtd++;
    return 1;
}

int remove_Fila(Fila* fi){
    if(fi == NULL)
        return 0;
    if(fi->inicio == NULL)//fila vazia
        return 0;
    Elem *no = fi->inicio;
    fi->inicio = fi->inicio->prox;
    if(fi->inicio == NULL)//fila ficou vazia
        fi->final = NULL;
    free(no);
    fi->qtd--;
    return 1;
}

int tamanho_Fila(Fila* fi){
    if(fi == NULL)
        return 0;
    return fi->qtd;
}

int Fila_vazia(Fila* fi){
    if(fi == NULL)
        return 1;
    if(fi->inicio == NULL)
        return 1;
    return 0;
}

int Fila_cheia(Fila* fi){
    return 0;
}

void imprime_Fila(Fila* fi){
    if(fi == NULL)
        return;
    Elem* no = fi->inicio;
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

int separa_fila(Fila* f1, Fila* f2, int n){
    if(f1 == NULL || f2 == NULL){
        return 0;
    }
    Elem* no = f1->inicio;

    while(no != NULL && no->dados.matricula != n){
        no = no->prox;
    }
    if(no == NULL){
        printf("Esse numero de matricula nao existe");
        return 0;
    }

    // f2 começa no próximo nó depois de no
    f2->inicio = no->prox;
    
    no->prox = NULL;

    f1->final = no;

    if (f2->inicio == NULL) {
        f2->final = NULL;
    } else {
    
        // Atualiza o fim de f2
        Elem* aux = f2->inicio;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        f2->final = aux;
    }
    
 
    return 1;
}

