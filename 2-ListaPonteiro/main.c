/*

* 2 - Lista de Ponteiros - Algoritmos e Estruturas de Dados III 
* Autores: | > Caio Macedo Lima da Cruz.....RA: 2651378
*          | > José Carlos Seben............RA: 2651130

*/

#include <stdio.h>
#include <stdlib.h>


// 0. Template de código //TODO comentar as linhas do código e explicar seu funcionamento abaixo.
int func() {
}

/* 
? (O que ela faz?)
? (Tratamentos)
? (Lógica e resultados)
!       input:  | output:
!       input:  | output:
*/

/*
Exercicio 1:
1) Sendo p um ponteiro, qual a diferença entre: 
•  p++;        
•  (*p)++;         
•  *(p++); 
•  O que quer dizer *(p+10);?
*/

/*
Resposta exercicio 1:
    p++: Incrementa o ponteiro fazendo o apontar para a proxima "posição" sem estar incrementado 
    o valor do ponteiro e sim apenas sua posição. Comumente utilizado em Arrays onde o ponteiro vai estar 
    apontando para a posição 0 utilizando p++ o ponteiro vai apontar para a proxima posiçãodo
    Array sem alterar o valor.
    Em um exemplo tendo um Array {7, 9, 11} onte o ponteiro vai estar apontando para a posição 0,
    ou seja neste exemplo o 7 utilizando o p++ vai apontar para o 9 sem alterar nenhuma valor.

    (*p)++: Com o ponteiro estando isolato em (*p) e o ++ utilizado para incrementar estando fora
    dos parenteses a posição do ponteiro não vai ser alterada diferente de p++ onde o valor não se 
    altera e sim apenas a posição apontada, em (*p)++ a posição do pontenteiro vai ser mantida e oque sai ser
    incrementedo com o ++ vai ser o valor apontado.
    Diferente do exemplo anterior que ao utilizar p++ alterou a posição do ponteiro no Array 
    passando da posição 0 que era o 7 para a posição 1 sendo o 9, neste caso de utilizarmos (*p)++
    oque vai ser incrementado é o valor que esta sendo apontado, em um exemplo pratico onde o ponteiro 
    vai estar apontando para a posição 0 sendo 7 utilizar (*p)++ o ponteiro vai continuar aopntando para a 
    posição 0 mais vai estar incrementando o valor mudando de 7 para 8, ficando assim nosso Array anterior 
    como {8, 9, 11}.

   *(p++): Por o * estar isolado fora do parentesses primeiro vai estar acessando o valor de p
    que vai ser a primeira posição do Array sendo a posição 0 o 7, por ++ usado para incrementar estar
    isolado entre os parenteses juntoco com p vai ser executado posteriormente e ira incrementar p para o proximo
    elemento simplificando vai estar primeiro com * acessando a posição 0 sendo o 7 e depois com (p++) 
    vai estar incrementando a posição e passara para a posição 1 do Array sendo neste caso do exemplo 9
    sem estar incrementando o valor de nenhuma das 2 posiçãos do ponteiro mas sim acessando duas posições 
    com so uma ação.

    Oque quer dizer *(p+10): Utilizar *(p+10) o ponteiro vai estar acessando diretamente a posição 10 
    de um Array por exemplo, ao utilizar essa expressão o sistema fara a conta das posições e vai
    estar acessando diretamenta a posição 10 ou seja quer dizer que utilizar *(p+10) quer dizer para 
    a maquina estar acessando a posição 10 de um Array, vetor etc...
*/

int main(){
     
    //exercicio 2:
    printf("Exercicio 2:\n ");
    int y, *p, x;  //Declaração da variaveis sendo p um ponteiro.
    y = 0;  //inicia y com valor de 0
    p = &y;  //inicia p com o endereço de y
    x = *p;  /* inicia x com o valor de y pois com o *p esta apontando para o valor
                diferente de p que estava pontando para o local na memoria de y e nao o valor do seguinte */
    x = 4;  //adiciona 4 como valor de x 
    (*p)++;  //como na explicação da atividade 1 a posição vai ser mantida e vai ter uma incrementação no valor de y que passara a ser 1
    x--;  //logica contraria de ++ utilizada para incrementar utiliza -- para diminuir o valor de x
    (*p) += x;  /* faz a soma do valor do ponteiro de y que estava como 1 depois da incrementação com o valor de x
                    que estava como 1 depois da decrementação somando como 4*/
    printf ("y = %d\n", y);  //printa o valor de y apos todas as operações

    //exercicio 3:
    printf("\nExercicio 3:\n ");
    int x2, *p2, **q2; 
    p2 = &x2; 
    q2 = &p2; 
    x2 = 10; 
    printf("%d\n", **q2); /*para resolver o problema apenas troque o &q2 que armazena a posição de memoria de p2
                            por **q2 que por ser um ponteiro duplo armazena o valor de p2 que armazena o valor de x2 */

    return(0); 
}
