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
        printf("Valor de n inválido\n");
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
int pushNStr(PilhaStr* pi, int* x, int n){
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
            printf("Número: %d\n", no->dados);
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
            printf("são iguais");
            return 1;
        }

        printf("não são iguais");
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
            printf("são iguais");
            return 1;
        }

        printf("não são iguais");
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
        printf("Inválido\n");
        liberaPilhaStr(pi);
        return 0;
    }

    i++; // Avança para o próximo caractere após o separador 'C'

    // Percorre a string após o separador 'C'
    while(str[i] != '\0'){

        consultaTopoPilhaStr(pi, &c);
        // Verifica se o caractere atual é 'A' ou 'B'
        if (str[i]!='A' && str[i]!='B'){
            printf("Inválido\n");
            liberaPilhaStr(pi);
            return 0;
        }
        // Verifica se o caractere atual é igual ao topo da pilha
        if(str[i] == c){
            printf("Inválido\n");
            liberaPilhaStr(pi);
            return 0;
        }
        // Desempilha o caractere do topo da pilha
        if(pop1Str(pi) == 0){
            printf("Inválido\n");
            liberaPilhaStr(pi);
            return 0;
        }
        pop1Str(pi); // Desempilha o caractere do topo da pilha
        i++; // Avança para o próximo caractere
    }
    if (tamanhoPilhaStr(pi) == 0) {
        printf("Válido: %s\n", str);
        liberaPilhaStr(pi);
        return 1;
    } else {
        printf("Inválido\n");
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