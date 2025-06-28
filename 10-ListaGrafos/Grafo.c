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



