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

    // verfica se o elemento atual é o que deve ser removido
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
    
    // compara os elementos atuais
    if ((*li1)->dados.matricula == (*li2)->dados.matricula){
        return lista_ingual_rec(&((*li1)->prox), &((*li2)->prox));
    }

    return 0;
}

/* 
Funções para efetuar a remoção de um elemento de acordo com o número de matricula
e para comparar duas listas, verificando a igualdade entre elas, de forma recursiva.
A primeira função, recebe o número de matricula do aluno a ser removido e navega na lista
de forma recursiva até que encontre e o remova. A segunda função, recebe duas listas, navega
por ambas comparando o número de matricula até que o fim delas seja alcançado.
*/

// Exercicio 3
int insere_lista_pos(Lista* li, struct aluno al, int pos){
    if(li == NULL || tamanho_lista(li)+1 < pos) return 0;

    else if(pos == 1 || (*li) == NULL) return insere_lista_inicio(li, al);
    
    Elemento *no;
    no = (Elemento*) malloc(sizeof(Elemento));
    if(no == NULL) return 0;
    
    no->dados = al; // armazena os dados do aluno

    Elemento *aux = *li;

    // percorre a lista até o elemento anterior ao desejado
    for(int i = 1; i<pos-1; i++){
        aux = aux->prox;
    }
    
    // insere o elemento na posição desejada
    no->prox = aux->prox;
    aux->prox = no;

    return 1;   
}

/*
Função para inserir um elemento na lista pela posição dada, de forma que a lista
não perca a estrutura, a partir do tratamento correto dos ponteiros. Isso é feito
com a iteração de um elemento no, que "caminha" até um antes da posição, e é 
utilizado para inserção.
*/

// Exercicio 5
// Remove elementos com certa matricula da lista recursivamente
int remove_toda_lista_rec(Lista* li, int mat){
    if(li == NULL) return 0;

    if(*li == NULL) return 1; // lista vazia

    Elemento *no = *li;
    // verfica se o elemento atual deve ser removido
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

    // remove o primeiro elemento da lista
    while(*li != NULL && (*li)->dados.matricula == mat){
        Elemento *no = *li;
        *li = (*li) -> prox;
        free(no);
    }

    if(*li == NULL) return 1; // lista vazia

    Elemento *ant = *li;
    Elemento *no = ant->prox;

    // percorre a lista removendo os elementos com matricula igual a mat
    while(no != NULL){

        if(no->dados.matricula == mat){
            // remove o elemento atual
            ant->prox = no->prox;
            free(no);
            no = ant->prox;
        }

        else{
            // avança para o próximo elemento
            ant = no;
            no = no->prox;
        }
}
    return 1;
    
}

/*
Funções para remoção de elementos da lista correspondentes ao número de matricula mat. 
A função recursiva percorre a lista a partir da chamada recursiva da função, até encontrar o
elemento com a matricula mat. A função iterativa, percorre a lista com um loop while, onde é
.todos os elementos com matricula igual a mat são removidos até que o fim da lista seja alcançado.
*/

// Exercício 7 

int remove_repetido_lista(Lista* li){
    if(li == NULL) return 0;
    if(*li == NULL) return 0; // lista vazia

    Elemento* atual = *li;

    // percorre a lista verificando se o elemento atual é nulo
    while(atual != NULL){
        Elemento *no, *ant;
        no = (*li) -> prox;
        ant = no;
        while(no!=NULL){
            // verifica se o elemento atual é igual ao no
            if(no->dados.matricula == atual->dados.matricula){
                // remove o elemento atual
                ant->prox = no->prox;
                free(no);
                no = ant->prox;          
            }
            else{
                // avança para o próximo elemento
                ant = no;
                no = no->prox;
            }
        }  
        atual = atual -> prox;
    }

    return 1;    
}

/*
Função para eliminar elementos repetidos na lista. Isso é feito a partir
de um loop while para verificar se o termo atual é nulo, ou seja, se o fim da 
lista foi alcançado, e outro para verificar se os outros no chegaram ao fim da lista
também. O termo atual é comparado com os outros nos da lista, até que ambos sejam nulos.
*/

// Exercício 9

int Troca(Lista* li, Elemento* p ){
    if(li == NULL) return 0;
    if(*li == NULL) return 0; // lista vazia
    
    if(p == NULL) return 0;
    if(p->prox == NULL) return 0;

    // verifica se o elemento é o primeiro da lista
    if (p == *li) {
        
        // troca o primeiro elemento com o segundo
        Elemento* y = p->prox;

        p->prox = y->prox;
        y->prox = p;
        *li = y;

    } else {
        Elemento* ant = *li;

        Elemento* x = p;
        Elemento* y = p->prox;
        // percorre a lista até o elemento anterior ao p
        while(ant->prox!=p){
            ant = ant->prox;
        }
        // troca o elemento p com o próximo
        ant->prox = y;
        x->prox = y->prox;
        y->prox =x;

        }
    return 1;
}

/*
Função para efetuar a troca entre dois elementos da lista. Isso é 
feito a partir de uma lista e um elemento p passado na função, onde
será trocado pelo seu proximo elemento. É armazenado o elemento anterior e o
proximo do elemento p, para que os ponteiros sejam todos tratados da maneira correta. 
A troca é feita substituindo o o atual pelo proximo, com auxilio do anterior do atual.
*/