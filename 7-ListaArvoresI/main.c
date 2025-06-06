/*

* 7 - Arvores | - Algoritmos e Estruturas de Dados III 
* Autores: | > Caio Macedo Lima da Cruz.....RA: 2651378
*          | > José Carlos Seben............RA: 2651130

*/

#include <stdio.h>
#include <stdlib.h>
#include "Arvores.h"

int main(){
    int N = 8, dados[8] = {50,100,30,20,40,45,35,37};

    ArvBin* raiz = cria_ArvBin();

    int i;
    for(i=0; i < N; i++)
        insere_ArvBin(raiz,dados[i]);

    preOrdem_ArvBin(raiz);
    //emOrdem_ArvBin(raiz);
    //posOrdem_ArvBin(raiz);

    if(remove_ArvBin(raiz,50)){
        printf("removido\n");
        preOrdem_ArvBin(raiz);
    }else
        printf("NAO removido\n");


//    printf("altura: %d\n",altura_ArvBin(raiz));
//    printf("total NOs: %d\n",totalNO_ArvBin(raiz));
//
//    if (consulta_ArvBin(raiz, 4, &al))
//        printf("\n%d %s\n",al.mat,al.nome);

    libera_ArvBin(raiz);
    raiz = NULL;

    printf("\nFim!\n");
    system("pause"); // espera o usuário apertar uma tecla

    printf("\n\nExercicio 1 - Descricao de Funcoes\n\n");

    printf("insere_Arvore: A funcao segue um modelo de parecido com outras funcoes que ja trabalhamos \ncomecando com as verificacoes apoz isso cria a raiz alocando memoria, \nno caso de a arvore estar vazio o novo no se tornara a raiz, os nos esquerdo e direito sao inicializados como NULL \ne faz uma verificacao de se o valor ja existir na arvore libera o novo no.\n");

    printf("\nremove_Arvore: Assim como a outra funcao comeca com a verificacao de se a arvore existe, \na funcao recebe um valor interio para ser o valor do no a ser removido \nao percorrer a arvore e localizar o no onde as informacoes sejam iguais as de \natual->info vai utilizar a funcao remove_atual para remover o no com valor correspondete ao que o usuario informar \ncomo a funcao tem um controle de anterior (pai) e atual \nvai ser utilizado para reposicionar os ponterios que conectavam o no removido \nem caso de ser um no filho, e no caso de o no removido ser a raiz vai atualizar a raiz.\n\n");

    system("pause");

    printf("\n\nExercicio 2 - funcoes de varredura\n\n");

    raiz = cria_ArvBin();

    for(i=0; i < N; i++)
        insere_ArvBin(raiz,dados[i]);

    printf("Pre Ordem:\n");
    preOrdem_ArvBin(raiz);

    printf("\nEm Ordem:\n");
    emOrdem_ArvBin(raiz);

    printf("\nPos Ordem:\n");
    posOrdem_ArvBin(raiz);

    libera_ArvBin(raiz);
    raiz = NULL;

    system("pause"); 

    printf("\n\nExercicio 3 - Conta nos\n\n");

    raiz = cria_ArvBin();

    for(i=0; i < N; i++) insere_ArvBin(raiz,dados[i]);

    printf("Total de nos: %d\n", totalNO_ArvBin(raiz));    

    libera_ArvBin(raiz);
    raiz = NULL;
    system("pause");

    printf("\n\nExercicio 4 - Localizar valor\n\n");

    raiz = cria_ArvBin();
    for(i=0; i < N; i++) insere_ArvBin(raiz,dados[i]);

    int valor;

    printf("Digite um valor a ser consultado se existe ou nao na matriz: ");
    scanf("%d", &valor);

    if (consulta_ArvBin(raiz, valor)) {
        printf("O valor existe na arvore.\n\n");
    } else {
        printf("O valor nao esta presente na arvore.\n\n");
    }

    libera_ArvBin(raiz);
    raiz = NULL;
    system("pause");

    return 0;
}
