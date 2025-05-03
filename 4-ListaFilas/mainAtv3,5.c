#include <stdio.h>
#include "Fila.h"

int main() {

    FilaInt* fila = cria_Fila_int();
    
    //demonstração
    for (int i = 1; i <= 5; i++) {
        insere_Fila_int(fila, i);
    }
    
    //fila original
    printf("Fila original: \n");
    imprime_Fila_int(fila);
    
    // Inverte a fila usando a função do exercício 3
    inverte_FilaInt(fila);
    
    //fila invertida
    printf("\nFila invertida: \n");
    imprime_Fila_int(fila);
    
    libera_Fila_int(fila);
    
    printf("\nPressione Enter Para ir para a atividade 5\n");
    getchar();

    system("cls || clear");

    //atividade 5
    printf("Atividade 5 - Pista De Decolagem\n\n");

    int i = 0;

    //Dados dos aviões para a struct
        Aviao avioes[5] = {
            {"Boeing 737", "Avianca"},
            {"Airbus A320", "Gol"},
            {"Embraer 190", "Azul"},
            {"Boeing 777", "American Airlines"},
            {"Airbus A380", "Lufthansa"}
        };
    
        FilaAviao* fi = cria_Fila_Aviao();
    
        //inserindo os aviões na fila
        while (i < 5){
            insere_Fila_Aviao(fi, avioes[i]);
            i++;
        }   
    
        printf("Quantidade de avioes da fila de decolagem: %d\n", fi->qtd);
        
        printf("\nPresione ENTER para liberar o primeiro aviao da fila a decolar\n");
        getchar();

        remove_Fila_Aviao(fi, &avioes[0]); // remove o primeiro avião da fila

        printf("\nAviao liberado para a decolagem, avioes na fila de espera %d \n", fi->qtd );

        insere_Fila_Aviao(fi, avioes[0]); // insere novamente o avião que havia decolado

        printf("\nO aviao que havia decolado retornou avioes na fila de espera %d \n", fi->qtd );

        printf("\nAvioes na fila de espera:\n");

        imprime_Fila_Aviao(fi); // imprime a fila de espera

        printf("\nPressione ENTER para vizualizar os dados do primeiro aviao da fila de espera\n");
        getchar();

        imprime_Fila_Primeiro_Aviao(fi); // imprime os dados do primeiro avião da fila de espera

        libera_Fila_Aviao(fi);
        fi = NULL; 

        libera_Fila_int(fila);
        fila = NULL; 
    return 0;
}
