/*

* 4- Lista - Algoritmos e Estruturas de Dados III 
* Autores: | > Caio Macedo Lima da Cruz.....RA: 2651378
*          | > José Carlos Seben............RA: 2651130

*/

#include "Fila.h"

struct elemento{
    struct aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elem;

struct elementoInt{
    int dados;
    struct elementoInt *prox;
};
typedef struct elementoInt ElemInt;

// Exercício  2

// Elemento fila de pilha
struct elementoFiPi{
    Pilha* pi;
    struct elementoFiPi *prox;
};typedef struct elementoFiPi ElemFiPi;

// Elemento fila de filas
struct elementoFiFi {
    Fila* fi;
    struct elementoFiFi *prox;
};typedef struct elementoFiFi ElemFiFi;

// Elemento pilha de fila
struct elementoPi
{
    Fila* fi;
    struct elementoPi *prox;

};typedef struct elementoPi ElemPi;


//Defini��o do N� Descritor da Fila
struct fila{
    Elem*inicio;
    Elem*final;
    int qtd;
};typedef struct fila Fila;

struct filaint{
    ElemInt* inicio;
    ElemInt* final;
    int qtd;
};typedef struct filaint FilaInt;
struct filaFiPi{
    ElemFiPi*inicio;
    ElemFiPi*final;
    int qtd;
};typedef struct filaFiPi FilaFiPi;
struct filaFiFi{
    ElemFiFi*inicio;
    ElemFiFi*final;
    int qtd;
};typedef struct filaFiFi FilaFiFi;


Fila* cria_Fila(){
    Fila* fi = (Fila*) malloc(sizeof(Fila));
    if(fi != NULL){
        fi->final = NULL;
        fi->inicio = NULL;
        fi->qtd = 0;
    }
    return fi;
}
FilaInt* cria_Fila_int(){
    FilaInt* fi = (FilaInt*) malloc(sizeof(FilaInt));
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

void libera_Fila_int(FilaInt* fi){
    if(fi != NULL){
        ElemInt* no;
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

int consulta_Fila_int(FilaInt* fi, int *al){
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

int insere_Fila_int(FilaInt* fi, int al){
    if(fi == NULL)
        return 0;
    ElemInt *no = (ElemInt*) malloc(sizeof(ElemInt));
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

int remove_Fila_int(FilaInt* fi){
    if(fi == NULL)
        return 0;
    if(fi->inicio == NULL)//fila vazia
        return 0;
    ElemInt *no = fi->inicio;
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

int tamanho_Fila_int(FilaInt* fi){
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

void imprime_Fila_int(FilaInt* fi){
    if(fi == NULL)
        return;
    ElemInt* no = fi->inicio;
    while(no != NULL){
        int i = 1;
        printf(" [%d] %d\n",i,no->dados);
        no = no->prox;
        i++;
    }
}

// exercicio 1 - separar fila
int separa_fila(Fila* f1, Fila* f2, int n){
    if(f1 == NULL || f2 == NULL){
        return 0;
    }
    Elem* no = f1->inicio; // nó auxiliar para percorrer a fila

    // verifica se a fila f1 está vazia
    if(no == NULL){
        printf("Fila vazia\n");
        return 0;
    }
    // procura o nó com a matrícula igual a n
    while(no != NULL && no->dados.matricula != n){
        no = no->prox;
    }
    // se não encontrou o nó com a matrícula igual a n
    if(no == NULL){
        printf("Esse numero de matricula nao existe");
        return 0;
    }

    // f2 começa no próximo nó depois de no
    f2->inicio = no->prox;
    
    
    no->prox = NULL; // desconecta o nó no da fila f1

    f1->final = no; // atualiza o final da fila f1 para o nó no

    // verifica se a fila f2 está vazia
    if (f2->inicio == NULL) {
        f2->final = NULL;
    }
    // se a fila f2 não estiver vazia, percorre até o final
    // e atualiza o ponteiro final
    else {
    
        // Atualiza o fim de f2
        Elem* aux = f2->inicio;
        while (aux->prox != NULL) {
            aux = aux->prox;
            f2->qtd++;
        }
        f2->final = aux;
        f1->qtd = f1->qtd - f2->qtd; // atualiza a quantidade de elementos na fila f1
    }
 
    return 1;
}

/*
Separa a fila em duas filas, a primeira fila (f1) contém os elementos até o nó no (inclusive),
e a segunda fila (f2) contém os elementos a partir do nó no (exclusivo).
Percorre a fila f1 até encontrar o nó com a matrícula igual a n.
Se o nó não for encontrado, imprime uma mensagem de erro e retorna 0.
Se o nó for encontrado, atualiza o ponteiro de início da fila f2 para o próximo nó de no. 
Atualiza o ponteiro de próximo do nó no para NULL, para que a fila f1 termine nesse nó.
Atualiza o ponteiro de final da fila f1 para o nó no.
Se a fila f2 estiver vazia, atualiza o ponteiro de final da fila f2 para NULL.
Caso contrário, percorre a fila f2 até o final e atualiza o ponteiro de final da fila f2.
*/   

// exercicio 3 - inverter fila
/*Oque a atividade pedia é que atravez de operações com funções ja existentes 
invertessemos os elementos de uma fila utilizando uma pilha como auxiliar, graças a divergencia no funionamento de filas e pilhas apenas enviando os
dados da fila para a pilha e depois enviando novamente os dados da pilha para a fila eles ja ficariam invertidos, e foi oque foi feito na função abaixo*/

//funçoes de pilha utilizadas para inverter os elementos da fila
PilhaAux* cria_Pilha(){
    PilhaAux* pi = (PilhaAux*) malloc(sizeof(PilhaAux));
    if(pi != NULL){
        pi->topo = NULL;
        pi->qtd = 0;
    }
    return pi;
}

void libera_Pilha(PilhaAux* pi){
    if(pi != NULL){
        ElemPilha* no;
        while(pi->topo != NULL){
            no = pi->topo;
            pi->topo = pi->topo->prox;
            free(no);
        }
        free(pi);
    }
}

int empilha(PilhaAux* pi, int dados){
    if(pi == NULL)
        return 0;
    ElemPilha* no = (ElemPilha*) malloc(sizeof(ElemPilha));
    if(no == NULL)
        return 0;
    no->dados = dados;
    no->prox = pi->topo;
    pi->topo = no;
    pi->qtd++;
    return 1;
}

int desempilha(PilhaAux* pi, int *dados){
    if(pi == NULL)
        return 0;
    if(pi->topo == NULL)//pilha vazia
        return 0;
    ElemPilha* no = pi->topo;
    *dados = no->dados;
    pi->topo = pi->topo->prox;
    free(no);
    pi->qtd--;
    return 1;
}

int Pilha_vazia(PilhaAux* pi){
    if(pi == NULL)
        return 1;
    if(pi->topo == NULL)
        return 1;
    return 0;
}

int FilaInt_vazia(FilaInt* fi) {
    if (fi == NULL) return 1;
    return (fi->inicio == NULL);
}

void inverte_FilaInt(FilaInt* fi) {
    if (fi == NULL || FilaInt_vazia(fi)) return;

    PilhaAux* pilhaAux = cria_Pilha();
    int elemento;

    // Remove elementos da fila e empilha
    while (!FilaInt_vazia(fi)) {
        remove_Fila_int2(fi, &elemento);
        empilha(pilhaAux, elemento);
    }

    // Desempilha e reinsere na fila (invertendo a ordem)
    while (!Pilha_vazia(pilhaAux)) {
        desempilha(pilhaAux, &elemento);
        insere_Fila_int(fi, elemento);
    }

    libera_Pilha(pilhaAux);
}

int remove_Fila_int2(FilaInt* fi, int* elemento) {
    if (fi == NULL || fi->inicio == NULL) // Fila vazia
        return 0;

    ElemInt* no = fi->inicio;
    *elemento = no->dados; // Armazena o valor removido
    fi->inicio = fi->inicio->prox;

    if (fi->inicio == NULL) // Fila ficou vazia
        fi->final = NULL;

    free(no);
    fi->qtd--;
    return 1;
}

// exercicio 4 - furar fila
void FuraFila(Fila* fi, struct aluno al) {
    if (fi == NULL) return;
     
    Elem* novo = (Elem*) malloc(sizeof(Elem));
    if (novo == NULL) return;
     
    novo->dados = al;
    if (Fila_vazia(fi)) {
        novo->prox = novo; 
        fi->final = novo;
    } else {
        novo->prox = fi->inicio;
        fi->final->prox = novo;
        fi->inicio = novo;
     }
     
    fi->qtd++;
 }

int FuraFilaInt(FilaInt* fi, int al) {
    if (fi == NULL) return 0;
     
    ElemInt* novo = (ElemInt*) malloc(sizeof(ElemInt));
    if (novo == NULL) return 0;
     
    novo->dados = al;
    if (Fila_vazia(fi)) {
        novo->prox = novo; 
        fi->final = novo;
    } else {
        novo->prox = fi->inicio;
        fi->final->prox = novo;
        fi->inicio = novo;
     }
     
    fi->qtd++;
    return 1;
 }
 
 /*
Função para se aproveitar da estrutura de fila circular onde o inicio e o final se encontram 
possibilitando inserir valores na primeria posição sem alterar os outros
*/

FilaInt* ordem_crescente(FilaInt* fi){
    if(fi == NULL)
        return NULL;
    if(fi->inicio == NULL)//fila vazia
        return NULL;
    ElemInt* no = fi->inicio; // nó auxiliar para percorrer a fila
    int j = 1;
    while (j != 0)
    {
        if(no != NULL){
            if(no->dados > no->prox->dados){
                // troca os dados dos nós
                int temp = no->dados;
                no->dados = no->prox->dados;
                no->prox->dados = temp;
            }
            no = no->prox;
            j = 1; // reinicia o loop

        }
        else{
            break; // fim da fila
        }
    }
    

    return fi;
}

// exercicio 6 - ordem crescente
int nova_fila_ordem_crescente(FilaInt* f1, FilaInt* f2, FilaInt* f3){
    if(f1 == NULL || f2 == NULL || f3 == NULL){
        return 0;
    }
    // Verifica se as filas f1 e f2 não estão vazias
    if(f1->inicio == NULL || f2->inicio == NULL){
        return 0;
    }
    
    ordem_crescente(f1); // ordena a fila f1
    ordem_crescente(f2); // ordena a fila f2

    ElemInt* no = f1->inicio; // nó auxiliar para percorrer a fila
    ElemInt* no2 = f2->inicio; // nó auxiliar para percorrer a fila

    while(no != NULL && no2 != NULL){

        if(no->dados > no2->dados){
            // troca os dados dos nós
            insere_Fila_int(f3, no2->dados);
            no2 = no2->prox;
            f3->qtd++;
        }
        
        else if(no->dados < no2->dados){
            // troca os dados dos nós
            insere_Fila_int(f3, no->dados);
            no = no->prox;
            f3->qtd++;
        }
        
        else{
            // Quando os dados são iguais, insere ambos em f3
            insere_Fila_int(f3, no->dados);
            no = no->prox;
            f3->qtd++;
            insere_Fila_int(f3, no2->dados);
            no2 = no2->prox;
            f3->qtd++;
        }

        
    }

    while(no2 != NULL){
        insere_Fila_int(f3, no2->dados);
        no2 = no2->prox;
    }
    
    while(no != NULL){
        insere_Fila_int(f3, no->dados);
        no = no->prox;
    }
    
    return 1;
}

/*
Função nova_fila_ordem_crescente recebe três filas (f1, f2 e f3) como parâmetros,
e ordena as filas f1 e f2 em ordem crescente, na fila f3.
A função percorre as filas f1 e f2, comparando os elementos e inserindo-os na fila f3 em ordem crescente.
Se os elementos forem iguais, ambos são inseridos na fila f3.
A função retorna 1 se a operação for bem-sucedida, ou 0 se alguma das filas estiver vazia ou nula.
A função ordem_crescente é chamada para ordenar as filas f1 e f2, caso ainda não estejam, antes de mesclá-las na fila f3.
*/

// exercicio 7 - reverso
int reverso(Fila* f1){
    if(f1 == NULL)
        return 0;
    if(f1->inicio == NULL)//fila vazia
        return 0;
    
    ElemInt* ant = NULL; // nó anterior
    ElemInt* atual = f1->inicio; // nó atual
    ElemInt* prox = NULL; // nó próximo

    f1->final = atual; // atualiza o final da fila para o nó atual
    while(atual != NULL){

        prox = atual->prox;
        atual->prox = ant;
        ant = atual;
        atual = prox;

    }

    f1->inicio = ant;

    return 1;
}

/*
Função reverso inverte a ordem dos elementos da fila f1.
A função percorre a fila f1, atualizando os ponteiros de cada nó para apontar para o nó anterior.
Dessa forma, o primeiro nó da fila se torna o último e o último nó se torna o primeiro.
A função atualiza o ponteiro de início da fila para o último nó visitado e o ponteiro de final da fila para o primeiro nó visitado.
A função retorna 1 se a operação for bem-sucedida, ou 0 se a fila estiver vazia ou nula.
*/

// Menu do exercício 9 
void menu(){

    FilaInt* fi = NULL;
    int op = 0;

    while(op != 9){

    printf("--------------------------------------------------\n");
    printf("Escolha uma opcao:\n");
    printf("1-Inicializa fila.\n");
    printf("2-Verifica se a fila e vazia.\n");
    printf("3-Verifica se a fila e cheia.\n");
    printf("4-Emfileira o elemento na fila.\n");
    printf("5-Desenfileira elemento da fila.\n");
    printf("6-Le o número no inicio da fila.\n");
    printf("7-Testar qual fila possui mais elementos.\n");
    printf("8-Furar a Fila");
    printf("9-Sair.\n");
    printf("--------------------------------------------------\n");

    printf("Digite a opcao desejada: ");
    scanf("%d", &op);

    switch(op){
        case 1: // cria fila
            fi = cria_FilaInt();
            printf("Fila criada com sucesso.\n");
            break;
        case 2: // verifica se a fila está vazia 
            if (fi == NULL || fi->inicio == NULL)
                printf("fila vazia.\n");
            break;
        case 3: // verifica se a fila está cheia
            if (fi->inicio != NULL)
                printf("Fila cheia.\n");
            break;
        case 4: // emfileira elemento na fila
        {
            int x;
            // recebe o elemento a ser enfileirado
            printf("Digite um numero inteiro: ");
            scanf("%d", &x);
            // verifica se o elemento foi inserido com sucesso
            if(insere_Fila_int(fi, x) == 1)
                printf("Elemento enfileirado com sucesso.\n");
            
            break;
        }
        case 5: // desenfileira elemento da fila
            // verifica se o elemento foi desenfileirado com sucesso
            if(remove_Fila_int(fi) == 1)
                printf("Elemento desenfileirado com sucesso.\n");
            break;
        case 6: // lê o número no início da fila
        {
            int xInicio;
            // verifica se o elemento foi lido com sucesso
            if(consulta_Fila_int(fi, &xInicio) == 1)
                printf("Elemento no inicio da fila: %d\n", xInicio); // imprime o elemento no início da fila
            break;
        }
        case 7: // testar qual fila possui mais elementos
        {
            FilaInt* fi2 = cria_Fila_int(); // cria a fila 1
            FilaInt* fi3 = cria_Fila_int(); // cria a fila 2
            int n;
            // recebe o tamanho da fila 1 e os elementos
            printf("Digite um numero inteiro para tamanho da fila 1: ");
            scanf("%d", &n);
            for(int i = 0; i < n; i++){
                int x;
                // recebe o elemento a ser enfileirado
                printf("Digite um numero inteiro para fila 1: ");
                scanf("%d", &x);
                insere_Fila_int(fi2, x); // insere o elemento na fila 1
            }
            // recebe o tamanho da fila 2 e os elementos
            printf("Digite um numero inteiro para tamanho da fila 2: ");
            scanf("%d", &n);
            for(int i = 0; i < n; i++){
                int x;
                // recebe o elemento a ser enfileirado
                printf("Digite um numero inteiro para fila 2: ");
                scanf("%d", &x);
                insere_Fila_int(fi3, x); // insere o elemento na fila 2
            }
            // imprime as filas
            printf("Fila 1:\n");
            imprime_Fila_int(fi2);
            printf("Fila 2:\n");
            imprime_Fila_int(fi3);

            // verifica se alguma das filas está vazia
            if(tamanho_Fila_int(fi2) == 0 && tamanho_Fila_int(fi3) == 0){
                printf("As filas estao vazias.\n");
            }else if(tamanho_Fila_int(fi2) == 0){
                printf("Fila 1 esta vazia.\n");
            }else if(tamanho_Fila_int(fi3) == 0){
                printf("Fila 2 esta vazia.\n");
            }

            // verifica qual fila possui mais elementos
            if(tamanho_Fila_int(fi2) > tamanho_Fila_int(fi3)){
                printf("Fila 1 possui mais elementos.\n");
            }else if(tamanho_Fila_int(fi2) < tamanho_Fila_int(fi3)){
                printf("Fila 2 possui mais elementos.\n");
            }else
                printf("As filas possuem o mesmo numero de elementos.\n");
            
            libera_Fila_int(fi2); // libera a memória alocada para a fila 1
            libera_Fila_int(fi3); // libera a memória alocada para a fila 2
            break;
        }
        case 8: // fura fila
        int x;
        // recebe o elemento a ser enfileirado
        printf("Digite um numero inteiro: ");
        scanf("%d", &x);
        // verifica se o elemento foi inserido com sucesso
        if(FuraFilaInt(fi, x) == 1)
            printf("Elemento enfileirado com sucesso, na primeira posiao.\n");

        break;
        case 9: // sair
            libera_Fila_int(fi);
            printf("Saindo...\n");
            break;
        default: // opção inválida
            printf("Opcao invalida. Tente novamente.\n");
            break;
    }
}
}

/*
Função menu exibe um menu de opções para o usuário interagir com a fila.
O usuário pode criar uma fila, verificar se ela está vazia ou cheia, enfileirar e desenfileirar elementos,
ler o elemento no início da fila, testar qual fila possui mais elementos e sair do programa.
A função utiliza um loop while para continuar exevcuutando até que o usuário escolha a opção de sair (opção 9).
e utiliza um switch para executar a opção escolhida pelo usuário.
A função libera a memória alocada para a fila antes de sair do programa.
*/
