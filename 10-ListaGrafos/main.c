/*

* 10 - Grafos - Algoritmos e Estruturas de Dados III 
* Autores: | > Caio Macedo Lima da Cruz.....RA: 2651378
*          | > José Carlos Seben............RA: 2651130

*/

#include "Grafo.h"

int main(){
    int eh_digrafo = 0;
    Grafo* gr = cria_Grafo(5, 5, 1);

    insereAresta(gr, 0, 1, eh_digrafo, 3.0);
    insereAresta(gr, 1, 3, eh_digrafo, 3.5);
    insereAresta(gr, 1, 2, eh_digrafo, 4.0);
    insereAresta(gr, 2, 4, eh_digrafo, 4.5);
    insereAresta(gr, 3, 0, eh_digrafo, 5.0);
    insereAresta(gr, 3, 4, eh_digrafo, 5.5);
    insereAresta(gr, 4, 1, eh_digrafo, 6.0);

    imprime_Grafo(gr);
    printf("\nBusca \n");

   // libera_Grafo(gr);

    system("pause");

    printf("\nAtividade 1 - Representacao vizual de grafo direcional e nao direcional\n");
    printf("\nResposta da atividade 1 esta contida no PDF de respostas\n\n");
    system("pause");

    printf("\nAtividade 2 - Interpretação de grafo direcionado\n");
    printf("\nResposta da atividade 2 esta contida no PDF de respostas\n\n");
    system("pause");

    printf("\nAtividade 3 - Explicacoes de Funcoes\n");
    printf("\nResposta da atividade 3 esta contida no PDF de respostas\n\n");
    system("pause");

    printf("\nAtividade 4 - Lista de adjacencia\n");
    GrafoLista* grafol = cria_GrafoLista(5);
    insere_aresta_lista(grafol, "A", 3, 0);
    insere_aresta_lista(grafol, "B", 3, 1);
    insere_aresta_lista(grafol, "C", 4, 2);
    printf("Arestas inseridas na lista de adjacencia:\n");
    imprime_GrafoLista(grafol);
    remove_aresta_lista(grafol, 1, "B");
    printf("\nAresta removida da lista de adjacencia:\n");
    imprime_GrafoLista(grafol);
    
    system("pause");

    printf("\nAtividade 5 - Algoritmo Prim\n");
    Prim(gr, 0);

    printf("\n Atividade 6 - encontra nos\n");
    if(encontra_no(gr, 2)){
        printf("No 2 encontrado com sucesso.\n");
    } else {
        printf("No 2 nao encontrado.\n");
    }
    if(encontra_aresta_menor_peso(gr, 1)){
        printf("Aresta de menor peso do no 1 encontrada com sucesso.\n");
    } else {
        printf("Aresta de menor peso do no 1 nao encontrada.\n");
    }
    

    libera_GrafoLista(grafol);
    libera_Grafo(gr);
    system("pause");
    return 0;
}
