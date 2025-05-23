// ListaDupla.c
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
        printf("Notas: %.1f %.1f %.1f\n",no->dados.n1,
                                   no->dados.n2,
                                   no->dados.n3);
        printf("-------------------------------\n");

        no = no->prox;
    }
}

//Exercicio 1.:
/*Resolução: Utilizando a logica de localizar os dados atravez da matricula da função consulta_lista_mat 
apenas implementei para reorganizar os nos com a identificação e organização para que se for removido do inicio reorganizar
os nos da maneira que li apontara para o proximo, se for tirado do meio o anterior apontara para o proximo apoz o que foi 
removido e o se tirar o ultimo o anterior apontara para null*/
int remove_lista_Pmat(Lista* li, int mat){
    if(li == NULL || *li == NULL) return 0;

    Elem *no = *li;
    while(no != NULL && no->dados.matricula != mat){
        no = no->prox;
    }

    if(no == NULL) return 0;

    if (no->ant == NULL){
        *li = no ->prox;
        if(no->prox != NULL)
            no->prox->ant = NULL;
    }

    else if(no->prox == NULL){
        no->ant->prox = NULL;
    }

    else{
        no->ant->prox = no->prox;
        no->prox->ant = no->ant;
    }

    free(no);
    return 1;
}

//Exercicio 2.:
/*Resolução: Utilizando a função insere_lista_ordenada que estava na lita 5 de listas que fazia quase a mesma coisa
mas em um sentido de listas simples, agora modificada com os nos apontando para as duas direções onde o inicio aponta
para o novo inicio que é o novo no e o fim faz a mesma coisa onde os nos sempre vão estar apontando para o proximo e o
anterior ao mesmo tempo*/
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
            atual = atual->prox;
        
        if (atual == *li)
        { // insere in�cio
            no->prox = *li;
            no->ant = NULL;
            (*li)->ant = no;
            *li = no;
        }
        else if (atual == NULL)
        { 
            Elem *ultimo = *li;

            while (ultimo->prox != NULL)
                ultimo = ultimo->prox;

            ultimo->prox = no;
            no->ant = ultimo;
            no->prox = NULL;
        }
        else
        {
            Elem *anterior = atual->ant;
            no->prox = atual;
            no->ant = anterior;
            anterior->prox = no;
            atual->ant = no;

        }
        return 1;
}


//Exercicio 3.:
/*Resolução: Usando como base a função tamanho_lista e aplicando as restrições impostar por a questão 3 da lista
precisei modificar um pouco a logica por tras da funcionalidade da função para percorrer a lista utilizando o 
proprio *li e não o ponteiro auxiliar, comparando o int em n1 analisando quais notas são iguais mas como 
estamos trabalhando com int casos como notas quebradas como float serão comparada so o primeiro numero
como no caso de 7.8, 7.9 etc... serão considerados apenas 7 para analisar quantos alunos possuem a nota 7
atribuindo a quantidade de vezes que a nota em expecifica foi encontrada na lista e atribuindo a quantidade em count
assim cada vez que encrontar count sera adicionado 1 a count, e no final apenas foi adicionado um while para levar *li 
de volta ao começo*/
int conta_lista_nota(Lista* li, int n1){
    if(li == NULL)
        return 0;
    int cont = 0;
    while(*li != NULL){
        if((int)(*li)->dados.n1 == n1) cont++;

        *li = (*li)->prox;
    }

    while(*li != NULL && (*li)->ant != NULL){
        *li = (*li)->ant;
    }
    return cont;
}


// EXERCICIO 4:

// Função para inserção de elemento no inicio da lista circular
int insere_lista_circular_inicio(Lista* li, struct aluno al){
    if(li == NULL) return ERR;

    Elem *no = malloc(sizeof *no);
    if (no == NULL) return ERR;

    no->dados = al; // atribui os dados ao novo nó
    
    if(*li == NULL){
        // para lista vazia
        no->prox = no;
        no->ant = no;
        *li = no;
        
        return OK;
    } else{
        
        no->prox = *li; // novo nó aponta para o primeiro
        no->ant = (*li)->ant; // novo nó aponta para o último
        (*li)->ant->prox = no; // último aponta para o novo nó
        (*li)->ant = no; // primeiro aponta para o novo nó
        *li = no; // atualiza o primeiro nó para o novo nó
        
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
        // para lista vazia
        no->prox = no;
        no->ant = no;
        *li = no;
        return OK;
    } else{

        no->prox = *li; // novo nó aponta para o primeiro
        no->ant = (*li)->ant; // novo nó aponta para o último, pelo ant
        (*li)->ant->prox = no; // último aponta para o novo nó, pelo prox
        (*li)->ant = no; // atualiza o último nó para o novo nó
        return OK;
    }
}

// Função para remvoer primeiro elemento de lista circular
int remove_lista_circular_inicio(Lista* li){
    if(li == NULL) return ERR;
    if(*li == NULL) return ERR;

    Elem *no = *li;

    if(no->prox == no){
        // se for o único elemento
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
        // se for o único elemento
        free(no);
        *li = NULL;
        return OK;
    } else{
        no->prox->ant = no->ant; // prox do ant do ultima aponta para o novo ultimo
        no->ant->prox = no->prox; // ant do prox do ultimo aponta para novo ultimo
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

        no = no->prox; // avança para o próximo nó
    }while(no != *li);
    
    return OK;
}
void libera_lista_circular(Lista* li) {
    if (li == NULL || *li == NULL)
        return;

    Elem *atual = (*li)->prox;
    while (atual != *li) {
        Elem *prox = atual->prox;
        free(atual);
        atual = prox;
    }
    free(*li); // libera o nó que era o primeiro (ou o único)
    *li = NULL;
}

/*
Funções para manipulação de listas duplamente encadeadas circular.
Lista circular é uma lista onde o último elemento aponta para o primeiro e vice-versa,
formando um ciclo. Dessa forma, ao manipular a lista, é possível percorrê-la em ambas as direções
sem encontrar um final. As funções de inserção e remoção foram adaptadas para lidar com essa estrutura circular.
A função insere_lista_circular_inicio insere um novo elemento no "início" da lista circular, manipulando
os ponteiros para manter a circularidade. A função insere_lista_circular_final faz o mesmo, mas no "final".
A função remove_lista_circular_inicio remove o primeiro elemento da lista circular, ajustando os ponteiros
para manter a circularidade. A função remove_lista_circular_final faz o mesmo, mas para o último elemento.
A função percorre_lista_circular percorre a lista circular, imprimindo os dados de cada elemento.
*/


// EXERCICIO 5:

// Função para inicializar no decritor.
int inicializa_noDesc(noDesc *no){
    if(no == NULL) return ERR; 

    *no = (noDesc)malloc(sizeof(struct nodesc));

    if(*no == NULL) return ERR; 
    
    (*no)->ini = NULL;
    (*no)->fim = NULL;

    return OK;
}

// Função para enfileiramento em filas, utilizando no descritor
int enfileirar(noDesc *desc, int elem){
    if(desc == NULL) return ERR;

    Fila *no = malloc(sizeof *no);
    if(no == NULL) return ERR;

    no->info = elem; // elemento a ser inserido
    no->prox = NULL; // proximo elemento
    no->ant = NULL; // elemento anterior

    if((*desc)->ini == NULL){
        // adiciona o primeiro elemento
        (*desc)->ini = no; 
        (*desc)->fim = no; 
        return OK;

    } else{

        (*desc)->fim->prox = no; // proximo do ultimo elemento aponta para o novo
        no->ant = (*desc)->fim; // ant do novo aponta para o ultimo
        (*desc)->fim = no; // novo elemento se torna o ultimo

        return OK;
    }
}

// Função para desenfileiramento em filas, utilizando no descritor
int desenfileirar(noDesc *desc, int *elem){

    if(desc == NULL) return ERR;

    Fila *no = (*desc)->ini;
    if(no == NULL) return ERR;

    *elem = no->info; // elemento que será retirado

    (*desc)->ini = no->prox; // novo primeiro elemento

    if ((*desc)->ini == NULL) (*desc)->fim = NULL;
    else{
        (*desc)->ini->ant = NULL; // removendo o primeiro elemento
    }

    free(no);
    return OK;
}

void imprime_fila(noDesc *desc){
    if(desc == NULL) return ;
    if((*desc)->ini == NULL) return ;

    Fila *no = (*desc)->ini;

    while(no != NULL){
        printf("%d ", no->info);
        no = no->prox;
    }
    printf("\n");
    return;
}


/*
Funções para manipulação de filas utilizando nó descritor.
No descritor é uma estrutura que contém ponteiros para o início e o fim da fila.
As funções de enfileiramento e desenfileiramento foram adaptadas para lidar com essa estrutura.
A função inicializa_noDesc inicializa o nó descritor, alocando memória e definindo os ponteiros de início e fim como nulos.
A função enfileirar adiciona um novo elemento ao final da fila, ajustando os ponteiros de início e fim conforme necessário.
A função desenfileirar remove o primeiro elemento da fila, ajustando os ponteiros de início e fim.
A função desenfileirar retorna o elemento removido através de um ponteiro passado como argumento.
*/

