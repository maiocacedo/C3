#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h" //inclui os Prot�tipos

// Defini��o do tipo lista
struct elemento
{
    struct aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elemento;

Lista *cria_lista()
{
    Lista *li = (Lista *)malloc(sizeof(Lista));
    if (li != NULL)
        *li = NULL;
    return li;
}

void libera_lista(Lista *li)
{
    if (li != NULL)
    {
        Elemento *no;
        while ((*li) != NULL)
        {
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

int insere_lista_final(Lista *li, struct aluno al)
{
    if (li == NULL)
        return 0;
    Elemento *no;
    no = (Elemento *)malloc(sizeof(Elemento));
    if (no == NULL)
        return 0;
    no->dados = al;
    no->prox = NULL;
    if ((*li) == NULL)
    { // lista vazia: insere in�cio
        *li = no;
    }
    else
    {
        Elemento *aux;
        aux = *li;
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = no;
    }
    return 1;
}

int insere_lista_inicio(Lista *li, struct aluno al)
{
    if (li == NULL)
        return 0;
    Elemento *no;
    no = (Elemento *)malloc(sizeof(Elemento));
    if (no == NULL)
        return 0;
    no->dados = al;
    no->prox = (*li);
    *li = no;
    return 1;
}

int insere_lista_ordenada(Lista *li, struct aluno al)
{
    if (li == NULL)
        return 0;
    Elemento *no = (Elemento *)malloc(sizeof(Elemento));
    if (no == NULL)
        return 0;
    no->dados = al;
    if ((*li) == NULL)
    { // lista vazia: insere in�cio
        no->prox = NULL;
        *li = no;
        return 1;
    }
    else
    {
        Elemento *ant, *atual = *li;
        while (atual != NULL && atual->dados.matricula < al.matricula)
        {
            ant = atual;
            atual = atual->prox;
        }
        if (atual == *li)
        { // insere in�cio
            no->prox = (*li);
            *li = no;
        }
        else
        {
            no->prox = atual;
            ant->prox = no;
        }
        return 1;
    }
}

int remove_lista(Lista *li, int mat)
{
    if (li == NULL)
        return 0;
    if ((*li) == NULL) // lista vazia
        return 0;
    Elemento *ant, *no = *li;
    while (no != NULL && no->dados.matricula != mat)
    {
        ant = no;
        no = no->prox;
    }
    if (no == NULL) // n�o encontrado
        return 0;

    if (no == *li) // remover o primeiro?
        *li = no->prox;
    else
        ant->prox = no->prox;
    free(no);
    return 1;
}

int remove_lista_inicio(Lista *li)
{
    if (li == NULL)
        return 0;
    if ((*li) == NULL) // lista vazia
        return 0;

    Elemento *no = *li;
    *li = no->prox;
    free(no);
    return 1;
}

int remove_lista_final(Lista *li)
{
    if (li == NULL)
        return 0;
    if ((*li) == NULL) // lista vazia
        return 0;

    Elemento *ant, *no = *li;
    while (no->prox != NULL)
    {
        ant = no;
        no = no->prox;
    }

    if (no == (*li)) // remover o primeiro?
        *li = no->prox;
    else
        ant->prox = no->prox;
    free(no);
    return 1;
}

int tamanho_lista(Lista *li)
{
    if (li == NULL)
        return 0;
    int cont = 0;
    Elemento *no = *li;
    while (no != NULL)
    {
        cont++;
        no = no->prox;
    }
    return cont;
}

int lista_cheia(Lista *li)
{
    return 0;
}

int lista_vazia(Lista *li)
{
    if (li == NULL)
        return 1;
    if (*li == NULL)
        return 1;
    return 0;
}

void imprime_lista(Lista *li)
{
    if (li == NULL)
        return;
    Elemento *no = *li;
    while (no != NULL)
    {
        printf("Matricula: %d\n", no->dados.matricula);
        printf("Nome: %s\n", no->dados.nome);
        printf("Notas: %f %f %f\n", no->dados.n1,
               no->dados.n2,
               no->dados.n3);
        printf("-------------------------------\n");

        no = no->prox;
    }
}

// exercicio 1) A.:
/*Resolução: É uma função bem simples que foi elaborada apenas
reaproveitando as funções ja existentes, onde o funcionamento dele vai
ser em base de o usuario informar um valor de matricula o codigo vai percorrer
a lista e ao encontrar a struct com que o numero da matrico bate como informado
pelo usuario vai printar os dados.*/
void consulta_lista_Pmatricula(Lista *li, int matricula)
{
    if (li == NULL || *li == NULL)
        return;
    Elemento *no = *li;
    while (no != NULL)
    {
        if (no->dados.matricula == matricula)
        {
            printf("Matricula: %d\n", no->dados.matricula);
            printf("Nome: %s\n", no->dados.nome);
            printf("Notas: %f %f %f\n", no->dados.n1,
                   no->dados.n2,
                   no->dados.n3);
            printf("-------------------------------\n");
            return;
        }
        no = no->prox;
    }
    printf("\nMatricula nao encontrada\n");
}

// exercicio 1) B.:
/*Resolução: Reutilizando a logica da função de tamanho_lista e pegando algumas
coisa da função de printar so para printar os dados do aluno encontrado, a função vai
percorrer quando a posição da lista for igual a posição informada pelo usuario, vai printar os dados*/
void consulta_lista_Pposicao(Lista *li, int posicao)
{
    if (li == NULL || *li == NULL)
        return;

    int cont = 1;
    Elemento *no = *li;

    while (no != NULL && cont < posicao)
    {
        no = no->prox;
        cont++;
    }
    if (no == NULL)
    {
        printf("\nPosicao nao encontrada\n");
    }
    else
    {
        printf("Matricula: %d\n", no->dados.matricula);
        printf("Nome: %s\n", no->dados.nome);
        printf("Notas: %f %f %f\n", no->dados.n1,
               no->dados.n2,
               no->dados.n3);
        printf("-------------------------------\n");
        return;
    }
}

// Exercicio 4:
/*Resolução: Os valores do vetor serão pegados e armazenados nas structs no lugar de n1
e usando a logica de pegar o valor e avançar para o proximo do vetor garantindo que cada um
seja anexado a uma struct, utilizando a temp.matricula como um controle de posições da lista para facilitar
a manipulação e a implementação de funções ja existentes como insere_lista_final*/
void lista_Vetor(Lista *li, float v[], int n)
{
    if (li == NULL || v == NULL)
        return;

    int i = 0;

    while (i < n)
    {
        struct aluno temp;
        temp.n1 = v[i]; // armazena o valor do vetor em n1
        temp.matricula = i + 1;
        strcpy(temp.nome, "Float"); // adiociona um nome generico ao nome
        temp.n2 = 0.0;
        temp.n3 = 0.0;

        insere_lista_final(li, temp);
        i++;
    }
}

// Exercicio 6:
/*Resolução: Uma logica bem simples como concatenar é apenas juntar duas listas onde uma termina a outra começa
para resolver primeiro faz a verificação das listas, depois verifica de *li não é vazia se for vai ser atribuida 
lista_floats como *li, se *li não for vazia apenas percore *li até o utimo elemento e começa apontat para o começo de 
lista_floats, deixando uma seguida da outra no caso *li ficara com os elementos dela mesmo e os de lista_floats isso sem
esvazias a lista_floats*/
void concatena_listas(Lista *li, Lista *lista_floats)
{
    if (li == NULL || lista_floats == NULL)
        return;
    if (*li == NULL)
    {
        *li = *lista_floats;
    }
    else
    {
        Elemento *ultimo_li = *li;
        while (ultimo_li->prox != NULL)
        {
            ultimo_li = ultimo_li->prox;
        }
        ultimo_li->prox = *lista_floats;
    }
}

//exercicio 8:
/*Resolução: Utiliza uma logica parecida de quando queremos percorrer um vetor e utilizamos uma variavel auxiliar
neste caso são dois ponteiros que estão percorrendo as listas e analisando pela matricola pegando os valores menores'
e movendo os nos menores para a menor lista, no final faz uma verificação e manda se ha algum no restante*/
void funde_listas_ord(Lista *li1, Lista *li2, Lista *lista_resultado) {
    if (li1 == NULL || li2 == NULL || lista_resultado == NULL) return;

    *lista_resultado = NULL; // Inicializa a lista resultado como vazia

    struct elemento *p1 = *li1;
    struct elemento *p2 = *li2;
    struct elemento *ultimo = NULL;

    while (p1 != NULL && p2 != NULL) {
        struct elemento **menor;
        if (p1->dados.matricula <= p2->dados.matricula) {
            menor = &p1;
        } else {
            menor = &p2;
        }

        struct elemento *no = *menor;
        *menor = (*menor)->prox;

        no->prox = NULL;

        if (*lista_resultado == NULL) {
            *lista_resultado = no;
        } else {
            ultimo->prox = no;
        }
        ultimo = no;
    }

    struct elemento *resto = (p1 != NULL) ? p1 : p2;
    while (resto != NULL) {
        struct elemento *no = resto;
        resto = resto->prox;
        no->prox = NULL;

        if (*lista_resultado == NULL) {
            *lista_resultado = no;
        } else {
            ultimo->prox = no;
        }
        ultimo = no;
    }

    *li1 = NULL;
    *li2 = NULL;
}

