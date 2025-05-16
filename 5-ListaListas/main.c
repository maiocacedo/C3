#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"

int main()
{
    struct aluno al, a[4] = {{2, "Andre", 9.5, 7.8, 8.5},
                             {4, "Ricardo", 7.5, 8.7, 6.8},
                             {1, "Bianca", 9.7, 6.7, 8.4},
                             {3, "Ana", 5.7, 6.1, 7.4}};
    Lista *li = cria_lista();
    printf("Tamanho: %d\n\n\n\n", tamanho_lista(li));

    int i;
    for (i = 0; i < 4; i++)
        insere_lista_ordenada(li, a[i]);

    imprime_lista(li);
    printf("\n\n\n\n Tamanho: %d\n", tamanho_lista(li));

    for (i = 0; i < 4; i++)
    {
        remove_lista_final(li);
        imprime_lista(li);
        printf("\n Tamanho: %d\n\n\n", tamanho_lista(li));
    }

    for (i = 0; i < 4; i++)
        insere_lista_ordenada(li, a[i]);
    imprime_lista(li);

    // exercicio 1) A.:

    int matricula;
    printf("\nExercicio 1) A.:\n");

    printf("\nDigite uma matricula para buscar um aluno na lista: ");
    scanf("%d", &matricula);

    consulta_lista_Pmatricula(li, matricula);

    // exercicio 1) B.:
    printf("\nExercicio 1) B.:\n");

    printf("\nTamanho: %d\n", tamanho_lista(li));

    int posicao = 0;
    printf("\nDigite uma posicao da lista de tamanho %d para buscar um aluno: ", tamanho_lista(li));
    scanf("%d", &posicao);

    consulta_lista_Pposicao(li, posicao);

    // libera_lista(li);

    // exercicio 4:
    printf("\nExercicio 4:\n\n");

    float vetor[] = {5.5, 8, 9.1, 25};
    Lista *lista_floats = cria_lista();

    lista_Vetor(lista_floats, vetor, 4);

    imprime_lista(lista_floats);

    // exercicio 6:
    //Esta commentado para não interferir no exercicio 8, para testes so retirar os comentarios
    printf("\nExercicio 6:\n\n");

    //printf("\nLista de Alunos: \n\n");
    //imprime_lista(li);

    //printf("\n\nLista de Floats: \n\n");
    //imprime_lista(lista_floats);

    //printf("\n\nLista Concatenada: \n\n");
    //concatena_listas(li, lista_floats);
    //imprime_lista(li);

    printf("\nO exercicio 6 foi comentado para nao interferir nos seguintes codigos mas esta funcionando perfeitamente\n para testar basta retirar os comentarios\n\n");

    //exercicio 8:
    printf("\nExercicio 8:\n\n");

    Lista *lista_resultado = cria_lista();

    funde_listas_ord(li, lista_floats, lista_resultado);

    imprime_lista(lista_resultado);

    libera_lista(lista_floats);
    libera_lista(li);
    libera_lista(lista_resultado);

    system("pause");
    return 0;
}
