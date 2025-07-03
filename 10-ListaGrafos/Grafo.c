#include "Grafo.h"

//Defini��o do tipo Grafo
struct grafo{
    int eh_ponderado;
    int nro_vertices;
    int grau_max;
    int** arestas;
    float** pesos;
    int* grau;
};

/*--------- EXERCICIO 4 ---------*/

// Definição do tipo Lista (de adjacência), baseado em listas encadeadas. 
// (verticen | peso) -> prox
typedef struct elemento{
    char *vertice; 
    int peso;
    struct elemento *prox;
} Elemento;

typedef struct elemento Lista;

// Lista de listas
// (Lista* vertice1, Lista* vertice2, Lista* vertice3, ...)
typedef struct grafolista{
    Lista **vet; //vetor de listas 
    int nos; //numero de nos no grafo
}GrafoLista;

/* 
    Função para criar a lista de adjacência do grafo.
*/
GrafoLista* cria_GrafoLista(int n_nos){
    if(n_nos <= 0) return NULL; // Verifica se o número de nós é válido

    GrafoLista* gl;    

    gl = (GrafoLista*) malloc(sizeof(GrafoLista));
    if(gl == NULL) return NULL;

    gl->vet = (Lista**) malloc(n_nos * sizeof(Lista*));
    if (gl->vet == NULL) {
        free(gl);
        return NULL;
    }

    gl->nos = n_nos;

    for(int i  = 0;i < n_nos; i++) gl->vet[i] = NULL;
    
    return gl;
}

/* 
    Função para inserir aresta na lista de adjacência
*/
int insere_aresta_lista(GrafoLista* grafol, char *nome_v, int peso, int no){
    if(grafol == NULL || no < 0 || no >= grafol->nos) return 0; // verifica se os parametros são válidos 

    Elemento* novo = (Elemento*) malloc(sizeof(Elemento)); // Aloca memória para o novo nó
    if(novo == NULL) return 0;
    
    novo->vertice = (char*) malloc(strlen(nome_v) + 1);

    if (novo->vertice == NULL) {
        free(novo);
        return 0;
    }

    strcpy(novo->vertice, nome_v); // copia o conteúdo da string
    novo->peso = peso; // Atribui o peso da aresta
    novo->prox = NULL; // Inicializa o próximo como NULL

    if(grafol->vet[no] == NULL) {
        grafol->vet[no] = novo; // Se a lista estiver vazia, insere o novo nó
    } else {
        Elemento* atual = grafol->vet[no];
        while(atual->prox != NULL) atual = atual->prox;
        atual->prox = novo;
    }

    return 1;
}

/* 
    Função para remover aresta na lista de adjacência
*/
int remove_aresta_lista(GrafoLista* grafol, int no, char *nome_v){
    if(grafol == NULL || no < 0 || no >= grafol->nos) return 0;
    if(grafol->vet[no] == NULL) return 0; // Verifica se a lista está vazia

    Elemento* atual = grafol->vet[no];

    Elemento* anterior = NULL;
    while(atual != NULL && strcmp(atual->vertice, nome_v)){
        anterior = atual;
        atual = atual->prox;
    }
    
    if(atual == NULL) return 0; // Verifica se o nó foi encontrado

    if(anterior == NULL) {
        // Se o nó a ser removido é o primeiro
        grafol->vet[no] = atual->prox;
    } else {
        // Se o nó a ser removido não é o primeiro
        anterior->prox = atual->prox;
    }

    free(atual->vertice); // Libera a memória alocada para o nome do vértice
    free(atual); // Libera a memória alocada para o nó

    return 1; // Retorna 1 se a remoção foi bem-sucedida
}

int libera_GrafoLista(GrafoLista* grafol){
    if(grafol == NULL) return 0;

    for(int i = 0; i < grafol->nos; i++){
        Elemento* atual = grafol->vet[i];
        while(atual != NULL){
            Elemento* temp = atual;
            atual = atual->prox;
            free(temp->vertice); // Libera a memória alocada para o nome do vértice
            free(temp); // Libera a memória alocada para o nó
        }
    }

    free(grafol->vet);
    free(grafol);
    return 1;
}

void imprime_GrafoLista(GrafoLista* grafol){
    if(grafol == NULL) return;

    for(int i = 0; i < grafol->nos; i++){
        printf("No %d: ", i);
        Elemento* atual = grafol->vet[i];
        while(atual != NULL){
            printf("%s(%d) -> ", atual->vertice, atual->peso);
            atual = atual->prox;
        }
        printf("NULL\n");
    }
    return;
}

/*--------- FIM EXERCÍCIO 4 ---------*/

Grafo* cria_Grafo(int nro_vertices, int grau_max, int eh_ponderado){
    Grafo *gr;
    gr = (Grafo*) malloc(sizeof(struct grafo));
    if(gr != NULL){
        int i;
        gr->nro_vertices = nro_vertices;
        gr->grau_max = grau_max;
        gr->eh_ponderado = (eh_ponderado != 0)?1:0;
        gr->grau = (int*) calloc(nro_vertices,sizeof(int));

        gr->arestas = (int**) malloc(nro_vertices * sizeof(int*));
        for(i=0; i<nro_vertices; i++)
            gr->arestas[i] = (int*) malloc(grau_max * sizeof(int));

        if(gr->eh_ponderado){
            gr->pesos = (float**) malloc(nro_vertices * sizeof(float*));
            for(i=0; i<nro_vertices; i++)
                gr->pesos[i] = (float*) malloc(grau_max * sizeof(float));
        }

    }
    return gr;
}

void libera_Grafo(Grafo* gr){
    if(gr != NULL){
        int i;
        for(i=0; i<gr->nro_vertices; i++)
            free(gr->arestas[i]);
        free(gr->arestas);

        if(gr->eh_ponderado){
            for(i=0; i<gr->nro_vertices; i++)
                free(gr->pesos[i]);
            free(gr->pesos);
        }
        free(gr->grau);
        free(gr);
    }
}

int insereAresta(Grafo* gr, int orig, int dest, int eh_digrafo, float peso){
    if(gr == NULL)
        return 0;
    if(orig < 0 || orig >= gr->nro_vertices)
        return 0;
    if(dest < 0 || dest >= gr->nro_vertices)
        return 0;

    gr->arestas[orig][gr->grau[orig]] = dest;
    if(gr->eh_ponderado)
        gr->pesos[orig][gr->grau[orig]] = peso;
    gr->grau[orig]++;

    if(eh_digrafo == 0)
        insereAresta(gr,dest,orig,1,peso);
    return 1;
}

int removeAresta(Grafo* gr, int orig, int dest, int eh_digrafo){
    if(gr == NULL)
        return 0;
    if(orig < 0 || orig >= gr->nro_vertices)
        return 0;
    if(dest < 0 || dest >= gr->nro_vertices)
        return 0;

    int i = 0;
    while(i<gr->grau[orig] && gr->arestas[orig][i] != dest)
        i++;
    if(i == gr->grau[orig])//elemento nao encontrado
        return 0;
    gr->grau[orig]--;
    gr->arestas[orig][i] = gr->arestas[orig][gr->grau[orig]];
    if(gr->eh_ponderado)
        gr->pesos[orig][i] = gr->pesos[orig][gr->grau[orig]];
    if(eh_digrafo == 0)
        removeAresta(gr,dest,orig,1);
    return 1;
}

void imprime_Grafo(Grafo *gr){
    if(gr == NULL)
        return;

    int i, j;
    for(i=0; i < gr->nro_vertices; i++){
        printf("%d: ", i);
        for(j=0; j < gr->grau[i]; j++){
            if(gr->eh_ponderado)
                printf("%d(%.2f), ", gr->arestas[i][j], gr->pesos[i][j]);
            else
                printf("%d, ", gr->arestas[i][j]);
        }
        printf("\n");
    }
}

//Exercicio 5 - Algoritmo Prim
void Prim(Grafo* gr, int origem) {
    if (gr == NULL || gr->eh_ponderado == 0) return;

    int n = gr->nro_vertices;
    int* visitado = (int*) calloc(n, sizeof(int));
    int* pai = (int*) malloc(n * sizeof(int));
    float* custo = (float*) malloc(n * sizeof(float));

    for (int i = 0; i < n; i++) {
        pai[i] = -1;
        custo[i] = 1e9;
    }
    custo[origem] = 0;

    for (int cont = 0; cont < n - 1; cont++) {
        int u = -1;

        for (int i = 0; i < n; i++) {
            if (!visitado[i] && (u == -1 || custo[i] < custo[u])) u = i;
        }

        if (u == -1) break;
        visitado[u] = 1;

        for (int i = 0; i < gr->grau[u]; i++) {
            int v = gr->arestas[u][i];
            float peso = gr->pesos[u][i];

            if (!visitado[v] && peso < custo[v]) {
                custo[v] = peso;
                pai[v] = u;
            }
        }
    }

    printf("Prim:\n");
    float soma = 0;
    for (int i = 0; i < n; i++) {
        if (pai[i] != -1) {
            printf("%d - %d (peso %.2f)\n", pai[i], i, custo[i]);
            soma += custo[i];
        }
    }
    printf("Custo: %.2f\n", soma);

    free(visitado);
    free(pai);
    free(custo);
}

int encontra_no(Grafo* gr, int no){
    if (no < 0 || no >= gr->nro_vertices) {
        // índice fora do intervalo [0 .. nro_vertices-1]
        printf("Índice inválido: %d, nó não encontrado.\n", no);
        return 0;
    }
    printf("No %d encontrado.\n", no);
    // índice válido
    return 1;

}

int encontra_aresta_menor_peso(Grafo* gr, int no){
    if (gr == NULL || no < 0 || no >= gr->nro_vertices){
        // grafo nulo ou índice fora do intervalo [0 .. nro_vertices-1]
        printf("Grafo inválido ou índice fora do intervalo: %d.\n", no);
        return 0;
    }

    float menor_peso = 1e9;
    int aresta = -1;

    for (int i = 0; i < gr->grau[no]; i++){
        if (gr->pesos[no][i] < menor_peso){
            menor_peso = gr->pesos[no][i];
            aresta = gr->arestas[no][i];
        }
    }

    if (aresta != -1){
        printf("Aresta de menor peso do nó %d: %d (peso %.2f)\n", no, aresta, menor_peso);
    } else {
        printf("Nó %d não possui arestas.\n", no);
    }

    return 1;
}

