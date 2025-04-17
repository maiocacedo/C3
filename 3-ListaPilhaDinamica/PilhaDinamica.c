#include <stdio.h>
#include <stdlib.h>
#include "PilhaDinamica.h" //inclui os Prot�tipos


struct elemento{
    Aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elem;


Pilha* criaPilha(){
    Pilha* pi = (Pilha*) malloc(sizeof(Pilha));
    if(pi != NULL)
        *pi = NULL;
    return pi;
}

void liberaPilha(Pilha* pi){
    if(pi == NULL){
        Elem* no;
        while((*pi) != NULL){
            no = *pi;
            *pi = (*pi)->prox;
            free(no);
        }
        free(pi);
    }
}

int tamanhoPilha(Pilha* pi){
    if(pi == NULL)
        return 0;
    int cont = 0;
    Elem* no = *pi;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int consultaTopoPilha(Pilha* pi, struct aluno *al){
    if(pi == NULL)
        return 0;
    if((*pi) == NULL)
        return 0;
    *al = (*pi)->dados;
    return 1;
}

Pilha *copiaPilha (Pilha* pi){
    if (pi == NULL){
        printf("Pilha nula\n");
        return NULL;
    }
    if (*pi != NULL){
        Pilha* piAuxReverso = criaPilha();
        if(piAuxReverso == NULL ){
            printf("Erro ao alocar pilha auxiliar\n");
            return NULL;
        }
        Pilha* piAux = criaPilha();
        if(piAux == NULL ){
            printf("Erro ao alocar pilha auxiliar\n");
            return NULL;
        }
        Elem *no = *pi;
        while(no != NULL){
            Elem* novo = (Elem*) malloc(sizeof(Elem));
            if(novo == NULL){
                printf("Erro ao alocar no auxiliar\n");
                liberaPilha(piAuxReverso);
                liberaPilha(piAux);
                return NULL;
            }
            novo->dados = no->dados;
            novo->prox = *piAuxReverso;
            *piAuxReverso = novo;
            no = no->prox;
        }
        no = *piAuxReverso;
        while(no != NULL){
            Elem* novo = (Elem*) malloc(sizeof(Elem));
            if(novo == NULL){
                printf("Erro ao alocar no auxiliar\n");
                liberaPilha(piAuxReverso);
                liberaPilha(piAuxReverso);
                return NULL;
            }
            novo->dados = no->dados;
            novo->prox = *piAux;
            *piAux = novo;
            no = no->prox;
        }
        liberaPilha(piAuxReverso);
        return piAux; 
    }
    return NULL; 
}

int pop2(Pilha* pi){
    if (*pi == NULL){
        printf("pilha vazia");
        return 0;
    }
    if(pi != NULL){
        Elem* no;
        int count = 0;
        while((*pi) != NULL && count < 2){
            no = *pi;
            *pi = (*pi)->prox;
            free(no);
            count++;
        }
        return 1;
    }
    printf("Pilha nula\n");
    return 0;
}



int push2(Pilha* pi, Aluno* al){
    if (pi == NULL){
        printf("Pilha nula");
        return 0;
    }
    int count = 0;
    while(count < 2){
        Elem* no = (Elem*) malloc(sizeof(Elem));
        if (no == NULL){
            printf("Erro ao alocar no auxiliar");
            
            while (*pi != NULL) {
                Elem* temp = *pi;
                *pi = (*pi)->prox;
                free(temp);
            }
            return 0;
        }
        no -> dados = al[count];
        no -> prox = *pi;
        *pi = no;
        count++;
}
    return 1;
}

int popN(Pilha* pi, int n){
    if (*pi == NULL){
        printf("Pilha vazia");
        return 0;
    }
    if(pi != NULL){
        Elem* no;
        int count = 0;
        while((*pi) != NULL && count < n){
            no = *pi;
            *pi = (*pi)->prox;
            free(no);
            count++;
        }
        return 1;
    }
    printf("Pilha nula");
    return 0;
}



int pushN(Pilha* pi, Aluno* al, int n){
    if (pi == NULL){
        printf("Pilha nula");
        return 0;
    }
    int count = 0;
    while(count < n){
        Elem* no = (Elem*) malloc(sizeof(Elem));
        if (no == NULL) {
            printf("Erro ao alocar no auxiliar\n");
            while (*pi != NULL) {
                Elem* temp = *pi;
                *pi = (*pi)->prox;
                free(temp);
            }
            return 0;
        }

        no -> dados = al[count];
        no -> prox = *pi;
        *pi = no;
        count++;

    }
    return 1;
}

void imprimirPilha(Pilha* pi){
    if(*pi != NULL){
        Elem* no = *pi;
        while(no!=NULL){
            printf("Matricula: %d\n", no->dados.matricula);
            printf("Nome: %s\n", no->dados.nome);
            printf("Nota 1: %.2f\n", no->dados.n1);
            printf("Nota 2: %.2f\n", no->dados.n2);
            printf("Nota 3: %.2f\n", no->dados.n3);
            printf("-------------------------------\n");
            no = no->prox;
        }
        return;
    }
    return;
}

void imprimirPilhaRecursiva(Elem* no) {
    if (no == NULL) {
        return; // Caso base: fim da pilha
    }
    
    
    // Imprime os dados do elemento atual
    printf("Matricula: %d\n", no->dados.matricula);
    printf("Nome: %s\n", no->dados.nome);
    printf("Nota 1: %.2f\n", no->dados.n1);
    printf("Nota 2: %.2f\n", no->dados.n2);
    printf("Nota 3: %.2f\n", no->dados.n3);
    printf("-------------------------------\n");
    
    // Chamada recursiva para o próximo elemento
    imprimirPilhaRecursiva(no->prox);
}

void imprimirPilhaInversaRecursiva(Elem* no) {
    if (no == NULL) {
        return; // Caso base: fim da pilha
    }
    
    imprimirPilhaRecursiva(no->prox);
    
    // Imprime os dados do elemento atual
    printf("Matricula: %d\n", no->dados.matricula);
    printf("Nome: %s\n", no->dados.nome);
    printf("Nota 1: %.2f\n", no->dados.n1);
    printf("Nota 2: %.2f\n", no->dados.n2);
    printf("Nota 3: %.2f\n", no->dados.n3);
    printf("-------------------------------\n");

    // Chamada recursiva para o próximo elemento
}