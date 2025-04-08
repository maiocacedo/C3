/*

* 2 - Lista de Ponteiros - Algoritmos e Estruturas de Dados III 
* Autores: | > Caio Macedo Lima da Cruz.....RA: 2651378
*          | > José Carlos Seben............RA: 2651130

*/

#include <stdio.h>
#include <stdlib.h>


// 0. Template de código //TODO comentar as linhas do código e explicar seu funcionamento abaixo.

/* 
? (O que ela faz?)
? (Tratamentos)
? (Lógica e resultados)
!       input:  | output:
!       input:  | output:
*/

// Structs exercicio 7:
typedef struct {
    int cod; // Idade do aluno
    char nome[50]; // Nome do aluno
    float preco; // 
} Produto; // Nome da struct

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

// Função Exercicio 8:

void leVetor(int *p, int n){
    for(int i = 0; i < n; i++){
        printf("Digite o valor do vetor[%d]: ", i); // Mensagem para o usuário
        scanf("%d", &p[i]); // Lê o valor do vetor
    }
    printf("\nVetor:\n"); // Mensagem para o usuário
    for(int i = 0; i < n; i++){
        printf(" %d ", p[i]); // Imprime o valor do vetor
    }
    printf("\n\n"); // Imprime uma nova linha para separar a saída

}

// Função Exercício 9:

int ** criaMatriz(int m, int n){
    int **matriz = (int **) malloc((1+m) * sizeof(int*)); // Aloca memória para a matriz

    if (matriz == NULL) { // Verifica se a alocação foi bem-sucedida
        printf("Erro ao alocar memoria\n"); // Mensagem de erro
        exit(1); // Encerra o programa com erro
    }

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
        matriz[i]= (int*) malloc((n+1)*sizeof(int));

        if(matriz[i] == NULL){
            printf("Erro de alocação");
        }
        }
    }

    return matriz; // Retorna o ponteiro para a matriz alocada
}

void limpaBaguncaMatriz(int **matriz, int m){
    for (int i = 0; i < m; i++){
        free(matriz[i]); // Libera a memória de cada linha da matriz
    }
    free(matriz); // Libera a memória da matriz
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

    v = (int *) malloc((unsigned int) n * sizeof(int)); // Aloca a memoria como N ja foi digitado por o usuario para a criação do vetor
    
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

    VET1 = (int *) malloc((unsigned int)n2 * sizeof(int)); //alocando memoria para o vetor 1
    VET2 = (int *) malloc((unsigned int)n2 * sizeof(int)); //alocando memoria para o vetor 2

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

    printf("\nExercicio 6:\n");
    
    //exercicio 6:
    /*Resolução: Para a resolução do exercício, foi utilizado de operações com ponteiros para que, a partir do decremento
    e incremento do ponteiro, fosse possível percorrer a string, independente do seu tamanho. Dessa forma, foram utilizados dois loops while
    para percorrer a string até o fim, e outro para percorrer a string até o início. Assim, primeiro é impresso a string pré-inversão e depois
    a mesma invertida. Utilizou-se apenas duas variáveis, o ponteiro char cptr e a string s.*/


    char s[10] = "abcde"; // vetor de char
    char* cptr; // ponteiro para char

    // Seu código começa aqui

    cptr = s; //cptr recebe o endereço de s que é o vetor de char
    while (*cptr != '\0') // enquanto o valor apontado por cptr não for o caractere nulo
    {
        printf(" %c ", *cptr); // imprime o caractere atual
        cptr++; // avança para o próximo caractere
    }
    {
        printf(" %c ", *cptr); // imprime o caractere nulo
        cptr++; // avança para o próximo caractere
    }

    printf("\n\n"); // imprime uma nova linha para separar a saída

    while (cptr >= s) {
        cptr--; // retrocede para o caractere anterior
        printf(" %c ", *cptr); // imprime o caractere atual
    }


    printf("\nExercicio 7:\n");
    //exercicio 7:
    /*Resolução: Esse exercício foi resolvido utilizando um ponteiro do tipo Produto, uma struct contendo as características
    de um produto. É feita uma alocação dinamica com o número de produtos a serem cadastrados. Os produtos são cadastrados pelo 
    Usuário, e o código de cada produto é gerado. Depois, é impressa a lista de códigos onde o cliente pode consultar os produtos pelo
    código. Por fim, a memória é liberada.*/

    Produto *produtoPtr; // Declara uma variável do tipo Produto
    
    
    int numeroProdutos; // Número de produtos cadastrados
    int produtoConsulta; // Declara um ponteiro para inteiro
    
    printf("Deseja cadastrar quantos produtos?\n");
    scanf("%d", &numeroProdutos); // Lê o numero de produtos a serem cadastrados
    
    produtoPtr = (Produto *) malloc((numeroProdutos+1)*sizeof(Produto)); // Aloca memória para a variável p do tipo Produto

    for(int i = 0; i<numeroProdutos; i++){
        printf("Digite o nome do produto:\n"); 
        scanf("%s", produtoPtr[i].nome); // Lê o valor do código do produto 
        printf("Digite o preço do produto:\n"); 
        scanf("%f", &produtoPtr[i].preco); // Lê o valor do código do produto
        produtoPtr[i].cod = i+1; // Gera código do produto
        printf("O codigo do produto é: %d\n", produtoPtr[i].cod); // Imprime o código desse produto
    }

    for(int i = 0; i<numeroProdutos; i++){
        printf("\nProduto de Codigo: %d\n", produtoPtr[i].cod); // Imprime o nome do produto
    } 

    printf("\nDigite o codigo do produto a ser consultado:\n"); // Mensagem para o usuário
    scanf("%d", &produtoConsulta); // Lê o código do produto a ser consultado

    printf("\nCodigo: %d\n", produtoPtr[produtoConsulta-1].cod); // Imprime o nome do produto
    printf("\nProduto: %s\n", produtoPtr[produtoConsulta-1].nome); // Imprime o nome do produto
    printf("Preco: %.2f\n", produtoPtr[produtoConsulta-1].preco); // Imprime o preço do produto

    free(produtoPtr); // Limpando a bagunça

    printf("\nExercicio 8:\n");
    
    //exercicio 8:
    /*Resolução: O usuario informa o numero de elementos, com esse valor, é feita a alocação dinamica do vetorINT,
    e a função responsável por receber e imprimir os valores desse vetor é chamada, tendo como parâmetros o vetor
    e o numero de elementos. O vetor é preenchido pelo usuário.*/


    int nelementos; // Declaração da variável nelementos
    
    int *vetorINT; // Declaração do ponteiro p
    
    printf("Informe o tamanho do vetor:\n"); // Mensagem para o usuário"
    scanf("%d", &nelementos); // Lê o tamanho do vetor a ser alocado

    vetorINT = (int *) malloc(nelementos*sizeof(int)); // Aloca memória para o ponteiro p, com espaço para 5 inteiros

    leVetor(vetorINT, nelementos); // Chama a função imprimeVetor passando o ponteiro p como argumento

    free(vetorINT); // Libera a memória alocada para o ponteiro p

    printf("\nExercicio 9:\n");

    // exercicio 9:
    /*Resolução: Nesse exercício, foi criada uma função responsavel por criar uma matriz utilizando alocação
    dinâmica a partir de um numero de linhas e colunas m e n, e outra função para limpar a memoria de uma matriz. 
    No programa principal, é criada uma matriz mat que é preenchida e impressa e depois limpada.
    */


    int nlinhas = 2, ncolunas = 2;
    int **mat = criaMatriz(nlinhas, ncolunas); // Chama a função para criar a matriz

    // Preenche a matriz com valores para testar
    for (int i = 0; i < nlinhas; i++){
        for (int j = 0; j < ncolunas; j++){
            mat[i][j] = i + j; // Exemplo de preenchimento
        }
    }

    // Imprime a matriz
    for (int i = 0; i < nlinhas; i++){
        for (int j = 0; j < ncolunas; j++){
            printf("%d\t", mat[i][j]); // Imprime os valores da matriz
        }
        printf("\n"); // Nova linha após cada linha da matriz
    }


    limpaBaguncaMatriz(mat, nlinhas); // Chama a função para limpar a bagunça



return(0); 
}
