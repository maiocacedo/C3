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

//função da atividade 5:
int inverte_vetor(int *v1, int *v2, int n){
    int maiorValor = v1[0];

    for (int i = 0; i < n; i++){
        v2[n - 1 - i] = v1[i]; //realiza a inversão do vetor
        if (v1[i] > maiorValor){ //if para fazer a verificação do maior valor
            maiorValor = v1[i]; //se encontrado um valor maior adiciona a maiorValor
        }
    }
    return maiorValor; //retorna o maior valor encontrado
}

int main(){
     
    //exercicio 2:
    printf("Exercicio 2:\n");
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
    /*Resolução:para resolver o problema apenas troque o &q2 que armazena a posição de memoria de p2
    por **q2 que por ser um ponteiro duplo armazena o valor de p2 que armazena o valor de x2 
    */

    printf("\nExercicio 3:\n");
    int x2, *p2, **q2; 
    p2 = &x2; 
    q2 = &p2; 
    x2 = 10; 
    printf("%d\n", **q2); 

    //exercicio 4:
    /*Resolução: Como no enunciado da atividade 4 nos limita a a apenas salvar o vetor na memoria apos 
    o usuario digitar o valor de N para ser o tamanho do vetor utilizei alocação dinamica guardando 
    a memoria apenas apos receber o valor de N o restante do codigo sendo uma manipulação simples de vetor
    onde o usuario fornece o valor de N para ser o tamanho do vetor apos isso o sistema pedira os valores 
    para preencher o valor e depois printara o valor, so para mostrar o funcionamento*/
    printf("\nExercicio 4:\n");
    
    int n, *v;

    printf("Informe o valor de N para o tamanho do vetor:\n");
    scanf("%d", &n); //recebera o tamanho de n para depois criar o vetor

    v = (int *) malloc(n * sizeof(int)); // Aloca a memoria como N ja foi digitado por o usuario para a criação do vetor
    
    printf("Digite os valores para o vetor:\n"); // for utilizado para pegar as entradas do usuario e as atribuir ao vetor
    for (int i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }

    printf("\nVetor:\n"); //utilizado para printar o vetor criado pelo usuario
    for (int i = 0; i < n; i++){
        printf("%d ", v[i]);
    }

    free (v); //como foi utilizado alocação agora precisa limpar a memoria alocada por v

    printf("\n");

    //exercicio 5:
    /*Resolução: De principio para resolver este exercicio como primeiro precisamos criar o vetor 1 e receber
    seus valores utilizei alocação dinamica para armazenar os valores do vetor 1, e do vetor 2 para depois na função
    inverte_vetor usar uma logica de subtração das posições no vetor para estar fazendo a inverção do vetor 1 e o 
    armazenar no vetor 2, e alem disso utilizando o modelo de comparação para encontrar no vetor 1 qual é seu maior valor
    onde para fazer isso consideramos o valor presente na posição 0 como o maior valor, e depois utilizamos o for que percorre
    o vetor para comparar o valor da primeira posição com os demais valores presentes no vetor assim quando um valor
    maio que o contido na posição 0 for encontrado o valor de maiorValor a variavel utilizada para receber o maior valor
    contido no vetor vai ser atualizada, assim percorrendo o vetor todo e armazenando nesta variavel o maior valor encontrado*/
    printf("\nExercicio 5:\n");

    int n2;

    printf("Digite o tamanho de N para os vetores V1 e V2: \n"); //recebendo o tamanho dos dois vetores
    scanf("%d", &n2);

    int *VET1, *VET2;

    VET1 = (int *) malloc(n2 * sizeof(int)); //alocando memoria para o vetor 1
    VET2 = (int *) malloc(n2 * sizeof(int)); //alocando memoria para o vetor 2

    printf("\nDigite os valores para o vetor V1:\n"); //recebendo os valores do vetor 1
    for(int i2 = 0; i2 < n2; i2++){
        scanf("%d", &VET1[i2]);
    }

    int maiorValor = inverte_vetor(VET1, VET2, n2);

    //imprimindo os resultados depois da execução de inverte_vetor
    printf("\nMaior valor do vetor 1: %d\n", maiorValor); 

    printf("\nVetor 1:\n");
    for(int i2 = 0; i2 < n2; i2++){
        printf("%d ", VET1[i2]);
    }
    printf("\n");

    printf("\nVetor 2:\n");
    for(int i2 = 0; i2 < n2; i2++){
        printf("%d ", VET2[i2]);
    }
    printf("\n");

    free(VET1); //limpando bagunça
    free(VET2); //limpando bagunça

return(0); 
}
