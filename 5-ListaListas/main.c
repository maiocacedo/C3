#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"
int main(){
    struct aluno al, a[4] = {{2,"Andre",9.5,7.8,8.5},
                         {4,"Ricardo",7.5,8.7,6.8},
                         {1,"Bianca",9.7,6.7,8.4},
                         {3,"Ana",5.7,6.1,7.4}};

    Lista* li = cria_lista();
    Lista* li2 = cria_lista();
    Lista* li3 = cria_lista();
    
    printf("Tamanho: %d\n\n\n\n",tamanho_lista(li));

    int i;
    for(i=0; i < 4; i++){
        insere_lista_ordenada(li,a[i]);
        insere_lista_ordenada(li2,a[i]);
        insere_lista_ordenada(li3,a[i]);
    }
    imprime_lista(li);
    printf("\n\n\n\n Tamanho: %d\n",tamanho_lista(li));

    for(i=0; i < 4; i++){
        remove_lista_final(li);
        imprime_lista(li);
        printf("\n Tamanho: %d\n\n\n",tamanho_lista(li));
    }

    for(i=0; i < 4; i++)
        insere_lista_ordenada(li,a[i]);
    imprime_lista(li);
    
    system("pause");
    system("cls");

    printf("\n\n------------ Exercicio 2 ------------\n\n");

    imprime_lista(li2);
    imprime_lista(li3);

    if(lista_ingual_rec(li2,li3) == 1)
        printf(" > As Listas sao inguais\n\n");
    
    
    
    if(remove_lista_rec(li, 3) == 1)
        printf(" > Aluno de matricula %d removido com sucesso!\n", 3);
    imprime_lista(li);
    
    system("pause");
    system("cls");

    printf("\n\n------------ Exercicio 3 ------------\n\n");
    int pos = 2;
    imprime_lista(li);
    if(insere_lista_pos(li, a[2], pos) == 1)
        printf(" > Inserido com sucesso na posicao %d\n", pos);
    imprime_lista(li);
    libera_lista(li);
    libera_lista(li2);
    libera_lista(li3);
    system("pause");
    return 0;
}

