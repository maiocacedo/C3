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

*/

// Menu do exercício 9 
void menu(){
    FilaInt* fi = NULL;
    int op = 0;
    while(op != 9){
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
    scanf("%d", &op);
    switch(op){
        case 1:
            fi = cria_FilaInt();
            printf("Fila criada com sucesso.\n");
            break;
        case 2:
            if (fi == NULL || fi->inicio == NULL)
                printf("fila vazia.\n");
            break;
        case 3:
            if (fi->inicio != NULL)
                printf("Fila cheia.\n");
            break;
        case 4:{
            int x;
            printf("Digite um numero inteiro: ");
            scanf("%d", &x);
            if(insere_Fila_int(fi, x) == 1)
                printf("Elemento enfileirado com sucesso.\n");
            
            break;
        }
        case 5:
            if(remove_Fila_int(fi) == 1)
                printf("Elemento desenfileirado com sucesso.\n");
            break;
        case 6:{
            int xInicio;
            if(consulta_Fila_int(fi, &xInicio) == 1)
                printf("Elemento no inicio da fila: %d\n", xInicio);
            break;
        }
        case 7:{
            FilaInt* fi2 = cria_Fila_int();
            FilaInt* fi3 = cria_Fila_int();
            int n;
            printf("Digite um numero inteiro para tamanho da fila 1: ");
            scanf("%d", &n);
            for(int i = 0; i < n; i++){
                int x;
                printf("Digite um numero inteiro para fila 1: ");
                scanf("%d", &x);
                insere_Fila_int(fi2, x);
            }
            printf("Digite um numero inteiro para tamanho da fila 2: ");
            scanf("%d", &n);
            for(int i = 0; i < n; i++){
                int x;
                printf("Digite um numero inteiro para fila 2: ");
                scanf("%d", &x);
                insere_Fila_int(fi3, x);
            }
            printf("Fila 1:\n");
            imprime_Fila_int(fi2);
            printf("Fila 2:\n");
            imprime_Fila_int(fi3);

            if(tamanho_Fila_int(fi2) > tamanho_Fila_int(fi3)){
                printf("Fila 1 possui mais elementos.\n");
            }else if(tamanho_Fila_int(fi2) < tamanho_Fila_int(fi3)){
                printf("Fila 2 possui mais elementos.\n");
            }else
                printf("As filas possuem o mesmo numero de elementos.\n");
            
            libera_Fila_int(fi2);
            libera_Fila_int(fi3);
            break;
        }
        case 8:
            // Fura fila aqui ó poggers
            break;
        case 9:
            libera_Fila_int(fi);
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida. Tente novamente.\n");
            break;
    }
}
}
