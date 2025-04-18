#include <stdio.h>
#include <stdlib.h>
#include "PilhaDinamica.h" //inclui os Prot�tipos


struct elemento{
    Aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elem;

struct elementoNum{
    int dados;
    struct elemento *prox;
};
typedef struct elementoNum ElemNum;

struct elementoStr{
    char dados;
    struct elemento *prox;
};
typedef struct elementoStr ElemStr;

// Cria uma pilha vazia
Pilha* criaPilha(){
    Pilha* pi = (Pilha*) malloc(sizeof(Pilha));
    if(pi != NULL)
        *pi = NULL;
    return pi;
}
/*

*/


// Libera a pilha
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
/*

*/

// Tamanho da pilha
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
/*

*/

// Consulta o topo da pilha
int consultaTopoPilha(Pilha* pi, Aluno *al){
    if(pi == NULL)
        return 0;
    if((*pi) == NULL)
        return 0;
    *al = (*pi)->dados;
    return 1;
}
/*

*/

// Copia a pilha *Exercicio 3*
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
/*

*/

// Copia a pilha de string *Exercicio 3*
PilhaStr *copiaPilhaStr(PilhaStr* pi){
    if (pi == NULL){
        printf("Pilha nula\n");
        return NULL;
    }
    if (*pi != NULL){
        PilhaStr* piAuxReverso = criaPilha();
        if(piAuxReverso == NULL ){
            printf("Erro ao alocar pilha auxiliar\n");
            return NULL;
        }
        PilhaStr* piAux = criaPilha();
        if(piAux == NULL ){
            printf("Erro ao alocar pilha auxiliar\n");
            return NULL;
        }
        ElemStr *no = *pi;
        while(no != NULL){
            ElemStr* novo = (ElemStr*) malloc(sizeof(ElemStr));
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
            ElemStr* novo = (ElemStr*) malloc(sizeof(ElemStr));
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
/*

*/

// Remove 2 elementos da pilha *Exercicio 1*
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
/*

*/

// Adiciona 2 elementos na pilha *Exercicio 1*
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
/*

*/

// Remove n elementos da pilha *Exercicio 2*
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
/*

*/

// Adiciona n elementos na pilha *Exercicio 2*
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
/*

*/

// Adiciona n elementos na pilha de inteiros
int pushNNum(PilhaNum* pi, int* x, int n){
    if (pi == NULL){
        printf("Pilha nula");
        return 0;
    }
    int count = 0;
    while(count < n){
        ElemNum* no = (ElemNum*) malloc(sizeof(ElemNum));
        if (no == NULL) {
            printf("Erro ao alocar no auxiliar\n");
            while (*pi != NULL) {
                ElemNum* temp = *pi;
                *pi = (*pi)->prox;
                free(temp);
            }
            return 0;
        }

        no -> dados = x[count];
        no -> prox = *pi;
        *pi = no;
        count++;

    }
    return 1;
}
/*

*/

// Adiciona 1 elemento na pilha de inteiros
int push1(PilhaNum* pi, int x){
    if (pi == NULL){
        printf("Pilha nula");
        return 0;
    }
    int count = 0;
    ElemNum* no = (ElemNum*) malloc(sizeof(ElemNum));
    if (no == NULL) {
        printf("Erro ao alocar no auxiliar\n");
        while (*pi != NULL) {
            ElemNum* temp = *pi;
            *pi = (*pi)->prox;
            free(temp);
            }
        return 0;
        }

    no -> dados = x;
    no -> prox = *pi;
    *pi = no;

    return 1;
}
/*

*/

// Imprime a pilha
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
/*

*/

// Imprime a pilha 
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
/*

*/

// Imprime a pilha de forma inversa
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
/*

*/

// imprime o maior, menor e a media da pilha de inteiros *Exercicio 4*
int maiorMenorMedia(PilhaNum* pi){
    if (pi == NULL){
        printf("pilha nula.");
        return 0;
    }

    int maior;
    int menor;
    float media = 0;
    int n = 0;

    if(*pi != NULL){

        ElemNum* no = *pi;
        
        maior = no->dados;
        menor = no->dados;
        
        while(no!=NULL){

            if(no->dados > maior){
                maior = no->dados;
            }
            if(no->dados < menor){
                menor = no->dados;
            }

            media += no->dados;
            n++;
            no = no->prox;
        }

        media = media / n;

        printf("| MAIOR: %d\n", maior);
        printf("| MENOR: %d\n", menor);
        printf("| MEDIA: %.2f\n", media);
        return 1;
    }
    return 0;
}
/*

*/

// Compara duas pilhas de inteiros *Exercicio 5*
int pilhaIgual(PilhaNum* pi1, PilhaNum* pi2){
    if (pi1 == NULL || pi2 == NULL){
        printf("pilhas nulas.");
        return 0;
    }
    if(*pi1 != NULL && *pi2 != NULL){

        ElemNum* no1 = *pi1;
        ElemNum* no2 = *pi2;

        while(no1!=NULL && no2 != NULL
            && no1->dados == no2->dados){

            no1 = no1->prox;
            no2 = no2->prox;
            
        }
        if(no1 == NULL && no2 == NULL){
            printf("são iguais");
            return 1;
        }

        printf("não são iguais");
        return 0;

        }
    return 0;
}
/*

*/

// Compara duas pilhas de string
int pilhaIgualStr(PilhaStr* pi1, PilhaStr* pi2){
    if (pi1 == NULL || pi2 == NULL){
        printf("pilhas nulas.");
        return 0;
    }
    if(*pi1 != NULL && *pi2 != NULL){

        ElemStr* no1 = *pi1;
        ElemStr* no2 = *pi2;

        while(no1!=NULL && no2 != NULL
            && no1->dados == no2->dados){

            no1 = no1->prox;
            no2 = no2->prox;
            
        }
        if(no1 == NULL && no2 == NULL){
            printf("são iguais");
            return 1;
        }

        printf("não são iguais");
        return 0;

        }
    return 0;
}
/*

*/

// Inverte a pilha de string *Exercicio 6a*
int pilhaStrInversa(PilhaStr* pi){
    
    if (pi == NULL || *pi == NULL){
        printf("pilha nula ou vazia.");
        return 0;
    }
    PilhaStr* piAuxReverso = criaPilha();
    if(piAuxReverso == NULL ){
        printf("Erro ao alocar pilha auxiliar\n");
        return 0;
    }
    
    ElemStr *no = *pi;
    while(no != NULL){
        ElemStr* novo = (ElemStr*) malloc(sizeof(ElemStr));
        if(novo == NULL){
            printf("Erro ao alocar no auxiliar\n");
            liberaPilha(piAuxReverso);
            return 0;
        }
        novo->dados = no->dados;
        novo->prox = *piAuxReverso;
        *piAuxReverso = novo;
        no = no->prox;
    }
    return piAuxReverso;
}
/*

*/

// Verifica se a pilha de string é palíndromo *Exercicio 6b*
int pilhaStrPalindromo(PilhaStr* pi){

    if (pi == NULL || *pi == NULL){
        printf("pilha nula ou vazia.");
        return 0;
    }
    PilhaStr* piAuxReverso = pilhaStrInversa(pi);
    if (piAuxReverso == NULL) {
    if (pilhaIgualStr(pi, piAuxReverso)){
        return 0;
    }

    if (pilhaIgualStr(pi, piAuxReverso) == 1){
        liberaPilha(piAuxReverso);
        printf("É palíndromo");
        return 1;
    }
    else{
        liberaPilha(piAuxReverso);
        printf("Não é palíndromo");
        return 0;
    }
}
}
/*

*/

// Verifica a quantidade de números pares e ímpares na pilha de inteiros
int pilhasNumParImpar(PilhaNum* pi){
    if (pi == NULL){
        printf("pilha nula.");
        return 0;
    }

    int parCount = 0;
    int imparCount = 0;

    if(*pi != NULL){

        ElemNum* no = *pi; 
        
        while(no!=NULL){
            if(no->dados % 2 == 0){
                parCount++;
            }
            if(no->dados % 2 != 0){
                imparCount++;
            }
            no = no->prox;
        }

        printf("| Par: %d\n", parCount);
        printf("| Impar: %d\n", imparCount);
        return 1;

    }
    return 0;
}
/*

*/

// 
int cadeiaStr(PilhaStr* pi){

}
/*

*/

// Converte um número decimal para binário e armazena na pilha de inteiros
int conversorBin(int dec, PilhaNum* pi){
    if(pi == NULL){
        printf("pilha nula.");
        return 0;
    }
    int resto;
    while(dec != 0)
    {
       resto = dec%2;
       push1(pi, resto);
       dec = dec/2;
   }
}