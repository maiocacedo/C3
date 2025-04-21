/*

* 3 - Lista de Pilha Dinamica - Algoritmos e Estruturas de Dados III 
* Autores: | > Caio Macedo Lima da Cruz.....RA: 2651378
*          | > José Carlos Seben............RA: 2651130

*/

// Arquivo: PilhaDinamica.c - Funções da pilha dinamica

#include <stdio.h>
#include <stdlib.h>
#include "PilhaDinamica.h" //inclui os Prototipos


struct elemento{
    Aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elem;

struct elementoNum{
    int dados;
    struct elementoNum *prox;
};
typedef struct elementoNum ElemNum;

struct elementoStr{
    char dados;
    struct elementoStr *prox;
};
typedef struct elementoStr ElemStr;

// Cria uma pilha vazia
Pilha* criaPilha(){
    Pilha* pi = (Pilha*) malloc(sizeof(Pilha)); // Aloca espaço para a pilha
    if(pi != NULL) // Verifica se a alocação foi bem sucedida
        *pi = NULL; // Inicializa a pilha como vazia
    return pi; // Retorna o ponteiro para a pilha
}

// Cria uma pilhaStr vazia
PilhaStr* criaPilhaStr(){
    PilhaStr* pi = (PilhaStr*) malloc(sizeof(PilhaStr)); // Aloca espaço para a pilha
    if(pi != NULL) // Verifica se a alocação foi bem sucedida
        *pi = NULL; // Inicializa a pilha como vazia
    return pi; // Retorna o ponteiro para a pilha
}

PilhaNum* criaPilhaNum(){
    PilhaNum* pi = (PilhaNum*) malloc(sizeof(PilhaNum)); // Aloca espaço para a pilha
    if(pi != NULL) // Verifica se a alocação foi bem sucedida
        *pi = NULL; // Inicializa a pilha como vazia
    return pi; // Retorna o ponteiro para a pilha
}
/*

Funções para alocar dinamicamente a pilha de Aluno, char e int.

*/

// Libera a pilha
void liberaPilha(Pilha* pi){
    if(pi != NULL){
        Elem* no; 
        while((*pi) != NULL){
            no = *pi; // Armazena o elemento atual
            *pi = (*pi)->prox;  // Avança para o próximo elemento
            free(no); // Libera o elemento atual
        }
        free(pi); // Libera o ponteiro da pilha
    }
}

// Libera a pilhaStr
void liberaPilhaStr(PilhaStr* pi){
    if(pi != NULL){
        ElemStr* no;
        while((*pi) != NULL){
            no = *pi; // Armazena o elemento atual
            *pi = (*pi)->prox; // Avança para o próximo elemento
            free(no); // Libera o elemento atual
        }
        free(pi); // Libera o ponteiro da pilha
    }
}

void liberaPilhaNum(PilhaNum* pi){
    if(pi == NULL){
        ElemNum* no;
        while((*pi) != NULL){
            no = *pi; // Armazena o elemento atual
            *pi = (*pi)->prox; // Avança para o próximo elemento
            free(no); // Libera o elemento atual
        }
        free(pi); // Libera o ponteiro da pilha
    }
}
/*

Funções para liberar a pilha de Aluno, char e int.

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

// Tamanho da pilha de Inteiros
int tamanhoPilhaNum(PilhaNum* pi){
    if(pi == NULL)
        return 0;
    int cont = 0;
    ElemNum* no = *pi;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}
 // Tamanho da pilha de string
int tamanhoPilhaStr(PilhaStr* pi){
    if(pi == NULL)
        return 0;
    int cont = 0;
    ElemStr* no = *pi;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}
/*
Funções para calcular o tamanho da pilha de Aluno, char e int.
Ela percorre a pilha e vai incrementando o contador até chegar no final da pilha.
Ela retorna o contador.
*/

// Consulta o topo da pilha
int consultaTopoPilha(Pilha* pi, Aluno *al){
    if(pi == NULL) // Verifica se a pilha é nula
        return 0;
    if((*pi) == NULL) // Verifica se a pilha é nula ou vazia
        return 0;
    *al = (*pi)->dados; // Armazena o valor do topo da pilha
    return 1; // Retorna 1 se a pilha não for nula e não estiver vazia
}

// Consulta o topo da pilha
int consultaTopoPilhaStr(PilhaStr* pi, char *str){
    if(pi == NULL) // Verifica se a pilha é nula
        return 0; 
    if((*pi) == NULL) // Verifica se a pilha é nula ou vazia
        return 0;
    *str = (*pi)->dados; // Armazena o valor do topo da pilha
    return 1; // Retorna 1 se a pilha não for nula e não estiver vazia
}

// Consulta o topo da pilha
int consultaTopoPilhaNum(PilhaNum* pi, int *x){
    if(pi == NULL) // Verifica se a pilha é nula
        return 0; 
    if((*pi) == NULL) // Verifica se a pilha é nula ou vazia
        return 0; 
    *x = (*pi)->dados; // Armazena o valor do topo da pilha
    return 1; // Retorna 1 se a pilha não for nula e não estiver vazia
}
/*
Funções para consultar o topo da pilha de Aluno, char e int.
Para consultar o topo da pilha, ela verifica se a pilha é nula ou vazia.
Se não for, ela utiliza o ponteiro de inteiro para armazenar o valor do topo da pilha.	
*/

// Copia a pilha *Exercicio 3*
Pilha *copiaPilha (Pilha* pi){
    // Verifica se a pilha é nula
    if (pi == NULL){
        printf("Pilha nula\n");
        return NULL;
    }
    // Verifica se a pilha não é vazia
    if (*pi != NULL){
        // Cria uma pilha auxiliar para armazenar os elementos
        Pilha* piAuxReverso = criaPilha();
        if(piAuxReverso == NULL ){
            printf("Erro ao alocar pilha auxiliar\n");
            return NULL;
        }
        // Cria uma pilha auxiliar para armazenar os elementos
        Pilha* piAux = criaPilha();
        if(piAux == NULL ){
            printf("Erro ao alocar pilha auxiliar\n");
            return NULL;
        }
        // Percorre a pilha original e armazena os elementos na pilha auxiliar reversa
        Elem *no = *pi;
        while(no != NULL){
            Elem* novo = (Elem*) malloc(sizeof(Elem));
            if(novo == NULL){
                printf("Erro ao alocar no auxiliar\n");
                liberaPilha(piAuxReverso);
                liberaPilha(piAux);
                return NULL;
            }
            // Armazena os dados do elemento atual na pilha auxiliar reversa
            novo->dados = no->dados;
            novo->prox = *piAuxReverso;
            *piAuxReverso = novo;
            no = no->prox;
        }
        // Percorre a pilha auxiliar reversa e armazena os elementos na pilha auxiliar
        no = *piAuxReverso;
        while(no != NULL){
            Elem* novo = (Elem*) malloc(sizeof(Elem));
            if(novo == NULL){
                printf("Erro ao alocar no auxiliar\n");
                liberaPilha(piAuxReverso);
            }
            // Armazena os dados do elemento atual na pilha auxiliar
            novo->dados = no->dados;
            novo->prox = *piAux;
            *piAux = novo;
            no = no->prox;
        }
        liberaPilha(piAuxReverso);
        return piAux; // Retorna a pilha auxiliar, que contém os elementos da pilha original, em ordem correta
    }
    return NULL; 
}

// Copia a pilha de string *Exercicio 3*
PilhaStr *copiaPilhaStr(PilhaStr* pi){
    // Verifica se a pilha é nula
    if (pi == NULL){
        printf("Pilha nula\n");
        return NULL;
    }
    // Verifica se a pilha não é vazia
    if (*pi != NULL){
        // Cria uma pilha auxiliar para armazenar os elementos
        PilhaStr* piAuxReverso = criaPilhaStr();
        if(piAuxReverso == NULL ){
            printf("Erro ao alocar pilha auxiliar\n");
            return NULL;
        }
        // Cria uma pilha auxiliar para armazenar os elementos
        PilhaStr* piAux = criaPilhaStr();
        if(piAux == NULL ){
            printf("Erro ao alocar pilha auxiliar\n");
            return NULL;
        }
        // Percorre a pilha original e armazena os elementos na pilha auxiliar reversa
        ElemStr *no = *pi;
        while(no != NULL){
            ElemStr* novo = (ElemStr*) malloc(sizeof(ElemStr));
            if(novo == NULL){
                printf("Erro ao alocar no auxiliar\n");
                liberaPilhaStr(piAuxReverso);
                liberaPilhaStr(piAux);
                return NULL;
            }
            // Armazena os dados do elemento atual na pilha auxiliar reversa
            novo->dados = no->dados;
            novo->prox = *piAuxReverso;
            *piAuxReverso = novo;
            no = no->prox;
        }
        // Percorre a pilha auxiliar reversa e armazena os elementos na pilha auxiliar
        no = *piAuxReverso;
        while(no != NULL){
            ElemStr* novo = (ElemStr*) malloc(sizeof(ElemStr));
            if(novo == NULL){
                printf("Erro ao alocar no auxiliar\n");
                liberaPilhaStr(piAuxReverso);
                return NULL;
            }
            // Armazena os dados do elemento atual na pilha auxiliar
            novo->dados = no->dados;
            novo->prox = *piAux;
            *piAux = novo;
            no = no->prox;
        }
        liberaPilhaStr(piAuxReverso);
        return piAux; // Retorna a pilha auxiliar, que contém os elementos da pilha original, em ordem correta
    }
    return NULL; 
}

// Copia a pilha de inteiros
PilhaNum *copiaPilhaNum(PilhaNum* pi){
    // Verifica se a pilha é nula
    if (pi == NULL){
        printf("Pilha nula\n");
        return NULL;
    }
    // Verifica se a pilha não é vazia
    if (*pi != NULL){
        // Cria uma pilha auxiliar para armazenar os elementos
        PilhaNum* piAuxReverso = criaPilhaNum();
        if(piAuxReverso == NULL ){
            printf("Erro ao alocar pilha auxiliar\n");
            return NULL;
        }
        // Cria uma pilha auxiliar para armazenar os elementos
        PilhaNum* piAux = criaPilhaNum();
        if(piAux == NULL ){
            printf("Erro ao alocar pilha auxiliar\n");
            return NULL;
        }
        // Percorre a pilha original e armazena os elementos na pilha auxiliar reversa
        ElemNum *no = *pi;
        while(no != NULL){
            ElemNum* novo = (ElemNum*) malloc(sizeof(ElemNum));
            if(novo == NULL){
                printf("Erro ao alocar no auxiliar\n");
                liberaPilhaNum(piAuxReverso);
                liberaPilhaNum(piAux);
                return NULL;
            }
            // Armazena os dados do elemento atual na pilha auxiliar reversa
            novo->dados = no->dados;
            novo->prox = *piAuxReverso;
            *piAuxReverso = novo;
            no = no->prox;
        }
        // Percorre a pilha auxiliar reversa e armazena os elementos na pilha auxiliar
        no = *piAuxReverso;
        while(no != NULL){
            ElemNum* novo = (ElemNum*) malloc(sizeof(ElemNum));
            if(novo == NULL){
                printf("Erro ao alocar no auxiliar\n");
                liberaPilhaNum(piAuxReverso);
                return NULL;
            }
            // Armazena os dados do elemento atual na pilha auxiliar
            novo->dados = no->dados;
            novo->prox = *piAux;
            *piAux = novo;
            no = no->prox;
        }
        liberaPilhaNum(piAuxReverso);
        return piAux; // Retorna a pilha auxiliar, que contém os elementos da pilha original, em ordem correta
    }
    return NULL; 
}


/*
Funções para copiar a pilha de Aluno, char e int.
Ela percorre a pilha e vai alocando os elementos em uma nova pilha que será inversa.
Essa nova pilha é percorrida novamente para copiar os elementos da pilha original em ordem correta.
A função retorna a nova pilha.
*/

// Adiciona 1 elemento na pilha de Alunos
int pop1(Pilha* pi){
    // Verifica se a pilha é nula
    if (*pi == NULL){
        printf("pilha vazia");
        return 0;
    }
    // Verifica se a pilha não é nula
    if(pi != NULL){
        // remove o elemento do topo da pilha
        Elem* no;
        no = *pi;
        *pi = (*pi)->prox;
        free(no); // Libera a memória do elemento removido
    
        return 1; // Retorna 1 se a pilha não for nula e não estiver vazia
    }
    printf("Pilha nula\n");
    return 0; // Retorna 0 se a pilha for nula
}

// Remove 1 elemento da pilha de Alunos
int pop1Str(PilhaStr* pi){
    // Verifica se a pilha é nula
    if (*pi == NULL){
        printf("pilha vazia");
        return 0;
    }
    // Verifica se a pilha não é nula
    if(pi != NULL){
        // remove o elemento do topo da pilha
        ElemStr* no;
        no = *pi;
        *pi = (*pi)->prox;
        free(no); // Libera a memória do elemento removido

        return 1; // Retorna 1 se a pilha não for nula e não estiver vazia
    }  
    printf("Pilha nula\n");
    return 0; // Retorna 0 se a pilha for nula
}

// Remove 1 elemento da pilha de inteiros
int pop1Num(PilhaNum* pi){
    // Verifica se a pilha é nula
    if (*pi == NULL){
        printf("pilha vazia");
        return 0;
    }
    // Verifica se a pilha não é nula
    if(pi != NULL){
        ElemNum* no;
        // remove o elemento do topo da pilha
        no = *pi;
        *pi = (*pi)->prox;
        free(no);

        return 1; // Retorna 1 se a pilha não for nula e não estiver vazia
    }
    printf("Pilha nula\n");
    return 0; // Retorna 0 se a pilha for nula
}

/*
Funções para remover elementos da pilha de Aluno, char e int.
Ela remove o elemento do topo da pilha e libera a memória alocada para ele.
*/

// Remove 2 elementos da pilha *Exercicio 1*
int pop2(Pilha* pi){
    // Verifica se a pilha é nula e se o tamanho da pilha é menor que 2
    if (pi == NULL){
        printf("Pilha nula\n");
        return 0;
    }
    if (tamanhoPilha(pi) < 2) {
        printf("Pilha com menos de dois elementos\n");
        return 0;
    }

    int count = 0;
    if( *pi == NULL){
    // Percorre a pilha e remove os elementos
    while(count < 2){
        Elem* no = *pi;
        *pi = (*pi)->prox;
        free(no); // Libera a memória do elemento removido
        count++;
    }

    return 1;
}
    printf("Pilha vazia\n");
    return 0; // Retorna 0 se a pilha for nula

}


/*
Função para remover 2 elementos da pilha de Alunos.
Ela remove os dois elementos do topo da pilha, utilizando while e um contador de 0 a 2, e libera a memória alocada para eles.
Existe validação para verificar se a pilha é nula ou se a alocação de memória falhou, e também, para caso a pilha tenha tamanho menor que 2.
*/

// Remove n elementos da pilha *Exercicio 2*
int popN(Pilha* pi, int n){
    // Verifica se a pilha é vazia
    if (*pi == NULL){
        printf("Pilha vazia");
        return 0;
    }
    // Verifica o valor de n
    if (n < 1){
        printf("Valor de n invalido\n");
        return 0;
    }
    // Verifica o tamanho da pilha
    if (tamanhoPilha(pi) < n) {
        printf("Pilha com menos de %d elementos\n", n);
        return 0;
    }
    // Verifica se a pilha não é nula
    if(pi != NULL){
        Elem* no;
        int count = 0;
        // Percorre a pilha e remove os elementos
        while((*pi) != NULL && count < n){
            no = *pi;
            *pi = (*pi)->prox;
            free(no);
            count++;
        }
        return 1; // Retorna 1 se a pilha não for nula e não estiver vazia
    }
    printf("Pilha nula");
    return 0; // Retorna 0 se a pilha for nula
}

// Remove n elementos da pilha de String
int popNStr(PilhaStr* pi, int n){
    // Verifica se a pilha é Vazia
    if (*pi == NULL){
        printf("Pilha vazia");
        return 0;
    }
    // Verifica o valor de n
    if (n < 1){
        printf("Valor de n inválido\n");
        return 0;
    }
    // Verifica o tamanho da pilha
    if (tamanhoPilhaStr(pi) < n) {
        printf("Pilha com menos de %d elementos\n", n);
        return 0;
    }
    // Verifica se a pilha não é nula
    if(pi != NULL){
        ElemStr* no;
        int count = 0;
        // Percorre a pilha e remove os elementos
        while((*pi) != NULL && count < n){
            no = *pi;
            *pi = (*pi)->prox;
            free(no);
            count++;
        }
        return 1;// Retorna 1 se a pilha não for nula e não estiver vazia
    }
    printf("Pilha nula");
    return 0; // Retorna 0 se a pilha for nula
}

// Remove n elementos da pilha de inteiros
int popNNum(PilhaNum* pi, int n){
    // Verifica se a pilha é vazia
    if (*pi == NULL){
        printf("Pilha vazia");
        return 0;
    }
    // Verifica o valor de n
    if (n < 1){
        printf("Valor de n inválido\n");
        return 0;
    }
    // Verifica o tamanho da pilha
    if (tamanhoPilhaNum(pi) < n) {
        printf("Pilha com menos de %d elementos\n", n);
        return 0;
    }
    
    // Verifica se a pilha não é nula
    if(pi != NULL){
        ElemNum* no;
        int count = 0;
        // Percorre a pilha e remove os elementos
        while((*pi) != NULL && count < n){
            no = *pi;
            *pi = (*pi)->prox;
            free(no);
            count++;
        }
        return 1; // Retorna 1 se a pilha não for nula e não estiver vazia
    }
    printf("Pilha nula");
    return 0; // Retorna 0 se a pilha for nula
}

/*
Funções para remover n elementos da pilha de Aluno, char e int.
Ela remove os n elementos do topo da pilha, utilizando while e um contador de 0 a n, e libera a memória alocada para eles.
Existe validação para verificar se a pilha é nula ou se a alocação de memória falhou, e também, para caso a pilha tenha tamanho menor que n.
*/

// Adiciona 2 elementos na pilha *Exercicio 1*
int push2(Pilha* pi, Aluno* al){
    // Verifica se a pilha é nula
    if (pi == NULL){
        printf("Pilha nula");
        return 0;
    }
    int count = 0;
    // Verifica o tamanho da pilha
    while(count < 2){
        Elem* no = (Elem*) malloc(sizeof(Elem));
        // Verifica se a alocação de memória foi bem sucedida
        if (no == NULL){
            printf("Erro ao alocar no auxiliar");
            // Libera a memória alocada para os elementos da pilha, caso a alocação falhe
            while (*pi != NULL) {
                Elem* temp = *pi;
                *pi = (*pi)->prox;
                free(temp);
            }
            return 0;
        }
        // Armazena os dados do elemento atual na pilha auxiliar
        no -> dados = al[count];
        no -> prox = *pi;
        *pi = no;
        count++;
}
    return 1; // Retorna 1 se a pilha não for nula e não estiver vazia
}

/*
Função para adicionar 2 elementos na pilha de Alunos.
Ela adiciona os dois elementos no topo da pilha, utilizando while e um contador de 0 a 2, e libera a memória alocada para eles.
Existe validação para verificar se a pilha é nula ou se a alocação de memória falhou.
*/

// Remove 1 elemento da pilha de Alunos
int push1(Pilha* pi, Aluno x){
    // Verifica se a pilha é nula
    if (pi == NULL){
        printf("Pilha nula");
        return 0;
    }

    Elem* no = (Elem*) malloc(sizeof(Elem));
    // Verifica se a alocação de memória foi bem sucedida
    if (no == NULL) {
        printf("Erro ao alocar no auxiliar\n");
        // Libera a memória alocada para os elementos da pilha, caso a alocação falhe
        while (*pi != NULL) {
            Elem* temp = *pi;
            *pi = (*pi)->prox;
            free(temp);
            }
        return 0;
        }

    // Armazena os dados do elemento atual na pilha auxiliar
    no -> dados = x;
    no -> prox = *pi;
    *pi = no;

    return 1;
}

// Adiciona 1 elemento na pilha de inteiros
int push1Num(PilhaNum* pi, int x){
    // Verifica se a pilha é nula
    if (pi == NULL){
        printf("Pilha nula");
        return 0;
    }

    ElemNum* no = (ElemNum*) malloc(sizeof(ElemNum));
    // Verifica se a alocação de memória foi bem sucedida
    if (no == NULL) {
        printf("Erro ao alocar no auxiliar\n");
        // Libera a memória alocada para os elementos da pilha, caso a alocação falhe
        while (*pi != NULL) {
            ElemNum* temp = *pi;
            *pi = (*pi)->prox;
            free(temp);
            }
        return 0; 
        }
    // Armazena os dados do elemento atual na pilha auxiliar
    no -> dados = x;
    no -> prox = *pi;
    *pi = no;

    return 1; // Retorna 1 se a pilha não for nula e não estiver vazia
}

// Adiciona 1 elemento na pilha de String
int push1Str(PilhaStr* pi, char x){
    // Verifica se a pilha é nula
    if (pi == NULL){
        printf("Pilha nula");
        return 0;
    }
    ElemStr* no = (ElemStr*) malloc(sizeof(ElemStr));
    // Verifica se a alocação de memória foi bem sucedida
    if (no == NULL) {
        printf("Erro ao alocar no auxiliar\n");
        // Libera a memória alocada para os elementos da pilha, caso a alocação falhe
        while (*pi != NULL) {
            ElemStr* temp = *pi;
            *pi = (*pi)->prox;
            free(temp);
            }
        return 0;
        }
    // Armazena os dados do elemento atual na pilha auxiliar
    no -> dados = x;
    no -> prox = *pi;
    *pi = no;

    return 1; // Retorna 1 se a pilha não for nula e não estiver vazia
}

/*
Funções para adicionar 1 elemento na pilha de Aluno, char e int.
Ela adiciona o elemento no topo da pilha e libera a memória alocada para eles.
Existe validação para verificar se a pilha é nula ou se a alocação de memória falhou.
*/

// Adiciona n elementos na pilha *Exercicio 2*
int pushN(Pilha* pi, Aluno* al, int n){
    // Verifica se a pilha é nula
    if (pi == NULL){
        printf("Pilha nula");
        return 0;
    }
    int count = 0;
    // percorre a pilha e adiciona os elementos
    while(count < n){
        Elem* no = (Elem*) malloc(sizeof(Elem));
        // Verifica se a alocação de memória foi bem sucedida
        if (no == NULL) {
            printf("Erro ao alocar no auxiliar\n");
            // Libera a memória alocada para os elementos da pilha, caso a alocação falhe
            while (*pi != NULL) {
                Elem* temp = *pi;
                *pi = (*pi)->prox;
                free(temp);
            }
            return 0;
        }
        // Armazena os dados do elemento atual na pilha auxiliar
        no -> dados = al[count];
        no -> prox = *pi;
        *pi = no;
        count++;

    }
    return 1; // Retorna 1 se a pilha não for nula e não estiver vazia
}

// Adiciona n elementos na pilha de inteiros
int pushNNum(PilhaNum* pi, int* x, int n){
    // Verifica se a pilha é nula
    if (pi == NULL){
        printf("Pilha nula");
        return 0;
    }
    int count = 0;
    // percorre a pilha e adiciona os elementos
    while(count < n){
        ElemNum* no = (ElemNum*) malloc(sizeof(ElemNum));
        // Verifica se a alocação de memória foi bem sucedida
        if (no == NULL) {
            printf("Erro ao alocar no auxiliar\n");
            // Libera a memória alocada para os elementos da pilha, caso a alocação falhe
            while (*pi != NULL) {
                ElemNum* temp = *pi;
                *pi = (*pi)->prox;
                free(temp);
            }
            return 0;
        }
        // Armazena os dados do elemento atual na pilha auxiliar
        no -> dados = x[count];
        no -> prox = *pi;
        *pi = no;
        count++;

    }
    return 1; // Retorna 1 se a pilha não for nula e não estiver vazia
}

// Adiciona n elementos na pilha de String
int pushNStr(PilhaStr* pi, char* x, int n){
    // Verifica se a pilha é nula
    if (pi == NULL){
        printf("Pilha nula");
        return 0;
    }
    int count = 0;
    // percorre a pilha e adiciona os elementos
    while(count < n){
        ElemStr* no = (ElemStr*) malloc(sizeof(ElemStr));
        // Verifica se a alocação de memória foi bem sucedida
        if (no == NULL) {
            printf("Erro ao alocar no auxiliar\n");
            // Libera a memória alocada para os elementos da pilha, caso a alocação falhe
            while (*pi != NULL) {
                ElemStr* temp = *pi;
                *pi = (*pi)->prox;
                free(temp);
            }
            return 0;
        }
        // Armazena os dados do elemento atual na pilha auxiliar
        no -> dados = x[count];
        no -> prox = *pi;
        *pi = no;
        count++;

    }
    return 1; // Retorna 1 se a pilha não for nula e não estiver vazia
}


/*
Funções para adicionar n elementos na pilha de Aluno, char e int.
Ela adiciona os n elementos no topo da pilha, utilizando while e um contador de 0 a n, e libera a memória alocada para eles.
Existe validação para verificar se a pilha é nula ou se a alocação de memória falhou.
*/

// Imprime a pilha de Alunos
void imprimirPilha(Pilha* pi){
    // Verifica se a pilha é vazia
    if(*pi != NULL || pi == NULL){
        // Percorre a pilha e imprime os elementos
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
// Imprime a pilha de String
void imprimirPilhaStr(PilhaStr* pi){
    // Verifica se a pilha é vazia
    if(*pi != NULL || pi == NULL){
        ElemStr* no = *pi;
        // Percorre a pilha e imprime os elementos
        while(no!=NULL){
            printf("String: %c\n", no->dados);
            printf("-------------------------------\n");
            no = no->prox;
        }
        return;
    }
    return;
}
// Imprime a pilha de inteiros
void imprimirPilhaNum(PilhaNum* pi){
    // Verifica se a pilha é vazia
    if(*pi != NULL || pi == NULL){
        ElemNum* no = *pi;
        // Percorre a pilha e imprime os elementos
        while(no!=NULL){
            printf("Numero: %d\n", no->dados);
            printf("-------------------------------\n");
            no = no->prox;
        }
        return;
    }
    return;
}

/*
Funções para imprimir a pilha de Aluno, char e int.
Ela percorre a pilha e imprime os dados de cada elemento.
*/

// Imprime a pilha de Alunos de forma recursiva
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
Função para imprimir a pilha de Alunos de forma recursiva.
Ela percorre a pilha e imprime os dados de cada elemento.
*/

// Imprime a pilha de Alunos de forma inversa, utilizando recursão
void imprimirPilhaInversaRecursiva(Elem* no) {
    if (no == NULL) {
        return; // Caso base: fim da pilha
    }
    
    imprimirPilhaInversaRecursiva(no->prox);
    
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
Função para imprimir a pilha de Alunos de forma inversa, em relação a pilha, utilizando recursão.
Ela percorre a pilha e imprime os dados de cada elemento.
*/

// imprime o maior, menor e a media da pilha de inteiros *Exercicio 4*
int maiorMenorMedia(PilhaNum* pi){
    // Verifica se a pilha é nula
    if (pi == NULL){
        printf("pilha nula.");
        return 0;
    }

    int maior;
    int menor;
    float media = 0;
    int n = 0;

    // Verifica se a pilha não é vazia
    if(*pi != NULL){

        ElemNum* no = *pi;
        
        // Inicializa o maior e menor elemento com o primeiro elemento da pilha
        maior = no->dados;
        menor = no->dados;

        // Percorre a pilha e calcula o maior, menor e a média
        while(no!=NULL){

            // Verifica o maior e menor elemento
            if(no->dados > maior){
                maior = no->dados;
            }
            if(no->dados < menor){
                menor = no->dados;
            }
            // Soma os elementos para calcular a média
            media += no->dados;
            n++;// Incrementa o contador de elementos
            no = no->prox; //'
        }

        // Calcula a média
        media = media / n;

        // Imprime os resultados
        printf("| MAIOR: %d\n", maior);
        printf("| MENOR: %d\n", menor);
        printf("| MEDIA: %.2f\n", media);
        return 1; // Retorna 1 se a pilha não for nula e não estiver vazia
    }
    return 0; // Retorna 0 se a pilha for nula 
}

/*
Função para imprimir o maior, menor e a media da pilha de inteiros.
Ela percorre a pilha, comparando os elementos, onde é armazenado o maior e menor elemento, e calcula a média.
por fim, imprime os resultados.
*/

// Compara duas pilhas de inteiros *Exercicio 5*
int pilhaIgual(PilhaNum* pi1, PilhaNum* pi2){
    // Verifica se as pilhas são nulas
    if (pi1 == NULL || pi2 == NULL){
        printf("pilhas nulas.");
        return 0;
    }
    // Verifica se as pilhas não são vazias
    if(*pi1 != NULL && *pi2 != NULL){

        // Cria dois ponteiros para percorrer as pilhas
        ElemNum* no1 = *pi1;
        ElemNum* no2 = *pi2;

        // Percorre as pilhas e compara os elementos
        while(no1!=NULL && no2 != NULL
            && no1->dados == no2->dados){
            
            // Se os elementos forem iguais, avança para o próximo elemento
            no1 = no1->prox;
            no2 = no2->prox;
            
        }
        // Verifica se as pilhas são iguais, se ambas chegaram ao fim
        if(no1 == NULL && no2 == NULL){
            printf("As pilhas sao iguais");
            return 1;
        }

        printf("As pilhas nao sao iguais");
        return 0;

        }
    return 0;
}

// Compara duas pilhas de string
int pilhaIgualStr(PilhaStr* pi1, PilhaStr* pi2){
    // Verifica se as pilhas são nulas
    if (pi1 == NULL || pi2 == NULL){
        printf("pilhas nulas.");
        return 0;
    }

    // Verifica se as pilhas não são vazias
    if(*pi1 != NULL && *pi2 != NULL){
        // Cria dois ponteiros para percorrer as pilhas
        ElemStr* no1 = *pi1;
        ElemStr* no2 = *pi2;

        // Percorre as pilhas e compara os elementos
        while(no1!=NULL && no2 != NULL
            && no1->dados == no2->dados){
            
            // Se os elementos forem iguais, avança para o próximo elemento
            no1 = no1->prox;
            no2 = no2->prox;
            
        }
        // Verifica se as pilhas são iguais, se ambas chegaram ao fim
        if(no1 == NULL && no2 == NULL){
            printf("As pilhas são iguais");
            return 1;
        }

        printf("As pilhas nao sao iguais");
        return 0;

        }
    return 0;
}
/*
Funções para comparar duas pilhas de inteiros ou de strings.
Ela percorre as duas pilhas, comparando os elementos, e verifica se são iguais.
caso sejam iguais, ela comtinua o loop.
por fim, verifica se ambas chegaram ao fim, e imprime o resultado.
se não, imprime que não são iguais.
*/

// Inverte a pilha de string *Exercicio 6a*
PilhaStr* pilhaStrInversa(PilhaStr* pi){
    // Verifica se a pilha é nula
    if (pi == NULL || *pi == NULL){
        printf("pilha nula ou vazia.");
        return NULL;
    }
    PilhaStr* piAuxReverso = criaPilhaStr();
    // Verifica se a pilha auxiliar foi criada com sucesso
    if(piAuxReverso == NULL ){
        printf("Erro ao alocar pilha auxiliar\n");
        return NULL;
    }
    
    ElemStr *no = *pi;
    // Percorre a pilha original e armazena os elementos na pilha auxiliar reversa
    while(no != NULL){
        ElemStr* novo = (ElemStr*) malloc(sizeof(ElemStr));
        if(novo == NULL){
            printf("Erro ao alocar no auxiliar\n");
            liberaPilhaStr(piAuxReverso);
            return NULL;
        }
        // Armazena os dados do elemento atual na pilha auxiliar reversa
        novo->dados = no->dados;
        novo->prox = *piAuxReverso;
        *piAuxReverso = novo;
        no = no->prox;
    }
    return piAuxReverso;
}
/*
Função para inverter a pilha de string.
Ela percorre a pilha original e armazena os elementos na pilha auxiliar reversa.
se a pilha auxiliar for criada com sucesso, ela retorna a pilha auxiliar.
Caso contrário, libera a memória alocada e retorna NULL.
*/

// Verifica se a pilha de string é palíndromo *Exercicio 6b*
int pilhaStrPalindromo(PilhaStr* pi){
    // Verifica se a pilha é nula
    if (pi == NULL || *pi == NULL){
        printf("pilha nula ou vazia.");
        return 0;
    }

    PilhaStr* piAuxReverso = pilhaStrInversa(pi);
    // Verifica se a pilha auxiliar foi criada com sucesso
    if (piAuxReverso == NULL) {
        printf("Erro ao inverter a pilha\n");
        return 0;
    }
    // verifica se as pilhas são iguais
    if (pilhaIgualStr(pi, piAuxReverso) == 0){
        return 0;
    }
    if (pilhaIgualStr(pi, piAuxReverso) == 1){
        liberaPilhaStr(piAuxReverso);
        printf("É palíndromo");
        return 1; // Retorna 1 se a pilha for palíndromo
    }
    else{
        // Se não for palíndromo, libera a pilha auxiliar e retorna 0
        liberaPilhaStr(piAuxReverso);
        printf("Não é palíndromo");
        return 0;
    }
}

/*
Função para verificar se a pilha de string é palíndromo.
Ela utiliza a função pilhaStrInversa para inverter a pilha e compara as duas pilhas.
Caso sejam iguais, imprime que é palíndromo.
Caso contrário, imprime que não é palíndromo.
*/

// Verifica a quantidade de números pares e ímpares na pilha de inteiros *Exercicio 7*
int pilhasNumParImpar(PilhaNum* pi){
    // Verifica se a pilha é nula
    if (pi == NULL){
        printf("pilha nula.");
        return 0;
    }

    int parCount = 0;
    int imparCount = 0;

    // Verifica se a pilha não é vazia
    if(*pi != NULL){

        ElemNum* no = *pi; 
        // Percorre a pilha e conta os números pares e ímpares
        while(no!=NULL){
            // Verifica se o número é par ou ímpar
            if(no->dados % 2 == 0){
                parCount++; // Incrementa o contador de pares
            }
            if(no->dados % 2 != 0){
                imparCount++; // Incrementa o contador de ímpares
            }
            no = no->prox;
        }
        // Imprime os resultados
        printf("| Par: %d\n", parCount);
        printf("| Impar: %d\n", imparCount);
        return 1;

    }
    return 0;
}

/*
Função para verificar a quantidade de números pares e ímpares na pilha de inteiros.
Ela percorre a pilha, verificando se o número é par ou ímpar, e incrementa os contadores.
Por fim, imprime os resultados.
*/

// Exercicio 8
int xCy(char* str){
    // Verifica se a string é nula ou vazia
    if (str == NULL){
        printf("string nula.");
        return 0;
    }
    // Verifica se a string é vazia
    if (str[0] == '\0'){
        printf("string vazia.");
        return 0;
    }

    PilhaStr* pi = criaPilhaStr();
    // Verifica se a pilha foi criada com sucesso
    if(pi == NULL ){
        printf("Erro ao alocar pilha auxiliar\n");
        return 0;
    }

    char c;
    int i = 0;
    // Percorre a string até encontrar o separador 'C'
    while(str[i] != 'C' && str[i] != '\0' &&
            (str[i] == 'A' || str[i] == 'B')){
        push1Str(pi, str[i]); // Empilha o caractere atual
        i++; // Avança para o próximo caractere
    }
    // Verifica se o separador 'C' foi encontrado
    if(str[i] != 'C'){
        printf("Invalido\n");
        liberaPilhaStr(pi);
        return 0;
    }

    i++; // Avança para o próximo caractere após o separador 'C'

    // Percorre a string após o separador 'C'
    while(str[i] != '\0'){

        consultaTopoPilhaStr(pi, &c);
        // Verifica se o caractere atual é 'A' ou 'B'
        if (str[i]!='A' && str[i]!='B'){
            printf("InvAlido\n");
            liberaPilhaStr(pi);
            return 0;
        }
        // Verifica se o caractere atual é diferente do topo da pilha
        // Se o caractere atual for 'A', o topo da pilha deve ser 'B' e vice-versa
        if((c == 'A' && str[i] != 'B') || (c == 'B' && str[i] != 'A')){
            printf("InvAlido\n");
            liberaPilhaStr(pi);
            return 0;
        }
        // Desempilha o caractere do topo da pilha
        if(pop1Str(pi) == 0){
            printf("InvAlido\n");
            liberaPilhaStr(pi);
            return 0;
        }
            
        i++; // Avança para o próximo caractere
    }
    if (tamanhoPilhaStr(pi) == 0) {
        printf("VAlido: %s\n", str);
        liberaPilhaStr(pi);
        return 1;
    } else {
        printf("InvAlido\n");
        liberaPilhaStr(pi);
        return 0;
    }
}
/*
Função para verificar se a string segue o padrão xCy, onde se x é ABABAA Y é BABABB, e C é o separador.
Ela percorre a string, empilhando os caracteres A e B de x até encontrar o C.
Depois, desempilha os caracteres A e B e compara com y, verificando se são válidos.
Caso sejam válidos, imprime que é válido.
Caso contrário, imprime que é inválido.
*/

// Converte um número decimal para binário e armazena na pilha de inteiros *Exercicio 9*
PilhaNum *conversorBin(int dec, PilhaNum* pi){
    // Verifica se a pilha é nula
    if(pi == NULL){
        printf("pilha nula.");
        return NULL;
    }
    
    int resto;
    while(dec != 0)
    {     
        resto = dec%2;
        push1Num(pi, resto);
        dec = dec/2;
   }
    return pi;
}

/*
Função para converter um número decimal para binário e armazenar na pilha de inteiros.
Ela utiliza o método de divisão sucessiva, onde o resto da divisão é empilhado.
Depois, o número é dividido por 2 até que o número decimal seja 0.
Por fim, retorna a pilha com os números binários.
*/


/*
MENUS PARA ACESSAR AS PILHAS E REALIZAR AS OPERAÇÕES;

- MENU PRINCIPAL: TE LEVA PARA OS OUTROS MENUS;
- MENU PILHA ALUNO: TE LEVA PARA O MENU DE ALUNOS;
- MENU PILHA STR: TE LEVA PARA O MENU DE STRINGS;
- MENU PILHA NUM: TE LEVA PARA O MENU DE INTEIROS;
- MENU PILHA EX: TE LEVA PARA O MENU DE EXERCÍCIOS ONDE CADA EXERCÍCIO PODE SER ACESSADO INDIVIDUALMENTE;

*/

// Menu do exercício 9 
void menu(){
    PilhaNum* pi = NULL;
    int op = 0;
    while(op != 8){
    printf("Escolha uma opcao:\n");
    printf("1-Inicializa pilha.\n");
    printf("2-Verifica se a pilha e vazia.\n");
    printf("3-Verifica se a pilha e cheia.\n");
    printf("4-Empilha o elemento na pilha.\n");
    printf("5-Desempilha elemento da pilha.\n");
    printf("6-Le topo de um pilha.\n");
    printf("7-Converte um numero decimal em binario.\n");
    printf("8-Sair.\n");
    scanf("%d", &op);
    switch(op){
        case 1:
            pi = criaPilhaNum();
            printf("Pilha criada com sucesso.\n");
            break;
        case 2:
            if (pi == NULL || *pi == NULL)
                printf("Pilha vazia.\n");
            
            break;
        case 3:
            if (pi != NULL || *pi != NULL)
                printf("Pilha cheia.\n");
            break;
        case 4:{
            int x;
            printf("Digite um numero inteiro: ");
            scanf("%d", &x);
            if(push1Num(pi, x) == 1)
                printf("Elemento empilhado com sucesso.\n");
            
            break;
        }
        case 5:
            if(pop1Num(pi) == 1)
                printf("Elemento desempilhado com sucesso.\n");
            break;
        case 6:{
            int xTopo;
            if(consultaTopoPilhaNum(pi, &xTopo) == 1)
                printf("Elemento no topo da pilha: %d\n", xTopo);
            break;
        }
        case 7:{
            int dec;
            printf("Digite um numero decimal: ");
            scanf("%d", &dec);
            PilhaNum* piNumDec = criaPilhaNum();
            piNumDec = conversorBin( dec, piNumDec);
            printf("Pilha representando o número em binario:\n");
            imprimirPilhaNum(piNumDec);
            printf("Numero convertido com sucesso.\n");
            liberaPilhaNum(piNumDec);
            break;
        }
        case 8:
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida. Tente novamente.\n");
            break;
    }
}
}

// Menu principal
void menuPrincipal(){
    int op = 0;
    while (op != 5){
    
    printf("Escolha uma opcao:\n");
    printf("1-Pilha de Alunos.\n"); 
    printf("2-Pilha de String\n"); 
    printf("3-Pilha de inteiros.\n"); 
    printf("4- Exercicios\n"); 
    printf("5-Sair.\n");
    scanf("%d", &op);
    switch (op) {
        case 1:
            menuPilhaAluno();
            break;
        case 2:
            menuPilhaStr();
            break;
        case 3:
            menuPilhaNum();
            break;
        case 4:
            menuPilhaEx();
            break;
        case 5:
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida. Tente novamente.\n");
            break;
    
    }
}
} 

// Menu de pilha de Alunos
void menuPilhaAluno(){
    int op = 0;
    Pilha* pi = NULL;
    while (op != 8){
    
    printf("Escolha uma opcao:\n");
    printf("1-Inicializa pilha.\n"); 
    printf("2-Verifica se a pilha e vazia.\n"); 
    printf("3-Verifica se a pilha e cheia.\n"); 
    printf("4-Empilha o elemento na pilha.\n"); 
    printf("5-Desempilha elemento da pilha.\n"); 
    printf("6-Le topo de um pilha.\n"); 
    printf("7-Imprimir pilha Inversa\n"); 
    printf("8-Sair.\n");
    scanf("%d", &op);
    switch(op){
        case 1:
            pi = criaPilha();
            if(pi != NULL){
                printf("Pilha criada com sucesso.\n");
            }else{
                printf("Erro ao criar pilha.\n");
            }
            break;
        case 2:
            if (pi == NULL || *pi == NULL){
                printf("Pilha vazia.\n");
            }else{
                printf("Pilha nao vazia.\n");
            }
            break;
        case 3:
            if (pi == NULL || *pi == NULL){
                printf("Pilha cheia.\n");
            }else{
                printf("Pilha nao cheia.\n");
            }
            break;
        case 4:{
            Aluno al;
            printf("Digite a matricula: ");
            scanf("%d", &al.matricula);
            printf("Digite o nome: ");
            scanf("%s", al.nome);
            printf("Digite a nota 1: ");
            scanf("%f", &al.n1);
            printf("Digite a nota 2: ");
            scanf("%f", &al.n2);
            printf("Digite a nota 3: ");
            scanf("%f", &al.n3);
            if(push1(pi, al) == 1)
                printf("Aluno empilhado com sucesso.\n");
            break;
        }
        case 5:
            if(pop1(pi) == 1)
                printf("Aluno desempilhado com sucesso.\n");
            break;
        case 6:{
            Aluno alTopo;
        
            if(consultaTopoPilha(pi, &alTopo) == 1)
                printf("Aluno no topo da pilha: %d\n", alTopo.matricula);
            break;
        }
        case 7:
            printf("Pilha Inversa:\n");
            imprimirPilhaInversaRecursiva(*pi);
            break;
        case 8:
            liberaPilha(pi);
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida. Tente novamente.\n");
            break;
        }
    }
    }

// Menu de pilha de inteiros
void menuPilhaNum(){
    int op = 0;
    int x;
    PilhaNum* pi = NULL;
    while (op != 8){
    
    printf("Escolha uma opcao:\n");
    printf("1-Inicializa pilha.\n"); 
    printf("2-Verifica se a pilha e vazia.\n"); 
    printf("3-Verifica se a pilha e cheia.\n"); 
    printf("4-Empilha o elemento na pilha.\n"); 
    printf("5-Desempilha elemento da pilha.\n"); 
    printf("6-Le topo de um pilha.\n"); 
    printf("7-Converte um numero decimal em binario.\n"); 
    printf("8-Sair.\n");
    scanf("%d", &op);
    switch(op){
        case 1:
            pi = criaPilhaNum();
            if(pi != NULL){
                printf("Pilha criada com sucesso.\n");
            }else{
                printf("Erro ao criar pilha.\n");
            }
            break;
        case 2:
            if (pi == NULL || *pi == NULL){
                printf("Pilha vazia.\n");
            }else{
                printf("Pilha nao vazia.\n");
            }
            break;
        case 3:
            if (pi == NULL || *pi == NULL){
                printf("Pilha cheia.\n");
            }else{
                printf("Pilha nao cheia.\n");
            }
            break;
        case 4:
            printf("Digite um numero inteiro: ");
            scanf("%d", &x);
            if(push1Num(pi, x) == 1)
                printf("Numero empilhado com sucesso.\n");
            break;
        case 5:
            if(pop1Num(pi) == 1)
                printf("Numero desempilhado com sucesso.\n");
            break;
        case 6:{
            int topoNum;
            if(consultaTopoPilhaNum(pi, &topoNum) == 1)
                printf("Numero no topo da pilha: %d\n", topoNum);
            break;
        }
        case 7:{
            int dec;
            printf("Digite um numero decimal: ");
            scanf("%d", &dec);
            conversorBin(dec, pi);
            break;
        }
        case 8:
            liberaPilhaNum(pi);
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida. Tente novamente.\n");
            break;
        }
    }
}


// Menu de pilha de strings
void menuPilhaStr(){
    int op = 0;
    char c;
    PilhaStr* pi = NULL;
    while (op != 8){
    printf("Escolha uma opcao:\n");
    printf("1-Inicializa pilha.\n"); 
    printf("2-Verifica se a pilha e vazia.\n"); 
    printf("3-Verifica se a pilha e cheia.\n"); 
    printf("4-Empilha o elemento na pilha.\n"); 
    printf("5-Desempilha elemento da pilha.\n"); 
    printf("6-Le topo de um pilha.\n"); 
    printf("7-Verifica se cadeia de caracteres é xCy\n"); 
    printf("8-Sair.\n");
    scanf("%d", &op);
    switch(op){
        case 1:
            pi = criaPilhaStr();
            if(pi != NULL){
                printf("Pilha criada com sucesso.\n");
            }else{
                printf("Erro ao criar pilha.\n");
            }
            break;
        case 2:
            if (pi == NULL || *pi == NULL){
                printf("Pilha vazia.\n");
            }else{
                printf("Pilha nao vazia.\n");
            }
            break;
        case 3:
            if (pi == NULL || *pi == NULL){
                printf("Pilha cheia.\n");
            }else{
                printf("Pilha nao cheia.\n");
            }
            break;
        case 4:
            printf("Digite um caractere: ");
            scanf(" %c", &c);
            if(push1Str(pi, c) == 1)
                printf("Caractere empilhado com sucesso.\n");
            break;
        case 5:
            if(pop1Str(pi) == 1)
                printf("Caractere desempilhado com sucesso.\n");
            break;
        case 6:
            consultaTopoPilhaStr(pi, &c);
            if(c != '\0')
                printf("Caractere no topo da pilha: %c\n", c);
            break;
        case 7:{
            printf("Digite a cadeia de caracteres: ");
            char str[100];
            scanf("%s", str);
            if(xCy(str) == 1)
                printf("Cadeia de caracteres valida.\n");
            else
                printf("Cadeia de caracteres invalida.\n");
            break;
        }
        case 8:
            liberaPilhaStr(pi);
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida. Tente novamente.\n");
            break;
        }
    }
}

// Menu de exercícios
// - Exercicio 1: push2 e pop2
// - Exercicio 2: pushN e popN
// - Exercicio 3: copiaPilha
// - Exercicio 4: maiorMenorMedia
// - Exercicio 5: pilhaIgual
// - Exercicio 6: pilhaStrInversa e pilhaStrPalindromo
// - Exercicio 7: pilhasNumParImpar
// - Exercicio 8: xCy
// - Exercicio 9: conversorBin e Menu
void menuPilhaEx(){
    int op = 0;
    int n;
    Pilha* pi = criaPilha();
    PilhaNum* piNum = criaPilhaNum();
    PilhaStr* piStr = criaPilhaStr();
    while (op !=10){
    
    printf("Escolha uma opcao:\n");
    printf("1- Exercicio 1\n"); 
    printf("2- Exercicio 2\n"); 
    printf("3- Exercicio 3\n"); 
    printf("4- Exercicio 4\n"); 
    printf("5- Exercicio 5\n"); 
    printf("6- Exercicio 6\n"); 
    printf("7- Exercicio 7\n"); 
    printf("8- Exercicio 8\n");
    printf("9- Exercicio 9\n");
    printf("10-Sair.\n");
    scanf("%d", &op);

    switch (op) {
        case 1:
            printf("Exercicio 1\n");
            Aluno *al = (Aluno*) malloc(sizeof(Aluno)*2);
            printf("- push2\n\n");
            if (al == NULL) {
                printf("Erro ao alocar aluno\n");
                return;
            }
            for(int i = 0; i < 2; i++){
            printf("Digite a matricula: ");
            scanf("%d", &al[i].matricula);
            printf("Digite o nome: ");
            scanf("%s", al[i].nome);
            printf("Digite a nota 1: ");
            scanf("%f", &al[i].n1);
            printf("Digite a nota 2: ");
            scanf("%f", &al[i].n2);
            printf("Digite a nota 3: ");
            scanf("%f", &al[i].n3);
        }
            if(push2(pi, al) == 1){
                printf("Aluno empilhado com sucesso.\n");
                printf("Pilha de Alunos:\n");
                imprimirPilha(pi);
            }
            printf("- pop2\n\n");
            if(pop2(pi) == 1){
                printf("Aluno desempilhado com sucesso.\n");
                printf("Pilha de Alunos:\n");
                imprimirPilha(pi);
            }
            free(al);
            break;
        case 2:
            printf("Exercicio 2\n");
            printf("- pushN\n\n");
            printf("Digite a quantidade de alunos: ");

            scanf("%d", &n);
            Aluno *al2 = (Aluno*) malloc(sizeof(Aluno)*n);
            if (al2 == NULL) {
                printf("Erro ao alocar aluno\n");
                return;
            }
            for(int i = 0; i < n; i++){
                printf("Digite a matricula: ");
                scanf("%d", &al2[i].matricula);
                printf("Digite o nome: ");
                scanf("%s", al2[i].nome);
                printf("Digite a nota 1: ");
                scanf("%f", &al2[i].n1);
                printf("Digite a nota 2: ");
                scanf("%f", &al2[i].n2);
                printf("Digite a nota 3: ");
                scanf("%f", &al2[i].n3);
            }
            if(pushN(pi, al2, n) == 1){
                printf("Alunos empilhados com sucesso.\n");
                printf("Pilha de Alunos:\n");
                imprimirPilha(pi);
            }
            printf("- popN\n\n");
            printf("Digite a quantidade de alunos a desempilhar: ");
            scanf("%d", &n);
            if(popN(pi, n) == 1){
                printf("Alunos desempilhados com sucesso.\n");
                printf("Pilha de Alunos:\n");
                imprimirPilha(pi);
            }
            break;
        case 3:
            printf("Exercicio 3\n");
            printf("- copiaPilha\n\n");
            Pilha* piCopia = copiaPilha(pi);
            if(piCopia != NULL){
                printf("Pilha copiada com sucesso.\n");
                printf("Pilha de Alunos:\n");
                imprimirPilha(piCopia);
            }
            break;
        case 4:
            printf("Exercicio 4\n");
            printf("- maiorMenorMedia\n\n");
            printf("Digite a quantidade de numeros: ");
            int nNum;
            scanf("%d", &nNum);
            int* x = (int*) malloc(sizeof(int)*nNum);
            if (x == NULL) {
                printf("Erro ao alocar numeros\n");
                return;
            }
            for(int i = 0; i < nNum; i++){
                printf("Digite o numero %d: ", i+1);
                scanf("%d", &x[i]);
            }
            if(pushNNum(piNum, x, nNum) == 1){
                printf("Numeros empilhados com sucesso.\n");
                printf("Pilha de Numeros:\n");
                imprimirPilhaNum(piNum);
            }
            printf("- maiorMenorMedia: \n");
            if(maiorMenorMedia(piNum) == 1)
                printf("Maior, menor e media calculados com sucesso.\n");
            free(x);    
            break;
            
        case 5:
            printf("Exercicio 5\n");
            printf("- pilhaIgual\n\n");
            PilhaNum* piNum2 = criaPilhaNum();
            PilhaNum* piNum3 = criaPilhaNum();

            if(piNum2 != NULL)
                printf("Pilha criada com sucesso.\n");
            if(piNum3 != NULL)
                printf("Pilha criada com sucesso.\n");
            for(int i = 0; i < 5; i++){
                push1Num(piNum2, i);
            }
            for(int i = 0; i < 5; i++){
                push1Num(piNum3, i);
            }

            printf("Pilha 1:\n");
            imprimirPilhaNum(piNum2);

            printf("Pilha 2:\n");
            imprimirPilhaNum(piNum3);
            
            if(pilhaIgual(piNum2, piNum3) == 1)
                printf("As pilhas sao iguais.\n");

            liberaPilhaNum(piNum2);
            liberaPilhaNum(piNum3);
            break;
        case 6:
            printf("Exercicio 6\n");
            printf("- pilhaStrInversa\n\n");
            printf("Digite a quantidade de caracteres: ");
            int nStr;
            scanf("%d", &nStr);
            char* str = (char*) malloc(sizeof(char)*(nStr+1));
            if (str == NULL) {
                printf("Erro ao alocar caracteres\n");
                return;
            }
            printf("Digite a String: ");
            scanf("%s", str);
            PilhaStr* piStr2 = criaPilhaStr();
            PilhaStr* piStrInv = criaPilhaStr();
            if(piStr2 != NULL)
                printf("Pilha criada com sucesso.\n");
            pushNStr(piStr2, str, nStr);
            printf("Pilha de String:\n");
            imprimirPilhaStr(piStr2);
            printf("- pilhaStrInversa: \n");
            piStrInv = pilhaStrInversa(piStr2);
            imprimirPilhaStr(piStrInv);
            printf("- pilhaStrPalindromo: \n");
            if(pilhaStrPalindromo(piStr2) == 1)
                printf("A pilha e palíndromo.\n");
            else
                printf("A pilha nao e palíndromo.\n");
            free(str);
            liberaPilhaStr(piStr2);
            break;
        case 7:
            printf("Exercicio 7\n");
            printf("- pilhasNumParImpar\n\n");
            printf("Digite a quantidade de numeros: ");
            int nNum2;
            PilhaNum* piNumParImpar = criaPilhaNum();
            scanf("%d", &nNum2);
            int* x2 = (int*) malloc(sizeof(int)*nNum2);
            if (x2 == NULL) {
                printf("Erro ao alocar numeros\n");
                return;
            }
            for(int i = 0; i < nNum2; i++){
                printf("Digite o numero %d: ", i+1);
                scanf("%d", &x2[i]);
            }
            if(pushNNum(piNumParImpar, x2, nNum2) == 1){
                printf("Numeros empilhados com sucesso.\n");
                printf("Pilha de Numeros:\n");
                imprimirPilhaNum(piNumParImpar);
            }
            printf("- pilhasNumParImpar: \n");
            if(pilhasNumParImpar(piNumParImpar) == 1)
                printf("Quantidade de pares e impares calculadas com sucesso.\n");
            free(x2);
            liberaPilhaNum(piNumParImpar);
            break;
        case 8:
            printf("Exercicio 8\n");
            printf("- xCy\n\n");
            printf("Digite a cadeia de caracteres: ");
            char str2[100];
            scanf("%s", str2);

            if(xCy(str2) == 1)
                printf("Cadeia de caracteres valida.\n");
            else
                printf("Cadeia de caracteres invalida.\n");

            break;
        case 9:
            printf("Exercicio 9\n");
            printf("- Menu\n\n");
            menu();
            break;
        case 10:
            
            liberaPilha(pi);
            liberaPilhaNum(piNum);
            liberaPilhaStr(piStr);
            printf("Saindo...\n");

            break;
        default:
            printf("Opcao invalida. Tente novamente.\n");
            break;
    }
}
}
