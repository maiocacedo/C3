#include <stdio.h>
#include <stdlib.h>
#include "PilhaDinamica.h"

int main(){
    Aluno a[4] = {{2,"Andre",9.5,7.8,8.5},
    {4,"Ricardo",7.5,8.7,6.8},
    {1,"Bianca",9.7,6.7,8.4},
    {3,"Ana",5.7,6.1,7.4}};
    Pilha* pi = cria_Pilha();
    printf("Tamanho: %d\n\n\n\n",tamanho_Pilha(pi));

    pushN(pi,a,4);

    imprimirPilha(pi);
    printf("Tamanho: %d\n\n\n\n",tamanho_Pilha(pi));
    
    popN(pi, 4);
    printf("Tamanho: %d\n\n\n\n",tamanho_Pilha(pi));
    
    pushN(pi,a, 4);
    printf("Tamanho: %d\n\n\n\n",tamanho_Pilha(pi));
    
    imprimirPilhaRecursiva(*pi);
    printf("Tamanho: %d\n\n\n\n",tamanho_Pilha(pi));
    
    imprimirPilhaInversaRecursiva(*pi);
    printf("Tamanho: %d\n\n\n\n",tamanho_Pilha(pi));

    imprimirPilha(pi);
    printf("Tamanho: %d\n\n\n\n",tamanho_Pilha(pi));

    libera_Pilha(pi);
    system("pause");
    return 0;
}