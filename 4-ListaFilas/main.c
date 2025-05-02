/*

* 4- Lista - Algoritmos e Estruturas de Dados III 
* Autores: | > Caio Macedo Lima da Cruz.....RA: 2651378
*          | > José Carlos Seben............RA: 2651130

*/

#include "Fila.h"

int main(){
    // menu de opções
    menu();

    system("cls"); // limpa a tela
    printf("-------------------------\n\n");

    FilaInt* fila1 = cria_Fila_int(); // cria fila de inteiros
    FilaInt* fila2 = cria_Fila_int(); // cria fila de inteiros
    FilaInt* fila3 = cria_Fila_int(); // cria fila de inteiros
    FilaInt* fila4 = cria_Fila_int(); // cria fila de inteiros
    Fila* filaal1 = cria_Fila(); // cria fila de inteiros
    Fila* filaal2 = cria_Fila(); // cria fila de inteiros

    struct aluno al1, al2, al3; // variáveis do tipo aluno
    al1.matricula = 1; // inicializa a matrícula do aluno 1
    strcpy(al1.nome, "Caio"); // inicializa o nome do aluno 1
    al1.n1 = 10; // inicializa a nota 1 do aluno 1
    al1.n2 = 10; // inicializa a nota 2 do aluno 1
    al1.n3 = 10; // inicializa a nota 3 do aluno 1

    al2.matricula = 2; // inicializa a matrícula do aluno 2
    strcpy(al2.nome, "José"); // inicializa o nome do aluno 2
    al2.n1 = 10; // inicializa a nota 1 do aluno 2
    al2.n2 = 10; // inicializa a nota 2 do aluno 2
    al2.n3 = 10; // inicializa a nota 3 do aluno 2

    al3.matricula = 3; // inicializa a matrícula do aluno 3
    strcpy(al3.nome, "Carlos"); // inicializa o nome do aluno 3
    al3.n1 = 10; // inicializa a nota 1 do aluno 3
    al3.n2 = 10; // inicializa a nota 2 do aluno 3
    al3.n3 = 10; // inicializa a nota 3 do aluno 3


    for (int i = 0; i < 10; i++){
        insere_Fila_int(fila1, i*2); // insere elementos na fila f1
    }
    for (int i = 0; i < 5; i++){
        insere_Fila_int(fila1, i*4); // insere elementos na fila f1
    }

    for (int i = 0; i < 10; i++){
        insere_Fila_int(fila2, i*4); // insere elementos na fila f1
    }
    for (int i = 0; i < 5; i++){
        insere_Fila_int(fila2, i*2); // insere elementos na fila f1
    }

    insere_Fila(filaal1, al1); // insere o aluno 1 na fila de alunos
    insere_Fila(filaal1, al2); // insere o aluno 2 na fila de alunos
    insere_Fila(filaal1, al3); // insere o aluno 3 na fila de alunos
    

    printf("-------------------------\n\n");

    printf("Exercicio 1 - Separar fila\n\n");
    // imprime as filas
    printf("Fila 1:\n");
    imprime_Fila(filaal1); // imprime a fila 1
    printf("\n\nFila 2:\n");
    imprime_Fila(filaal2); // imprime a fila 2

    separa_fila(filaal1, filaal2, 2); // separa a fila f1 em duas filas, f1 e f3, a partir do elemento 10

    printf("\n\nFila 1:\n");
    imprime_Fila(filaal1); // imprime a fila 1
    printf("\n\nFila 2:\n");
    imprime_Fila(filaal2); // imprime a fila 2

    system("pause"); // espera o usuário apertar uma tecla
    system("cls"); // limpa a tela
    
    printf("-------------------------\n\n");

    printf("Exercicio 6 - Ordem crescente\n\n");
    // imprime as filas
    printf("Fila 1:\n");
    imprime_Fila_int(fila1);
    printf("Fila 2:\n");
    imprime_Fila_int(fila2);

    nova_fila_ordem_crescente(fila1, fila2, fila4); // cria uma nova fila com os elementos em ordem crescente

    printf("Fila 3:\n");
    imprime_Fila_int(fila4); // imprime a fila 3

    system("pause"); // espera o usuário apertar uma tecla
    system("cls"); // limpa a tela
    
    
    printf("Exercicio 7 - Inverter fila\n\n");
    printf("Fila 1:\n");
    imprime_Fila_int(fila1); // imprime a fila 1

    reverso(fila1); // inverte a ordem dos elementos da fila f1
    
    printf("-------------------------\n\n");
    printf("Fila 1 invertida:\n");
    imprime_Fila_int(fila1); // imprime a fila 1

    printf("-------------------------\n\n");

    system("pause"); // espera o usuário apertar uma tecla
    system("cls"); // limpa a tela

    printf("Saindo");
    for(int i = 0; i < 3; i++){
        printf(".");
        Sleep(700); // espera 1 segundo
    }

    printf("\n\n");

    libera_Fila_int(fila1); // libera a memória da fila f1
    libera_Fila_int(fila2); // libera a memória da fila f2
    libera_Fila_int(fila3); // libera a memória da fila f3
    libera_Fila_int(fila4); // libera a memória da fila f4
    libera_Fila(filaal1); // libera a memória da fila de alunos 1
    libera_Fila(filaal2); // libera a memória da fila de alunos 2

    return 0;
}