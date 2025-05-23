#include <stdio.h>
#include <stdlib.h>
#include "ListasDupla.h"

int main(){
    struct aluno al, a[4] = {{2,"Andre",9.5,7.8,8.5},
                         {4,"Ricardo",7.8,8.7,6.8},
                         {1,"Bianca",9.7,6.7,8.4},
                         {3,"Ana",5.7,6.1,7.4}};
    Lista* li = cria_lista();
    printf("Tamanho: %d\n\n\n\n",tamanho_lista(li));

    int i;
    for(i=0; i < 4; i++)
        insere_lista_ordenada(li,a[i]);

    imprime_lista(li);
    printf("\n\n\n\n Tamanho: %d\n",tamanho_lista(li));


    for(i=0; i < 4; i++){
      remove_lista_final(li);
      imprime_lista(li);  
        printf("\nTamanho: %d\n\n\n\n",tamanho_lista(li));
    }

    //libera_lista(li);
    printf("\n\n\n\n Tamanho: %d\n",tamanho_lista(li));
    system("pause");

    //Exercicio 1.:
    printf("\nExercicio 1: Remover por matricula \n\n");

    for(i=0; i < 4; i++)
        insere_lista_ordenada(li,a[i]);
    imprime_lista(li);

    printf("\n\nDigite a matricula que deseja remover: ");
    scanf("%d",&al.matricula);

    remove_lista_Pmat(li,al.matricula);

    printf("\n\nLista apos a remocao: \n");
    imprime_lista(li);

    libera_lista(li);

    system("pause");

    //Exercicio 2.:
    printf("\nExercicio 2: Lista Ordenada \n\n");

    for(i=0; i < 4; i++)
        insere_lista_ordenada(li,a[i]);

    imprime_lista(li);
    //libera_lista(li);
    system("pause");

    printf("\nExercicio 3: Contar notas iguais \n\n");

    printf("Digite a nota que deseja contar: ");
    scanf("%f",&al.n1);

    int cont = conta_lista_nota(li,al.n1);
    printf("\n\nA quantidade de alunos com a nota %.1f e: %d\n",al.n1,cont);
    libera_lista(li);
    return 0;
}

